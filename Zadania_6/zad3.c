#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int (*operation)(int, int);
    int choice, a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Choose operation:\n1. Add\n2. Subtract\n3. Multiply\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = subtract;
            break;
        case 3:
            operation = multiply;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("Result: %d\n", operation(a, b));
    return 0;
}