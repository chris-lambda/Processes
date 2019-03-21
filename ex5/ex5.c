// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1\n";
char* msg2 = "hello world #2\n";
char* msg3 = "hello world #3\n";

int main(void)
{
    // Your code here

    char buf[128];

    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        write(fd[1], msg1, MSGSIZE);
        pid_t pid2 = fork();
        if (pid2 == 0) {
            write(fd[1], msg2, MSGSIZE);
            pid_t pid3 = fork();
            if (pid3 == 0) {
                write(fd[1], msg3, MSGSIZE);
            } else {
                wait(NULL);
            }
        } else {
            wait(NULL);
        }
    } else {
        wait(NULL);
        int bytes_read = read(fd[0], buf, sizeof buf);
        write(STDOUT_FILENO, buf, bytes_read);
    }
    
    return 0;
}
