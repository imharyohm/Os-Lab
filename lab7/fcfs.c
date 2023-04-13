#include <stdio.h>
typedef struct
{
    int pid, at, bt, tat, ct, wt;
} process;

void sort(process *p, int n)
{ // sorting on the basis of arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                process temp;
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calculate(process *p, int n)
{

   
    int temp = 0;
    p[0].ct = p[0].at + p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt = p[0].tat - p[0].bt;

    for (int i = 1; i < n; i++)
    {
        if (p[i - 1].ct < p[i].at)      // condition for when cpu is in ideal case
            temp = p[i].at - p[i - 1].ct;


        p[i].ct = p[i].bt +p[i-1].ct+ temp;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void display(process *p, int n)
{
    printf("Pid\tAt\tBt\tTat\tWt\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].tat, p[i].wt);
    }
}


int main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time of the process %d:", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
    }
    sort(p, n);
    calculate(p, n);
    display(p, n);
}
