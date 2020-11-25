#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("MEMORY FULL!!!!\n");
        exit(0);
    }
    return x;
}
NODE insert_rear(NODE first, int item)
{
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = temp;
    return first;
}
void display(NODE first)
{
    NODE temp;
    if (first == NULL)
        printf("List is EMPTY!!!\n");
    for (temp = first; temp != NULL; temp = temp->link)
    {
        printf("%d\n", temp->info);
    }
}

NODE concat(NODE first, NODE second)
{
    NODE cur;
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    cur = first;
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = second;
    return first;
}
void main()
{
    int item, choice, pos, i, n;
    NODE firsta = NULL, firstb=NULL;
    for (;;)
    {
        printf("\n1:INSERT_FRONT LIST1\n2:INSERT_FRONT LIST2\n3:DISPLAY LIST1\n4:DISPLAY LIST2\n5:CONCATENATE AND DISPLAY\n6:EXIT\n");
        printf("Enter choice:\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter the item\n");
            scanf("%d", &item);
            firsta = insert_rear(firsta, item);
            break;
            case 2:
            printf("Enter the item\n");
            scanf("%d", &item);
            firstb = insert_rear(firstb, item);
            break;
            case 3:
            display(firsta);
            break;
            case 4:
            display(firstb);
            break;
            case 5:
            firsta=concat(firsta,firstb);
            display(firsta);
            break;
            case 6:
            exit(0);
            default:printf("INVALID INPUT!!\n");


        }
    }
}