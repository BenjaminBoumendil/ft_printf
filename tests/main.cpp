/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 16:37:03 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/17 22:05:58 by ochase           ###   ########.fr       */
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
    // int fds[2];
    // int saved_stdout;

    // fflush(stdout);
    // pipe(fds);
    // saved_stdout = dup(STDOUT_FILENO);
    // dup2(fds[1], STDOUT_FILENO);
    // close(fds[1]);
    int ret = f(format, args...);
    // fflush(stdout);
    // auto flags = fcntl(fds[0], F_GETFL);
    // fcntl(fds[0], F_SETFL, flags | O_NONBLOCK);
    // auto read_ret = read(fds[0], buff, BUFF_MAX_SIZE);
    // dup2(saved_stdout, STDOUT_FILENO);
    // write(1, "BUFF : ", 7);
    // write(1, buff, read_ret);
    std::cout << "\nRET  : " << ret << std::endl;

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

template<class T>
void        display_bit(T t)
{
    for(int i = sizeof(T) * 8 - 1; i >= 0; i--) {
        std::cout << ((t >> i) & 1);
    }
    std::cout << std::endl;
}

#include <locale.h>
#include <cstring>
int         main(void)
{
    char* local = setlocale(LC_ALL, "en_US.UTF-8");

    if (local == NULL) {
    printf("Locale not set\n");
    } else {
    printf("Locale set to %s\n", local);
    }

    // display_bit(L'米');

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
    // assert(test_one("% d", 10), "(\"% d\", 10)");
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
    // assert(test_one("%S", L"test"), "(\"%S\", \"test\")");
    // assert(test_one("%S", 0), "(\"%S\", \"test\")");
    // assert(test_one("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
    // L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
    // L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", 0), "\"%S\", L\"我是一只猫。\"");

    // "c" option test
    // assert(test_one("%c", 0), "(\"%c\", 0)");
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
    // assert(test_one("%C", 0), "(\"%C\", 0)");
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
    // assert(test_one("{%-15p}", 0), "(\"{%-15p}\", 0)");
    // assert(test_one("% p|%+p", 42, 42), "(\"% p|%+p\", 42, 42)");

    // "e" option test
    // assert(test_one("%e", 256455.42), "(\"%e\", 10.42)");

    // "o" option test
    // assert(test_one("%o", 42), "(\"%o\", 42)");
    // assert(test_one("%0535.2o", INT_MAX), "(\"%053.2o\", INT_MAX)");
    // assert(test_one("%+o", 42), "(\"%+o\", 42)");
    // assert(test_one("%+O", 0), "(\"%+O\", 0)");
    // assert(test_one("%+o", -42), "(\"%+o\", -42)");
    // assert(test_one("%+O", -42), "(\"%+O\", -42)");
    // assert(test_one("%o, %ho, %hho", -42, -42, -42), "(\"%o, %ho, %hho\", -42, -42, -42)");

    // "x" option test
    // assert(test_one("%x", 42), "(\"%x\", \"42\")");
    // assert(test_one("%#x", 42), "(\"%#x\", \"42\")");
    // assert(test_one("%X", 42), "(\"%X\", \"42\")");
    // assert(test_one("%x%x%x%x%x", 1, 100, 999, 42, 999988888), "(\"%x\", \"42\")");
    // assert(test_one("%X%X%X%X%X", 1, 100, 999, 42, 999988888), "(\"%X\", \"42\")");

    // "0" flag test
    // assert(test_one("{%0d}", -42), "(\"{%0d}\", -42)");
    // assert(test_one("{%010d}", -42), "(\"{%010d}\", -42)");
    // assert(test_one("{%10d}", -42), "(\"{%10d}\", -42)");
    // assert(test_one("{%03c}", 0), "(\"{%03c}\", 0)");
    // assert(test_one("{%3c}", 0), "(\"{%03c}\", 0)");

    // "min_width" option test
    // assert(test_one("{%010d}", 42), "(\"{%10d}\", 42)");
    // assert(test_one("{%4d}", 10000), "(\"{%4d}\", 10000)");
    // assert(test_one("{%30d}", 10000), "(\"{%30d}\", 10000)");
    // assert(test_one("{%10d}", -42), "(\"{%10d}\", -42)");
    // assert(test_one("{%3c}", 0), "(\"{%3c}\", 0)");
    // assert(test_one("{%5p}", 0), "(\"{%5p}\", 0)");
    // assert(test_one("{%-15p}", 0), "(\"{%-15p}\", 0)");
    // assert(test_one("{%-13p}", &strlen), "(\"{%-13p}\", &strlen)");
    // assert(test_one("{%-12p}", &strlen), "(\"{%-12p}\", &strlen)");
    // assert(test_one("{%10Rqewgrehtrjytu}"), "(\"{%10R}\")");
    // assert(test_one("{%10Rewrhr%s}", "ok"), "(\"{%10R}\")");
    // assert(test_one("{%30S}", L"我是一只猫。"), "(\"{%30S}\", L\"我是一只猫。\")");
    // assert(test_one("{%-30S}", L"我是一只猫。"), "(\"{%-30S}\", L\"我是一只猫。\")");

    // precision tests
    // assert(test_one("%.4d", 42), "(\"%.4d\", 42)");
    // assert(test_one("%15.4d", 42), "(\"%15.4d\", 42)");
    // assert(test_one("%4.15d", 42), "(\"%4.15d\", 42)");
    // assert(test_one("%.4S", L"我是一只猫。"), "(\"%.4S\", \"我是一只猫。\")");
    // assert(test_one("%05.2s", "test"), "(\"%05.2s\", \"test\")");
    // assert(test_one("%15.4d", 424242), "(\"%15.4d\", 424242)");
    // assert(test_one("%15.4d", -42), "(\"%15.4d\", -42)");
    // assert(test_one("%+.4d", 242), "(\"%15.4d\", 242)");
    // assert(test_one("%.3d", -42), "(\"%15.4d\", 242)");
    assert(test_one("%C%%%S", L'該', L"لحم خنزير"), "(\"%15.4d\", 242)");
    assert(test_one("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"), "(\"%15.4d\", 242)");

    free(local);
    return (0);
}
