// czesc pierwsza
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Nie można otworzyć pliku.\n");
        return 1;
    }

    char line[256];
    int total_energy = 0;

    while (fgets(line, sizeof(line), file)) {
        int first_digit = -1;
        int last_digit = -1;

        for (int i = 0; line[i] != '\0'; i++) {
            if (isdigit(line[i])) {
                if (first_digit == -1) {
                    first_digit = line[i] - '0';
                }
                last_digit = line[i] - '0';
            }
        }

        if (first_digit != -1 && last_digit != -1) {
            int energy_value = first_digit * 10 + last_digit;
            total_energy += energy_value;
        }
    }

    fclose(file);
    printf("Suma wartości energetycznych: %d\n", total_energy);

    return 0;
}
/* 

czesc druga:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_digit_from_word(const char *word) {
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1;
}

int get_digit(const char *line, int start, int end) {
    char buffer[6];
    int j = 0;
    for (int i = start; i <= end && j < 5; i++) {
        if (isalpha(line[i])) {
            buffer[j++] = line[i];
        } else {
            if (j > 0) {
                buffer[j] = '\0';
                int digit = get_digit_from_word(buffer);
                if (digit != -1) return digit;
                j = 0;
            }
        }
    }
    buffer[j] = '\0';
    return get_digit_from_word(buffer);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Nie można otworzyć pliku.\n");
        return 1;
    }

    char line[256];
    int total_energy = 0;

    while (fgets(line, sizeof(line), file)) {
        int first_digit = -1;
        int last_digit = -1;

        for (int i = 0; line[i] != '\0'; i++) {
            if (isdigit(line[i])) {
                if (first_digit == -1) {
                    first_digit = line[i] - '0';
                }
                last_digit = line[i] - '0';
            } else if (isalpha(line[i])) {
                int digit = get_digit(line, i, i+4);
                if (digit != -1) {
                    if (first_digit == -1) {
                        first_digit = digit;
                    }
                    last_digit = digit;
                    i += strlen("nine") - 1; // skip the word length
                }
            }
        }

        if (first_digit != -1 && last_digit != -1) {
            int energy_value = first_digit * 10 + last_digit;
            total_energy += energy_value;
        }
    }

    fclose(file);
    printf("Suma wartości energetycznych: %d\n", total_energy);

    return 0;
}


*/