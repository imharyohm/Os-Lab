// write a c code to make one parent with its child and that child have its own child
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int A, B, C;
    printf("Parent A id: %d\n", getpid());
    B = fork();
    if (B == 0)
    {
        printf("Child of A(B)id: %d\n", getpid());
        printf("parent of B(A) id: %d\n", getppid());
        C = fork();
        if (C == 0)
        {
            printf("Child of B(C) id: %d\n", getpid());
            printf("parent of C(B) id: %d\n", getppid());
        }
        else
        {
            wait(NULL);
            printf("Parent B id: %d\n", getpid());
        }
    }

    else
    {
        wait(NULL);
        printf("Parent A id: %d\n", getpid());
    }
    return 0;
}