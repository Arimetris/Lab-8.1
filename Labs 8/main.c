#include "Header.h"

// ‡ Їа иЁў Ґв 2 Ї®«Ё­®¬  Ё ўлў®¤Ёв ®¤Ё­, Є®в®ал© б®бв®Ёв Ё§ вҐе б« Ј Ґ¬ле ўв®а®Ј® Ї®«Ё­®¬  г Є®в®але Ї®Є § вҐ«м бвҐЇҐ­Ё > зҐ¬ ўбҐ г ЇҐаў®Ј®
int main(void)
{
    setlocale(LC_ALL, "rus");
    struct polynom *head_L1, *head_L2, *head_L;

    head_L1 = get_list();
    head_L2 = get_list();

    if (head_L1 == NULL || head_L2 == NULL)
        puts("„ ­­лҐ ­Ґ ўўҐ¤Ґ­л");
    else
        puts("‘ЇЁб®Є Ї®«Ё­®¬®ў: ");

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
