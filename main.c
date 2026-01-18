/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:40:07 by htoe              #+#    #+#             */
/*   Updated: 2026/01/18 23:56:13 by htoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	c = 'A';
	char	*str1 = "Akari Min Thant";
	char	*str2 = NULL ;
	int		maxn = 2147483647;
	int		minn = -2147483648;
	int		zero = 0;
	unsigned int	maxu = 4294967295;
	int		num = 1821996;
	int		hex = 255;

	printf("############\n");
	printf("# Original #\n");
	printf("############\n\n");
	printf("[%d]\n", printf("%c", c));
	printf("[%d]\n", printf("%s", str1));
	printf("[%d]\n", printf("%s", str2));
	printf("[%d]\n", printf("%p", str1));
	printf("[%d]\n", printf("%p", str2));
	printf("[%d]\n", printf("%d", maxn));
	printf("[%d]\n", printf("%i", maxn));
	printf("[%d]\n", printf("%u", maxn));
	printf("[%d]\n", printf("%d", minn));
	printf("[%d]\n", printf("%i", minn));
	printf("[%d]\n", printf("%u", minn));
	printf("[%d]\n", printf("%d", zero));
	printf("[%d]\n", printf("%i", zero));
	printf("[%d]\n", printf("%u", zero));
	printf("[%d]\n", printf("%d", maxu));
	printf("[%d]\n", printf("%i", maxu));
	printf("[%d]\n", printf("%u", maxu));
	printf("[%d]\n", printf("%d", num));
	printf("[%d]\n", printf("%i", num));
	printf("[%d]\n", printf("%u", num));
	printf("[%d]\n", printf("%x", hex));
	printf("[%d]\n", printf("%X", hex));
	

	printf("\n\n\n#############\n");
	printf("# Prototype #\n");
	printf("#############\n\n");
	printf("[%d]\n", ft_printf("%c", c));
	printf("[%d]\n", ft_printf("%s", str1));
	printf("[%d]\n", ft_printf("%s", str2));
	printf("[%d]\n", ft_printf("%p", str1));
	printf("[%d]\n", ft_printf("%p", str2));
	printf("[%d]\n", ft_printf("%d", maxn));
	printf("[%d]\n", ft_printf("%i", maxn));
	printf("[%d]\n", ft_printf("%u", maxn));
	printf("[%d]\n", ft_printf("%d", minn));
	printf("[%d]\n", ft_printf("%i", minn));
	printf("[%d]\n", ft_printf("%u", minn));
	printf("[%d]\n", ft_printf("%d", zero));
	printf("[%d]\n", ft_printf("%i", zero));
	printf("[%d]\n", ft_printf("%u", zero));
	printf("[%d]\n", ft_printf("%d", maxu));
	printf("[%d]\n", ft_printf("%i", maxu));
	printf("[%d]\n", ft_printf("%u", maxu));
	printf("[%d]\n", ft_printf("%d", num));
	printf("[%d]\n", ft_printf("%i", num));
	printf("[%d]\n", ft_printf("%u", num));
	printf("[%d]\n", ft_printf("%x", hex));
	printf("[%d]\n", ft_printf("%X", hex));
	return (0);
}
