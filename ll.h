#include <stdio.h>
#include <malloc.h>
struct node
{
    int value;
    struct node *next;
};
typedef struct node snode;
void insert_node_first();
void insert_node_last();
void insert_node_pos();
void delete_pos();
void display();
snode *newnode, *ptr, *prev, *temp;
snode *first = NULL, *last = NULL;
snode* create_node(int val)
{
    newnode = (snode *)malloc(sizeof(snode)); //https://www.geeksforgeeks.org/calloc-versus-malloc/
    newnode->value=val;
    newnode->next=NULL;
    return newnode;
}
void insert_node_first()
{
    int val;
    printf("\nEnter the value: ");
    scanf("%d", &val);
    newnode=create_node(val);
    if (first==last&&first==NULL)
    {
        first=newnode;
        last=newnode;
        first->next=NULL;
        last->next=NULL;
    }
    else
    {
        temp=first;
        first=newnode;
        first->next=temp;
    }
}
void insert_node_last()
{
    int val;
    printf("\nEnter the value:");
    scanf("%d", &val);
    newnode=create_node(val);
    if(first==last&&last==NULL)
    {
        first=newnode;
        last=newnode;
        first->next=NULL;
        last->next=NULL;
    }
    else
    {
        last->next=newnode;
        last=newnode;
        last->next=NULL;
    }
}
void insert_node_pos()
{
    int pos, val, count = 0, i;
    printf("\nEnter the value for the Node:");
    scanf("%d", &val);
    newnode=create_node(val);
    printf("\nEnter the position ");
    scanf("%d", &pos);
    ptr=first;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    if(pos==1)
    {
        if(first==last&&first==NULL)
        {
            first=newnode;
            last=newnode;
            first->next=NULL;
            last->next=NULL;
        }
        else
        {
            temp=first;
            first=newnode;
            first->next=temp;
        }
        printf("\nInserted");
    }
    else if (pos>1&&pos<=count)
    {
        ptr=first;
        for(i=1;i<pos;i++)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=newnode;
        newnode->next=ptr;
        printf("\n----INSERTED----");
    }
    else
    {
        printf("Position is out of range");
    }
}
void delete_pos()
{
    int pos,count=0,i;

    if (first==NULL)
    {
        printf("Empty\n");
        printf(":No node to delete\n");
    }
    else
    {
        printf("\nEnter the position of value to be deleted:");
        scanf("%d",&pos);
        ptr=first;
        if(pos==1)
        {
            first=ptr->next;
            printf("\nElement deleted");
        }
        else
        {
            while(ptr!=NULL)
            {
                ptr=ptr->next;
                count++;
            }
            if(pos>0&&pos<=count)
            {
                ptr=first;
                for(i=1;i<pos;i++)
                {
                    prev=ptr;
                    ptr=ptr->next;
                }
                prev->next=ptr->next;
            }
            else
            {
                printf("Position is out of range");
            }
        free(ptr);
        printf("\nElement deleted");
        }
    }
}
void display()
{
    if (first==NULL)
    {
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to display\n");
    }
    else
    {
        for(ptr=first;ptr!=NULL;ptr=ptr->next)
        {
            printf("%d\t",ptr->value);
        }
    }
}
