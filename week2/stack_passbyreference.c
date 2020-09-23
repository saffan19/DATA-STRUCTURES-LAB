/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define size 5
void push(int *item,int s[],int *top)
{
    if(*top==size-1)
    {
        printf("\nStack overflow\n");
        return;
    }
    (*top)++;
    s[*top]=*item;
    
}

void pop(int s[],int *top)
{
    
    if(*top==-1)
    {
        printf("Stack underflow \n");
        return;
    }

    *top=*top-1;

}
void display(int *top,int s[])
{
    if(*top==-1)
    {
        printf("Empty Stack\n");
        return;
        
    }
    printf("STACK: \n");
    for(int i=*top;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
}


int main()
{
    int top = -1;
    int item,s[10],choice,check=1;
    while(check==1)
    {
        
        printf("Enter choice :\n\n1:push\n2:pop\n3:display\n4:exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the item to be inserted\n");
            scanf("%d",&item);
            push(&item,s,&top);
            break;
            case 2:pop(s,&top);
            break;
            case 3 : display(&top,s);
            break;
            case 4:check=0;
                break;
            
            default : printf("Invalid choice\n");
        }
		
    }
    return 0;
}
    

