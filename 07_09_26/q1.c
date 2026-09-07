// Q1) WACP to find midpoint of link-list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} sl;


sl* insert(sl* head, int val)
{
    sl* p = NULL, *t = head;
    int x = 0;
    p = (sl*)malloc(sizeof(sl));
    if(p == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    p->data = val;
    p->next = NULL;
    if(head == NULL)
    {
        return p;
    }
    while(t->next != NULL)
    {
        t = t->next;
    }
    t->next = p;
    return head;
}


sl* findMiddle(sl* head)
{
    sl* slow = head, * fast = head;
    if(head == NULL){
        printf("List is empty\n");
        return NULL;
    }
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }if(fast->next != NULL){
        printf("Number of nodes is EVEN\n");

        printf("Middle nodes are: %d and %d\n",
               slow->data, slow->next->data);
    }else{
        printf("Number of nodes is ODD\n");

        printf("Middle node is: %d\n", slow->data);
    } return slow;
}

void disp(sl *head) {
    if(head == NULL) {
        printf("List is empty\n");
    } else {
        while(head != NULL) {
            printf("%d-> ", head->data);
            head = head->next;
        }
        printf("NULL");
    }
}

void count(sl *head) {
    int count = 0; 
    
    if(head == NULL) {
        printf("List empty\n");
    } else {
        while(head != NULL) {
            count++;
            head = head->next;
        }
        printf("Count: %d\n", count);
    }
}

int main()
{
    sl* head = NULL;
    int ch, val, n;
    do
    {
        printf("\n1. Insert\n2. Middle node\n3. Display\n4. Node count\n5. Exit\n");
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
                findMiddle(head);
                break;
            case 3:
                disp(head);
                break;    
            case 4:
                count(head);
                break;
            case 5:
                printf("Exit\n");
                break;
        }
    }while(ch != 5);
    return 0;
}