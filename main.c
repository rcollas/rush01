/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:02:22 by rcollas           #+#    #+#             */
/*   Updated: 2021/03/20 17:05:37 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		*get_col(int grid[4][4], int indx, int pov);
int 	*get_row(int grid[4][4], int indx, int pov);
int		*ft_return_tab(int grid[4][4], int indx);

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int		ft_input_check(char *str)
{
	int i;

	i = 0;
	while (str[i] && i < 32)
	{
		if (!(str[i] >= '1' && str[i] <= '4'))
			return (1);
		i += 2;
	}
	i = 1;
	while (str[i])
	{
		if (!(str[i] == ' '))
			return (1);
		if (i > 29)
			return (1);
		i += 2;
	}
	return (0);
}

void	char_to_int(char *str, int tab[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 32)
	{
		tab[j] = str[i] - 48;
		i += 2;
		j++;
	}
}

void	print_tab(int tab[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 2 || ft_input_check(argv[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	int input_values[16];
	int grid[4][4] = {0};
	int *ptr = ft_return_tab(grid, 2);
	char_to_int(argv[1], input_values);	
	print_tab(grid);
	int i;
	for (i = 0; i < 4; i++)
		printf("%d\n", ptr[i]);

}
