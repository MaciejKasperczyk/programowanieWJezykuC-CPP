#include <stdio.h>
int main() {
    /*
    - Zadeklaruj zmienną typu **`int`** i przypisz jej wartość.
    - Utwórz wskaźnik do tej zmiennej.
    - Zmodyfikuj wartość zmiennej za pomocą wskaźnika.
    - Wypisz wartość zmiennej na dwa sposoby: bezpośrednio i przez wskaźnik.
    */
    int a = 10;
    int *wskaznik = &a;
    *wskaznik = 15;
    
    printf("%d \n",a);
    printf("%d",*wskaznik);
    
    return 0;
}
