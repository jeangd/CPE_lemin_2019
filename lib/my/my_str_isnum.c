/*
** EPITECH PROJECT, 2019
** my str isnum
** File description:
** return a number if the string contain only digits
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] > 47 && str[i] < 58) {
        if (str[i + 1] == '\0' || str[i + 1] == '\n')
            return (0);
        i++;
    }
    return (1);
}
