#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    int c;
    c = scanf("%lf%lf", &a, &b);
    if (c==2)
        printf("%lf", pow(a, b));
    return 0;
}
