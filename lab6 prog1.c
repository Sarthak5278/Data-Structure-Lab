#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void display(Node* head) {
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr= ptr->next;
    }
    printf("NULL\n");
}
void sortList(Node** head) {
    if (*head == NULL) {
        return;
    }
    int temp;
    Node* current1 = *head;
    Node* current2;
    while (current1 != NULL) {
        current2 = current1->next;

        while (current2 != NULL) {
            if (current1->data > current2->data) {
                temp = current1->data;
                current1->data = current2->data;
                current2->data = temp;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
}
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    *head = prev;
}
void concatenateLists(Node** list1, Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
    } else {
        Node* current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2;
    }
}
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    insert(&list1, 2);
    insert(&list1, 1);
    insert(&list1, 8);

    insert(&list2, 2);
    insert(&list2, 6);

    printf("Original List 1:\n");
    display(list1);

    printf("\nSorting List 1:\n");
    sortList(&list1);
    display(list1);

    printf("\nReversing List 1:\n");
    reverseList(&list1);
    display(list1);

    printf("\nOriginal List 2:\n");
    display(list2);

    printf("\nConcatenating List 1 and List 2:\n");
    concatenateLists(&list1, list2);
    display(list1);

    return 0;
}
