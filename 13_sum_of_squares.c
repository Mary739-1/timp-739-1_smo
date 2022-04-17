#include <stdio.h>

int main()
{
    int n = 0, x = 0, i;
    double s = 0;
    (void)scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        (void)scanf("%d", &x);
        s = s + x * x;
    }
    printf("%lf\n", s);
    return 0;
}
