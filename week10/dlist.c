#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Memory Full!!\n");
        exit(0);
    }
    return x;
}
void freenode(NODE x)
{
    free(x);
}
NODE insert_rear(NODE head, int item)
{
    NODE temp, cur;
    temp = getnode();
    temp->rlink = NULL;
    temp->llink = NULL;
    temp->info = item;
    cur = head->llink;
    temp->llink = cur;
    cur->rlink = temp;
    head->llink = temp;
    temp->rlink = head;
    head->info = head->info + 1;
    return head;
}
NODE insert_leftpos(int item, NODE head)
{
    NODE temp, cur, prev;
    if (head->rlink == head)
    {
        printf("List is Empty!\n");
        return head;
    }
    cur = head->rlink;
    while (cur != head)
    {
        if (item == cur->info)
            break;
        cur = cur->rlink;
    }
    if (cur == head)
    {
        printf("Key not found\n");
        return head;
    }
    prev = cur->llink;
    printf("Enter item to be inserted towards left of %d=", item);
    temp = getnode();
    scanf("%d", &temp->info);
    prev->rlink = temp;
    temp->llink = prev;
    cur->llink = temp;
    temp->rlink = cur;
    return head;
}

NODE delete_all_key(int item, NODE head)
{
    NODE prev, cur, next;
    int count;
    if (head->rlink == head)
    {
        printf("List is Empty!");
        return head;
    }
    count = 0;
    cur = head->rlink;
    while (cur != head)
    {
        if (item != cur->info)
            cur = cur->rlink;
        else
        {
            count++;
            prev = cur->llink;
            next = cur->rlink;
            prev->rlink = next;
            next->llink = prev;
            freenode(cur);
            cur = next;
        }
    }
    if (count == 0)
        printf("Key not found");
    else
        printf("Keys found at % d positions and are deleted\n", count);

    return head;
}


void search_key(int item, NODE head)
{
    NODE prev, cur, next;
    
    if (head->rlink == head)
    {
        printf("List is Empty!\n");
        return;
    }
    
    cur = head->rlink;
    while (cur != head)
    {
        if (item != cur->info)
            cur = cur->rlink;
        else
        {
            printf("Item found!\n");return;
        }

    }
    printf("Item not found!\n");


}



NODE delete_dup(int item, NODE head)
{
    NODE prev, cur, next;
    int count;
    if (head->rlink == head)
    {
        printf("List is Empty!");
        return head;
    }
    count = 0;
    cur = head->rlink;
    while (cur != head)
    {
        if (item != cur->info)
            cur = cur->rlink;
        else
        {
            count++;
            if(count==1)
            {
                cur = cur->rlink;
            }
            if(count!=1)
            {
                prev = cur->llink;
                next = cur->rlink;
                prev->rlink = next;
                next->llink = prev;
                freenode(cur);
                cur = next;
            }
            
        }
    }
    if (count == 0)
        printf("Key not found");
    else
        printf("Duplicates are deleted are deleted\n");

    return head;
}

void display(NODE head)
{
    NODE temp;
    if (head->rlink == head)
    {
        printf("List is Empty\n");
        return;
    }
    for (temp = head->rlink; temp != head; temp = temp->rlink)
        printf("%d\n", temp->info);
}
void main()
{
    int item, choice, key;
    NODE head;
    head = getnode();
    head->rlink = head;
    head->llink = head;

    for (;;)
    {
        printf("\n1.Insert_rear\n2.Insert_left_of\n3.Delete_all_key\n4.Delete duplicates\n5.Search key\n6.Display\n6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item\n");
            scanf("%d", &item);
            head = insert_rear(head, item);
            break;
        case 2:
            printf("Enter the key item\n");
            scanf("%d", &item);
            head = insert_leftpos(item, head);
            break;
        case 3:
            printf("Enter the key item to be deleted:\n");
            scanf("%d", &item);
            head = delete_all_key(item, head);
            break;
        case 4:
            printf("Enter the key item whose duplicates are to be deleted:\n");
            scanf("%d", &item);
            head = delete_dup(item, head);
            break;
        case 5:
            printf("Enter the key item to be searched:\n");
            scanf("%d", &item);
            search_key(item, head);
            break;
        case 6:
            printf("The list is:\n");
            display(head);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Inavlid choice!\n");
        }
    }
}
