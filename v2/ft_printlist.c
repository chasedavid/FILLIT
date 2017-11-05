#include "libft.h"
#include <stdio.h>

void ft_printlist(t_list **alst)
{
	t_list *current; 
	int i;

	current = (*(alst)); 
	i = 0;
	while (current != NULL) 
	{
		printf("\n-----------------\n");
		printf("Linked List: %d\n", i);
		printf("-----------------\n");
		printf("current->content:\n%s\n", current->content);
		printf("current->alpha: %c \n", current->alpha);
		if (current->next == NULL)
			printf("current->next is NULL\n");
		else
			printf("current->next->content:\n%s \n", current->next->content);
		if (current->prev == NULL)
			printf("current->prev is NULL\n");
		else
			printf("current->prev->content:\n%s \n", current->prev->content);
		current = current->next;
		i++;
	}
}
