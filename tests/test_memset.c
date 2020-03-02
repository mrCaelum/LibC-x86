/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** memset
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef void *(*memset_t)(void *, int, size_t);

static memset_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "memset");
}

Test(memset, simple)
{
    void *lib = NULL;
    memset_t memset_copy = setup(&lib);
    char tab[2][50];

    cr_assert_eq(*(size_t *)memset(tab[0], 1, 50), *(size_t *)memset_copy(tab[1], 1, 50));
    for (unsigned char i = 0; i < 50; ++i)
        cr_assert_eq(tab[0][i], tab[1][i]);
    dlclose(lib);
}