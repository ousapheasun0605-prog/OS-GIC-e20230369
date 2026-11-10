
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    const char *text = "Hello from Operating Systems class!\n";
    const char *confirm = "File created successfully!\n";

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    if (write(fd, text, strlen(text)) < 0) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);

    write(STDOUT_FILENO, confirm, strlen(confirm));

    return 0;
}
