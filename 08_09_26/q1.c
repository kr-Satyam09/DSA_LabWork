// Q1) WACP to implement a circular linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct circular_list {
    int data;
    struct circular_list *next;
} cl;

void insert(cl **head) {
    cl *p = (cl *)malloc(sizeof(cl));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
    } else {
        printf("Enter data to insert: ");
        scanf("%d", &p->data);
        if (*head == NULL) {
            *head = p;
            p->next = *head;
        } else {
            cl *temp = *head;
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = p;
            p->next = *head;
        }
    }
}

void delete(cl **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
    } else {
        int val;
        printf("Enter data to delete: ");
        scanf("%d", &val);
        cl *curr = *head;
        cl *prev = NULL;
        int found = 1;
        
        while (curr->data != val) {
            if (curr->next == *head) {
                printf("Element %d not found \n", val);
                found = 0;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        
        if (found == 1) {
            if (curr->next == *head && curr == *head) {
                *head = NULL;
                free(curr);
                printf("Node %d deleted.List is now empty.\n", val);
            } else if (curr == *head) {
                cl *temp = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }
                *head = curr->next;  
                temp->next = *head;   
                free(curr);
                printf("Head node %d deleted.\n", val);
            } else {
                prev->next = curr->next;
                free(curr);
                printf("Node %d deleted.\n", val);
            }
        }
    }
}

void disp(cl *head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        cl *temp = head;
        printf("Circular List: ");
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head); 
        printf("\n");
    }
}

int main() {
    cl *head = NULL;
    int ch;
    do {
        printf("1. Insert Node |2. Delete Node |3. Display List |4. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert(&head); break;
            case 2:
                delete(&head); break;
            case 3:
                disp(head); break;
            case 4:
                printf("Exiting\n"); break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 4);
    return 0;
}