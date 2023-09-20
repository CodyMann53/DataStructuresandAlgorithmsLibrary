#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

void print_elem(unsigned int p_elem)
{
    printf("%u\n", p_elem);
    return;
}

int main(int argc, char ** argv)
{
    struct LinkedList ll;
    if (linkedListInit(&ll) != 0)
    {
        printf("linkedListInit failure.\n");
        return EXIT_FAILURE;
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        if (linkedListInsert(&ll, i) != 0)
        {
            printf("linkedListInsert failure.\n");
            return EXIT_FAILURE;
        }
    }

    linkedListWalk(&ll, &print_elem);
    linkedListCleanup(&ll, NULL);

    printf("All tests passed.\n");
    return EXIT_SUCCESS;
}