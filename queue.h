#include<stdio.h>
int head=0;
int tail=0;
char queue[100];
void enqueue(char key)
{
    if(tail<99&&tail>=0)
    {
        tail++;
        queue[tail]=key;
    }
    else
        printf("QUEUE IS FULL\n");
}
char dequeue()
{
    if(head>=tail)
        printf("QUEUE IS EMPTY");
    else
        return queue[++head];
}
