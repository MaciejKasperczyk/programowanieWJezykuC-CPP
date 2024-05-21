#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca pojedynczy element listy
typedef struct Node {
    int value;          // Wartość przechowywana w węźle
    struct Node *next;  // Wskaźnik na następny element listy
} Node;

// Funkcja usuwająca pierwszy element z listy o określonej wartości
void remove_by_value(Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty, nothing to remove.\n");
        return;
    }
    // Specjalny przypadek dla pierwszego elementu
    if ((*head)->value == value) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node *current = *head;
    // Szukamy węzła przed węzłem do usunięcia
    while (current->next != NULL && current->next->value != value) {
        current = current->next;
    }
    if (current->next == NULL) { // Jeśli nie znajdziemy wartości
        printf("Value not found in the list.\n");
        return;
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
    // Usuwanie elementu o określonej wartości
    remove_by_value(&head, 10); // Usuwanie z pustej listy
    print_list(head);

    return 0;
}
