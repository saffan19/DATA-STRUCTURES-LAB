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

NODE reverse(NODE first)
{
    NODE cur, temp;
    cur = NULL;
    while (first != NULL)
    {
        temp = first;
        first = first->link;
        temp->link = cur;
        cur = temp;
    }
    return cur;
}
void main()
{
    int item, choice, pos, i, n;
    NODE first = NULL, a, b;
    for (;;)
    {
        printf("1: Insert_front\n2: Reverse\n3: Dislay\n4: Exit\n");
        printf("Enter choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item\n");
            scanf("%d", &item);
            first = insert_rear(first, item);
            break;

        case 2:
            first = reverse(first);
            printf("REVERSED!!\n");
            break;
        case 3:
            display(first);
            break;
        default:
            exit(0);
        }
    }
}