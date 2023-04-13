#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int pid, AT, BT, WT, TT, visited;
} Process;

int main()
{
    int n;
    printf("ENter the number of process : ");
    scanf("%d", &n);
    Process P[n];
    printf("Enter the processor id, arrival time and burst time for each processor respectively.\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details for %d processor\n", i + 1);
        scanf("%d%d%d", &P[i].pid, &P[i].AT, &P[i].BT);
        P[i].visited = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (P[i].AT > P[j].AT)
            {

                Process temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
            else if (P[i].AT == P[j].AT)
            {
                if (P[i].BT > P[j].BT)
                {
                    Process temp = P[i];
                    P[i] = P[j];
                    P[j] = temp;
                }
            }
        }
    }
    int completion_time = P[0].AT;
    int total_waiting = 0;
    int index = 0;
    int a = 0, temp = 1;
    while (temp == 1)
    {

        if (a == 0)
        {
            index = a;
            completion_time += P[index].BT;
            P[index].TT = completion_time - P[index].AT;
            P[index].WT = P[index].TT - P[index].BT;
            P[index].visited = 1;
            a++;
        }
        else
        {
            index = -1;
            int minimum_job = 76543;
            for (int i = 1; i < n; i++)
            {
                if (P[i].AT <= completion_time && P[i].visited == 0)
                {
                    if (P[i].BT < minimum_job)
                    {
                        index = i;
                        minimum_job = P[i].BT;
                    }
                }
            }
            if (index != -1)
            {
                completion_time += P[index].BT;
                P[index].TT = completion_time - P[index].AT;
                P[index].WT = P[index].TT - P[index].BT;
                P[index].visited = 1;
                a++;
            }
            else
                completion_time++;
        }
        if (a == n)
            temp = 0;
    }
    printf("pid\tAT\tBT\tTT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", P[i].pid, P[i].AT, P[i].BT, P[i].TT, P[i].WT);
    return 0;
}