// Q1) C prog. to merge two arrays (they don't need to be sorted)

#include <stdio.h>
int main() {
    int n1, n2, a[20], b[20], c[50];
    printf("Enter size of arr1:");
    scanf("%d", &n1);
    int i;
    for(i=0; i<n1 ; i++){
        scanf("%d", &a[i]); 
    }
    printf("Enter size of arr2:");
    scanf("%d", &n2);
    for(i=0; i<n2; i++){
        scanf("%d", &b[i]); 
    }
    for(i=0; i<n1; i++){
        c[i] = a[i]; 
    }
    for(i=0; i<n2; i++){
        c[n1+i] = b[i]; 
    }
    printf("Merged arr\n");
    for(i=0; i<n1+n2; i++){
        printf("%d", c[i]); 
    }
    return 0; }