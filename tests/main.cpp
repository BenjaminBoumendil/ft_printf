/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 16:37:03 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/14 18:32:20 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static const auto BUFF_MAX_SIZE = 1024;

void assert(bool passed, const std::string & description)
{
    bool verbose = true;
    if (verbose)
    {
        std::cout.width(42);
        std::cout << std::endl;
    }

    if (passed)
    {
        if (verbose)
            std::cout << std::left << description << "\033[38;5;2m (passed)\033[0m";
        else
            std::cout << "\033[38;5;2m.\033[0m";
    }
    else
    {
        if (verbose)
            std::cout << std::left << description << "\033[38;5;1m (failed)\033[0m";
        else
            std::cout << "\033[38;5;1m.\033[0m";
    }
    std::cout << std::endl;
}
#include <stdio.h>
template <class F, class... Args>
static auto printf_call(const F & f, const char * format, Args... args)
{
    char buff[BUFF_MAX_SIZE] = {0};
    int fds[2];
    int saved_stdout;

    fflush(stdout);
    pipe(fds);
    saved_stdout = dup(STDOUT_FILENO);
    dup2(fds[1], STDOUT_FILENO);
    close(fds[1]);
    int ret = f(format, args...);
    fflush(stdout);
    fcntl(fds[0], F_SETFL);
    read(fds[0], buff, BUFF_MAX_SIZE);
    dup2(saved_stdout, STDOUT_FILENO);
    std::cout << "BUFF : " << buff << std::endl;
    std::cout << "RET  : " << ret << std::endl;

    return std::make_pair(std::string(buff), ret);
}

template <class... Args>
static bool test_one(const char * format, Args... args)
{
    std::cout << "FT_PRINTF : " << std::endl;
    auto ft_printf_ret = printf_call(ft_printf, format, args...);
    std::cout << std::endl << "PRINTF : " << std::endl;
    auto printf_ret = printf_call(printf, format, args...);
    return printf_ret == ft_printf_ret;
}

#include <locale.h>

