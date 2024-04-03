#include <stdio.h>

// Funkcja rekurencyjnego wyszukiwania binarnego
int wyszukiwanieBinarne(int tab[], int lewy, int prawy, int x) {
    if (prawy >= lewy) {
        int srodek = lewy + (prawy - lewy) / 2;

        // Jeśli element znajduje się w środku
        if (tab[srodek] == x)
            return srodek;

        // Jeśli element jest mniejszy od środkowego, szukamy w lewej połowie
        if (tab[srodek] > x)
            return wyszukiwanieBinarne(tab, lewy, srodek - 1, x);

        // W przeciwnym razie szukamy w prawej połowie
        return wyszukiwanieBinarne(tab, srodek + 1, prawy, x);
    }

    // Jeśli element nie jest obecny w tablicy
    return -1;
}

int main() {
    int tablica[] = {2, 3, 4, 10, 40};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    int szukanaWartosc = 10;
    int wynik = wyszukiwanieBinarne(tablica, 0, rozmiar - 1, szukanaWartosc);
    if (wynik == -1)
        printf("Element %d nie został znaleziony w tablicy.\n", szukanaWartosc);
    else
        printf("Element %d został znaleziony na indeksie %d.\n", szukanaWartosc, wynik);
    return 0;
}
