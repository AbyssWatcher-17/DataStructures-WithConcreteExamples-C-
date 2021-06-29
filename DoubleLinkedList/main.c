#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

int main()
{
     int i;
    DLLI* head = NULL;// EMPTY LIST - List HASN'T GOT any item(s) yet
    head=OrderedAddItem(head,3);
    head=OrderedAddItem(head,4);
    head=OrderedAddItem(head,6);
    head=OrderedAddItem(head,1);
    head=OrderedAddItem(head,5);
    head=OrderedAddItem(head,1111);
    head=OrderedAddItem(head,921);
    head=OrderedAddItem(head,0);
      head=OrderedAddItem(head,931);
      head=OrderedAddItem(head,2221);

    PrintList(head);

    for (i = 0; i < 10; ++i)
        head = AddItemToEnd(head, i + 1);

    printf("The original list...\n");
    PrintList(head);
    printf("------------------\n");
      head=ReverseList(head);
     printf("REVERSED list...\n");
     PrintList(head);

     printf("Reverse List\n");
     head=ReverseList(head);
     PrintList(head);
        printf("------------------\n");
        printf("Add item to Front\n");
         head = AddItemToFront(head, 18);
        PrintList(head);
     printf("------------------\n");
      head=RecoursiveReverseList(head);
      PrintList(head);
      printf("***************\n");
      PrintListRecursive(head);
      printf("00000000000000000000\n");
      PrintListReverse(head);



    return 0;
}

