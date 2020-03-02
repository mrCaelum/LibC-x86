/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** rindex
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef char *(*rindex_t)(const char *, int);

static rindex_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "rindex");
}

Test(rindex, simple)
{
    void *lib = NULL;
    rindex_t rindex_copy = setup(&lib);
    struct {
        char *str;
        int c;
    } tab[] = {
        {"test", 'e'},
        {"ewhfoihew", 'a'},
        {"mdr", 'd'},
        {"qwertyuiop", 't'},
        {"asdfghjkl", 'g'},
        {"zxcvbnm", 'm'},
        {NULL, 0}
    };
    for (unsigned char i = 0; tab[i].str; ++i)
        cr_assert_eq(rindex(tab[i].str, tab[i].c), rindex_copy(tab[i].str, tab[i].c));
    dlclose(lib);
}