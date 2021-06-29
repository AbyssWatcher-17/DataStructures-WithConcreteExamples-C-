#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"
void PrintList(DLLI* head)
{
    while (NULL != head) {
        printf("Data : %d\n", head->data);
        head = head->next;
    }
}


DLLI* AddItemToEnd(DLLI* head, int dataToAdd)
{
    // STEP 1-) Create a new item
    DLLI* pNewItem;

    pNewItem = (DLLI*)malloc(sizeof(DLLI));
    if (NULL == pNewItem) {
        printf("AddItemToEnd - ERROR : Cannot allocate memory for item...\n");
        exit(EXIT_FAILURE);
    }

    pNewItem->data = dataToAdd;
    pNewItem->next = NULL;
    pNewItem->prev = NULL;

    // CASE 1 - EMPTY List
    if (NULL == head)
        return pNewItem;
    else { // CASE 2 - List HAS AT LEAST ONE ITEM!
        DLLI* temp = head;

        // Find the last item
        while (NULL != temp->next)
            temp = temp->next;

        // Set the next of the last item as the new item
        temp->next = pNewItem;
        // New last item's previous link will be temp
        // So, temp becomes one before the last instead of being the last
        pNewItem->prev = temp;

        return head;
    }

}
DLLI* ReverseList(DLLI* head){
 DLLI* temp=NULL;
 DLLI* curr;

  if (NULL == head)
        return curr;


 curr=head;
 printf("First curr = %d\n",curr->data);

 while (curr !=  NULL)
     {
         temp=curr->prev;
         curr->prev=curr->next;
         curr->next=temp;

         curr=curr->prev;///Bu da burayı ilerletmek için
     }
     if(temp != NULL )
        curr= temp->prev;

 return curr;
}

DLLI* RecoursiveReverseList(DLLI* head){ ///Normal Linked listtekinin nerdeyse aynısı

// BASE CASE
    if (NULL == head)
        return head;

    // MAKING PROGRESS TOWARDS THE CASE
    DLLI* temp = RecoursiveReverseList(head->next); /* OLAY BURASI*/
    return AddItemToEnd(temp, head->data);
/** Bide şöle bi tane daha var
Node* Reverse(Node* node)
{
    // If empty list, return
    if (!node)
        return NULL;

    // Otherwise, swap the next and prev
    Node* temp = node->next;
    node->next = node->prev;
    node->prev = temp;

    // If the prev is now NULL, the list
    // has been fully reversed
    if (!node->prev)
        return node;

    // Otherwise, keep going
    return Reverse(node->prev);
}
*/

}
DLLI* AddItemToFront(DLLI* head, int dataToAdd){
  DLLI*  pItem;
  pItem=(DLLI*)malloc(sizeof(DLLI));
  if (NULL == pItem) {
        printf("Cannot allocate memory for the new item!!!\n");
        exit(1);
    }
    pItem->data=dataToAdd;
    pItem->next = head;
    pItem->prev= NULL;

    return pItem;

}
DLLI* OrderedAddItem(DLLI* head, int dataToAdd){

DLLI*  pItem;
  pItem=(DLLI*)malloc(sizeof(DLLI));
  if (NULL == pItem) {
        printf("Cannot allocate memory for the new item!!!\n");
        exit(1);
    }
    pItem->data=dataToAdd;
    pItem->prev=NULL;
    pItem->next=NULL;

      if (NULL == head)//EMPTY
      {
           return pItem;
      }

      if(dataToAdd < head->data){ // ilk elemandan kucuk durumu
			// root degisiyor

			pItem->next= head;
			head->prev= pItem;

			return pItem;
	}

DLLI*  temp=head;
	while(temp->next !=NULL && temp->next->data <dataToAdd){
        temp=temp->next;
	}
	pItem->next=temp->next;
	temp->next=pItem;
	pItem->prev=temp;


	if(pItem->next !=NULL){///SONA EKLENME DURUMU BU ÇÜNKÜ EĞER SONSA Next i NULL dır
	pItem->next->prev=pItem;///bunu normalde önde olanın prev ini pItem a bağlanması için yaptık
	}



	return head;
}




// Prints the list
void PrintListRecursive(DLLI* head)
{
    if (NULL != head) {
        printf("(PrintListRecursive) Data : %d\n", head->data);
        PrintListRecursive(head->next);/* OLAY BURASI*/
    }
}

// Prints the list in REVERSE order i.e from end to beginning
void PrintListReverse(DLLI* head)
{
    if (NULL == head) // BASE CASE
        return;

    // MAKE PROGRESS TOWARDS THE BASE CASE
    PrintListReverse(head->next); /* OLAY BURASI*/
    printf("(PrintListReverse) Data : %d\n", head->data);

//     if (NULL != head) {
//         PrintListReverse(head->next);
//         printf("(PrintListReverse) Data : %d\n", head->data);
//     }
}
