#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    int expo, coeff;
    struct polynomial *next;
} poly;

poly * create() {
    poly * p = NULL, * l = NULL, * r = NULL;
    int e, c, ch;
    
    while(1) {
        p = (poly *) malloc(sizeof(poly));
        if (p == NULL) {
            printf("Memory allocation failed!\n");
            return l;
        }       
        p->next = NULL; // Explicitly initialize next pointer       
        printf("Enter expo & coeff (i.e. 2 5 for 5x^2): ");
        scanf("%d %d", &e, &c);
        p->expo = e;
        p->coeff = c;       
        if (l == NULL && r == NULL) {
            l = r = p;
        } else {
            r->next = p;
            r = p;
        }       
        printf("Do you want to continue (1/0): ");
        scanf("%d", &ch);
        if (ch == 0) {
            break;
        }
    }   
    if (r != NULL) {
        r->next = NULL;
    }
    return l;
}

poly * add_poly(poly * p1, poly * p2) {
    poly * p = NULL, * l = NULL, * r = NULL;
    
    while(p1 != NULL && p2 != NULL) {
        p = (poly *) malloc(sizeof(poly));
        p->next = NULL; // Explicitly initialize        
        if (p1->expo == p2->expo) {
            p->expo = p1->expo;
            p->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->expo > p2->expo) {
            p->expo = p1->expo;
            p->coeff = p1->coeff;
            p1 = p1->next;
        }
        else {
            p->expo = p2->expo;
            p->coeff = p2->coeff;
            p2 = p2->next;
        }       
        if (l == NULL && r == NULL) {
            l = r = p;
        } else {
            r->next = p;
            r = p;
        }
    }
    
    // Safely append remaining nodes if any
    if (r != NULL) {
        if (p1 == NULL && p2 == NULL) {
            r->next = NULL;
        }
        else if (p1 != NULL) {
            r->next = p1;
        }
        else if (p2 != NULL) {
            r->next = p2;
        }
    } else {
        // If 'r' is NULL, it means the while loop never ran. 
        // We just return whichever list is not empty.
        if (p1 != NULL) return p1;
        if (p2 != NULL) return p2;
    }
    
    return l;
}

void disp(poly * l) {
    if (l == NULL) {
        printf("Poly empty\n");
        return;
    }    
    while (l != NULL) {
        if (l->next != NULL) {
            printf("%dx^%d + ", l->coeff, l->expo);
        } else {
            printf("%dx^%d\n", l->coeff, l->expo);
        }
        l = l->next;
    }
}

int main () {
    poly * p1 = NULL, * p2 = NULL, * p3 = NULL;    
    printf("First poly:\n");
    p1 = create(); 
    disp(p1);   
    printf("\nSecond poly:\n");
    p2 = create(); 
    disp(p2);    
    printf("\nAddition of poly (1 & 2):\n");
    p3 = add_poly(p1, p2);
    disp(p3);   
    return 0;
}
