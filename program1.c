#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double x_start, x_end, dx;

    printf("Введите a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    printf("Введите Xнач, Xкон, dX: ");
    if (scanf("%lf %lf %lf", &x_start, &x_end, &dx) != 3) return 1;

    if (dx <= 0) {
    printf("Ошибка: dX должен быть больше 0.\n");
    return 1;
    }

    int A_c = (int)a;
    int B_c = (int)b;
    int C_c = (int)c;

    int is_real = ((A_c & B_c) ^ C_c) != 0;

    printf("\n---------------------------\n");
    printf("|     X      |      F     |\n");
    printf("---------------------------\n");

    for (double x = x_start; x <= x_end + 1e-9; x += dx) {
        double F = 0;
        int valid = 1;

        if (x < 1.0 && c != 0.0) {
            F = a * x * x + (b / c);
        } 
        else if (x > 1.5 && c == 0.0) {
            
            F = (x - a) / ((x - c)*(x - c));
        } 
        else {
            if (c == 0.0) {
                valid = 0; 
            } else {
                F = (x * x) / (c * c);
            }
        }

        if (!valid) {
            printf("| %10.4lf |  Деление на 0  |\n", x);
        } else {
            if (is_real) {
                printf("| %10.4lf | %10.4lf |\n", x, F);
            } else {
                printf("| %10.4lf | %10ld |\n", x, (long)F);
            }
        }
    }

    printf("---------------------------\n");
    return 0;
}