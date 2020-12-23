#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int cf;
    int px;
    int py;
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


NODE insert_rear(NODE first,int cf,int px,int py)
{
    NODE temp,cur;
    temp=getnode();
    temp->cf=cf;
    temp->px=px;
    temp->py=py;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    cur=first;
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link=temp;
    return first;
}

void display(NODE first)
{
    NODE temp,temp2;
    if(first==NULL)
        printf("Equation is EMPTY!\n");
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        printf("%d*x^%d*y^%d",temp->cf,temp->px,temp->py);
        temp2=temp->link;
        if(temp2!=NULL)printf("+");
    }
    printf("\n");
}



int calculate(NODE first,int x,int y)
{
    NODE temp;
    if(first==NULL)return 0;
    int ans=0;
    for(temp=first;temp!=NULL;temp=temp->link)
    {
        ans=ans+(temp->cf)*pow(x,temp->px)*pow(y,temp->py);
    }    
    return ans;

}

void main()
{
    int cf,px,py,choice;
    NODE first=NULL;

    printf("Enter the polynomial equation:\n");
    for(;;)
    {
        printf("Enter coefficient,power of x and power of y:\n");
        scanf("%d",&cf);
        scanf("%d",&px);
        scanf("%d",&py);

        first=insert_rear(first,cf,px,py);
        printf("Press 1 to enter another term\nPress 2 to exit\n");
        scanf("%d",&choice);
        if(choice==2)break;
    }
    printf("Polynomial equationn is:\n");
    display(first);
    printf("Enter the values of x and y:\n");
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);

    printf("Value of the equation is :%d",calculate(first,x,y));


}