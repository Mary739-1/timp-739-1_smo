#include <stdio.h>
#include <stdlib.h>

int N = 0; //размер массива

void print(int* x, int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", x[i]);
    printf("\n");
}

void qst(int* a, int low, int high){
    int temp;
    int pivot = a[low + (high - low) / 2];
    int i = low;
    int j = high;
    while (i <= j)
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < high)
        qst(a, i, high);
    if (low < j)
        qst(a, low, j);
}

int main()
{
    (void)scanf(" %i", &N); //задаём размер массива
    int a[N];// объявлен массив a из N элементов
    int o; 
    for (o = 0; o < N; o++) 
    {
        scanf("%d", &a[o]); 
    }
    qst(a, 0, N-1);
    print(a, N);
    return 0;
}
