/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** strstr
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef char *(*strstr_t)(const char *, const char *);

static strstr_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "strstr");
}

Test(strstr, simple)
{
    void *lib = NULL;
    strstr_t strstr_copy = setup(&lib);
    static const char *tab[][2] = {
        {"test", "test"},
        {"ewhfoihew", ""},
        {"mdr", "dr"},
        {"qwertyuiop", "iopm"},
        {"asdfghjkl", "jklm"},
        {"zxcvbnm", "cvb"},
        {"", "test"},
        {"", ""},
        {NULL, NULL}
    };

    for (unsigned char i = 0; tab[i][0]; ++i)
        cr_assert_eq(strstr(tab[i][0], tab[i][1]), strstr_copy(tab[i][0], tab[i][1]));
    dlclose(lib);
}