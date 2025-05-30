#include "Header.h"

struct polynom* get_list(void)
{
    struct polynom *head, *prev, *current;
    head = prev = NULL;
    char *endptr;
    char input[SIZE];
    fputs("?÷?ýð¢? ô?òÿ?ÿ¢??¬ ¡¢?ô??ð: ", stdout);
    while (s_gets(input, SIZE) != NULL && input[0] != '\0')
    {
        // ?«ý??¯?? ôÿ?¯¢¬ ô?ý ¡¢ £ò¢£ £(¢?ò£©ð? £òÿ?ÿ¢??¬)
        current = (struct polynom*)malloc(sizeof(struct polynom));
        if (current == NULL)
            exit(1);
        // ?¡?ð ­¢? ò? ??¬, ¢??ýÿ ¢?ò£©ð? £òÿ?ÿ¢??¬ - ­¢? ò? ??¬
        if (head == NULL)
            head = current;
        //??ÿ§? ¦?ô?¯?? ¢?ò£©ð? £òÿ?ÿ¢??¬ ò ô ?ý«ý£©??£ 
        else
            prev->next = current;
        // ?¡??ýÿ ô ?ýô????ÿ??, §¢? ö£ý£©??? ????¢ ?? ö«¢¬ 
        current->next = NULL;

        // ? ??ö ÿ?£?¢ ¡¢ ?ò£ ÷ long
        // ?òÿ?ÿ¢??¬ ?ÿ £òÿ?ÿ¢??¬, ?ÿ ô? ÷«? ??ô ??ö ÿ??÷ÿ??«? ¡ð?÷?? ÷ ¡¢ ?ò?
        // ?¡?ð £¡ô?¥, endptr ö£ý?¢ £òÿ?«÷ÿ¢¬ ?ÿ ¡??ý£®©ð? ?ÿ ô?¡??ý?ð? ô ??ö ÿ??÷ÿ??«? ¡ð?÷????.
        // ????¢? ô? ?ýÿ¢¬ NULL
        current->degree = strtol(input, &endptr, 10);
        check_num(endptr, input);

        fputs("?÷?ýð¢? ò?­¤¤ð¦ð??¢: ", stdout);
        s_gets(input, SIZE);
        current->coeff = strtol(input, &endptr, 10);
        check_num(endptr, input);

        // ?? ?ýÿ?? ¢?ò£©ð? £òÿ?ÿ¢??¬ ?ÿ ö£ý£©??
        prev = current;
        fputs("?÷?ýð¢? ô?òÿ?ÿ¢??¬ ¡¢?ô??ð (ð?ð ô£¡¢£® ¡¢ ?ò£ ý?¯ ô ?ò ÿ©??ð¯ ÷÷?ýÿ): ", stdout);
    }
    return head;
}

void put_list(struct polynom* current)
{
    // ?? ÷ÿ¯ ô ?÷? òÿ ?£??ÿ ý?¯ ò?  ?ò¢???? ÷«÷?ýÿ ?????§???ÿ
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
        printf("?? £ýÿ??¡¬ ô ??ö ÿ??÷ÿ¢¬ ¡¢ ?ò£ ÷ §ð¡??.\n");
        exit(2);
    }
}

struct polynom* make_polynom(struct polynom* head_L1, struct polynom* head_L2)
{
    struct polynom *head = NULL, *prev = NULL, *current;
    struct polynom *current_L1 = head_L1;
    struct polynom *current_L2 = head_L2;
    int max_deg_L1 = -1;

    // ??ð¡ò ­?????¢ÿ ¡ ?ÿò¡ð?ÿ?¬?«? ô?òÿ?ÿ¢???? £ ô? ÷??? ô??ð???ÿ
    while (current_L1 != NULL)
    {
        if (current_L1->degree > max_deg_L1)
            max_deg_L1 = current_L1->degree;
        current_L1 = current_L1->next;
    }

    //???¬¨?? ¦ðò? ö??ð¢ ô? ÷¢? ??£ ?????§???£
    while (current_L2 != NULL)
    {
        // ?¡?ð ?ÿ¨?ð, ¢? ¡??ýÿ?? ??÷«? ¡ôð¡?ò
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