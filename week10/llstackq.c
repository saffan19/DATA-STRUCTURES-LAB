#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory is full!!\n");
        exit(0);
    }
    return x;
}
void freenode(NODE x)
{
    free(x);
}
NODE insert_front(NODE first,int item)
{
    NODE temp;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    temp->link=first;
    first=temp;
    return first;
}
NODE insert_rear(NODE first,int item)
{
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    cur=first;
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link=temp;
    return first;
}
NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Stack is empty cannot pop!\n");
        return first;
    }
    temp=first;
    temp=temp->link;
    printf("The popped item from the stack is : %d\n",first->info);
    free(first);
    return temp;
}
NODE delete_frontq(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Queue is empty cannot delete!\n");
        return first;
    }
    temp=first;
    temp=temp->link;
    printf("The deleted item from the queue is : %d\n",first->info);
    free(first);
    return temp;
}

void display(NODE first)
{
    NODE temp;
    if(first==NULL)
        printf("Stack is EMPTY!\n");
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("%d\n",temp->info);    
    }
}
void displayq(NODE first)
{
    NODE temp;
    if(first==NULL)
        printf("Queue is EMPTY!\n");
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("%d\n",temp->info);    
    }
}
void main()
{
    int items,itemq,choice;
    NODE firsts=NULL;
    NODE firstq=NULL;

    for(;;)
    {
        printf("\n--------------------------\n1:PUSH into stack\n2:POP from stack\n3:Display stack\n4:Insert in queue\n5:Delete from queue\n6:Display Queue\n7:Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the item to push into stack\n");
                    scanf("%d",&items);
                    firsts=insert_front(firsts,items);
                    break;
            case 2:firsts=delete_front(firsts);
                    break;
            case 3:
                    printf("The stack is:\n");
                    display(firsts);
                    break;
            case 4:
                    printf("Enter the item to be inserted in queue:");
                    scanf("%d",&itemq);
                    firstq=insert_rear(firstq,itemq);
                    break;
            case 5:firstq=delete_frontq(firstq);
                    break;

            case 6:
                    printf("The Queue is:\n");
                    displayq(firstq);
                    break;
            case 7: exit(0);break;
            default:printf("INVALID CHOICE!\n");
                    break;
        }
    }
}