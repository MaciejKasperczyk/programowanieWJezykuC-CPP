

#include <stdio.h>

float funkcjaKwadrat(float *a)
{
    *a *=2;
    return *a;
}
int main() {
   /*
   - Zdefiniuj funkcję, która przyjmuje wskaźnik do zmiennej typu float i modyfikuje jej wartość (np. podwaja).
   - W funkcji main, utwórz zmienną typu float, przekaż wskaźnik do tej zmiennej do funkcji, a następnie wypisz nową wartość zmiennej.
   */
   float a = 123;
   funkcjaKwadrat(&a);
   printf("%f",a);
   
   return 0;
}
