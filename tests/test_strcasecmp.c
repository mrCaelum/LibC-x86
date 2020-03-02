/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** strcasecmp
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef int (*strcasecmp_t)(const char *, const char *);

static strcasecmp_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "strcasecmp");
}

Test(strcasecmp, simple)
{
    void *lib = NULL;
    strcasecmp_t strcasecmp_copy = setup(&lib);
    char *tab[][2] = {
        {"test", "TEST"},
        {"aAbBcC", "aAbBcC"},
        {"123abcABC", "123ABCabc"},
        {"abAB1", "acAC1"},
        {NULL, NULL}
    };

    for (unsigned char i = 0; tab[i][0]; ++i)
        cr_assert_eq(strcasecmp(tab[i][0], tab[i][1]), strcasecmp_copy(tab[i][0], tab[i][1]));
    dlclose(lib);
}