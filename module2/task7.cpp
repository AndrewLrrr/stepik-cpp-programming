/*
В этой задаче вам нужно реализовать функцию resize. Функция resize принимает на вход три аргумента: указатель на
область памяти, выделенную с помощью оператора new[], размер области (size) и новый размер (new_size). Функция должна
выделить память размера new_size, скопировать в нее данные из переданной области памяти, освободить старую область
памяти и вернуть выделенную область памяти нового размера со скопированными данными.

Обратите внимание, что память, возвращенная из функции, будет освобождена с помощью оператора delete[]. Несмотря на то,
что входной тип данных — это const char *, не стоит рассчитывать, что там хранится C-style строка. При выполнении
задания также учтите, что new_size может быть меньше size.

Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции. Вводить или
выводить что-либо не нужно. Определять функцию main не нужно.
*/

#include <iostream>
using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size) {
    char *new_str = new char[new_size];

    for (int i = 0; i < size && i < new_size; i++) {
        new_str[i] = str[i];
    }

    delete[] str;

    return new_str;
}

int main() {
    char *s = new char[strlen("Hello, world!")];
    strcpy(s, "Hello, world!");
    cout << "String: " << s << endl;
    cout << "String size: " << strlen(s) << endl;
    char *t = resize(s, strlen(s), strlen(s) * 2);
    strcpy(t, "Hello, world! My friend!");
    cout << "New string size: " << strlen(t) << endl;
    return 0;
}