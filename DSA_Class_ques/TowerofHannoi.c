#include <stdio.h>

void towerOfHanoi(int n, char A, char C, char B) {
    if (n == 1) {
         printf("Move disk %d from rod %c to rod %c\n", n, A, C);
        return;
    }
    towerOfHanoi(n - 1, A, B, C);
    printf("Move disk %d from rod %c to rod %c\n", n, A, C);
    towerOfHanoi(n - 1, B, C, A);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\nSteps to solve Tower of Hanoi for %d disk(s):\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');  // A = source, C = destination, B = auxiliary
    printf("\nTotal moves: %d\n", (1 << n) - 1);  // 2^n - 1
    return 0;
}