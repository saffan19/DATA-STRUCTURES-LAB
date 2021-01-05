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
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("MEMORY FULL\n");
        exit(0);
    }
    return x;
}

NODE insert(NODE root, int item)
{
    NODE temp = getnode();
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
    {
        return temp;
    }
    NODE cur = root;
    while (cur != NULL)
    {
        if (item > cur->info)
        {
            if (cur->rlink != NULL)
                cur = cur->rlink;
            else
            {
                cur->rlink = temp;
                break;
            }
        }
        else if (item < cur->info)
        {
            if (cur->llink != NULL)
                cur = cur->llink;
            else
            {
                cur->llink = temp;
                break;
            }
        }
        else
        {
            printf("Item exists!\n");
            break;
        }
    }
    return root;
}
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%d\n", root->info);
        inorder(root->rlink);
    }
}
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d\n", root->info);
        preorder(root->llink);
        
        preorder(root->rlink);
    }
}
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->llink);
        
        postorder(root->rlink);
        printf("%d\n", root->info);
    }
}
void display(NODE root, int i)
{
    int j;
    if (root != NULL)
    {
        display(root->rlink, i + 1);
        for (j = 0; j < i; j++)
            printf("     ");
        printf("%d <\n", root->info);
        display(root->llink, i + 1);
    }
}
void main()
{
    int choice, c = 1, item;
    NODE root = NULL;
    while (c == 1)
    {
        printf("Enter choice:\n1)Insert\n2)Display\n3)Inorder\n4)Preorder\n5)Postorder\n6)Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item:\n");
            scanf("%d", &item);
            root = insert(root, item);
            break;
        case 2:
            display(root, 1);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:c=0;break;
        default:
            printf("Invalid choice!\n");
        }
    }
}