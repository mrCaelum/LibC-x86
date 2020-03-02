/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** strlen
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>

typedef int (*strlen_t)(char const *);

static strlen_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "strlen");
}

Test(strlen, len)
{
    void *lib = NULL;
    strlen_t strlen_copy = setup(&lib);
    const char *tab[] = {
        "maman",
        "coucou",
        "J'aime les macarons !",
        "OWJFPOQIHFEOIWQHFPQIFPIWQPIFHPWIQHFPIHQPIHFPIWHFQPIHFPWIHF",
        NULL
    };

    for (unsigned char i = 0; tab[i]; ++i)
        cr_assert_eq(strlen(tab[i]), strlen_copy(tab[i]));
    dlclose(lib);
}