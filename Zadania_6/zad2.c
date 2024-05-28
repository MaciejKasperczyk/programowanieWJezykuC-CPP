#include <stdio.h>

int main() {
    int numbers[10];
    int *ptr;

    // Inicjalizacja tablicy wartościami od 0 do 9
    for (int i = 0; i < 10; i++) {
        numbers[i] = i;
    }

    // Użycie wskaźnika do wyświetlenia każdego elementu tablicy
    ptr = numbers; // ustawienie wskaźnika na początek tablicy
    for (int i = 0; i < 10; i++) {
        printf("%d ", *ptr);
        ptr++; // inkrementacja wskaźnika
    }

    printf("\n");
    return 0;
}