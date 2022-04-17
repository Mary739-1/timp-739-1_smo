#include <stdio.h>
#include <stdlib.h>

//Размер массива
int N;

//Меняем местми элементы
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int* a, int n, int i) {
    int max = i; // Максимальный элемент в корне
    int left = 2 * i + 1;//Индекс элемента слева
    int right = 2 * i + 2;//Индекс элемента справа
    if (left < n && a[left] > a[max]){// Если левый больше, то меняем макс на него
        max = left;
    }
    if (right < n && a[right] > a[max]){// Если правый больше, то меняем макс на него
        max = right;
    }
    if (max != i) { // Если самый большой элемент не корень
        swap(&a[i], &a[max]); //меняем местами корень с максимальным
        heapify(a, n, max); // Прогоняем снова для ступени ниже
    }
}

void hps(int* a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--){//Построение кучи (перегруппируем массив)
        heapify(a, n, i);
    }
    
    for (int i = n - 1; i >= 0; i--) { //Один за другим извлекаем элементы из кучи
        swap(&a[0], &a[i]);//Перемещаем текущий корень в конец
        heapify(a, i, 0);//вызываем процедуру heapify на уменьшенной куче
    }
}

void print(int* a){
    for(int i = 0; i < N; i++)
    {
        printf("%i ", a[i]);
    }
}

int main()
{
    scanf("%i", &N);
    int a[N];
    int i;
    for (i = 0; i<N; i++) 
    {
        scanf("%d", &a[i]);
    }
    printf("\n");
    hps(a, N);//сортируем
    print(a);
    return 0;
}
