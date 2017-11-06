
#include "libft.h"


void	ft_lstitermap(t_list *lst, char **map, void (*f)(t_list *elem, char **map, int c))
{
	t_list	*current;
//	char **map; 

//	map = str;

	current = lst;
	while (current)
	{
		f(current, map, current->alpha);
		current = current->next;
	}
}
