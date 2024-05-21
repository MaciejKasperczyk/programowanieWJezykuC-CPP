#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca pojedynczy element listy
typedef struct Node {
    int value;          // Wartość przechowywana w węźle
    struct Node *next;  // Wskaźnik na następny element listy
} Node;

// Funkcja usuwająca ostatni element z listy
void remove_last(Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to remove.\n");
        return;
    }
    // Jeśli lista ma tylko jeden element
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    // Znajdowanie przedostatniego elementu
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    // Usunięcie ostatniego elementu
    free(current->next);
    current->next = NULL;
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

    // Przykładowe dodanie elementów do listy
    // Usunięcie ostatniego elementu dla pokazania funkcji
    remove_last(&head); // Usuwanie z pustej listy
    print_list(head);

    return 0;
}
