/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:15:03 by ahallain          #+#    #+#             */
/*   Updated: 2019/11/08 13:21:35 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	red(void)
{
	printf("\033[0;31m");
}

void	boldred(void)
{
	printf("\033[1;31m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	boldgreen(void)
{
	printf("\033[1;32m");
}

void	yellow(void)
{
	printf("\033[0;33m");
}

void	boldyellow(void)
{
	printf("\033[01;33m");
}

void	blue(void)
{
	printf("\033[0;34m");
}

void	boldblue(void)
{
	printf("\033[1;34m");
}

void	magenta(void)
{
	printf("\033[0;35m");
}

void	boldmagenta(void)
{
	printf("\033[1;35m");
}

void	cyan(void)
{
	printf("\033[0;36m");
}

void	boldcyan(void)
{
	printf("\033[1;36m");
}

void	reset(void)
{
	printf("\033[0m");
}

void	testcolor(void)
{
	red();
	printf("red\n");
	boldred();
	printf("boldred\n");
	green();
	printf("green\n");
	boldgreen();
	printf("boldgreen\n");
	yellow();
	printf("yellow\n");
	boldyellow();
	printf("boldyellow\n");
	blue();
	printf("blue\n");
	boldblue();
	printf("boldblue\n");
	magenta();
	printf("magenta\n");
	boldmagenta();
	printf("boldmagenta\n");
	cyan();
	printf("cyan\n");
	boldcyan();
	printf("boldcyan\n");
	reset();
	printf("reset\n");
}
