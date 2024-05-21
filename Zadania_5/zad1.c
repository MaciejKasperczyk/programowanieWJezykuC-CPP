#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca pojedynczy element listy
typedef struct Node {
    int value;          // Wartość przechowywana w węźle
    struct Node *next;  // Wskaźnik na następny element listy
} Node;

// Funkcja dodająca element na początek listy
void add_first(Node **head, int value) {
    // Tworzymy nowy węzeł
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        return;
    }
    // Ustawiamy wartość i wskazujemy na obecny pierwszy element
    new_node->value = value;
    new_node->next = *head;
    // Nowy węzeł staje się nowym początkiem listy
    *head = new_node;
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

    // Dodajemy elementy na początek listy
    add_first(&head, 10);
    add_first(&head, 20);
    add_first(&head, 30);

    // Wyświetlamy całą listę
    print_list(head);

    return 0;
}
