/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:48:41 by crondeau          #+#    #+#             */
/*   Updated: 2021/12/09 10:09:36 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb > 0)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int ft_atoi(char *str)
{
    int i;
	int signe;
    int valeur;

    i = 0;
	signe = 0;
    valeur = 0;
	while (str[i] == " " || (str[i] >= '\t'  && str[i] <= '\r'))
	{
		i++;
	}
    while (str[i] == "+" || str[i] == "-")
    {
		if (str[i] == "-")
			j++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
    {
		valeur = (valeur * 10) + str[i] - '0';
		i++;
	}
	if ((signe % 2) == 1) 
		return (valeur * -1); 
	else
		return (valeur);
}