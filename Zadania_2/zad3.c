#include <stdio.h>

struct Point
{
    float X;
    float Y;
};

struct Rectangle
{
    float A;
    float B;
    
};

void zmien(struct Point *p, float nowyX, float nowyY)
{
    p->X = nowyX;
    p->Y = nowyY;
}
float pole(struct Rectangle r)
{
    float pole = r.A  * r.B;
    printf("Pole wynosi:%f", pole);
    return pole;
}
int main() {
   /*
    - Zdefiniuj strukturę **`Point`**, która przechowuje współrzędne punktu na płaszczyźnie (x, y).
    - Napisz funkcję, która przyjmuje wskaźnik do struktury **`Point`** i zmienia jej wartości współrzędnych.
    - Utwórz instancję **`Point`** i zmień jej współrzędne za pomocą funkcji, a następnie wypisz zmienione współrzędne.
    - Następnie utwórz strukturę `Rectangle`
    - Napisz funkcję, która przyjmuje do struktury `Rectangle` i liczy pole, obwód tej struktury.
   */
   struct Point p1 = {3,2};
   printf("Współrzędne p1: (%.2f, %.2f)\n", p1.X, p1.Y);
   zmien(&p1, 10,2);
   printf("Współrzędne p1: (%.2f, %.2f)\n", p1.X, p1.Y);
   struct Rectangle r1 = {23211,6};
   pole(r1);
   

   
   return 0;
}
