#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("MEMORY FULL!");
        exit(0);
    }
    return x;
}
NODE insert_front(NODE first,int item)
{
    NODE temp=getnode();
    temp->info=item;
    temp->rlink=NULL;
    temp->llink=NULL;
    if(first==NULL)return temp;
    temp->rlink=first;
    return temp;
}
NODE insert_rear(NODE first,int item)
{
    NODE temp=getnode();
    temp->info=item;
    temp->rlink=NULL;
    temp->llink=NULL;
    NODE cur=first;
    if(first==NULL)return temp;
    while(cur!=NULL)
    {
        if(cur->rlink==NULL)
        {
            cur->rlink=temp;
            temp->llink=cur;
            break;
        }
        cur=cur->rlink;
    }
    return first;
}
NODE insert_leftof(NODE first,int item,int key)
{
    NODE temp=getnode();
    temp->info=item;
    temp->rlink=NULL;
    temp->llink=NULL;
    if(first==NULL)
    {
        printf("Key doesnt exit!\n");
        return first;
    }   
    if(first->info==key)
    {
        temp->rlink=first;
        first->llink=temp;
        return temp;
    }
    NODE cur=first->rlink;
    NODE prev=first;
    while(cur!=NULL)
    {
        if(cur->info==key)
        {
            prev->rlink=temp;
            temp->llink=prev;
            temp->rlink=cur;
            cur->llink=temp;
            return first;
        }
        cur=cur->rlink;
        prev=prev->rlink;
    }
    printf("Key doesnt exit!\n");
    return first;
}
void display(NODE first)
{
    NODE cur=first;
    while(cur!=NULL)
    {
        printf("%d\n",cur->info);
        cur=cur->rlink;
    }
}

NODE delete_key(NODE first,int key)
{
    int count=0;
    NODE cur=first;
    NODE prev=NULL,next=NULL;
    if(first==NULL)
    {
        printf("Empty!\n");
        return first;
    }
    while(first->info==key)
    if(first->info==key)
    {
        cur=first;
        first=first->rlink;
        count++;
        free(cur);
    }
    
    cur=first;
    while(cur!=NULL)
    {
        if(cur->info==key)
        {
            count++;
            prev=cur->llink;
            next=cur->rlink;
            prev->rlink=next;
            next->llink=prev;
            free(cur);
            cur=next;
        }
        else
        {
            cur=cur->rlink;
        }
        
    }

    printf("%d deleted from %d places\n",key,count);    
    return first;

}
void main()
{
    int choice,c=1,item,key;
    NODE first=NULL;
    while(c==1)
    {
        printf("Enter choice:\n1)Insert rear\n2)Insert front\n3)Insert left of key\n4)Display\n5)Delete all key\n6)Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter item:\n");
                scanf("%d",&item);
                first=insert_rear(first,item);
                break;
            case 2:
                printf("Enter item:\n");
                scanf("%d",&item);
                first=insert_front(first,item);
                break;
            case 3:
                printf("Enter key :\n");
                scanf("%d",&key);
                printf("Enter item to be inserted left of key:\n");
                scanf("%d",&item);
                first=insert_leftof(first,item,key);
                break;
            case 4:
                display(first);
                break;
            case 5:
                printf("Enter key value to be deleted:\n");
                scanf("%d",&key);
                first=delete_key(first,key);
                break;
            case 6:c=0;break;
            default:printf("Invalid choice!\n");
        }
    }
}