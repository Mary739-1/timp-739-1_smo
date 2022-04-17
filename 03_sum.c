#include <stdio.h>

int main()
{
    int n = 0;
    int x = 0;
    double s = 0;
    (void)scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++)
    {
        (void)scanf("%d", &x);
        s = s + x;
    }
    printf("%lf\n", s);
    return 0;
}
