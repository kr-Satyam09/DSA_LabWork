# include <stdio.h>
# include <stdlib.h>

typedef struct dlist{
  int data;
  struct dlist *next,*prev;
}dl;

void insertL(dl **l, dl **r){
  dl * p =(dl*)malloc(sizeof(dl));
  if(p == NULL){
    printf("Memory not allocated \n");
    return;
  }
  printf("Enter data: ");
  scanf("%d",&p-> data);
  p-> prev = NULL;
  p-> next = *l;
  if(*l != NULL){
    (*l)-> prev = p;
  } else {
    *r = p;
  } 
  *l = p;
}

void insertR(dl **l, dl **r){
  dl * p =(dl*)malloc(sizeof(dl));
  if(p == NULL){
    printf("Memory not allocated \n");
    return;
  }
  printf("Enter data: ");
  scanf("%d",&p-> data);
  p-> next = NULL;
  if(*r == NULL){
    p-> prev =NULL;
    *r = p;
    *l = p;
  } else{
    p-> prev = *r;
    (*r)-> next =p;
    *r = p;
  }
}

void delNode(dl **l,dl **r){
  int val;
  dl *temp = *l;
  if(*l == NULL){
    printf("List is empty\n");
    return;
  }
  printf("Enter data to delete: ");
  scanf("%d", &val);
  while(temp != NULL && temp-> data != val)
    temp= temp-> next;
  if(temp == NULL){
    printf("Node not found\n");
    return;
  }
  if(temp == *l && temp == *r){
    *l = *r = NULL;
  } else if(temp == *l){
    *l = temp-> next;
    (*l)-> prev = NULL;
  } else if(temp ==*r){
    *r = temp-> prev;
    (*r)-> next = NULL;
  } else{
    temp-> prev-> next = temp-> next;
    temp-> next-> prev = temp-> prev;
  }
  free(temp);
  printf("Deleted node: %d\n",val);
}

void disp(dl *l){
  if(l == NULL){
    printf("List is empty\n");
    return;
  }
  printf("List: ");
  while(l != NULL){
    printf("%d-> ", l->data);
    l = l-> next;
  }
  printf("\n");
}

int main(){
  dl *l = NULL, *r = NULL;
  int ch;
  do{
    printf("1. Insert LHS |2. Insert RHS |3.Delete node |4.Display link list |5.Exit\nChoice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        insertL(&l, &r); break;
      case 2:
        insertR(&l, &r); break;
      case 3:
        delNode(&l, &r); break;
      case 4:
        disp(l); break;
      case 5:
        printf("Exiting.\n"); break;
      default:
        printf("Invalid choice\n");
    }
  }while(ch != 5);
  return 0;
}