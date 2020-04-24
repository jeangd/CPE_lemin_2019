/*
** EPITECH PROJECT, 2019
** hexa
** File description:
** hexa
*/

void my_putchar(char n);

unsigned int my_put_nbr_hexa(unsigned int nbr)
{
    char nb[32];
    int i = 0;
    int rest = 0;

    while (nbr > 0) {
        rest = nbr % 16;
        if (rest < 10)
            nb[i] = rest + '0';
        else
            nb[i] = 'A' + (rest - 10);
        nbr /= 16;
        i++;
    }
    while (i--)
        my_putchar(nb[i]);
    return (0);
}
