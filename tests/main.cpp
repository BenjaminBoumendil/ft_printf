/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 16:37:03 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/07 23:37:27 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static const auto BUFF_MAX_SIZE = 1024;

template <class F>
static auto printf_call(const F & f, const char * format, ...)
{
    char buff[BUFF_MAX_SIZE];
    int fds[2];
    int saved_stdout;

    fflush(stdout);
    pipe(fds);
    saved_stdout = dup(STDOUT_FILENO);
    dup2(fds[1], STDOUT_FILENO);
    close(fds[1]);
    int ret = f(format);
    fflush(stdout);
    read(fds[0], buff, BUFF_MAX_SIZE);
    dup2(saved_stdout, STDOUT_FILENO);

    return std::make_pair(std::string(buff), ret);
}

static bool test_one(const char * format, ...)
{
    auto printf_ret = printf_call(printf, format);
    auto ft_printf_ret = printf_call(ft_printf, "format");
    return printf_ret == ft_printf_ret;
}

int         main(void)
{
    if (test_one("test", "lol"))
        std::cout << "OK" << std::endl;
    else
        std::cout << "KO" << std::endl;

    return (0);
}