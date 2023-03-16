#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

int		main(int argc, char **argv);
char	**create_tab(int len, char **values);
void	create_pile_a(int len, char **tab_ascii);
int		*sort_int_tab(int *tab, int len);
int		check_error(char **tab);

#endif
