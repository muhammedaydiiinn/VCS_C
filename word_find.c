#include <stdio.h>
#include <string.h>

void findWordsStartingWith(char *metin, char *aranan) {
    int metinUzunluk = strlen(metin);
    int arananUzunluk = strlen(aranan);
    int kelimeBasladi = 0;

    printf("Aranan kelimeyi içeren kelimeler: ");

    for (int i = 0; i < metinUzunluk; i++) {
        if (metin[i] == ' ' || metin[i] == '\t' || metin[i] == '\n') {
            kelimeBasladi = 0;
        } else if (!kelimeBasladi) {
            if (strncmp(&metin[i], aranan, arananUzunluk) == 0) {
                printf("%.*s ", arananUzunluk, &metin[i]);
            }
            kelimeBasladi = 1;
        }
    }

    printf("\n");
}

int main() {
    char metin[] = "Merhaba, dunyada herkes mutlu olmak istemektedir. Mutluluk insanlar icin onemlidir.";
    char aranan[] = "mutlu";

    findWordsStartingWith(metin, aranan);

    return 0;
}
