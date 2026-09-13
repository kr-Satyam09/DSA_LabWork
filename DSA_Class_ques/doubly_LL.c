#include <stdio.h>
#include <stdlib.h>

typedef struct doublelist {
    struct doublelist *prev, *next;
    int data;
} dl;

// Insert function 
dl* insert(dl *r) {
    dl *p = NULL; int x = 0;
    p = (dl*)malloc(sizeof(dl));
    if (p != NULL) {
        printf("Enter data: ");
        scanf("%d", &x);
        p->data = x;
        if (r == NULL) {
            r = p;
            r->prev = NULL;
        } else {
            r->next = p;
            p->prev = r;
            r = p;
        }r->next = NULL;
    }return r;
}

void dispL(dl *l) {   // Display Left to Right
    if (l == NULL) {
        printf("Empty\n");
    } else {
        printf("List (L to R): ");
        while (l != NULL) {
            printf("%d ", l->data);
            l = l->next;
        }
        printf("\n");
    }
}

void dispR(dl *r) {   // Display Right to Left
    if (r == NULL) {
        printf("Empty\n");
    } else {
        printf("List (R to L): ");
        while (r != NULL) {
            printf("%d ", r->data);
            r = r->prev;
        }
        printf("\n");
    }
}

void delete_node(dl **l, dl **r) {
    int val;
    if (*l == NULL) {
        printf("List is Empty\n");
        return;
    }
    printf("Enter data to delete: ");
    scanf("%d", &val);
    dl *temp = *l;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    // Node not found
    if (temp == NULL) {
        printf("Element %d not found.\n", val);
        return;
    }
    // Deleting the only node in the list
    if (temp == *l && temp == *r) {
        *l = NULL;
        *r = NULL;
    }
    // Deleting the head node (L.H.S)
    else if (temp == *l) {
        *l = temp->next;
        (*l)->prev = NULL;
    }
    // Deleting the tail node (R.H.S)
    else if (temp == *r) {
        *r = temp->prev;
        (*r)->next = NULL;
    }
    // Deleting a node in the middle
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node %d deleted.\n", val);
}

int main() {
    dl *l = NULL, *r = NULL;
    int ch;
    do {
        printf("\n1. Insert |2. Delete |3. DispL |4. DispR |5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                r = insert(r);
                if (l == NULL) {
                    l = r;
                }
                break;
            case 2:
                // Pass addresses so the function can modify 'l' and 'r' if needed
                delete_node(&l, &r); 
                break;
            case 3:
                dispL(l); 
                break;
            case 4:
                dispR(r); 
                break;
            case 5:
                printf("Exit\n"); 
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 5);
    
    return 0;
}