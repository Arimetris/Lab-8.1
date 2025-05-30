#include "Header.h"

// Запрашивает 2 полинома и выводит полином, который состоит из тех слагаемых второго полинома у которых показатель степени > чем все у первого
int main(void)
{
    setlocale(LC_ALL, "rus");
    struct polynom *head_L1, *head_L2, *head_L;

    head_L1 = get_list();
    head_L2 = get_list();

    if (head_L1 == NULL || head_L2 == NULL)
        puts("Данные не введены");
    else
        puts("Список полиномов: ");

    fputs("L1: ", stdout);
    put_list(head_L1);
    fputs("L2: ", stdout);
    put_list(head_L2);

    head_L = make_polynom(head_L1, head_L2);

    fputs("L: ", stdout);
    put_list(head_L);

    clear_list(&head_L);
    clear_list(&head_L1);
    clear_list(&head_L2);

    return 0;
}
