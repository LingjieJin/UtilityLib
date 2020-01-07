#include <stdint.h>
#include <stdbool.h>

typedef void Node;
typedef void *PNode;

typedef struct _ListAbstract
{
    int size;
    Node *head;
    Node *tail;
} List, *PList;

typedef struct _ListAPI
{
    /* Init a empty list */
    List *(*Init)();
    /* Create a list of a specified size */
    List *(*Creat)(int num);
    /* Destroy a list */
    bool (*Destroty)(List *list);
    /* Whether the list is empty */
    bool (*isEmpty)(List *list);
    /* Select a Node */
    Node *(*Select)(List *list, int index);
    /* Append a Node */
    int (*Append)(List *list, Node *node);
    /** Forward Insert a Node
     * list must already have elements
     */
    int (*Insert)(List *list, Node *node, int index);
    Node *(*Remove)(List *list);
    Node *(*Delete)(List *list, int index);
    void (*Show)(List *list);
    bool (*Sort)(List *list, int (*comp)(const void *, const void *));
} ListAPI;

const ListAPI _Dlist_api;