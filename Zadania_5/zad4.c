#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca pojedynczy element listy
typedef struct Node {
    int value;          // Wartość przechowywana w węźle
    struct Node *next;  // Wskaźnik na następny element listy
} Node;

// Funkcja usuwająca element z listy po indeksie
void remove_by_index(Node **head, int index) {
    if (*head == NULL) {
        printf("List is empty, nothing to remove.\n");
        return;
    }
    if (index == 0) { // Usuwamy pierwszy element
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *current = *head;
    int i = 0;
    // Szukamy węzła przed węzłem do usunięcia
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
        if (current == NULL || current->next == NULL) {
            printf("Index out of bounds.\n");
            return;
        }
    }
    // Usuwamy węzeł
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
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
    // Usuwanie elementu o określonym indeksie
    remove_by_index(&head, 1); // Usuwanie z pustej listy
    print_list(head);

    return 0;
}
