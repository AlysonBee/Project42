

#include <stdlib.h>
#include "matt_daemon.h"

t_proc		*new_id(int process_id)
{
	t_proc	*head;

	head = (t_proc *)malloc(sizeof(t_proc));
	head->id = process_id;
	head->next = NULL;
	return (head);
}

t_proc		*add_id(t_proc *head, int process_id)
{
	t_proc	*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_proc *)malloc(sizeof(t_proc));
	trav->next->id = process_id;
	trav->next->next = NULL;
	return (trav);
}

t_proc		*process_list_handling(t_proc *head, int process_id)
{
	t_proc		*trav;

	trav = head;
	if (trav == NULL)
	{
		head = new_id(process_id);
		trav = head;
	}
	else
	{
		trav = add_id(head, process_id);
		trav = head;
	}
	return (trav);
}

