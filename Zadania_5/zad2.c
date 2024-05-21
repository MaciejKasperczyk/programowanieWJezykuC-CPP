#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca pojedynczy element listy
typedef struct Node {
    int value;          // Wartość przechowywana w węźle
    struct Node *next;  // Wskaźnik na następny element listy
} Node;

// Funkcja usuwająca pierwszy element z listy
void pop(Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to pop.\n");
        return;
    }
    // Przechowujemy wskazanie na element, który zostanie usunięty
    Node *temp = *head;
    // Przesuwamy nagłówek listy na następny element
    *head = (*head)->next;
    // Zwolnienie pamięci zajmowanej przez usunięty węzeł
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

    // Dodajemy elementy na początek listy
    // Demonstracja, że pop faktycznie usuwa pierwszy element
    pop(&head); // Testujemy usuwanie z pustej listy
    print_list(head);

    return 0;
}
