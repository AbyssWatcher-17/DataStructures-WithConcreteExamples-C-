#ifndef Linkedlist
#define Linkedlist
typedef struct tagSingleLinkedList {
    int data; // A single integer will be stored as data
    struct tagSingleLinkedList* next;
}SLLI; // Single Linked List Item

SLLI* AddItemToFront(SLLI* head, int dataToAdd);

SLLI* AddItemToEnd(SLLI* head, int dataToAdd);
void PrintList(SLLI* head);

SLLI* DeleteFromList(SLLI* head, int dataToRemove);

void PrintListReverse(SLLI* head);
void PrintListRecursive(SLLI* head);

SLLI* ReverseList(SLLI* head);
SLLI* ReverseListUsignAddItemToFront(SLLI* head); SLLI* AddNewItemToFront(SLLI* head, SLLI* pItem);
SLLI* DestructivelyReverseList(SLLI* head);
#endif

