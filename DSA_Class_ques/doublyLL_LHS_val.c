// Q2) Insert LHS using Call by Value

#include <stdio.h>
#include <stdlib.h>

typedef struct doublelist {
    struct doublelist *prev, *next;
    int data;
} dl;

dl* insert_lhs(dl *l) {
    dl *p = (dl*)malloc(sizeof(dl));
    printf("Enter data: ");
    scanf("%d", &p->data);
    
    p->prev = NULL;
    p->next = l;
    if (l != NULL) l->prev = p;
    
    return p; 
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
    dl *l = NULL; 
    int ch;
    do {
        printf("\n1. Insert LHS | 2. Display | 3. Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: l = insert_lhs(l); break;
            case 2: disp(l); break;
            case 3: break;
            default: printf("Invalid\n");
        }
    } while (ch != 3);
    return 0;
}