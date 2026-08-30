/* 
    Q1) WACP to create a single linked list by inserting 
    nodes at RHS and perform following operations:
        i.   Display linked list
        ii.  Count total nodes
        iii. Deletion of nodes
    */

# include <stdio.h>
# include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}sl;

sl *insert(sl *r ){
    sl *p = NULL;  int x;
    p = (sl*)malloc(sizeof(sl));
    if(p!=NULL){
        printf("******* Memory allocated *******\n");
        printf("Enter data:");
        scanf("%d",&x);
        p-> data =x;
        if(r==NULL){
            r=p;
        }else{
            r-> next =p;
            r = p;
        }
        r->next = NULL;
    }
    return r;
}

sl *delLHS(sl *l){
    if(l == NULL){
        printf("List is empty.");
        return NULL;
    }
    sl *temp =l;
    printf("Deleted node is: %d\n", temp-> data);
    l = l-> next;
    free(temp);
    return l;
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

void count(sl *l) {
    int count = 0; 
    
    if(l == NULL) {
        printf("List empty\n");
    } else {
        while(l != NULL) {
            count++;
            l = l->next;
        }
        printf("Count: %d\n", count);
    }
}


int main() {
    sl *l = NULL, *r = NULL;
    int ch;
    
    do {
        printf("\n1. Insert \n2. Delete node \n3. Display \n4. Count \n5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                r = insert(r);
                if(l == NULL) {
                    l = r;
                }
                break;
            case 2:
                l = delLHS(l);
                break;
            case 3:
                disp(l);
                break;
            case 4:
                count(l);
                break;
            default:
                printf("Exit!\n");
                break;
        }
    } while (ch <= 4);
    
    return 0;
}
