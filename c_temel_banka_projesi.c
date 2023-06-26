#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KULLANICI_SAYISI 100
#define MAX_AD_UZUNLUGU 50

struct kullanici {
    char ad[MAX_AD_UZUNLUGU];
    int hesap_numarasi;
    double bakiye;
};

void dosyaya_yaz(struct kullanici kullanicilar[], int kullanici_sayisi) {
    FILE *dosya = fopen("kullanicilar.txt", "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi.");
        exit(1);
    }

    for (int i = 0; i < kullanici_sayisi; i++) {
        fprintf(dosya, "%s %d %.2lf\n", kullanicilar[i].ad, kullanicilar[i].hesap_numarasi, kullanicilar[i].bakiye);
    }

    fclose(dosya);
}

struct kullanici *dosya_oku() {
    struct kullanici *kullanicilar = malloc(MAX_KULLANICI_SAYISI * sizeof(struct kullanici));
    FILE *dosya = fopen("kullanicilar.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilamadi.");
        exit(1);
    }

    int kullanici_sayisi = 0;
    while (fscanf(dosya, "%s %d %lf", kullanicilar[kullanici_sayisi].ad, &kullanicilar[kullanici_sayisi].hesap_numarasi, &kullanicilar[kullanici_sayisi].bakiye) != EOF) {
        kullanici_sayisi++;
    }

    fclose(dosya);
    return kullanicilar;
}

void kullanici_ekle(struct kullanici *kullanicilar, int *kullanici_sayisi) {
    char ad[MAX_AD_UZUNLUGU];
    int hesap_numarasi;
    double bakiye;

    printf("Ad: ");
    scanf("%s", ad);

    printf("Hesap Numarasi: ");
    scanf("%d", &hesap_numarasi);

    printf("Bakiye: ");
    scanf("%lf", &bakiye);

    strcpy(kullanicilar[*kullanici_sayisi].ad, ad);
    kullanicilar[*kullanici_sayisi].hesap_numarasi = hesap_numarasi;
    kullanicilar[*kullanici_sayisi].bakiye = bakiye;

    (*kullanici_sayisi)++;

    dosyaya_yaz(kullanicilar, *kullanici_sayisi);
    printf("Kullanici eklendi.\n");
}

void kullanici_sil(struct kullanici *kullanicilar, int *kullanici_sayisi, int hesap_numarasi) {
    int silinecek_index = -1;
    for (int i = 0; i < *kullanici_sayisi; i++) {
        if (kullanicilar[i].hesap_numarasi == hesap_numarasi) {
            silinecek_index = i;
            break;
        }
    }

    if (silinecek_index != -1) {
        for (int i = silinecek_index; i < *kullanici_sayisi - 1; i++) {
            kullanicilar[i] =kullanicilar[i + 1];
}    (*kullanici_sayisi)--;
    dosyaya_yaz(kullanicilar, *kullanici_sayisi);
    printf("Kullanici silindi.\n");
} else {
    printf("Hesap numarasi bulunamadi.\n");
}
}

void bakiye_guncelle(struct kullanici *kullanicilar, int kullanici_sayisi, int hesap_numarasi, double miktar) {
int kullanici_index = -1;
for (int i = 0; i < kullanici_sayisi; i++) {
if (kullanicilar[i].hesap_numarasi == hesap_numarasi) {
kullanici_index = i;
break;
}
}
if (kullanici_index != -1) {
    kullanicilar[kullanici_index].bakiye += miktar;
    dosyaya_yaz(kullanicilar, kullanici_sayisi);
    printf("Bakiye guncellendi.\n");
} else {
    printf("Hesap numarasi bulunamadi.\n");
}
}

void bakiye_goruntule(struct kullanici *kullanicilar, int kullanici_sayisi, int hesap_numarasi) {
int kullanici_index = -1;
for (int i = 0; i < kullanici_sayisi; i++) {
if (kullanicilar[i].hesap_numarasi == hesap_numarasi) {
kullanici_index = i;
break;
}
}
if (kullanici_index != -1) {
    printf("Bakiye: %.2lf\n", kullanicilar[kullanici_index].bakiye);
} else {
    printf("Hesap numarasi bulunamadi.\n");
}
}

void menu_goster() {
printf("1. Kullanici Ekle\n");
printf("2. Kullanici Sil\n");
printf("3. Bakiye Goruntule\n");
printf("4. Bakiye Guncelle\n");
printf("0. Cikis\n");
printf("Seciminizi yapiniz: ");
}

int main() {
struct kullanici *kullanicilar = dosya_oku();
int kullanici_sayisi = 0;
int secim;
int hesap_numarasi;
double miktar;

while (1) {
    menu_goster();
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            kullanici_ekle(kullanicilar, &kullanici_sayisi);
            break;
        case 2:
            printf("Hesap Numarasi: ");
            scanf("%d", &hesap_numarasi);
            kullanici_sil(kullanicilar, &kullanici_sayisi, hesap_numarasi);
            break;
        case 3:
            printf("Hesap Numarasi: ");
            scanf("%d", &hesap_numarasi);
            bakiye_goruntule(kullanicilar, kullanici_sayisi, hesap_numarasi);
            break;
        case 4:
            printf("Hesap Numarasi: ");
            scanf("%d", &hesap_numarasi);
            printf("Miktar: ");
            scanf("%lf", &miktar);
            bakiye_guncelle(kullanicilar, kullanici_sayisi,hesap_numarasi,miktar);
break;
case 0:
printf("Cikis yapiliyor...\n");
free(kullanicilar);
exit(0);
default:
printf("Gecersiz secim. Tekrar deneyin.\n");
break;
}
}
return 0;
}
