// WACP to implement bubble and selection sort in array

#include <stdio.h>

void bubble_sort(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int a[], int n) {
    int min_idx, temp;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }if (min_idx != i) {
            temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
        }
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void copy_array(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int n, ch;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n], temp_arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    do {
        copy_array(a, temp_arr, n);
        printf("\n1. Bubble Sort | 2. Selection Sort | 3. Display Original | 4. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                bubble_sort(temp_arr, n);
                printf("Array sorted using Bubble Sort: ");
                display(temp_arr, n); break;
            case 2:
                selection_sort(temp_arr, n);
                printf("Array sorted using Selection Sort: ");
                display(temp_arr, n); break;
            case 3:
                printf("Original Array: ");
                display(a, n); break;
            case 4:
                printf("Exiting\n"); break;
        }
    } while (ch != 4);
    return 0;
}