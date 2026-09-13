#include <stdio.h>
#include <stdlib.h>


typedef struct doublelist {
    struct doublelist *prev, *next;
    int data;
} dl;

void insert(dl **head) {
    dl *p = (dl*)malloc(sizeof(dl));
    printf("Enter data to insert: ");
    scanf("%d", &p->data);
    // If the list is empty, initialize the first node to point to itself
    if (*head == NULL) {
        p->next = p;
        p->prev = p;
        *head = p;
    } else {
        // Finds the last node
        dl *last = (*head)->prev;
        p->next = *head;
        p->prev = last;
        last->next = p;
        (*head)->prev = p;
    }
}

void delete(dl **head) {
    int val;
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    printf("Enter node to delete: ");
    scanf("%d", &val);
    dl *curr = *head;
    while (curr->data != val) {
        if (curr->next == *head) {
            printf("Element not in list.\n");
            return;
        }
        curr = curr->next;
    }
    // The list has only one node
    if (curr->next == curr && curr->prev == curr) {
        *head = NULL;
        free(curr);
        printf("Node %d deleted. List is now empty.\n", val);
        return;
    }
    // The node to delete is the head node
    if (curr == *head) {
        dl *last = (*head)->prev;
        *head = curr->next; // Shift head to the next node
        
        last->next = *head;
        (*head)->prev = last;
        
        free(curr);
        printf("Head node %d deleted.\n", val);
        return;
    }
    // The node to delete is in the middle or end
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
    printf("Node %d deleted.\n", val);
}

void disp(dl *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }    
    dl *temp = head;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when it wraps back around to the head
    printf("\n");
}

int main() {
    dl *head = NULL;
    int ch;

    do {
        printf("\n1. Insert Node |2. Delete Node |3. Display List |4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                insert(&head);
                break;
            case 2:
                delete(&head);
                break;
            case 3:
                disp(head);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 4);

    return 0;
}