int         main(void)
{
    char* local = setlocale(LC_ALL, "en_US.UTF-8");

    if (local == NULL) {
    printf("Locale not set\n");
    } else {
    printf("Locale set to %s\n", local);
    }
    // "s" option test
    // assert(test_one("test%s", 0), "(\"test%s\", \"NULL\")");
    // assert(test_one("%010s", "test"), "(\"%010s\", \"test\")");
    // assert(test_one("%10s", "test"), "(\"%10s\", \"test\")");
    // assert(test_one("%-010s", "test"), "(\"%-010s\", \"test\")");
    // assert(test_one("%-10s", "test"), "(\"%-10s\", \"test\")");
    // assert(test_one("111%s333%s555%saaa%sccc", "222", "444", "666", "bbb"),
        // "(\"111%s333%s555%saaa%sccc\", \"222\", \"444\", \"666\", \"bbb\")");
    // assert(test_one("%+s", 0), "(\"%+s\", \"0\")");
    // assert(test_one("{%s}", ""), "(\"{%s}\", \"\")");

    // "d" option test
    // assert(test_one("%d", 10), "(\"%d\", 10)");
    // assert(test_one("%+d", 42), "(\"%+d\", 42)");
    // assert(test_one("%ld", (long)INT_MAX + 1), "(\"%ld\", (long)INT_MAX + 1)");
    // assert(test_one("%hhd", CHAR_MAX + 42), "(\"%hhd\", CHAR_MAX + 42)");

    // "D" option test
    // assert(test_one("%D", LONG_MAX), "(\"%D\", 9223372036854775807)");
    // assert(test_one("%D", LONG_MIN), "(\"%D\", -9223372036854775808)");
    // assert(test_one("%D", 0L), "(\"%D\", 0L)");
    // assert(test_one("%D", 1L), "(\"%D\", 1L)");
    // assert(test_one("%D", -1L), "(\"%D\", -1L)");

    // "S" option test
    // assert(test_one("%lS", "test"), "(\"%lS\", \"test\")");
    // assert(test_one("%S", "test"), "(\"%S\", \"test\")");
    // assert(test_one("%S", L"米"), "\"%S\", L\"米\"");

    // "c" option test
    // assert(test_one("%c", 'a'), "(\"%c\", \'a\')");
    // assert(test_one("%+c", 'a'), "(\"%c\", \'a\')");
    // assert(test_one("%c", 49), "(\"%c\", 49)");
    // assert(test_one("%c", "aa"), "(\"%c\", \"aa\")");

    // "C" option test
    // assert(test_one("%C", 'a'), "(\"%C\", \'a\')");
    // assert(test_one("%C", L'α'), "(\"%C\", L\'α\')");
    // assert(test_one("%C", L'a'), "(\"%C\", L\'a\')");
    // assert(test_one("%C", L'猫'), "(\"%C\", L\'猫\')");
    // assert(test_one("%C", L'δ'), "(\"%C\", L\'δ\')");
    // assert(test_one("%+C", 0), "(\"%+C\", \'a\')");
    // assert(test_one("%C", 0), "(\"%C\", \'a\')");
    // assert(test_one("%hhC, %hhC", 0, L'米'), "(\"TEST%hhCTEST\", L\'米\')");

    // "%" option test
    // assert(test_one("%%s", "test"), "(\"%%s\", \"test\")");
    // assert(test_one("%%", "test"), "(\"%%s\", \"test\")");
    // assert(test_one("%%"), "(\"%%s\")");
    // assert(test_one("%%%s", "test"), "(\"%%%s\", \"test\")");

    // "i" option test
    // assert(test_one("%i", 10), "(\"%i\", 10)");
    // assert(test_one("%i", 42949672955), "(\"%i\", 4294967295)");

    // "u" option test
    // assert(test_one("%u", -10), "(\"%u\", -10)");
    // assert(test_one("%u", 10), "(\"%u\", 10)");
    // assert(test_one("%hhu, %hhu", 0, UCHAR_MAX + 42), "(\"%hhu, %hhu\", 0, UCHAR_MAX + 42)");

    // "U" option test
    // assert(test_one("%U", ULONG_MAX), "\"%U\", LONG_MAX");

    // "p" option test
    // assert(test_one("%p", "test"), "(\"%p\", \"test\")");
    // int i;
    // assert(test_one("%p", &i), "(\"%p\", &i)");
    // unsigned long l;
    // assert(test_one("%p", &l), "(\"%p\", &l)");
    // char *str;
    // assert(test_one("%p", &str), "(\"%p\", &str)");
    // assert(test_one("%p", &ft_printf), "(\"%p\", &strlen)");
    // assert(test_one("%p", 0), "(\"%p\", 0)");
    // assert(test_one("{%-15p}\n", 0), "(\"{%-15p}\", 0)");

    // "e" option test
    // assert(test_one("%e", 256455.42), "(\"%e\", 10.42)");

    // "o" option test
    // assert(test_one("%o", 42), "(\"%o\", 42)");
    // assert(test_one("%0535.2o", INT_MAX), "(\"%053.2o\", INT_MAX)");
    // assert(test_one("%+o", 42), "(\"%+o\", 42)");
    // assert(test_one("%+O", 0), "(\"%+O\", 0)");
    // assert(test_one("%+o", -42), "(\"%+o\", -42)");
    // assert(test_one("%+O", -42), "(\"%+O\", -42)");

    // "x" option test
    // assert(test_one("%x", 42), "(\"%x\", \"42\")");
    // assert(test_one("%X", 42), "(\"%X\", \"42\")");
    // assert(test_one("%x%x%x%x%x", 1, 100, 999, 42, 999988888), "(\"%x\", \"42\")");
    // assert(test_one("%X%X%X%X%X", 1, 100, 999, 42, 999988888), "(\"%X\", \"42\")");

    // "0" flag test
    // assert(test_one("{%0d}", -42), "(\"{%0d}\", -42)");
    // assert(test_one("{%010d}", -42), "(\"{%010d}\", -42)");
    // assert(test_one("{%10d}", -42), "(\"{%10d}\", -42)");
    // assert(test_one("{%03c}", 0), "(\"{%03c}\", 0)");
    // assert(test_one("{%3c}", 0), "(\"{%03c}\", 0)");

    return (0);
}
