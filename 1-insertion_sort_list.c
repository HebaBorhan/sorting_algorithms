#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the first element of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *compare, *temp;
if (*list == NULL || (*list)->next == NULL)
return;
for (current = (*list)->next; current != NULL; current = temp)
{
temp = current->next;
compare = current->prev;
while (compare != NULL && current->n < compare->n)
{
compare->next = current->next;
if (current->next != NULL)
current->next->prev = compare;
current->prev = compare->prev;
current->next = compare;
if (compare->prev != NULL)
compare->prev->next = current;
else
*list = current;
compare->prev = current;
compare = current->prev;
print_list(*list);
}
}
}
