// Q3) Insert RHS using Call by Reference (Double Pointers)

#include <stdio.h>
#include <stdlib.h>

typedef struct doublelist {
    struct doublelist *prev, *next;
    int data;
} dl;

void insert_rhs_ref(dl **l, dl **r) {
    dl *p = (dl*)malloc(sizeof(dl));
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = NULL;

    if (*r == NULL) {
        p->prev = NULL;
        *l = *r = p; 
    } else {
        p->prev = *r;
        (*r)->next = p;
        *r = p; 
    }
}

void disp(dl *l) {
    if (l == NULL) { printf("Empty\n"); return; }
    printf("List: ");
    while (l != NULL) {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

int main() {
    dl *l = NULL, *r = NULL;
    int ch;
    do {
        printf("\n1. Insert RHS | 2. Display | 3. Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert_rhs_ref(&l, &r); break;
            case 2: disp(l); break;
            case 3: break;
            default: printf("Invalid\n");
        }
    } while (ch != 3);
    return 0;
}