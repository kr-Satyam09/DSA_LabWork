// Q2) Write a C prog. to convert an unsorted array in ascending order.

Soln: #include <stdio.h>
int main() {
    int n, a[100], i, j, t;
    printf("Enter size of arr:");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(a[i] > a[j]){
                t = a[i];
                a[i] = a[j];
                a[j] = t; 
            }
        }
    }
    printf("Ascending order:\n");
    for(i=0; i<n; i++){
        printf("%d", a[i]); 
    }
    printf("\nIn Descending order:\n");
    for(i=n-1; i>=0; i--){
         printf("%d", a[i]); 
    }
    return 0; 
}