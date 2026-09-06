/* 
    Q1) WACP to implement a singly link-list with help of given function (using call by value):
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

typedef struct list{
    int data;
    struct list *next;
}sl;

sl *insertL(sl *l) {
    sl *p = (sl *)malloc(sizeof(sl));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return l;
    }
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = l;
    return p;
}

sl *insertR(sl *l) {
    sl *p = (sl *)malloc(sizeof(sl));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return l;
    }
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = NULL;
    if (l == NULL) {
        return p;
    }
    sl *temp = l;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
    return l;
}

sl *insertPos(sl *l, int pos, int x) {
    sl *newNode = (sl *)malloc(sizeof(sl));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return l;
    }
    newNode->data = x;
    if (pos == 1) {
        newNode->next = l;
        return newNode;
    }
    sl *temp = l;
    int i = 1;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return l;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return l;
}

sl *delLHS(sl *l) {
    if (l == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    sl *temp = l;
    printf("Deleted node is: %d\n", temp->data);
    l = l->next;
    free(temp);
    return l;
}

sl *delRHS(sl *l) {
    if (l == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (l->next == NULL) {
        printf("Deleted node is: %d\n", l->data);
        free(l);
        return NULL;
    }
    sl *temp = l;
    sl *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted node is: %d\n", temp->data);
    free(temp);
    prev->next = NULL;
    return l;
}

sl *delPos(sl *l, int pos) {
    if (l == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    sl *temp = l, *prev = NULL;
    int i = 1;
    while (temp != NULL && i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return l;
    }
    if (prev == NULL) {
        l = temp->next;
    } else {
        prev->next = temp->next;
    }
    printf("Deleted node is: %d\n", temp->data);
    free(temp);
    return l;
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
                l = insertL(l);
                break;
            case 2:
                l = insertR(l);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &val);
                l = insertPos(l, pos, val);
                break;
            case 4:
                l = delLHS(l);
                break;
            case 5:
                l = delRHS(l);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                l = delPos(l, pos);
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
    } while(ch != 9);
    return 0;
}