// Q2) WACP to print nodes in multiple of 'K'(i.e. for k = 2 (print nodes 2,4,6,8...)).

# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} sl;

sl *insert(sl *r) {
    sl *p = NULL;
    int x;
    p = (sl *)malloc(sizeof(sl));
    if (p != NULL) {
        printf("\tMemory allocation successfull\n");
        printf("Enter data: ");
        scanf("%d", &x);
        p->data = x;
        p->next = NULL;

        if (r != NULL) {
            r->next = p;
        }
        r = p;
    }
    return r;
}

void printK(sl *head, int k) {
    int count = 1;
    while (head != NULL) {
        if (count % k == 0) {
            printf("%d ", head->data);
        }
        head = head->next;
        count++;
    }
}

void disp(sl *l) {
    if(l == NULL) {
        printf("List is empty\n");
    } else {
        while(l != NULL) {
            printf("%d-> ", l->data);
            l = l->next;
        }
        printf("NULL");
    }
}

int main() {
    sl *l = NULL, *r = NULL;
    int ch, k;

    do {
        printf("\n1. Insert \n2. Nodes at Kth multiple \n3. Display \n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                r = insert(r);
                if (l == NULL) {
                    l = r;
                }
                break;
            case 2:
                printf("Enter K: ");
                scanf("%d", &k);
                if (k > 0) {
                    printK(l, k);
                    printf("\n");
                } else {
                    printf("K must be greater than 0.\n");
                }
                break;
            case 3:
                disp(l);
                break;
            case 4:
                printf("Exit!\n");
                break;
        }
    } while (ch != 4);
    return 0;
}