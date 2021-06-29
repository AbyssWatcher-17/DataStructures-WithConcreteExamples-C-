#ifndef DoubleLinkedlistComp
#define DoubleLinkedlistComp
typedef struct tagStudent {
    char name[20];
    char surname[20];
    int id;
    double gpa;
     struct tagStudent* next;
     struct tagStudent* prev;
}DLLI;

//Protos.
DLLI* ReverseList(DLLI* head);
void PrintList(DLLI* head);
DLLI* AddItemToEnd(DLLI* head, DLLI* dataToAdd);
DLLI* AddItemToFront(DLLI* head, DLLI* dataToAdd);
DLLI* OrderedAddItem(DLLI* head, DLLI* dataToAdd);
DLLI* DeleteItemOptimized(DLLI* head, int dataToDel);
DLLI* RecoursiveReverseList(DLLI* head);
void PrintListReverse(DLLI* head);
void PrintListRecursive(DLLI* head);
#endif

