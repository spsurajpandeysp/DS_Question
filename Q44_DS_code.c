/* Q44. Write a program to implement a binary search tree with following operation: insertion, deletion and display. *30   */
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};
struct node *createNewNode(int element)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memoery not allocated:\n");
        exit(0);
    }
    newNode->right=newNode->left=NULL;
    newNode->data=element;
    return newNode;
}

struct node *inOrderSuccessor(struct node *root)
{
    struct node *temp;
    temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
struct node *insertion(struct node *root ,int element)
{
    if(root==NULL)
    {
        return createNewNode(element);
    }
    else if(root->data>element)
    {
        root->left=insertion(root->left,element);
    }
    else if(root->data<element)
    {
        root->right=insertion(root->right,element);
    }
    return root;
}
struct node *deletion(struct node *root,int element)
{
    if(root==NULL)
    {
        printf("Element not found in BST:\n");
        return root;
    }
    else if(root->data<element)
    {
        root->right=deletion(root->right,element);
    }
    else if(root->data>element)
    {
        root->left=deletion(root->left,element);
    }
    else if(root->data==element)
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL && root->right!=NULL)
        {
            struct node *temp;
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            struct node *temp;
            temp=root->left;
            return temp;
        }
        else if(root->left!=NULL && root->right!=NULL)
        {
            struct node *temp;
            temp=inOrderSuccessor(root->right);
            root->data=temp->data;
            root->right = deletion(root->right,temp->data);
        }
    }
}
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->data);
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
    printf("%d\n",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    struct node *root=NULL;
    int choice,element;
    while(1)
    {
        printf("Press 1. for insertion in binary search tree:\n");
        printf("Press 2. for deletion in binary search tree\n");
        printf("PRess 3. for preorder display:\n");
        printf("Press 4. for inorder display:\n");
        printf("Press 5. for postorder display:\n");
        printf("Press 6. for exit this program:\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element you want to add:\n");
                scanf("%d",&element);
                root=insertion(root,element);
                break;
            case 2:
                if(root==NULL)
                {
                    printf("Tree is not exist:\n");
                }
                else
                {
                    printf("Enter element you want to delete:\n");
                    scanf("%d",&element);
                    root=deletion(root,element);
                }
                break;
            case 3:
                if(root==NULL)
                {
                    printf("Tree not exist:\n");
                }
                else
                {
                    printf("Preorder Traversal:\n");
                    preorder(root);
                }
                break;
            case 4:
                if(root==NULL)
                {
                    printf("Tree is not exist:\n");
                }
                else
                {
                    printf("InorderTraversal:\n");
                    inorder(root);
                }
                break;
            case 5:
                if(root==NULL)
                {
                    printf("Tree is not exist:\n");
                }
                else
                {
                    printf("Postoder Traversal:\n");
                    postorder(root);
                }
                break;
            case 6:
                printf("You successfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valid chouce:\n");
                break;

        }

    }
    return 0;
}