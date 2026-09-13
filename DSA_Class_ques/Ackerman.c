#include <stdio.h>

int acker(int m, int n) {
    if (m == 0) {
        return (n + 1);
    }
    else if (m > 0 && n == 0) {
        return acker(m - 1, 1);
    }
    else if (m > 0 && n > 0) {
        return acker(m - 1, acker(m, n - 1));
    }
    //return 0; /* unreachable, but keeps the compiler happy about all paths returning a value */
}

int main() {
    int m, n, z = 0;
    printf("Enter argument 1: ");
    scanf("%d", &m);
    printf("Enter argument 2: ");
    scanf("%d", &n);
    z = acker(m, n);
    printf("\nThe value of Ackermann(%d, %d) is: %d\n", m, n, z);
    return 0;
}