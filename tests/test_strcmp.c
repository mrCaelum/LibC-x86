/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** strcmp
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef int (*strcmp_t)(const char *, const char *);

static strcmp_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "strcmp");
}

Test(strcmp, simple)
{
    void *lib = NULL;
    strcmp_t strcmp_copy = setup(&lib);
    char *tab[][2] = {
        {"test", "test"},
        {"ewhfoihew", "ewhfoihew"},
        {"mdr", "nop"},
        {"qwertyuiop", "qwertymdr"},
        {"asdfghjkl", "asdfgghjkl"},
        {"zxcvbnm", "zxcvbnm"},
        {NULL, NULL}
    };

    for (unsigned char i = 0; tab[i][0]; ++i)
        cr_assert_eq(strcmp(tab[i][0], tab[i][1]), strcmp_copy(tab[i][0], tab[i][1]));
    dlclose(lib);
}