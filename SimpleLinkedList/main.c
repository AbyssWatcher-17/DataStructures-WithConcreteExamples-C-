#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
int main(int argc, char** argv)
{
    SLLI* head = NULL; // This means the list hasn't got any items
    int i;

    for (i = 10; i > 0; --i)
        head = AddItemToEnd(head, i);

    printf("Print list...\n");
    PrintList(head);
//     PrintListRecursive(head);

    printf("----------------------------------\n");

//     head = ReverseList(head);
//     printf("Print list after REVERSE operation...\n");
//     PrintList(head);

///That's newest solution
//    head =DestructivelyReverseList(head);
//    PrintList(head);




/**
    head = ReverseListUsignAddItemToFront(head);
    printf("Print list after REVERSE operation...\n");
    PrintList(head);
    */
    head = ReverseList(head);
    PrintList(head);


//     printf("Print list in REVERSE ORDER...\n");
//     PrintListReverse(head);

//     head = AddItemToFront(head, 10);
//     PrintList(head);

//     printf("Remove the last item\n");
//     head = DeleteFromList(head, 1);
//     PrintList(head);
//
//     printf("Remove the first item\n");
//     head = DeleteFromList(head, 10);
//     PrintList(head);
//
//
//     printf("Remove an inner item\n");
//     head = DeleteFromList(head, 5);
//     PrintList(head);
//
//
//     printf("Remove an item whish is NOT in the list\n");
//     head = DeleteFromList(head, 15);
//     PrintList(head);

}
