#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char imie[50];
    float ocena;
} Student;

void sortujStudentow(Student *tablica, int rozmiar) {
    int i, j;
    Student temp;
    
    for (i = 1; i < rozmiar; i++) {
        temp = tablica[i];
        j = i - 1;
        
        while (j >= 0 && tablica[j].ocena < temp.ocena) {
            tablica[j + 1] = tablica[j];
            j--;
        }
        
        tablica[j + 1] = temp;
    }
}

int main() {
    int ilosc_studentow = 100;
    Student lista_studentow[100];

    for (int i = 0; i < ilosc_studentow; i++) {
        sprintf(lista_studentow[i].imie, "Student%d", i+1); 
        lista_studentow[i].ocena = rand() % 101; 
    )

    sortujStudentow(lista_studentow, ilosc_studentow);

    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < ilosc_studentow; i++) {
        printf("Imie: %s, Ocena: %.2f\n", lista_studentow[i].imie, lista_studentow[i].ocena);
    }

    return 0;
}
