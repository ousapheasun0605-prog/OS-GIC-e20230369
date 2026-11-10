#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include "common.h"

int main(void) {
    mqd_t mq;
    const char *message = "Hello from the message queue sender!";

    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, NULL);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        mq_close(mq);
        exit(EXIT_FAILURE);
    }

    printf("Sender: message sent successfully!\n");
    printf("Sender: message = \"%s\"\n", message);

    mq_close(mq);
    return 0;
}
