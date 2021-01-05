
#include<stdio.h>
int size,s[100],item,front=0,top=-1;

void push()
{
    if(top==size-1)
    {
        printf("STACK OVERFLOW!\n");return;
    }
    top++;
    s[top]=item;
}
int pop()
{
    if(top<front)
    {
        printf("STACK UNDERFLOW!\n");return -1;
    }
    top--;
    return s[top+1];
}
void display()
{
    printf("------------\n");
    for(int i=front;i<=top;i++)
    {
        printf("%d\n",s[i]);
    }
}
void main()
{
    printf("Enter size:\n");
    scanf("%d",&size);
    int c=1,ch,pop_item;
    while(c==1)
    {
        printf("1)Push\n2)Pop\n3)Display\n4)Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter item:\n");
                scanf("%d",&item);push();break;
            case 2:
                pop_item=pop();
                if(pop_item!=-1)
                printf("Popped:%d\n",pop_item);
                break;
            case 3:display();break;
            case 4:c=0;break;
            default:printf("Invalid choice!\n");
        }
        
    }
}