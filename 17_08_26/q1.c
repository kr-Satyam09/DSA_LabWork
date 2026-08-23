/*
    Q1) WACP to implement linear queue (simple queue).
*/

# include <stdio.h>
# define max 50

int sqenq(int sq[],int r){
    int x=0;
    if(r==max-1)
        printf("Queue is full\n");
    else{
        printf("Enter value:");
        scanf("%d",&x);
        r++;
        sq[r]=x;}
    return r;
}

int sqdeq(int sq[],int r,int f){
    if(f == -1 && r == -1 )
        printf("Queue is empty\n");
    else{
        printf("Element dequed is %d .\n",sq[f]);
        if(f == r)
            f=-1;
        else
            f++;
    }
    return f;
}

void disp(int sq[],int r,int f){
    if(f == -1 && r == -1 )
        printf("Queue is empty\n");
    else{
    printf("Elements of queue are:\n");
    while(f <= r){
        printf("%d ", sq[f]);
        f++;}
    }
    printf("\n");
}

void peek(int sq[],int f){
    if(f == -1 )
        printf("Queue is empty\n");
    else{
        printf("Elements is: %d\n", sq[f]);
    }
}

int main(){
    int sq[max],f= -1, r= -1, ch;
    do{
        printf("\n1. Enqueue\n2. Deque\n3. Display\n4. Peek\n5. Exit!\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                r=sqenq(sq,r);
                if(f == -1)
                    f=0;
                break;
            case 2:
                f=sqdeq(sq,r,f);
                if(f == -1)
                    r=-1;
                break;
            case 3:
                disp(sq,r,f);
                break;
            case 4:
                peek(sq,f);
                break;
            case 5:
                printf("Exiting...!\n");
                break;
            }
    }while(ch<=4);
    return 0;
}