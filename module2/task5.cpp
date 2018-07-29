/*
Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк. Функция конкатенации принимает на вход две
C-style строки и дописывает вторую в конец первой так, чтобы первая строка представляла из себя одну C-style строку
равную конкатенации двух исходных.

Не забудьте, что в результирующей строке должен быть только один нулевой символ — тот, что является маркером конца
строки.

Гарантируется, что в первой строке достаточно памяти (т.е. она располагается в массиве достаточной длины), чтобы
разместить конкатенацию обеих строк, но не больше.

Требования к реализации: при выполнении задания вы можете определять любые вспомогательные функции, если они вам нужны.
Выводить или вводить что-либо не нужно. Функцию main определять не нужно.
*/

#include <stdio.h>

unsigned strlen(const char *str) {
    int len = 0;

    while (true) {
        if (str[len] == '\0') {
            break;
        }
        len += 1;
    }

    return len;
}

void strcat(char *to, const char *from) {
    int len_to = strlen(to);

    while (true) {
        to[len_to] = *from;
        if (*from == '\0') {
            break;
        }
        len_to++;
        from++;
    }
}

int main() {
    char s1[] = "Hello, ";
    char s2[] = "world!";
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);
    strcat(s1, s2);
    printf("Concatenated string: %s\n", s1);
}