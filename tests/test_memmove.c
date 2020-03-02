/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** memmove
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef void *(*memmove_t)(void *, const void *, size_t);

static memmove_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "memmove");
}

Test(memmove, simple)
{
    void *lib = NULL;
    memmove_t memmove_copy = setup(&lib);
    char *src = "qwertyuiopasdfgjklzxcvbnm";
    char dest[2][26];

    cr_assert_eq(*(size_t *)memmove(dest[0], src, 26), *(size_t *)memmove_copy(dest[1], src, 26));
    for (unsigned char i = 0; i < 26; ++i)
        cr_assert_eq(dest[0][i], dest[1][i]);
    dlclose(lib);
}

Test(memmove, left_to_right)
{
    void *lib = NULL;
    memmove_t memmove_copy = setup(&lib);
    char *src = "11111122222200000000";
    char dest[2][20];

    memmove(dest[0], src, 20);
    memmove(dest[1], src, 20);
    cr_assert_eq(*(size_t *)memmove(dest[0] + 8, dest[0], 12), *(size_t *)memmove_copy(dest[1] + 8, dest[1], 12));
    for (unsigned char i = 0; i < 20; ++i)
        cr_assert_eq(dest[0][i], dest[1][i]);
    dlclose(lib);
}

Test(memmove, right_to_left)
{
    void *lib = NULL;
    memmove_t memmove_copy = setup(&lib);
    char *src = "00000000111111222222";
    char dest[2][20];

    memmove(dest[0], src, 20);
    memmove(dest[1], src, 20);
    cr_assert_eq(*(size_t *)memmove(dest[0], dest[0] + 8, 12), *(size_t *)memmove_copy(dest[1], dest[1] + 8, 12));
    for (unsigned char i = 0; i < 20; ++i)
        cr_assert_eq(dest[0][i], dest[1][i]);
    dlclose(lib);
}