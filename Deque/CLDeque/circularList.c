#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
    assert( list != 0);
    struct Link *newLink = malloc(sizeof(struct Link));
    newLink->next = newLink;
    newLink->prev = newLink;
    newLink->value = 0;
    
    list->sentinel = newLink;
    list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
    struct Link *newLnk = malloc(sizeof(struct Link));
    assert(newLnk != NULL);
    
    newLnk->value = value;
    newLnk->next = NULL;
    newLnk->prev = NULL;
    
    return newLnk;
	//return NULL;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    assert(list !=0 && link != 0);
    
    struct Link* newLnk = createLink(value);
    link->next->prev = newLnk;
    newLnk->next = link->next;
    link->next = newLnk;
    newLnk->prev = link;
    
    list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
    struct Link *next;
    struct Link *prev;
    
    assert(list != NULL);
    assert(list->size != 0);
    assert(link !=NULL);
    
    prev= link->prev;
    next = link->next;
    
    free(link);
    
    list->size--;
    
    prev->next = next;
    next->prev = prev;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
    struct Link *temp;
    
    if(list != NULL)
    {
        temp = list->sentinel->next;
        
        while(temp != list->sentinel && temp != NULL)
        {
            temp = temp->next;
            free(temp->prev);
            temp->prev = NULL;
        }
        
        if(temp == list->sentinel)
        {
            free(temp);
        }
    
    }
    free(list);
    list = NULL;
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list != 0);
    addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    assert(list!= 0);
    addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
    removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
    removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
    if(list->size == 0)
    {
        return 1;
    }
    else;
        return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
    struct Link *temp = list->sentinel->next;
    
    while(temp != list->sentinel)
    {
        printf("%g", temp->value);
        temp=temp->next;
    }
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
    struct Link* current;
    struct Link* temp;
    
    current = list->sentinel;
    
    do
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    while(current != list->sentinel);
}
