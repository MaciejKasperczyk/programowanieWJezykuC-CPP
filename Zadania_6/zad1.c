#include <stdio.h>

union Data {
    int num;
    float flt;
    char chr;
};

int main() {
    union Data data;

    // Przechowywanie i wyświetlanie wartości typu int
    data.num = 100;
    printf("Data as integer: %d\n", data.num);

    // Przechowywanie i wyświetlanie wartości typu float
    data.flt = 123.456;
    printf("Data as float: %f\n", data.flt);

    // Przechowywanie i wyświetlanie wartości typu char
    data.chr = 'A';
    printf("Data as char: %c\n", data.chr);

    return 0;
}
