/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** strchr
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef char *(*strchr_t)(const char *, int);

static strchr_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "strchr");
}

Test(strchr, simple)
{
    void *lib = NULL;
    strchr_t strchr_copy = setup(&lib);
    struct {
        char *str;
        int c;
    } tab[] = {
        {"test", 0},
        {"ewhfoihew", 'a'},
        {"mdr", 'd'},
        {"qwertyuiop", 't'},
        {"asdfghjkl", 'g'},
        {"zxcvbnm", 'm'},
        {"", 'm'},
        {NULL, 0}
    };

    for (unsigned char i = 0; tab[i].str; ++i)
        cr_assert_eq(strchr(tab[i].str, tab[i].c), strchr_copy(tab[i].str, tab[i].c));
    dlclose(lib);
}