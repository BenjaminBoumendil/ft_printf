/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 16:37:03 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/09 23:31:53 by ochase           ###   ########.fr       */
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
    fcntl(fds[0], F_SETFL, O_NONBLOCK);
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
#include <climits>
int         main(void)
{
    assert(test_one("test%s", 0), "(\"test%s\", \"NULL\")");
    assert(test_one("%010s", "test"), "(\"%010s\", \"test\")");
    assert(test_one("%10s", "test"), "(\"%10s\", \"test\")");
    assert(test_one("%-010s", "test"), "(\"%-010s\", \"test\")");
    assert(test_one("%-10s", "test"), "(\"%-10s\", \"test\")");
    assert(test_one("%%s", "test"), "(\"%%s\", \"test\")");

    assert(test_one("%d", 10), "(\"%d\", 10)");
    assert(test_one("%D", LONG_MAX), "(\"%D\", 2 147 483 647)");
    assert(test_one("%D", LONG_MIN), "(\"%D\", -2 147 483 647)");

    assert(test_one("%lS", "test"), "(\"%lS\", \"test\")");
    assert(test_one("%S", "test"), "(\"%S\", \"test\")");

    return (0);
}
