#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 3
int item, front = 0, rear = -1, q[10];
void insertrear()
{
    if (rear == SIZE - 1)
    {
        printf("Queue OVERFLOW!!\n");
        return;
    }
    rear = rear + 1;
    q[rear] = item;
}
int deletefront()
{
    if (front > rear)
    {
        front = 0;
        rear = -1;
        return -1;
    }
    return q[front++];
}
void display()
{
    int i;
    if (front > rear)
    {
        printf("Queue is EMPTY!!\n");
        return;
    }
    printf("Contents of Queue:\n----------\n");
    for (i = front; i <= rear; i++)
    {
        printf("%d\n", q[i]);
    }
}
void main()
{
    int choice;
    while (1)
    {
        printf("\n1 : INSERT \n2 : DELETE\n3 : DISPLAY\n4 : EXIT\n");
        printf("Enter choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted:\n");
            scanf("%d", &item);
            insertrear();
            break;
        case 2:
            item = deletefront();
            if (item == -1)
            {
                printf("Queue is empty\n");
            }
            else
                printf("Item deleted : %d\n", item);
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}