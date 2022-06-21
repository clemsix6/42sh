/*
** EPITECH PROJECT, 2021
** my getnbr
** File description:
** my getnbr
*/

void my_putchar(char c);

int my_getnbr(char const *str)
{
    int res = 0;
    int negative = 0;
    int debut = 0;
    if (*str == '-') {
        negative = 1;
        debut = 1;
    } else if (*str == '+'){
        debut = 1;
    }
    for (int i = debut; str[i] != '\0'; i++) {
        res = res * 10 + str[i] - '0';
    }
    if (negative){
        res = -res;
    }
    return res;
}
