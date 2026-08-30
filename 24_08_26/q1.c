// Q1) WACP to implement a double-ended queue and use 'Switch' to perform operations.

#include <stdio.h>
#define max 50

int insertF(int dq[], int f, int r) {
    int x;
    if ((f == 0 && r == max - 1) || (f == r + 1)) {
        printf("Queue is full\n");
    } else {
        printf("Enter value:");
        scanf("%d", &x);
        if (f == -1) {
            f = 0;
        } else if (f == 0) {
            f = max - 1;
        } else {
            f = f - 1;
        }
        dq[f] = x;
    }
    return f;
}

int insertR(int dq[], int f, int r) {
    int x;
    if ((f == 0 && r == max - 1) || (f == r + 1)) {
        printf("Queue is full\n");
    } else {
        printf("Enter value:");
        scanf("%d", &x);
        if (r == -1) {
            r = 0;
        } else {
            r = (r + 1) % max;
        }
        dq[r] = x;
    }
    return r;
}

int delF(int dq[], int f, int r) {
    if (f == -1 && r == -1) {
        printf("Queue empty\n");
    } else {
        printf("%d\n", dq[f]);
        if (f == r) {
            f = -1;
        } else {
            f = (f + 1) % max;
        }
    }
    return f;
}

int delR(int dq[], int f, int r) {
    if (f == -1 && r == -1) {
        printf("Queue empty\n");
    } else {
        printf("%d\n", dq[r]);
        if (f == r) {
            r = -1;
        } else if (r == 0) {
            r = max - 1;
        } else {
            r = r - 1;
        }
    }
    return r;
}

void disp(int dq[], int f, int r) {
    if (f == -1 && r == -1) {
        printf("Queue empty\n");
    } else {
        while (f != r) {
            printf("%d ", dq[f]);
            f = (f + 1) % max;
        }
        printf("%d\n", dq[f]);
    }
}
int main() {
    int dq[max], f = -1, r = -1, ch;
    
    do {
        printf("\n1. Insert Front \n2. Insert Rear \n3. Delete Front \n4. Delete Rear \n5. Display \n6. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                f = insertF(dq, f, r);
                if(r == -1 && f != -1)
                    r = f;
                break;
                
            case 2:
                r = insertR(dq, f, r);
                if(f == -1 && r != -1)
                    f = r;
                break;
                
            case 3:
                f = delF(dq, f, r);
                if(f == -1)
                    r = -1;
                break;
                
            case 4:
                r = delR(dq, f, r);
                if(r == -1)
                    f = -1;
                break;
                
            case 5:
                disp(dq, f, r);
                break;
                
            case 6:
                printf("Exit!\n");
                break;
        }
    } while (ch <= 5);
    
    return 0;
}
