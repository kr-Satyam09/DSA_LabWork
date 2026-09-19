// Q1) WACP to swap adjacent nodes in linklist

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* insert(node *head, int val) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL) {
        return new_node;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

node* swap_adjacent(node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node *new_head = head->next, *prev = NULL, *curr = head;
    while (curr != NULL && curr->next != NULL) {
        node *next_pair = curr->next->next, *second = curr->next;   
        second->next = curr;
        curr->next = next_pair;
        if (prev != NULL) {
            prev->next = second;
        }
        prev = curr;
        curr = next_pair;
    }
    return new_head;
}

void display(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;
    int ch, val;
    do {
        printf("\n1. Insert Node | 2. Swap Adjacent Nodes | 3. Display | 4. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;
            case 2:
                head = swap_adjacent(head);
                printf("Adjacent nodes swapped.\n");
                break;
            case 3:
                display(head);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 4);
    return 0;
}