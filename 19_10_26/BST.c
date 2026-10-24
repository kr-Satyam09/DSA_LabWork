/* 
    WACP to implement BST with functions
    i.Create tree
    ii.Display(Preorder,Inorder,Postorder).
    iii.Count leaf nodes.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    struct list *left;
    int data;
    struct list *right;
}tree;

void create(tree **r,int val){
    tree *p = NULL;
    if(*r == NULL){
        p = (tree*)malloc(sizeof(tree));
        /*if(p == NULL){
            printf("Unable to allocate memory.\n");
            return;
        }*/
        p->data = val;
        p->left = NULL;
        p->right = NULL;
        *r = p;
        return;
    } else if(val < (*r)->data) {
        create(&((*r)->left),val);
    } else if(val > (*r)->data) {
        create(&((*r)->right),val);
    } else {
        printf("Duplicates are not allowed!");
    }
}

void disp_pre(tree *r){
    if(r != NULL){
        printf("%d ",r->data);
        disp_pre(r->left);
        disp_pre(r->right);
    }
}

void disp_in(tree *r){
    if(r != NULL){
        disp_in(r->left);
        printf("%d ",r->data);
        disp_in(r->right);
    }
}

void disp_post(tree *r){
    if(r != NULL){
        disp_post(r->left);
        disp_post(r->right);
        printf("%d ",r->data);
    }
}

void countleaf(tree *root,int *p){
    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            (*p)++;
        }
        countleaf(root->left,p);
        countleaf(root->right,p);
    }
}

int main(){
    tree *root = NULL;
    int ch, num,count;
    do{
        printf("\n1.Create tree |2.Pre_order |3.In_order |4.Post_order |5.Count leaf(s) |6.Exit\nEnter choice: ");
        scanf("%d",&ch);

        switch (ch){
            case 1:
                printf("Enter info: ");
                scanf("%d",&num);
                create(&root,num);
                break;
            case 2:
                printf("Display in pre_order: ");
                disp_pre(root);
                printf("\n");
                break;
            case 3:
                printf("Display in In_order: ");
                disp_in(root);
                printf("\n");
                break;
            case 4:
                printf("Display in post_order:");
                disp_post(root);
                printf("\n");
                break;
            case 5:
                count = 0;
                countleaf(root,&count);
                printf("Num. of leaf nodes are %d\n",count);
                break;
            case 6:
                printf("Exiting!\n\n");
                break;
        }
    }while(ch != 6);
    return 0;
}
