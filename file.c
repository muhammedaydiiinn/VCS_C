#include <stdio.h>

int main() {
    FILE *dosya;
    char metin[100];

    // Dosyayı yazma modunda aç
    dosya = fopen("metin.txt", "w");

    if (dosya == NULL) {
        printf("Dosya acilamadi.");
        return 1;
    }

    printf("Metin dosyasina yazilacak metni girin: ");
    fgets(metin, sizeof(metin), stdin);

    // Metni dosyaya yaz
    fprintf(dosya, "%s", metin);

    // Dosyayı kapat
    fclose(dosya);

    // Dosyayı okuma modunda aç
    dosya = fopen("metin.txt", "r");

    if (dosya == NULL) {
        printf("Dosya acilamadi.");
        return 1;
    }

    printf("Dosyadan okunan metin:\n");

    // Dosyadan metni oku ve ekrana yazdir
    while (fgets(metin, sizeof(metin), dosya) != NULL) {
        printf("%s", metin);
    }

    // Dosyayı kapat
    fclose(dosya);

    return 0;
}
