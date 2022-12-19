/* ********************************
   ****** Local & global var ******
   ******************************** */


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int globalVariable = 24;
int main()
{
    int localVariable = 99, i = 1;
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("In Child process");
        globalVariable++;
        localVariable++;
    }
    else if (pid < 0)
    {
        printf("Fork failed");
        exit(1);
    }
    else 
    {
        printf("Parent process");
    }

    printf("global variable: %d\n", globalVariable);
    printf("local variable: %d\n", localVariable);
    return 0;
}