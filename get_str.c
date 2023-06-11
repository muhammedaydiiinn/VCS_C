#include <stdio.h>
#include <string.h>

int main() {
    char metin[100];

    printf("Bir kelime veya cumle girin: ");
    fgets(metin, sizeof(metin), stdin);

    // Son karakteri '\n' olan satırı '\0' ile değiştiriyoruz
    metin[strcspn(metin, "\n")] = '\0';

    int uzunluk = strlen(metin);
    printf("Girilen metnin uzunlugu: %d\n", uzunluk);

    return 0;
}
