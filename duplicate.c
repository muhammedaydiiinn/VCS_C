#include <stdio.h>

void findDuplicates(int arr[], int size) {
    printf("Tekrar eden elemanlar: ");

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                break;
            }
        }
    }

    printf("\n");
}

int main() {
    int dizi[] = {1, 2, 3, 2, 4, 5, 3, 6, 7, 8, 1, 9, 5};
    int uzunluk = sizeof(dizi) / sizeof(dizi[0]);

    findDuplicates(dizi, uzunluk);

    return 0;
}
