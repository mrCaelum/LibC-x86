/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** strcspn
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef size_t (*strcspn_t)(const char *, const char *);

static strcspn_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "strcspn");
}

Test(strcspn, simple)
{
    void *lib = NULL;
    strcspn_t strcspn_copy = setup(&lib);
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
        cr_assert_eq(strcspn(tab[i][0], tab[i][1]), strcspn_copy(tab[i][0], tab[i][1]));
    dlclose(lib);
}