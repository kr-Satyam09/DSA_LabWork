// Q1) WACP to implement insertion and quick sort, to sort an array of characters.

#include <stdio.h>
#include <string.h>
#define max 50

void insert_sort(char a[], int n) {
    int i, j, t = 0;
    for (i = 1; i < n; i++) {
        t = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > t) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = t;
    }
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int partition(char a[], int low, int high) {
    char pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quick_sort(char a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}

void display(char a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
}

int main() {
    char arr[max], temp_arr[max];
    int n, ch;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    printf("Enter %d characters (without spaces): ", n);
    scanf("%s", arr);

    do {
        for (int i = 0; i < n; i++) {
            temp_arr[i] = arr[i];
        }
        printf("\n1. Insertion Sort |2. Quick Sort |3. Display Original |4. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_sort(temp_arr, n);
                printf("Sorted using Insertion Sort: ");
                display(temp_arr, n);
                break;
            case 2:
                quick_sort(temp_arr, 0, n - 1);
                printf("Sorted using Quick Sort: ");
                display(temp_arr, n);
                break;
            case 3:
                printf("Original Array: ");
                display(arr, n);
                break;
            case 4:
                printf("Exiting\n"); break;
        }
    } while (ch != 4);
    return 0;
}