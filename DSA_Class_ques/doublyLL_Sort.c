// Q5) Insert in Ascending Order without sorting later

#include <stdio.h>
#include <stdlib.h>

typedef struct doublelist {
    struct doublelist *prev, *next;
    int data;
} dl;

void insert_ascending(dl **l, dl **r) {
    dl *p = (dl *)malloc(sizeof(dl));
    if (p == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &p->data);
    // Empty list
    if (*l == NULL) {
        p->prev = NULL;
        p->next = NULL;
        *l = *r = p;
        return;
    }
    // Insert at the beginning
    if ((*l)->data >= p->data) {
        p->prev = NULL;
        p->next = *l;
        (*l)->prev = p;
        *l = p;
        return;
    }
    // Find correct position
    dl *temp = *l;
    while (temp->next != NULL &&
           temp->next->data < p->data) {
        temp = temp->next;
    }
    p->next = temp->next;
    p->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = p;
    } else {
        *r = p;
    }
    temp->next = p;
}

void delete_node(dl **l, dl **r) {
    if (*l == NULL) {
        printf("List is Empty\n");
        return;
    }
    int val;
    printf("Enter data to delete: ");
    scanf("%d", &val);
    dl *temp = *l;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found.\n", val);
        return;
    }//Deleting the only node in the list
    if (temp == *l && temp == *r) {
        *l = *r = NULL;
    }//Deleting the head node
    else if (temp == *l) {
        *l = temp->next;
        (*l)->prev = NULL;
    }//Deleting the tail node
    else if (temp == *r) {
        *r = temp->prev;
        (*r)->next = NULL;
    }//Deleting a middle node
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Deleted %d successfully.\n", val);
}

void disp(dl *l) {
    if (l == NULL) {
        printf("List is Empty\n");
    }
    printf("Sorted List: ");
    while (l != NULL) {
        printf("%d -> ", l->data);
        l = l->next;
    }printf("\n");
}

int main() {
    dl *l = NULL, *r = NULL;
    int ch;
    
    do {
        printf("\n1. Insert Ascending | 2. Delete | 3. Display | 4. Exit\nChoice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                insert_ascending(&l, &r);
                break;
            case 2:
                delete_node(&l, &r);
                break;
            case 3:
                disp(l);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 4);
    return 0;
}