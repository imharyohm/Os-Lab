#include <stdio.h>
#include <limits.h>
#define max(a, b) (a > b) ? a : b
typedef struct
{
    int pid;
    int st;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int visited;
    int remain_bt;
} rr;
typedef struct
{
    int f, r;
    int data[100];
} queue;
void init(queue *q)
{
    q->f = q->r = -1;
}
void push(queue *q, int val)
{
    if (q->r == -1)
    {
        q->f = q->r = 0;
        q->data[q->r] = val;
    }
    else{
        q->data[++q->r] = val;
    }
}
void pop(queue *q)
{
    if (q->f == q->r)
    {
        q->f = q->r = -1;
    }
    else
        q->f++;
}
int empty(queue q)
{
    if (q.f == -1)
        return 1;
    else
        return 0;
}
int peek(queue q)
{
    return (q.data[q.f]);
}
void sort(rr *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                rr temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n, qt,count=0;
    printf("Enter the no of process: ");
    scanf("%d", &n);
    printf("Enter the quantum time: ");
    scanf("%d", &qt);
    queue q;
    init(&q);
    rr p[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i;
        p[i].visited = 0;
        p[i].remain_bt = p[i].bt;
    }

    sort(p, n);
    push(&q, 0);
    count++;
    p[0].visited = 1;
    int completed = 0; // keeps track of no of process completed
    int curr_time = 0;
    printf("PID\tAT\tBT\tTT\tWT\tRT\n");
    while (completed != n)
    {
        // take the process from queue and remove it.
        int x = peek(q);
        pop(&q);
        if (p[x].remain_bt == p[x].bt)
        {
            p[x].st = max(curr_time, p[x].at);
            curr_time = p[x].st;
        }
        if ((p[x].remain_bt - qt) > 0)
        {
            p[x].remain_bt -= qt;
            curr_time += qt;
        }
        else
        {
            curr_time += p[x].remain_bt;
            p[x].remain_bt = 0;
            p[x].ct = curr_time;
            p[x].tat = p[x].ct - p[x].at;
            p[x].wt = p[x].tat - p[x].bt;
            p[x].rt = p[x].st - p[x].at;
            printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[x].pid, p[x].at, p[x].bt, p[x].tat, p[x].wt, p[x].rt);
            completed++;
        }

        for (int i = 1; i < n; i++) // check which process can enter into the ready queue till the time being other process exe
        {
            if(count==n) break;
            if (p[i].visited == 0 && p[i].remain_bt > 0 && p[i].at <= curr_time)
            {
                push(&q, i);
                count++;
                p[i].visited = 1;
            }
        }
        // check if the process which is executing need to be placed again in the ready queue or not
        if (p[x].remain_bt > 0)
            push(&q, x);

        // if queue becomes empty before the new process arrive to ready queue, then bring one of the process whose bt_remain > 0
        if (empty(q))
        {
            for (int i = 1; i < n; i++)
            {
                if (p[i].remain_bt > 0)
                {
                    push(&q, i);
                    p[i].visited = 1;
                    break;
                }
            }
        }
    }

}