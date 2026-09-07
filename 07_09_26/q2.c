// Q2) WACP to reverse link list from middle

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} sl;

sl* insert(sl* head, int val){
    sl* p = NULL, *t = head;
    p = (sl*)malloc(sizeof(sl));
    if(p == NULL){
        printf("Memory allocation failed\n");
        return head;
    }
    p->data = val;
    p->next = NULL;
    if(head == NULL){
        return p;
    }while(t->next != NULL){
        t = t->next;
    }
    t->next = p;
    return head;
}


void reverseFromMiddle(sl* head){
    if (head == NULL || head->next == NULL) {
        return;
    }
    sl *slow = head, *fast = head, *midPrev = NULL;
    while (fast != NULL && fast->next != NULL) {
        midPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    sl *curr = slow, *prev = NULL; // Crucial: Initialize to NULL so the new tail points to NULL
    sl *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    // Connects the 1st/2 to newly reversed 2nd/2 & 'prev' is now the head of the reversed 2nd/2
    if (midPrev != NULL) {
        midPrev->next = prev;
    }
}

void display(sl* head){
    sl* t = head;
    while(t != NULL){
        printf("%d -> ", t->data);
        t = t->next;
    }printf("NULL\n");
}


int main()
{
    sl* head = NULL;
    int ch, val;
    do
    {
        printf("\n1. Insert\n2. Reverse from middle\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &val);
                head = insert(head, val);
                break;
            case 2:
                reverseFromMiddle(head);
                printf("List reversed from middle.\n");
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exit\n");
                break;
        }
    }while(ch != 4);
    return 0;
}