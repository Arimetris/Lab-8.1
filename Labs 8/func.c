#include "Header.h"

struct polynom* get_list(void)
{
    struct polynom *head, *prev, *current;
    head = prev = NULL;
    char *endptr;
    char input[SIZE];
    fputs("?�?��? �?��?��??� ��?�??�: ", stdout);
    while (s_gets(input, SIZE) != NULL && input[0] != '\0')
    {
        // ?��??�?? ��?��� �?� ����򢣠�(�?��? ���?��??�)
        current = (struct polynom*)malloc(sizeof(struct polynom));
        if (current == NULL)
            exit(1);
        // ?�?� ��? �?�??�, �??�� �?��? ���?��??� - ��? �?�??�
        if (head == NULL)
            head = current;
        //??��? �?�?�?? �?��? ���?��??� � ��?�����??� 
        else
            prev->next = current;
        // ?�??�� ��?��????�??, ��? �����??? ????� ?? ���� 
        current->next = NULL;

        // ?�??���?�?� ���?� � long
        // ?��?��??� ?� ���?��??�, ?� �?���? ??��??���??��??�? ��?�?? � ���?�?
        // ?�?� ���?�, endptr ���?� ���?����� ?� �??�����? ?� �?�??�?�? ��??���??��??�? ��?�????.
        // ????�? �?�?���� NULL
        current->degree = strtol(input, &endptr, 10);
        check_num(endptr, input);

        fputs("?�?��? �?�����??�: ", stdout);
        s_gets(input, SIZE);
        current->coeff = strtol(input, &endptr, 10);
        check_num(endptr, input);

        // ??�?��?? �?��? ���?��??� ?� �����??
        prev = current;
        fputs("?�?��? �?��?��??� ��?�??� (�?� ������ ���?� �?� ��?���??� ��?��): ", stdout);
    }
    return head;
}

void put_list(struct polynom* current)
{
    // ??���� ��?�?��� ?�??� �?� �?��?�???? ���?�� ?????�???�
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
        printf("?? ���??�� ��??���??���� ���?� � ��??.\n");
        exit(2);
    }
}

struct polynom* make_polynom(struct polynom* head_L1, struct polynom* head_L2)
{
    struct polynom *head = NULL, *prev = NULL, *current;
    struct polynom *current_L1 = head_L1;
    struct polynom *current_L2 = head_L2;
    int max_deg_L1 = -1;

    // ??�� �?????�� � ?���?�?�?�? �?��?��???? � �?��??? �??�???�
    while (current_L1 != NULL)
    {
        if (current_L1->degree > max_deg_L1)
            max_deg_L1 = current_L1->degree;
        current_L1 = current_L1->next;
    }

    //???��?? ���? �??� �? ��?�??� ?????�???�
    while (current_L2 != NULL)
    {
        // ?�?� ?��?�, �? �??��?? ??��? ���?�
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