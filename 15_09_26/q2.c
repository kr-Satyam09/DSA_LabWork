// Q2) WACP to merge two LL, in such a way that it remains sorted.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* insert_sort(node *head, int val) {
    node *p = (node *)malloc(sizeof(node));
    p->data = val;
    p->next = NULL;
    if (head == NULL || head->data >= val) {
        p->next = head;
        return p;
    }
    node *temp = head;
    while (temp->next != NULL && temp->next->data < val) {
        temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
    return head;
}

node* merge_lists(node *l1, node *l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1; 
    node dummy;
    node *tail = &dummy;
    dummy.next = NULL; 
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }
    return dummy.next;
}

void disp(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node *list1 = NULL;
    node *list2 = NULL;
    node *merged_list = NULL;
    int ch, val;
    
    do {
        printf("\n1. Insert in List 1 | 2. Insert in List 2 | 3. Merge Both | 4. Display All | 5. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value for List 1: ");
                scanf("%d", &val);
                list1 = insert_sort(list1, val);
                break;
            case 2:
                printf("Enter value for List 2: ");
                scanf("%d", &val);
                list2 = insert_sort(list2, val);
                break;
            case 3:
                merged_list = merge_lists(list1, list2);
                list1 = NULL; 
                list2 = NULL;
                printf("Lists merged successfully.\n");
                break;
            case 4:
                printf("List 1: "); disp(list1);
                printf("List 2: "); disp(list2);
                printf("Merged: "); disp(merged_list);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (ch != 5);
    return 0;
}
