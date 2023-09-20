#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int linkedListEmpty(struct LinkedList * p_llist)
{
    if (!p_llist)
    {
        return -1;
    }

    return p_llist->m_head == NULL;
}

int linkedListInit(struct LinkedList * p_llist)
{
    if (!p_llist)
    {
        return -1;
    }

    p_llist->m_head = NULL;

    return 0;
}

int linkedListInsert(struct LinkedList * p_llist, unsigned int p_elem)
{
    if (!p_llist)
    {
        return -1;
    }

    // Check for empty list first
    if (linkedListEmpty(p_llist))
    {
        p_llist->m_head = malloc(sizeof(struct Bucket));
        if (p_llist->m_head == NULL)
        {
            perror("Memory allocation error when inserting element into linked list.");
            return -1;
        }

        p_llist->m_head->m_elem = p_elem;
        p_llist->m_head->m_nxt = NULL;
    }
    else
    {
        struct Bucket * tmp = p_llist->m_head;
        while (tmp->m_nxt != NULL)
        {
            tmp = tmp->m_nxt;
        }

        tmp->m_nxt = malloc(sizeof(struct Bucket));
        if (tmp->m_nxt == NULL)
        {
            perror("Memory allocation error when inserting element into linked list.");
            return -1;
        }
        
        tmp = tmp->m_nxt;
        tmp->m_elem = p_elem;
        tmp->m_nxt = NULL;
    }

    return 0;
}


void linkedListWalk(struct LinkedList * p_ll, void (*p_func)(unsigned int p_elem))
{
    if (!p_ll)
    {
        return;    
    }

    struct Bucket * tmp = p_ll->m_head;
    while (tmp)
    {
        p_func(tmp->m_elem);
        tmp = tmp->m_nxt;
    }

    return;
}

void linkedListCleanup(struct LinkedList * p_ll, void (*p_func)(unsigned int p_elem))
{
    if (!p_ll)
    {
        return;
    }

    struct Bucket * tmp = p_ll->m_head;
    struct Bucket * tmp2 = NULL;
    while(tmp)
    {
        if (p_func)
        {
            p_func(tmp->m_elem);
        }

        tmp2 = tmp;
        tmp = tmp->m_nxt;
        free(tmp2);
    }

    p_ll->m_head = NULL;
}