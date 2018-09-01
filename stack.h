#include<stdio.h>
int top=50;
char stack[51];
void push(char key)
{
    if(top<0)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    else
    {
        top--;
        stack[top]=key;
    }
    return;
}
char pop()
{
    if(top==50)
    {
        printf("STACK EMPTY\n");
        return;
    }
    else
    {
        return stack[top++];
    }
}
char display()
{
    if(top<-1)
    {
        printf("STACK EMPTY\n");
        return;
    }
    else
    {
        return stack[top];
    }
}
