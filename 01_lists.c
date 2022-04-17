#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list {
	struct node *head;  // начало списка
} list;

typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
} node;


// инициализация пустого списка
void init(list *l)
{
    l->head = NULL;//первый узел списка
}

// удалить все элементы из списка
void clean(list *l)
{
    node* tmp = l->head;
    while (tmp->next != NULL) 
    {
        node* i = tmp;
        tmp = tmp->next;
        free(i);
    }
    free(tmp);
    l->head = NULL;
}

// проверка на пустоту списка
bool is_empty(list *l)
{
    if (l->head == NULL) return 1;
    else return 0;
}

// поиск элемента по значению. вернуть NULL если элемент не найден
node *find(list *l, int data)
{
    struct node* Temp;
    Temp = l->head;
    if (Temp->value == data) return Temp;
    while (Temp->next) 
    {
        Temp = Temp->next;
        if (Temp->value == data) return Temp;
    }
    return NULL;
}

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = data;
    new_node->next = NULL;
    struct node* Temp;
    Temp = l->head;
    if (l->head == NULL) l->head = new_node;
    else
    {
        while (Temp->next) 
        {
            Temp = Temp->next;
        }
        Temp->next = new_node;
    }
    return 0;
}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = data;
    new_node->next = NULL;
    struct node* Temp;
    Temp = l->head;
    if (l->head == NULL) l->head = new_node;
    else {
        new_node->next = Temp;
        l->head = new_node;
    }
    return 0;
}

struct node* findk(struct list* l, int n)
{
    int i = 0;
    struct node* Temp = l->head;
    while (Temp->next != NULL) {
        if (i == n) return Temp;
        Temp = Temp->next;
        i++;
    }
    if (i == n) {
        return Temp;
    }
    return NULL;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int data)
{
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = data;
    new_node->next = n->next;
    n->next = new_node;
    return 0;
}

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_node(list *l, int data)
{
    node* tmp = l->head;
    node* prev = NULL;
    while (tmp->next != NULL)
    {
        if (l->head->value == data) {
            l->head = tmp->next;
            free(tmp);
            return 0;
        }
        if (tmp->value == data){
            prev->next = tmp->next;
            free(tmp);
            return 0;
        }
    prev = tmp;
    tmp = tmp->next;
    }

    if ((tmp->next == NULL) && (tmp->value == data))
    {
        prev->next = NULL;
        free(tmp);
        return 0;
    }
    return 1;
}

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l)
{
    struct node* tmp;
    tmp = l->head;
    while (tmp)
    {
    printf("%d ", tmp->value);
    tmp = tmp->next;
    }
    printf("\n");
}


int main()
{
    int i, n, x, k1, k2, k3;
    struct list p;
    init (&p);
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        push_back(&p, x);
    }
    print(&p);
    struct node* b;
    scanf("%d %d %d", &k1, &k2, &k3);
    b = find(&p, k1);
    if (b != NULL) k1 = 1;
        else k1 = 0;
    b = find(&p, k2);
    if (b != NULL) k2 = 1;
        else k2 = 0;
    b = find(&p, k3);
    if (b != NULL) k3 = 1;
        else k3 = 0;
    printf("%d %d %d\n", k1, k2, k3);
    scanf("%d", &x);
    push_back(&p, x);
    print(&p);
    scanf("%d", &x);
    push_front(&p, x);
    print(&p);
    scanf("%d %d", &n, &x);
    b = findk(&p, n - 1);
    insert_after(b, x);
    print(&p);
    scanf("%d", &x);
    remove_node(&p, x);
    print(&p);
    clean(&p);
    return 0;
}
