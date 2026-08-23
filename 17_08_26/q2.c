/*
    Q2) WACP to implement a circular queue.
*/

# include <stdio.h>
# define max 5

int cqenq(int cq[],int r,int f){
    int x=0;
    if((r+1)%max == f)
        printf("Queue is full\n");
    else{
    printf("Enter value:");
    scanf("%d",&x);
    r=(r+1)%max;
    cq[r]=x;}
    return r;
}

int cqdeq(int cq[],int r,int f){
    if(f == -1 && r == -1 )
        printf("Queue is empty\n");
    else{
    printf("Element dequed is %d.\n",cq[f]);
    if(f == r)
        f=-1;
    else
        f=(f+1)%max;
    }
    return f;
}

void disp(int cq[],int r,int f){
    if(f == -1 && r == -1 )
        printf("Queue is empty\n");
    else{
    printf("Elements of queue are:\n");
    while(f != r){
        printf("%d ", cq[f]);
        f=(f+1)%max;}
    printf("%d",cq[f]);
    }
    printf("\n");
}

void peek(int cq[],int f){
    if(f == -1 )
        printf("Queue is empty\n");
    else{
        printf("Elements is: %d\n", cq[f]);
    }
}

int main(){
    int cq[max],f= -1, r= -1, ch;
    do{
        printf("\n1. Enqueue\n2. Deque\n3. Display\n4. Peek\n5. Exit!\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                r=cqenq(cq,r,f);
                if(f == -1)
                    f=0;
                break;
            case 2:
                f=cqdeq(cq,r,f);
                if(f == -1)
                    r=-1;
                break;
            case 3:
                disp(cq,r,f);
                break;
            case 4:
                peek(cq,f);
                break;
            case 5:
                printf("Exiting...!\n");
                break;
            }
    }while(ch<=4);
    return 0;
}