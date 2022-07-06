/*
** EPITECH PROJECT, 2018
** getnbr
** File description:
** getnbr
*/

#include <unistd.h>
#include <stdio.h>

int getnbr(char *str)
{
    int retenu = 1;
    int res = 0;
    int a = 0;

    for (; str[a] >= 48 && str[a] <= 57; a++);
    a--;
    for (; a >= 0; a--) {
        res = res + ((str[a] - 48) * retenu);
        retenu = retenu * 10;
    }
    return (res);
}
