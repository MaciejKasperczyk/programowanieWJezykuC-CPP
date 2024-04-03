#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Podaj liczbę całkowitą: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Nie można obliczyć silni z liczby ujemnej.\n");
        return 1; 
    }
    
    printf("Silnia z %d wynosi: %d\n", n, factorial(n));
    return 0;
}
