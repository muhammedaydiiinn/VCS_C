#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düğüm oluşturur
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Bağlı listeye yeni bir düğüm ekler
void append(struct Node** head, int data) {
    struct Node* new_node = newNode(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Bağlı listedeki eleman sayısını bulur
int countElements(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    struct Node* head = NULL;

    // Örnek bağlı listeyi oluştur
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    // Bağlı listedeki eleman sayısını bul
    int elementCount = countElements(head);
    printf("Eleman sayisi: %d\n", elementCount);

    return 0;
}
