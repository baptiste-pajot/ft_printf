/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 14:24:59 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 15:40:53 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	printf("test : %s\n", "\"%c\", 0");
	printf("-->");
	printf("%c", 0);
	printf("<--\n");
	printf("test : %s\n", "\"%c\", 32");
	printf("-->");
	printf("%c", 32);
	printf("<--\n");
	printf("test : %s\n", "\"%c\", 'a'");
	printf("-->");
	printf("%c", 'a');
	printf("<--\n");
	printf("test : %s\n", "\"%c\", 132");
	printf("-->");
	printf("%c", 132);
	printf("<--\n");
	printf("test : %s\n", "\"%c\", -32");
	printf("-->");
	printf("%c", -32);
	printf("<--\n");
	return (0);
}
