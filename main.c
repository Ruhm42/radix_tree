/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 10:06:46 by rda-cost          #+#    #+#             */
/*   Updated: 2015/06/02 18:27:44 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix.h"

/*
**	argv[1] is a file with one entry by line.
**	argv[2] is the word that you want complete.
*/

int main(int argc, char **argv)
{
	t_search	search;

	if (argc != 3)
		return (0);
	memset(&search, 0, sizeof(t_search));
	radix_from_file(&(search.tree), argv[1]);
	/*
	**	Uncomment this if you want print all word in radix tree (only leaf)
	**	radix_print(search.tree, NULL);
	*/
	rdx_search(&search, argv[2]);
	printf("Actual word is '%s'.\n", argv[2]);
	printf("Its nearest prefix is '%s'\n", search.prefix);
	printf("All suggestions of words are :\n");
	print_wrap(search.start);
	return (0);
}
