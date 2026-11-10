#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include "common.h"

int main(void) {
    mqd_t mq;
    struct mq_attr attr;
    char *buffer;
    unsigned int priority;

    mq = mq_open(QUEUE_NAME, O_RDONLY);

    if (mq == (mqd_t)-1) {
        perror("mq_open");
        fprintf(stderr, "Hint: Run the sender first.\n");
        exit(EXIT_FAILURE);
    }

    if (mq_getattr(mq, &attr) == -1) {
        perror("mq_getattr");
        mq_close(mq);
        exit(EXIT_FAILURE);
    }

    buffer = malloc(attr.mq_msgsize);

    if (buffer == NULL) {
        perror("malloc");
        mq_close(mq);
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_read = mq_receive(
        mq, buffer, attr.mq_msgsize, &priority
    );

    if (bytes_read == -1) {
        perror("mq_receive");
        free(buffer);
        mq_close(mq);
        exit(EXIT_FAILURE);
    }

    printf("Receiver: message received successfully!\n");
    printf("Receiver: message = \"%s\"\n", buffer);
    printf("Receiver: message priority = %u\n", priority);

    free(buffer);
    mq_close(mq);

    if (mq_unlink(QUEUE_NAME) == -1) {
        perror("mq_unlink");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: message queue removed.\n");

    return 0;
}
