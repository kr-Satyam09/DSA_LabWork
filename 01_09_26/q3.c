/*
    Q3) WACP to implement a singly linked list and delete the nth node from the beginning.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} sl;

sl *insert(sl *head, int val) {
    sl *p = (sl *)malloc(sizeof(sl));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }
    p->data = val;
    p->next = NULL;
    if (head == NULL) {
        return p;
    }
    sl *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
    return head;
}

sl *delNthBegin(sl *head, int n) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (n <= 0) {
        printf("Invalid position.\n");
        return head;
    }
    if (n == 1) {
        sl *temp = head;
        head = head->next;
        printf("Deleted node is: %d\n", temp->data);
        free(temp);
        return head;
    }
    sl *temp = head, *prev = NULL;
    int i = 1; 
    while (temp != NULL && i < n) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    prev->next = temp->next;
    printf("Deleted node is: %d\n", temp->data);
    free(temp);   
    return head;
}

void disp(sl *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    sl *head = NULL;
    int ch, val, n;

    do {
        printf("\n1. Insert\n2. Delete Nth node from beginning\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;
            case 2:
                printf("Enter N: ");
                scanf("%d", &n);
                head = delNthBegin(head, n);
                break;
            case 3:
                disp(head);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);
    return 0;
}