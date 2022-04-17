#include <stdio.h>

int main() {
    double a, b;
    int c;
    c = scanf("%lf%lf", &a, &b);
    if (c==2)
        printf("%lf", a+b);
    return 0;
}
