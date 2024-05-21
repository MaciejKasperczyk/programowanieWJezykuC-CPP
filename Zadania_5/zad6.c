#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca pojedynczy element listy
typedef struct Node {
    int value;          // Wartość przechowywana w węźle
    struct Node *next;  // Wskaźnik na następny element listy
} Node;

// Funkcja dodająca element na określonym indeksie
void insert_at_index(Node **head, int value, int index) {
    if (index < 0) {
        printf("Index cannot be negative.\n");
        return;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        return;
    }
    new_node->value = value;

    if (index == 0) { // Wstawienie na początku listy
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
        if (current == NULL) {
            printf("Index out of bounds.\n");
            free(new_node);
            return;
        }
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

// Funkcja do wyświetlania listy
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Główna funkcja programu
int main() {
    Node *head = NULL; // Początek listy

    // Przykładowe dodanie elementów na określonym indeksie
    insert_at_index(&head, 10, 0); // Dodanie na początku
    insert_at_index(&head, 20, 1); // Dodanie na indeksie 1
    insert_at_index(&head, 30, 1); // Dodanie na indeksie 1, przesuwa 20 na indeks 2

    print_list(head);

    return 0;
}
