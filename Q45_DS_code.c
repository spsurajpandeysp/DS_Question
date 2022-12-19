/* Q45. Program to search a key and delete particular node from a binary search tree & count no. of node, leaf node & height of tree.*/
#include<stdio.h>
#include<stdlib.h>
 struct node
 {
    int data;
    struct node *left,*right;
 };
 
 int countNode(struct node *root)
 {
    static int j=0;
    if(root==NULL)
    {
        return j;
    }
    countNode(root->left);
    j++;
    countNode(root->right);
 }
 int countLeafNode(struct node *root)
 {
    static int i=0;
    if(root==NULL)
    {
        return i;
    }
    countLeafNode(root->left);
    if(root->left==NULL && root->right==NULL)
    {
        i++;
    }
    countLeafNode(root->right);
 }

 int countHeight(struct node *root)
 {
    if(root==NULL)
    {
        return 0;
    }
    
    if(countHeight(root->right)<=countHeight(root->left))
    {
        return countHeight(root->left)+1;
    }
    else if(countHeight(root->right)>=countHeight(root->left))
    {
        return countHeight(root->right)+1;
    }
 }
 struct node *createNewNode(int element)
 {
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Memory not allocated:\n");
        exit(0);
    }
    newNode->data=element;
    newNode->left=newNode->right=NULL;
    return newNode;
 }
struct node *insertion(struct node *root,int element)
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
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}
struct node *searchAndDelete(struct node *root,int element)
{
    if(root==NULL)
    {
        return NULL;
    }
}
 int main()
 {
    struct node *root=NULL;
    int choice,element,c;
    while(1)
    {
        printf("Press 1. for insertion:\n");
        printf("Press 2. for display:\n");
        printf("Press 3. for count height of tree:\n");
        printf("Press 4. for no of node:\n");
        printf("Press 5. for cout<leaf node:\n");
        printf("Press 6. search element and delete:\n");
        printf("Press 7. for exit this program:\n");
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
                    return 0;
                }
                else
                {
                    inorder(root);
                }
                break;
            case 3:
                if(root==NULL)
                {
                    printf("Tree is not exist:\n");
                    return 0;
                }
                else
                {
                    c=countHeight(root);
                    printf("Height of tree is: %d\n",c);
                }
                break;
            case 4:
                if(root==NULL)
                {
                    printf("Tree is not exist:\n");
                    return 0;
                }
                else
                {
                    c = countNode(root);
                    printf("Number of node is: %d\n",c);
                    
                }
                break;
            case 5:
                if(root==NULL)
                {
                    printf("Tree is not exist:\n");
                    return 0;
                }
                else
                {
                    c = countLeafNode(root);
                    printf("Number of leaf node are: %d\n",c);
                }
                break;
            case 6:
                if(root==NULL)
                {
                    printf("Tree is not exist:\n");
                    return 0;
                }
                else
                {
                    printf("Enter element you want to search and delete:\n");
                    scanf("%d",&element);
                    root = searchAndDelete(root,element);
                }
                break;
            case 7:
                printf("You successfully returned from this program:\n");
                return 0;
            default:
                printf("Enter valid choice:\n");
                break;
        }
    }
    return 0;
 }