#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buffer[256];

    int fd = open("output.txt", O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }


    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {

        if (write(STDOUT_FILENO, buffer, bytesRead) < 0) {
            perror("Error writing to terminal");
            close(fd);
            return 1;
        }
    }

    if (bytesRead < 0) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
