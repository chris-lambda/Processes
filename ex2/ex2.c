// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp;
    fp = fopen("./text.txt", "w");
    pid_t pid;
    
    pid = fork();
    pid = fork();

    char buf[20];

    if (pid == 0) {
        sprintf(buf, "child pid: %d\n", pid);
        fputs(buf, fp);
    } else {
        sprintf(buf, "parent pid: %d\n", pid);
        fputs(buf, fp);
    }

    fclose(fp);

    return 0;
}
