#include <stdio.h>

unsigned long long int faktoriyel(unsigned int sayi) {
    if (sayi == 0) {
        return 1;
    } else {
        return sayi * faktoriyel(sayi - 1);
    }
}

int main() {
    unsigned int sayi;

    printf("Bir sayi girin: ");
    scanf("%u", &sayi);

    unsigned long long int sonuc = faktoriyel(sayi);
    printf("%u! = %llu\n", sayi, sonuc);

    return 0;
}
