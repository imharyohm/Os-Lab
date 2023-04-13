//write a c program to create a parent class and it two child class

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    int A,B,C;
    printf("Parent A id: %d\n",getpid());
    B=fork();
    if(B==0){
        printf("Child of A(B)id: %d\n",getpid());
        printf("parent of B(A) id: %d\n",getppid());
    }
    else{
        C=fork();
        if(C==0){
            printf("Child of A(C) id: %d\n",getpid());
            printf("parent of C(A) id: %d\n",getppid());
        }
        else{
            wait(NULL);
            printf("Parent A id: %d\n",getpid());
        }
    }

    return 0;
}
