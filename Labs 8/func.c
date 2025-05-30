#include "Header.h"

struct polynom* get_list(void)
{
    struct polynom *head, *prev, *current;
    head = prev = NULL;
    char *endptr;
    char input[SIZE];
    fputs("‚ўҐ¤ЁвҐ Ї®Є § вҐ«м бвҐЇҐ­Ё: ", stdout);
    while (s_gets(input, SIZE) != NULL && input[0] != '\0')
    {
        // ‚л¤Ґ«пҐ¬ Ї ¬пвм Ї®¤ бвагЄвгаг(вҐЄгйЁ© гЄ § вҐ«м)
        current = (struct polynom*)malloc(sizeof(struct polynom));
        if (current == NULL)
            exit(1);
        // …б«Ё нв® Є®аҐ­м, в®Ј¤  вҐЄгйЁ© гЄ § вҐ«м - нв® Є®аҐ­м
        if (head == NULL)
            head = current;
        //€­ зҐ жҐЇ«пҐ¬ вҐЄгйЁ© гЄ § вҐ«м Є ЇаҐ¤л¤гйҐ¬г 
        else
            prev->next = current;
        // ‚бҐЈ¤  ЇаҐ¤Ї®«®Ј Ґ¬, зв® Ўг¤гйҐЈ® ¬®¦Ґв ­Ґ Ўлвм 
        current->next = NULL;

        // ЏаҐ®Ўа §гҐв бва®Єг ў long
        // “Є § вҐ«м ­  гЄ § вҐ«м, ­  ЇҐаўл© ­ҐЇаҐ®Ўа §®ў ­­л© бЁ¬ў®« ў бва®ЄҐ
        // …б«Ё гбЇҐе, endptr Ўг¤Ґв гЄ §лў вм ­  б«Ґ¤гойЁ© §  Ї®б«Ґ¤­Ё¬ ЇаҐ®Ўа §®ў ­­л¬ бЁ¬ў®«®¬.
        // Њ®¦ҐвҐ ЇҐаҐ¤ вм NULL
        current->degree = strtol(input, &endptr, 10);
        check_num(endptr, input);

        fputs("‚ўҐ¤ЁвҐ Є®нддЁжЁҐ­в: ", stdout);
        s_gets(input, SIZE);
        current->coeff = strtol(input, &endptr, 10);
        check_num(endptr, input);

        // ЏҐаҐ¤ Ґ¬ вҐЄгйЁ© гЄ § вҐ«м ­  Ўг¤гйҐҐ
        prev = current;
        fputs("‚ўҐ¤ЁвҐ Ї®Є § вҐ«м бвҐЇҐ­Ё (Ё«Ё Їгбвго бва®Єг ¤«п ЇаҐЄа йҐ­Ёп ўў®¤ ): ", stdout);
    }
    return head;
}

void put_list(struct polynom* current)
{
    // ЏҐаў п Їа®ўҐаЄ  ­г¦­  ¤«п Є®ааҐЄв­®Ј® ўлў®¤  ¬­®Ј®з«Ґ­ 
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
        printf("ЌҐ г¤ «®бм ЇаҐ®Ўа §®ў вм бва®Єг ў зЁб«®.\n");
        exit(2);
    }
}

struct polynom* make_polynom(struct polynom* head_L1, struct polynom* head_L2)
{
    struct polynom *head = NULL, *prev = NULL, *current;
    struct polynom *current_L1 = head_L1;
    struct polynom *current_L2 = head_L2;
    int max_deg_L1 = -1;

    // Џ®ЁбЄ н«Ґ¬Ґ­в  б ¬ ЄбЁ¬ «м­л¬ Ї®Є § вҐ«Ґ¬ г ЇҐаў®Ј® Ї®«Ё­®¬ 
    while (current_L1 != NULL)
    {
        if (current_L1->degree > max_deg_L1)
            max_deg_L1 = current_L1->degree;
        current_L1 = current_L1->next;
    }

    //Ѓ®«ми®© жЁЄ« ЎҐ¦Ёв Ї® ўв®а®¬г ¬­®Ј®з«Ґ­г
    while (current_L2 != NULL)
    {
        // …б«Ё ­ и«Ё, в® б®§¤ Ґ¬ ­®ўл© бЇЁб®Є
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