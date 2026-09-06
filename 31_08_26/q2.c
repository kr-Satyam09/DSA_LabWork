/* 
    Q1) WACP to implement a singly link-list with help of given function (using call by reference):
    i.  Insertion at left 
    ii  Insertion at right 
    iii. Insertion at given position
    iv. Del at left
    v.  Del at right
    vi. Del at given position
    vii. Display link-list
*/


# include <stdio.h>
# include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} sl;

void insertL(sl **l) {
    sl *p = (sl *)malloc(sizeof(sl));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = *l;
    *l = p;
}

void insertR(sl **l) {
    sl *p = (sl *)malloc(sizeof(sl));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = NULL;
    if (*l == NULL) {
        *l = p;
        return;
    }
    sl *temp = *l;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
}

void insertPos(sl **l, int pos, int x) {
    sl *newNode = (sl *)malloc(sizeof(sl));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;

    if (pos == 1) {
        newNode->next = *l;
        *l = newNode;
        return;
    }

    sl *temp = *l;
    int i = 1;

    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delLHS(sl **l) {
    if (*l == NULL) {
        printf("List is empty\n");
        return;
    }

    sl *temp = *l;
    printf("Deleted node is: %d\n", temp->data);
    *l = (*l)->next;
    free(temp);
}

void delRHS(sl **l) {
    if (*l == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*l)->next == NULL) {
        printf("Deleted node is: %d\n", (*l)->data);
        free(*l);
        *l = NULL;
        return;
    }

    sl *temp = *l;
    sl *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted node is: %d\n", temp->data);
    free(temp);
    prev->next = NULL;
}

void delPos(sl **l, int pos) {
    if (*l == NULL) {
        printf("List is empty\n");
        return;
    }

    sl *temp = *l, *prev = NULL;
    int i = 1;

    while (temp != NULL && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (prev == NULL) {
        *l = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("Deleted node is: %d\n", temp->data);
    free(temp);
}

void disp(sl *l) {
    if (l == NULL) {
        printf("List is empty\n");
        return;
    }

    while (l != NULL) {
        printf("%d -> ", l->data);
        l = l->next;
    }
    printf("NULL\n");
}

void count(sl *l) {
    int c = 0;
    while (l != NULL) {
        c++;
        l = l->next;
    }
    printf("Count: %d\n", c);
}

int main() {
    sl *l = NULL;
    int ch, pos, val;

    do {
        printf("\n1. Insert at left\n2. Insert at right\n3. Insert at given position\n4. Delete at left\n5. Delete at right\n6. Delete at given position\n7. Display\n8. Count\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertL(&l);
                break;
            case 2:
                insertR(&l);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &val);
                insertPos(&l, pos, val);
                break;
            case 4:
                delLHS(&l);
                break;
            case 5:
                delRHS(&l);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                delPos(&l, pos);
                break;
            case 7:
                disp(l);
                break;
            case 8:
                count(l);
                break;
            case 9:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 9);

    return 0;
}