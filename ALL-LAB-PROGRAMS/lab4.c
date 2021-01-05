#include <stdio.h>
#define size 3
int item, f = 0, r = -1, q[size], count = 0;
void insertrear()
{
    if (count == size)
    {
        printf("OVERFLOW!!\n");
        return;
    }
    r = (r + 1) % size;
    q[r] = item;
    count++;
}
int deletefront()
{
    if (count == 0)
        return -1;
    item = q[f];
    f = (f + 1) % size;
    count = count - 1;
    return item;
}
void display()
{
    int i;
    if (count == 0)
    {
        printf("QUEUE IS EMPTY!\n");
        return;
    }
    int front = f;
    printf("Contents:\n");
    for (int i = 1; i <= count; i++)
    {
        printf("%d \n", q[front]);
        front = (front + 1) % size;
    }
}
void main()
{
    int choice, check = 1;
    while (check == 1)
    {
        printf("--------------\n1)INSERT\n2)DELETE\n3)DISPLAY\n4)EXIT\nEnter choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item:\n");
            scanf("%d", &item);
            insertrear();
            break;
        case 2:
            item = deletefront();
            if (item == -1)
                printf("QUEUE IS EMPTY!\n");
            else
                printf("Deleted item:%d\n", item);
            break;
        case 3:
            display();
            break;
        default:
            check = 0;
        }
    }
}