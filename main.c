/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 10:06:46 by rda-cost          #+#    #+#             */
/*   Updated: 2015/06/02 18:44:34 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix.h"
#include <time.h>

static void		scratch_time(clock_t *tic)
{
	*tic = clock();
}

static void		elapsed_time(clock_t tic)
{
	clock_t end;

	end = clock();
	printf("Time Elapsed: %f seconds\n", (double)(end - tic) / CLOCKS_PER_SEC);
}

/*
**	argv[1] is a file with one entry by line.
**	argv[2] is the word that you want complete.
*/

int 		main(int argc, char **argv)
{
	t_search	search;
	clock_t		t;

	if (argc != 3)
		return (0);
	if (argc >= 2)
	{
		memset(&search, 0, sizeof(t_search));
		scratch_time(&t);
		radix_from_file(&(search.tree), argv[1]);
		printf("Building Radix Tree - ");
		elapsed_time(t);
	}
	/*
	**	Uncomment this if you want print all word in radix tree (only leaf)
	**	radix_print(search.tree, NULL);
	*/
	if (argc >= 3)
	{
		scratch_time(&t);
		rdx_search(&search, argv[2]);
		printf("Searching through Radix Tree - ");
		elapsed_time(t);
		printf("Actual word is '%s'.\n", argv[2]);
		printf("Its nearest prefix is '%s'\n", search.prefix);
		printf("All suggestions of words are :\n");
		print_wrap(search.start);
	}
	return (0);
}
