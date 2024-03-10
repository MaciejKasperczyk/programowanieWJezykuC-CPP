#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_SUBJECTS 2

int main() {
    int grades[NUM_SUBJECTS][NUM_STUDENTS];
    float averages[NUM_SUBJECTS] = {0};

    printf("Podaj oceny z matematyki:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Uczen %d: ", i + 1);
        scanf("%d", &grades[0][i]);
    }

    printf("Podaj oceny z fizyki:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Uczen %d: ", i + 1);
        scanf("%d", &grades[1][i]);
    }

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        for (int j = 0; j < NUM_STUDENTS; j++) {
            averages[i] += grades[i][j];
        }
        averages[i] /= NUM_STUDENTS;
    }

    printf("\nSrednia ocen z matematyki: %.2f\n", averages[0]);
    printf("Srednia ocen z fizyki: %.2f\n", averages[1]);

    return 0;
}