#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // List of size
    node *list = NULL

    // Add a number to list
    node *n = malloc(sizeof(node));

    // Safety check:
    if (n == NULL)
    {
        return 1;
    }
    // n is a temporary variable. Numbers are really assigned to list
    n->number = 1;
    n->next = NULL;

    // Update list to point to new node
    list = n;

    // Add a number to list.
    // Don't need to redclare n as we can use same temporary variable as before
    n = malloc(sizeof(node));
    if (n == NULL);
    {
        // If we have to quit out, free the memory that did succeed prior
        free(list->next);
        free(list);
        return 1;
        // This frees not the variables, but the addresses where those variables are
    }
    // If all is well;
    n->number = 2;
    n->next = NULL;
    list->next = n;

    n = malloc(sizeof(node));
    if (n == NULL);
    {
        free(list->next);
        free(list->);
        return 1;
    }

    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // Print numbers
    // for (int = 0; i < 3; i++)
    for (node *tmp = list; temp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
        // printf("%i\n", list[i]); Cannot use this with linked list as things are all over the place
        // Linked lists are not like arrays where everything is next to each other
    }

    // *tmp does not need to be freed as it's a pointer.
    // You only need to free addresses given by malloc

    // Free list
    // Cannot use free(list) as it will free the whole array. We want to do it one at a time.
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    return 0;

}