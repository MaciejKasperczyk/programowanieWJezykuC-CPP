#include <stdio.h>

int sumMultiples(int number) {
    if (number < 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    int number;
    printf("Podaj liczbe: ");
    scanf("%d", &number);

    int result = sumMultiples(number);
    printf("Suma wielokrotnosci 3 lub 5 ponizej %d wynosi: %d\n", number, result);

    return 0;
}