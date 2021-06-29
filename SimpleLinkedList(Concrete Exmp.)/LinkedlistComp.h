#ifndef LinkedlistComp
#define LinkedlistComp
// A single linked list item stroing Student Record as its data!
typedef struct tagStudent {
    char name[20];
    char surname[20];
    int id;
    double gpa;
    /// struct tagStudent* next  // EN:you may do with this solution too .Actually it's easier but you may need to change code a bit to run ,TR:bununlan ile de yapılabilir hatta bu daha kolay olur çünkü bide oraya taşımakla uğraşmıyorsun
}Student;

typedef struct tagSingleLinkedList {
    Student data;
    struct tagSingleLinkedList* next;
}SLLI;

void printList(SLLI* head);
SLLI* AddItemToFront(SLLI* head, Student* dataToAdd);
SLLI* AddItemToEnd(SLLI* head, Student* dataToAdd);
SLLI* DeleteFromList(SLLI* head,int id);///sadece bunun prototip i deiştirdim kalan mantık olarak birebir
void PrintListReverse(SLLI* head);///buna geegforGreeksten de bak
void PrintListRecursive(SLLI* head);
SLLI* ReverseList(SLLI* head);
SLLI* ReverseListUsignAddItemToFront(SLLI* head); SLLI* AddNewItemToFront(SLLI* head, SLLI* pItem);
SLLI* DestructivelyReverseList(SLLI* head);// bu yeni ve bunun içinde 2 yöntem var 1- klasik 2-recoursive
#endif
