#include <stdio.h>
#include <string.h>

int IsPalindrome(char* str) {
    int i, j;
    int length = strlen(str);

    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // Polindrom de�il
        }
    }

    return 1; // Polindrom
}

int main() {
    char str[100];

    printf("Kelimeyi girin: ");
    scanf("%s", str);

    if (IsPalindrome(str)) {
        printf("Girilen kelime bir polindromdur.\n");
    } else {
        printf("Girilen kelime bir polindrom de�ildir.\n");
    }

    return 0;
}
