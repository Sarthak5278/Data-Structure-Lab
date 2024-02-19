#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* right_child;
    struct node* left_child;
};
struct node* new_node(int x){
    struct node* temp;
    temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->right_child=NULL;
    temp->left_child=NULL;
    return temp;
};
struct node* insert(struct node *root, int x)
{
    if(root==NULL)
    {
        return new_node(x);
    }
    else if(x>root->data)
    {
        root->right_child=insert(root->right_child,x);
    }
    else{
        root->left_child=insert(root->left_child,x);

    }return root;
};
void preorder(struct node *root)
{
    if(root!=NULL)
    {
    printf("%d\n",root->data);
    preorder(root->left_child);
    preorder(root->right_child);
    }
}
void inorder(struct node *root)
{
     if(root!=NULL)
     {
    inorder(root->left_child);
    printf("%d\n",root->data);
   inorder(root->right_child);
     }

}
void postorder(struct node *root)
{
     if(root!=NULL)
     {
    postorder(root->left_child);
    postorder(root->right_child);
    printf("%d\n",root->data);
     }
}
int main()
{
    struct node *root=new_node(100);
    insert(root,5);
    insert(root,6);
    insert(root,10);
    insert(root,20);
    insert(root,15);
    insert(root,8);
    insert(root,28);
    printf("preorder traversal \n");
    preorder(root);
    printf("\n");
    printf("inorder traversal\n");
    inorder(root);
    printf("\n");
    printf("postorder traversal\n");
    postorder(root);
    printf("\n");

}
