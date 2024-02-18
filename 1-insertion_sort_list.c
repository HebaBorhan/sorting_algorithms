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
listint_t *current, *temp, *node;
if (*list == NULL || (*list)->next == NULL || list == NULL)
return;
for (node = (*list)->next; node != NULL; node = temp)
{
temp = node->next;
current = node->prev;
while (current != NULL && node->n < current->n)
{
current->next = node->next;
if (node->next != NULL)
node->next->prev = current;
node->prev = current->prev;
node->next = current;
if (current->prev != NULL)
current->prev->next = node;
else
*list = node;
current->prev = node;
current = node->prev;
print_list(*list);
}
}
}
