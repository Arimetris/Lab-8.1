#include "Header.h"

struct polynom* get_list(void)
{
    struct polynom* head, * prev, * current;
    head = prev = NULL;
    char* endptr;
    char input[SIZE];
    fputs("Введите показатель степени: ", stdout);
    while (s_gets(input, SIZE) != NULL && input[0] != '\0')
    {
        // Выделяем память под структуру(текущий указатель)
        current = (struct polynom*)malloc(sizeof(struct polynom));
        if (current == NULL)
            exit(1);
        // Если это корень, тогда текущий указатель - это корень
        if (head == NULL)
            head = current;
        //Иначе цепляем текущий указатель к предыдущему 
        else
            prev->next = current;
        // Всегда предпологаем, что будущего может не быть 
        current->next = NULL;

        // Преобразует строку в long
        // Указатель на указатель, на первый непреобразованный символ в строке
        // Если успех, endptr будет указывать на следующий за последним преобразованным символом.
        // Можете передать NULL
        current->degree = strtol(input, &endptr, 10);
        check_num(endptr, input);

        fputs("Введите коэффициент: ", stdout);
        s_gets(input, SIZE);
        current->coeff = strtol(input, &endptr, 10);
        check_num(endptr, input);

        // Передаем текущий указатель на будущее
        prev = current;
        fputs("Введите показатель степени (или пустую строку для прекращения ввода): ", stdout);
    }
    return head;
}

void put_list(struct polynom* current)
{
    // Первая проверка нужна для корректного вывода многочлена
    if (current != NULL)
    {
        printf("(%.0lf)*x^%d", current->coeff, current->degree);
        current = current->next;
    }

    while (current != NULL)
    {
        printf("+(%.0lf)*x^%d", current->coeff, current->degree);
        current = current->next;
    }
    putchar('\n');
}

void check_num(char* endptr, char* str)
{
    if (endptr == str)
    {
        printf("Не удалось преобразовать строку в число.\n");
        exit(2);
    }
}

struct polynom* make_polynom(struct polynom* head_L1, struct polynom* head_L2)
{
    struct polynom* head = NULL, * prev = NULL, * current;
    struct polynom* current_L1 = head_L1;
    struct polynom* current_L2 = head_L2;
    int max_deg_L1 = -1;

    // Поиск элемента с максимальным показателем у первого полинома
    while (current_L1 != NULL)
    {
        if (current_L1->degree > max_deg_L1)
            max_deg_L1 = current_L1->degree;
        current_L1 = current_L1->next;
    }

    //Большой цикл бежит по второму многочлену
    while (current_L2 != NULL)
    {
        // Если нашли, то создаем новый список
        if (current_L2->degree > max_deg_L1)
        {
            current = (struct polynom*)malloc(sizeof(struct polynom));
            if (current == NULL)
                exit(1);

            current->degree = current_L2->degree;
            current->coeff = current_L2->coeff;
            current->next = NULL;

            if (head == NULL)
                head = current;
            else
                prev->next = current;
            current->next = NULL;
            prev = current;
        }
        current_L2 = current_L2->next;
    }

    return head;
}

void clear_list(struct polynom** head)
{
    struct polynom* next_node = NULL;
    while (*head != NULL)
    {
        next_node = (*head)->next;
        free(*head);
        *head = next_node;
    }
}

char* s_gets(char* st, int n)
{
    char* ret_val, * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}