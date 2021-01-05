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
NODE insert_front(NODE first,int item)
{
    NODE temp=getnode();
    temp->info=item;
    if(first==NULL)return temp;
    temp->link=first;
    return temp;
}
NODE insert_pos(NODE first,int item,int pos)
{
    NODE temp=getnode();
    temp->info=item;
    temp->link=NULL;
    NODE cur=first;
    NODE prev=NULL;
    if(pos==1)
    {
        temp->link=first;
        return temp;  
    }
    int count=0;
    while(count<=pos)
    {
        count=count+1;
        if(count==pos)
        {
            temp->link=cur;
            prev->link=temp;
            return first;
        }
        cur=cur->link;
        if(count==1)prev=first;
        if(count>1)prev=prev->link;
    }
    printf("INVALID POSITION!\n");
    free(temp);
    return first;
}
NODE delete_first(NODE first)
{
    if(first==NULL)
    {
        printf("LIST EMPTY!\n");
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
        printf("LIST EMPTY!\n");
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
    printf("Item deleted: %d\n",cur->info);
    free(cur);
    prev->link=NULL;
    return first;
    
}
NODE delete_pos(NODE first,int pos)
{
    NODE cur=first;
    NODE prev=first;
    int count=1;
    if(pos==1)
    {
        cur=cur->link;
        printf("Deleted item: %d\n",first->info);
        free(first);
        return cur;
    }
    cur=cur->link;
    while(cur!=NULL)
    {
        count++;
        if(pos==count)
        {
            prev->link=cur->link;
            printf("Deleted item: %d\n",cur->info);
            free(cur);
            return first;
        }
        cur=cur->link;
        prev=prev->link;
    }
    printf("Position not found!\n");
    return first;

}
void display(NODE first)
{
    NODE cur=first;
    printf("The list is:\n-----------\n");
    while(cur!=NULL)
    {
        printf("%d\n",cur->info);
        cur=cur->link;
    }
}

void main()
{
    int choice,c=1,item,pos;
    NODE first=NULL;
    while(c==1)
    {
        printf("Enter choice:\n1)Insert rear\n2)Insert front\n3)Insert at any position\n4)Display\n5)Delete first\n6)Delete last\n7)Delete pos\n8)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter item :\n");
                scanf("%d",&item);
                first=insert_rear(first,item);
                break;
            case 2:
                printf("Enter item:\n");
                scanf("%d",&item);
                first=insert_front(first,item);
                break;
            case 3:
                printf("Enter position\n");
                scanf("%d",&pos);
                printf("Enter item:\n");
                scanf("%d",&item);
                first=insert_pos(first,item,pos);
                break;
            case 4:
                display(first);
                break;
            case 5:
                first=delete_first(first);
                break;
            case 6:
                first=delete_last(first);
                break;
            case 7:
                printf("Enter position:\n");
                scanf("%d",&pos);
                first=delete_pos(first,pos);
                break;
            case 8:
                c=0;
                break;
            default:printf("Invalid choice!\n");
        }
    }
}