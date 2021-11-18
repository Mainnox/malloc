/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:17:14 by lyhamrou          #+#    #+#             */
/*   Updated: 2021/11/18 17:45:26 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define M (1024 * 1024)

void	show_alloc_mem_more(void);
void	show_alloc_mem(void);

void	printAllocationSettings(void)
{
	/*
	   printf("t_page %zu\n", sizeof(t_pageType));
	   printf("t_page %zu\n", sizeof(t_page));
	   printf("t_block %zu\n", sizeof(t_block));
	   printf("size_t %zu\n", sizeof(size_t));
	   printf("TINY_BLOCK_SIZE %d\n", TINY_SIZE);
	   printf("SMALL_BLOCK_SIZE %d\n", SMALL_SIZE);
	   printf("getpagesize   : %d\n", getpagesize());
	   printf("===============================================================\n");
	*/
}

void	*fillPtr(unsigned char *ptr, size_t size, unsigned char c)
{
	if (!ptr)
		ptr = (unsigned char *)malloc(size);
	for (size_t i = 0; i < size; i++)
		ptr[i] = c;
	return ((void *)ptr);
}

void  test5(void)
{
	void *ptr = NULL;

	(void)ptr;
	ptr = malloc(1024);
	ptr = malloc(1024 * 32);
	ptr = malloc(1024 * 1024);
	ptr = malloc(1024 * 1024 * 16);
	ptr = malloc(1024 * 1024 * 128);
}

void  print(char *ptr)
{
	write(1, ptr, strlen(ptr));
}

void  test4(void)
{
	char  *addr = (char *)malloc(16);

	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("bonjours\n");
}

void  test3(void)
{
	char *ad1 = NULL;
	char *ad3 = NULL;

	ad1 = (char *)malloc(16 * M);
	strcpy(ad1, "bonjours\n");
	print(ad1);
	ad3 = realloc(ad1, 128 * M);
	ad3[127 * M] = 42;
	print(ad3);
	return ;
}

void  test2(void)
{
	char *tmp = NULL;

	for (int i = 0; i < 1024; i++)
	{
		tmp = malloc(1024);
		tmp[0] = 42;
		free(tmp);
	}
}

void  test1(void)
{
	char *tmp = NULL;

	for (int i = 0; i < 1024; i++)
	{
		tmp = (char *)malloc(1024);
		tmp[0] = 42;
	}
}

void	test0(void)
{
	int i = 0;

	while (i < 1024)
	{
		++i;
	}
}

void  mallocKiller(void)
{
	char	*ptr = NULL;
	char	*ptr2 = NULL;

	(void)ptr;
//	ptr = malloc(16);
//	ptr = calloc(32, 1);
//	strcpy(ptr, "salut");
//	strcpy(ptr + 10, "bonjour");
//	ptr[31] = 97;
//	ptr2 = realloc(ptr, 200);
}

int		main(int ac, char **av)
{
	//	printAllocationSettings();

	if (ac != 2)
		return (EXIT_SUCCESS);
	if (atoi(av[1]) == 0)
		test0();
	else if (atoi(av[1]) == 1)
		test1();
	else if (atoi(av[1]) == 2)
		test2();
	else if (atoi(av[1]) == 3)
		test3();
	else if (atoi(av[1]) == 4)
		test4();
	else if (atoi(av[1]) == 5)
		test5();
	else
	{
		mallocKiller();
	}
	return (EXIT_SUCCESS);
}

//	printf("\n", );
