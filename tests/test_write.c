/*
** EPITECH PROJECT, 2020
** ASM_minilibc_2019
** File description:
** write
*/

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

typedef int (*write_t)(int, const void *, size_t);

static write_t setup(void **lib)
{
    *lib = dlopen("./libasm.so", RTLD_LAZY);
    return dlsym(*lib, "write");
}

void redirect_all_outputs(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(write, test_stdout, .init=redirect_all_outputs)
{
    void *lib = NULL;
    write_t write_copy = setup(&lib);

    write_copy(1, "test", 4);
    cr_assert_stdout_eq_str("test");
    dlclose(lib);
}

Test(write, test_stderr, .init=redirect_all_outputs)
{
    void *lib = NULL;
    write_t write_copy = setup(&lib);

    write_copy(2, "coucou", 4);
    cr_assert_stderr_eq_str("coucou");
    dlclose(lib);
}