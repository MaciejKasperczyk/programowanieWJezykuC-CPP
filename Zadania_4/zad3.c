#include <stdio.h>

void zamien(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutuj(int *tablica, int start, int koniec) {
    if (start == koniec) {
        for (int i = 0; i <= koniec; i++)
            printf("%d ", tablica[i]);
        printf("\n");
    } else {
        for (int i = start; i <= koniec; i++) {
            zamien(&tablica[start], &tablica[i]);
            permutuj(tablica, start + 1, koniec);
            zamien(&tablica[start], &tablica[i]);
        }
    }
}

int main() {
    int tablica[] = {1, 2, 3,4,5};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    printf("Wszystkie permutacje ciągu:\n");
    permutuj(tablica, 0, rozmiar - 1);

    return 0;
}
