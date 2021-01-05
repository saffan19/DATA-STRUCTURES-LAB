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
        printf("MEMORY FULL!\n");
        exit(0);
    }
    return x;
}
NODE insert_rear(NODE first,int item)
{
    NODE temp=getnode();
    temp->info=item;
    temp->link=NULL;
    NODE cur=first;
    if(first==NULL)return temp;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;

}
NODE delete_first(NODE first)
{
    if(first==NULL)
    {
        printf("EMPTY!\n");
        return first;
    }
    NODE cur=first;
    printf("Item deleted: %d\n",first->info);
    cur=cur->link;
    free(first);
    return cur;
}
NODE delete_last(NODE first)
{
    if(first==NULL)
    {
        printf("EMPTY!\n");
        return first;
    }
    NODE cur=first;
    NODE prev=NULL;
    int c=0;
    while(cur->link!=NULL)
    {

        cur=cur->link;
        c++;
        if(c==1)prev=first;
        else
        {
            prev=prev->link;
        }
        
    }
    printf("Popped: %d\n",cur->info);
    free(cur);
    prev->link=NULL;
    return first;
    
}
void display(NODE first)
{
    NODE cur=first;
    while(cur!=NULL)
    {
        printf("%d\n",cur->info);
        cur=cur->link;
    }
}
void main()
{
    int c=1,choice,item;
    NODE qf=NULL,sf=NULL;
    while(c==1)
    {
        printf("Enter choice:\n");
        printf("1)PUSH into stack\n2)POP out of stack\n3)Display stack\n4)Insert into queue\n5)Delete from queue\n6)Display Queue\n7)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter item:\n");
                scanf("%d",&item);
                sf=insert_rear(sf,item);
                break;
            case 2:
                sf=delete_last(sf);
                break;
            case 3:
                printf("The STACK is :\n-----------\n");
                display(sf);
                break;
            case 4:
                printf("Enter item:\n");
                scanf("%d",&item);
                qf=insert_rear(qf,item);
                break;
            case 5:
                qf=delete_first(qf);
                break;
            case 6:
                printf("The QUEUE is :\n-----------\n");
                display(qf);
                break;
            case 7:
                c=0;
                break;
            default:
                printf("Invalid choice!\n");

        }
    }
}