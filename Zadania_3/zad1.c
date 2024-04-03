#include <stdio.h>

int wspolczynnikDwumianowy(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return wspolczynnikDwumianowy(n - 1, k - 1) + wspolczynnikDwumianowy(n - 1, k);
}

void wyswietlTrojkatPascala(int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", wspolczynnikDwumianowy(i, j));
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Podaj wysokość trójkąta Pascala: ");
    scanf("%d", &N);
    wyswietlTrojkatPascala(N);
    return 0;
}
