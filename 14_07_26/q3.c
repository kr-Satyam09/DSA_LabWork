// Q3) Write C prog.  to find the largest & smallest elem. in array.

#include <stdio.h>
int main() {
    int n, a[100], min, max;
    printf("Enter arr. size:");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]); 
    }
    min = max = a[0];
    for(i=0; i<n; i++) {
        if(a[i] > max){
            max = a[i]; 
        }
        if(a[i] < min) {
            min = a[i]; 
        }
    }
    printf("largest num= %d\n smallest num= %d\n", max, min);
    return 0;
}