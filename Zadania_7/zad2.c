#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

int parse_number(const char *str, const char *color) {
    char *pos = strstr(str, color);
    if (!pos) return 0;
    int num;
    sscanf(pos - 2, "%d", &num); // zakładamy, że liczba jest maksymalnie dwucyfrowa
    return num;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Nie można otworzyć pliku.\n");
        return 1;
    }

    char line[MAX_LINE];
    int game_id;
    int possible_game_sum = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Gra ", 4) == 0) {
            sscanf(line, "Gra %d:", &game_id);
        } else {
            int max_red = 0, max_green = 0, max_blue = 0;
            char *token = strtok(line, ";");

            while (token) {
                int red = parse_number(token, "czerwonych");
                int green = parse_number(token, "zielonych");
                int blue = parse_number(token, "niebieskich");

                if (red > max_red) max_red = red;
                if (green > max_green) max_green = green;
                if (blue > max_blue) max_blue = blue;

                token = strtok(NULL, ";");
            }

            if (max_red <= 12 && max_green <= 13 && max_blue <= 14) {
                possible_game_sum += game_id;
            }
        }
    }

    fclose(file);
    printf("Suma możliwych identyfikatorów gier: %d\n", possible_game_sum);

    return 0;
}

/* 

czesc druga

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

int parse_number(const char *str, const char *color) {
    char *pos = strstr(str, color);
    if (!pos) return 0;
    int num;
    sscanf(pos - 2, "%d", &num); // zakładamy, że liczba jest maksymalnie dwucyfrowa
    return num;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Nie można otworzyć pliku.\n");
        return 1;
    }

    char line[MAX_LINE];
    int game_id;
    int total_power = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Gra ", 4) == 0) {
            sscanf(line, "Gra %d:", &game_id);
        } else {
            int max_red = 0, max_green = 0, max_blue = 0;
            char *token = strtok(line, ";");

            while (token) {
                int red = parse_number(token, "czerwonych");
                int green = parse_number(token, "zielonych



*/