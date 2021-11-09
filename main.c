#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void int_handler(int signal) {
    if (signal == SIGINT) {
        int file = open("exit_file.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (file < 0) {
            printf("bruh couldn't even make a file to say that i was exiting\n");
            exit(-1);
        }

        write(file, "recieved sigint\n", 17);

        close(file);

        exit(0);
    }
}

static void usr_handler(int signal) {
    if (signal == SIGUSR1) {
        printf("Recieved SIGUSR1. Parent PID: %d\n", getppid());
    }
}

int main() {
    signal(SIGINT, int_handler);
    signal(SIGUSR1, usr_handler);

    while (1) {
        printf("This PID: %d\n", getpid());
        sleep(1);
    }

    return 0;
}
