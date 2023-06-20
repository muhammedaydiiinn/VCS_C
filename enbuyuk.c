#include <stdio.h>

int main() {
    int dizi[] = {10, 40, 8, 20, 15}; // Örnek dizi
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]); // Dizi uzunluğunu hesapla
    int enBuyuk = dizi[0]; // Başlangıçta en büyük değeri ilk eleman olarak varsayalım

    // Diziyi tarayarak en büyük sayıyı bulalım
    for (int i = 1; i < uzunluk; i++) {
        if (dizi[i] > enBuyuk) {
            enBuyuk = dizi[i];
        }
    }

    printf("En buyuk sayi: %d\n", enBuyuk);

    return 0;
}