/*
    Q1) WACP to arrange array of integers in such a way
        that all negative elements come at the left,positive at right and 
        zero at mid but don't change relative ordering of elements.
*/

#include <stdio.h>
#include <stdlib.h>

void arrange(int a[], int n) {
    int *p = (int *)malloc(n * sizeof(int)); 
    if (p == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }
    int ind = 0;
    // Collect negative elements
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            p[ind++] = a[i];
        }
    }
    
    // Collect zero elements
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            p[ind++] = a[i];
        }
    }
    
    // Collect positive elements
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            p[ind++] = a[i];
        }
    }
    
    // Copy elements back to original array
    for (int i = 0; i < n; i++) {
        a[i] = p[i];
    }
    free(p);
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    int a[n];
    printf("Enter %d integer elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("\nOriginal Array:   ");
    display(a, n);
    arrange(a, n);
    printf("Rearranged Array: ");
    display(a, n);
    return 0;
}