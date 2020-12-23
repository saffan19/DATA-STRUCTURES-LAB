#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int cf;
    int px;
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

/*
NODE insert_rear(NODE first,int cf,int px)
{
    NODE temp,cur;
    temp=getnode();
    temp->cf=cf;
    temp->px=px;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    cur=first;
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link=temp;
    return first;
}
*/
NODE order_list(int cf,int px,NODE first)
{
NODE temp,prev,cur;
temp=getnode();
temp->cf=cf;
temp->px=px;
temp->link=NULL;
if(first==NULL) return temp;
if(px>first->px)
{
temp->link=first;
return temp;
}
prev=NULL;
cur=first;
while(cur!=NULL&&px<cur->px)
{
prev=cur;
cur=cur->link;
}
prev->link=temp;
temp->link=cur;
return first;
}
NODE add(NODE first1,NODE first2)
{
    if(first1==NULL)return first2;
    if(first2==NULL)return first1;
    NODE t1=first1,t2=first2;
    NODE firstr=NULL;
    
    while(t1!=NULL&&t2!=NULL)
    {
       
        if(t1->px==t2->px)
        {
            firstr=order_list(t1->cf+t2->cf,t1->px,firstr);
            t1=t1->link;
            t2=t2->link;
            continue;
        }
        if(t1->px>t2->px)
        {
            firstr=order_list(t1->cf,t1->px,firstr);
            t1=t1->link;
            continue;
        }
        if(t2->px>t1->px)
        {
            firstr=order_list(t2->cf,t2->px,firstr);
            t2=t2->link;
            continue;
        }


    }
    return firstr;

}
void display(NODE first)
{
    NODE temp,temp2;
    if(first==NULL)
        printf("Equation is EMPTY!\n");
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("%d*x^%d",temp->cf,temp->px);
        temp2=temp->link;
        if(temp2!=NULL)printf("+");
    }
    printf("\n");
}

void main()
{
    int cf,px,choice;
    NODE first1=NULL,first2=NULL,firstr=NULL;

    printf("Enter the polynomial equation1:\n");
    for(;;)
    {
        printf("Enter coefficient and power of x :\n");
        scanf("%d",&cf);
        scanf("%d",&px);

        first1 = order_list(cf,px,first1);
        printf("Press 1 to enter another term\nPress 2 to exit\n");
        scanf("%d",&choice);
        if(choice==2)break;
    }
    printf("Enter the polynomial equation2:\n");
    for(;;)
    {
        printf("Enter coefficient and power of x :\n");
        scanf("%d",&cf);
        scanf("%d",&px);

        first2 = order_list(cf,px,first2);
        printf("Press 1 to enter another term\nPress 2 to exit\n");
        scanf("%d",&choice);
        if(choice==2)break;
    }
    printf("Polynomial equationn1 is:\n");
    display(first1);
    printf("Polynomial equationn2 is:\n");
    display(first2);
    firstr=add(first1,first2);
    printf("ADDED POLYNOMIAL:\n");
    display(firstr);

}