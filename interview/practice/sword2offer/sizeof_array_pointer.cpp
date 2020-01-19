#include <stdio.h>
int GetSize(int m[]) {
    return sizeof(m);
}
int main() {
    int d1[] = {1, 2, 3, 4, 5};
    int s1 = sizeof(d1);
    int *d2 = d1;
    int s2 = sizeof(d2);
    int s3 = GetSize(d1);
    printf("%d, %d, %d", s1, s2, s3);
    return 0;
}
