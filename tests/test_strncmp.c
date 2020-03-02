/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** strncmp
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef int (*strncmp_t)(const char *, const char *, size_t);

static strncmp_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "strncmp");
}

Test(strncmp, simple)
{
    void *lib = NULL;
    strncmp_t strncmp_copy = setup(&lib);
    struct {
        const char *s1;
        const char *s2;
        size_t n;
    } tab[] = {
        {"test", "test", 3},
        {"ewhfoihew", "ewhfoihew", 7},
        {"mdr", "nop", 7},
        {"abc", "ab", 10},
        {"ab", "abc", 10},
        {"bite", "bit", 4},
        {NULL, NULL, 0}
    };

    for (unsigned char i = 0; tab[i].s1; ++i)
        cr_assert_eq(strncmp(tab[i].s1, tab[i].s2, tab[i].n), strncmp_copy(tab[i].s1, tab[i].s2, tab[i].n));
    dlclose(lib);
}