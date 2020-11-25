#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("MEMORY FULL!!!!\n");
        exit(0);
    }
    return x;
}

NODE order_list(int item,NODE first)
{
NODE temp,prev,cur;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL) return temp;
if(item<first->info)
{
temp->link=first;
return temp;
}
prev=NULL;
cur=first;
while(cur!=NULL&&item>cur->info)
{
prev=cur;
cur=cur->link;
}
prev->link=temp;
temp->link=cur;
return first;
}


void display(NODE first)
{
    NODE temp;
    if (first == NULL)
        printf("List is EMPTY!!!\n");
    for (temp = first; temp != NULL; temp = temp->link)
    {
        printf("%d\n", temp->info);
    }
}

void main()
{
    int item, choice, pos, i, n;
    NODE first = NULL;
    for (;;)
    {
        printf("1: Insert_front\n2: Dislay sorted list\n3: Exit\n");
        printf("Enter choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item\n");
            scanf("%d", &item);
            first = order_list(item,first);
            break;
        case 2:
            display(first);
            break;
        case 3:
            exit(0);
        default:
            printf("INVALID INPUT!!!\n");
        }
    }
}