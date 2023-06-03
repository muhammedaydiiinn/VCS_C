#include <stdio.h>
#include <string.h>

void ReverseText(char* str) {
    int i, j;
    char temp;
    int length = strlen(str);

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[100];

    printf("Metni girin: ");
    fgets(str, sizeof(str), stdin);

    // fgets fonksiyonu sonuna bir newline karakteri eklediðinden, onu kaldýrýyoruz
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    ReverseText(str);

    printf("Ters çevrilmiþ metin: %s\n", str);

    return 0;
}
