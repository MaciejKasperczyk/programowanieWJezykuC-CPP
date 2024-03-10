#include <stdio.h>

int main() {
    char name[10]; 

    printf("Jak masz na imie?: ");
    scanf("%s", name);

    printf("Witaj, %s!\n", name);

    return 0;
}