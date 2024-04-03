#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** alokujMacierz(int wiersze, int kolumny) {
    int** macierz = malloc(wiersze * sizeof(int*));
    if (macierz == NULL) {
        printf("Błąd alokacji pamięci dla wierszy.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < wiersze; i++) {
        macierz[i] = malloc(kolumny * sizeof(int));
        if (macierz[i] == NULL) {
            printf("Błąd alokacji pamięci dla kolumn.\n");
            exit(EXIT_FAILURE);
        }
    }

    return macierz;
}

void wypelnijMacierz(int** macierz, int wiersze, int kolumny) {
    srand(time(NULL));

    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = rand() % 100; 
        }
    }
}

void wyswietlMacierz(int** macierz, int wiersze, int kolumny) {
    printf("Zawartość macierzy:\n");
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }
}

void zwolnijMacierz(int** macierz, int wiersze) {
    for (int i = 0; i < wiersze; i++) {
        free(macierz[i]);
    }
    free(macierz);
}

int main() {
    int wiersze, kolumny;

    printf("Podaj liczbę wierszy macierzy: ");
    scanf("%d", &wiersze);
    printf("Podaj liczbę kolumn macierzy: ");
    scanf("%d", &kolumny);

    int** macierz = alokujMacierz(wiersze, kolumny);
    wypelnijMacierz(macierz, wiersze, kolumny);
    wyswietlMacierz(macierz, wiersze, kolumny);
    zwolnijMacierz(macierz, wiersze);

    return 0;
}
