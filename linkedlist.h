struct Bucket
{
    unsigned int m_elem;
    struct Bucket * m_nxt;
};

struct LinkedList
{
    struct Bucket * m_head;
};

int linkedListInit(struct LinkedList * p_linkedList);

int linkedListInsert(struct LinkedList * p_llist, unsigned int p_elem);

int linkedListEmpty(struct LinkedList * p_llist);

void linkedListWalk(struct LinkedList * p_ll, void (*p_func)(unsigned int p_elem));

void linkedListCleanup(struct LinkedList * p_ll, void (*p_func)(unsigned int p_elem));