#ifndef DoubleLinkedList
#define DoubleLinkedList
typedef struct tagDoublyLinkedList {
    int data; // A single integer will be stored as data
    struct tagDoublyLinkedList* prev;
    struct tagDoublyLinkedList* next;
}DLLI;

//Protos.
DLLI* ReverseList(DLLI* head);
void PrintList(DLLI* head);
DLLI* AddItemToEnd(DLLI* head, int dataToAdd);
DLLI* AddItemToFront(DLLI* head, int dataToAdd);
DLLI* OrderedAddItem(DLLI* head, int dataToAdd);
DLLI* RecoursiveReverseList(DLLI* head);
void PrintListReverse(DLLI* head);
void PrintListRecursive(DLLI* head);



#endif
