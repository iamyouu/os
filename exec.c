/* ********************************
   ******* fork() & exec()  *******
   ******************************** */

// The exec() family of functions replaces the current process image with a new process image.

#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *args[]);
{
    int pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed");
        exit(-1);
    }
    else if (pid == 0)
    {
        execlp("/bin/ls","ls", NULL);
    }
    else 
    {
        wait(NULL);
        printf("child completed successfully");
        exit(0);
    }
}
