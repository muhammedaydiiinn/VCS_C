#include <stdio.h>

int main() {
    int sayi1, sayi2;
    int *ptr1, *ptr2;

    sayi1 = 10;
    sayi2 = 20;

    ptr1 = &sayi1;
    ptr2 = &sayi2;

    printf("Sayi 1: %d\n", *ptr1);
    printf("Sayi 2: %d\n", *ptr2);

    return 0;
}
