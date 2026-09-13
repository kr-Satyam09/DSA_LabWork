// Q1) Display without overlap

#include <stdio.h>
#include <stdlib.h>

typedef struct doublelist {
    struct doublelist *prev, *next;
    int data;
} dl;

void insert(dl **l, dl **r) {
    dl *p = (dl*)malloc(sizeof(dl));
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = NULL;

    if (*l == NULL) {
        p->prev = NULL;
        *l = *r = p;
    } else {
        p->prev = *r;
        (*r)->next = p;
        *r = p;
    }
}

void disp_no_overlap(dl *l, dl *r) {
    if (l == NULL || r == NULL) {
        printf("Empty List\n");
        return;
    }
    printf("Displaying outside-in without overlap:\n");
    while (1) {
        printf("Left: %d, Right: %d\n", l->data, r->data);
        if (l == r) break; // Odd nodes condition
        if (l->next == r) break; // Even nodes condition
        l = l->next;
        r = r->prev;
    }
}

int main() {
    dl *l = NULL, *r = NULL;
    int ch;
    do {
        printf("\n1. Insert | 2. Disp without Overlap | 3. Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert(&l, &r); break;
            case 2: disp_no_overlap(l, r); break;
            case 3: break;
            default: printf("Invalid\n");
        }
    } while (ch != 4);
    return 0;
}