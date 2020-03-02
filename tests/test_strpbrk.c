/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** strpbrk
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef char *(*strpbrk_t)(const char *, const char *);

static strpbrk_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "strpbrk");
}

Test(strpbrk, simple)
{
    void *lib = NULL;
    strpbrk_t strpbrk_copy = setup(&lib);
    static const char *tab[][2] = {
        {"test", "test"},
        {"ewhfoihew", ""},
        {"mdr", "dr"},
        {"qwertyuiop", "iopm"},
        {"asdfghjkl", "jkl"},
        {"zxcvbnm", "cvb"},
        {"", "test"},
        {"", ""},
        {NULL, NULL}
    };

    for (unsigned char i = 0; tab[i][0]; ++i)
        cr_assert_eq(strpbrk(tab[i][0], tab[i][1]), strpbrk_copy(tab[i][0], tab[i][1]));
    dlclose(lib);
}