#include <stdio.h>
#include<stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;

void InsertAtBeginning( Node **head_ref,int new_data);
void InsertAtEnd( Node **head_ref,int new_data);
void Insert( Node **prev_node,int new_data,int pos);
void PrintList(Node * next);

void InsertAtBeginning( Node **head_ref,int new_data)
{
    Node *new_node=(struct Node*)malloc(sizeof( Node));
    new_node->data=new_data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void InsertAtEnd(Node **head_ref,int new_data)
{
    Node *new_node=(struct Node*)malloc(sizeof( Node));
    Node *last=*head_ref;
    new_node->data=new_data;
    new_node->next=NULL;
    if (*head_ref==NULL)
    {
        *head_ref=new_node;
        return ;
    }
    while (last->next!=NULL)
        last=last->next;
    last->next=new_node;

}
void Insert(Node **head_ref,int new_data,int pos)
{
    if (*head_ref ==NULL)
    {
        printf("Cannot  be NULL\n");
        return;
    }
    Node *temp = *head_ref;
    Node *newNode = ( Node *) malloc (sizeof ( Node));
    newNode->data = new_data;
    newNode->next = NULL;

      while (--pos>0)
	{
	  temp = temp->next;
	}
	newNode->next = temp->next;
     temp->next = newNode;
}


void PrintList(Node *node)
{
    while (node!=NULL)
    {
        printf("%d\n",node->data);
        node=node->next;
    }
}


int main()
{
    int ch,new,pos;
    Node* head=NULL;
    while(ch!=5)
    {
    printf("Menu\n");
    printf("Enter your choice\n 1.To Insert at beginning\n 2. To Insert at a specific position\n 3.To Insert at end\n 4.To Display linked list\n 5.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
        printf("Enter the data you want to insert at beginning\n");
        scanf("%d",&new);
        InsertAtBeginning(&head,new);
        break;
        }
        case 2:
        {
        printf("Enter the data and position at which you want to insert \n");
        scanf("%d%d",&new,&pos);
        Insert(&head,new,pos);
        break;
        }
        case 3:
        {
        printf("Enter the data  you want to insert at end\n");
        scanf("%d",&new);
        InsertAtEnd(&head,new);
        break;
        }
        case 4:
        {
            printf("Created linked list is:\n");
            PrintList(head);
            break;
        }
        case 5:
        {
            return 0;
            break;
        }
        case 6:
        {
            printf("Invalid data!");
            break;
        }
        }
}
return 0;
}


