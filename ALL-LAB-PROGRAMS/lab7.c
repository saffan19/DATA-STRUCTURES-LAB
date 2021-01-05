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
        printf("MEMORY FULL!\n");
        exit(0);
    }
    return x;
}

NODE insert_rear(NODE first, int item)
{
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
        return temp;
    NODE cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}
NODE sort(NODE first)
{
    int n = 0, i, j;
    NODE cur = first;
    if (first == NULL)
    {
        printf("Empty list!\n");
        return first;
    }
    while (cur != NULL)
    {
        cur = cur->link;
        n++;
    }
    NODE next = NULL;
    int t;
    for (i = 0; i < n - 1; i++)
    {
        cur = first;
        next = cur->link;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (cur->info > next->info)
            {
                t = cur->info;
                cur->info = next->info;
                next->info = t;
            }
            next = next->link;
            cur = cur->link;
        }
    }
    return first;
}
NODE reverse(NODE first)
{
    NODE cur = first;
    NODE next = NULL, prev = NULL;
    while (cur != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
NODE concat(NODE first1, NODE first2)
{
    NODE cur = first1;
    if (first1 == NULL)
    {
        return first2;
    }
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = first2;
    return first1;
}
void display(NODE first)
{
    NODE cur = first;
    while (cur != NULL)
    {
        printf("%d\n", cur->info);
        cur = cur->link;
    }
}
void main()
{
    int choice, c = 1, item;
    NODE first1 = NULL, first2 = NULL;
    while (c == 1)
    {
        printf("Enter your choice:\n");
        printf("1)Insert in list1\n2)Insert in list2\n3)Sort list1\n4)Sort list2\n5)Reverse list1\n6)Reverse list2\n7)Concatenate\n8)Display list1\n9)Display list2\n10)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item:\n");
            scanf("%d", &item);
            first1 = insert_rear(first1, item);
            break;
        case 2:
            printf("Enter item:\n");
            scanf("%d", &item);
            first2 = insert_rear(first2, item);
            break;
        case 3:
            first1 = sort(first1);
            printf("After sorting:\n");
            display(first1);
            break;
        case 4:
            first2 = sort(first2);
            printf("After sorting:\n");
            display(first2);
            break;
        case 5:
            first1 = reverse(first1);
            printf("After reversing:\n");
            display(first1);
            break;
        case 6:
            first2 = reverse(first2);
            printf("After reversing:\n");
            display(first2);
            break;
        case 7:
            first1 = concat(first1, first2);
            printf("After concatenating:\n");
            display(first1);
            break;
        case 8:
            printf("LIST1:\n-------\n");
            display(first1);
            break;
        case 9:
            printf("LIST2:\n-------\n");
            display(first2);
            break;
        case 10:
            c = 0;
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
}