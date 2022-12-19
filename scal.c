/* ********************************
   ******* System call - 1  *******
   ******************************** */

#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t childpid = fork();
    int retval,status;
    if(childpid >= 0)
    {
        if(childpid ==0)
        {
            printf("I am child process running .\n PID:%d\n. Parrent PID:%d\n", getpid(), getppid());
            printf("sleep for 10 sec\n");
            sleep(10);
            printf("Enter anything to exit");
            scanf("%d", &retval);
            printf("BYE\n");
            exit(retval);
        }
        else
        {
            printf("I am parrent process running .\n PID:%d\n.", getpid());
            printf("I will wait now for my child process to exit\n");
            wait(&status);
            if(WIFEXITED(status))
            {
                printf("parent has exited %d\n", WEXITSTATUS(status));
            }
            printf("BYE\n");
            exit(0);
        }
    }
    else
    {
        perror("fork");
        exit(0);
    }
    
}
