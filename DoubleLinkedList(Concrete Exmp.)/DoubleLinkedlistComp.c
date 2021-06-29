#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedlistComp.h"

void PrintList(DLLI* head)
{
    while (NULL != head) {
        printf("Data(name) : %s\n", head->name);
        printf("Data(surname) : %s\n", head->surname);
        printf("Data(ID) : %d\n", head->id);
        printf("Data(gpa) : %lf\n", head->gpa);
        head = head->next;
    }
}
DLLI* AddItemToEnd(DLLI* head, DLLI* dataToAdd)
{
    // STEP 1-) Create a new item
    DLLI* pItem;

    pItem = (DLLI*)malloc(sizeof(DLLI));
    if (NULL == pItem) {
        printf("AddItemToEnd - ERROR : Cannot allocate memory for item...\n");
        exit(EXIT_FAILURE);
    }
    /*
      printf("Name\n");scanf("%s",pItem->name);///buradaki syntax lar önemli

      printf("SurName\n");scanf("%s",(student_dynamic_array+i)->surname);
      printf("id\n");scanf("%d",&(student_dynamic_array+i)->id);
      printf("gpa\n");scanf("%lf",&(student_dynamic_array+i)->gpa);
*/
   strcpy(pItem->name , dataToAdd->name);
     strcpy(pItem->surname , dataToAdd->surname);
      pItem->id = dataToAdd->id;
       pItem->gpa = dataToAdd->gpa;

       pItem->next = NULL;
    pItem->prev = NULL;

    // CASE 1 - EMPTY List
    if (NULL == head)
        return pItem;
    else { // CASE 2 - List HAS AT LEAST ONE ITEM!
        DLLI* temp = head;

        // Find the last item
        while (NULL != temp->next)
            temp = temp->next;

        // Set the next of the last item as the new item
        temp->next = pItem;
        // New last item's previous link will be temp
        // So, temp becomes one before the last instead of being the last
        pItem->prev = temp;

        return head;
    }

}
DLLI* DeleteItemOptimized(DLLI* head, int dataToDel) ///EN:That's better form.Made smarter Instead of typin 2-3 times  TR:bu çok daha iyi hali 2-3 kere tekrar yapmak yerine parantezlerle daha akıllıca yazılmış
{
    // EMPTY LIST CHECK
    if (NULL != head) {
        DLLI* temp = head;

        while(NULL != temp && temp->id != dataToDel)///En:This is critic,TR:OLAY BURASI ZATEN temp->data.id != id
            temp = temp->next;

        // NOT FOUND - Data is NOT in the list
        if (NULL != temp) {
            // ITEM FOUND - Remove it!
            // 1- Set the previous item's next value
            if (NULL != temp->prev)// If temp is NOT the first item!
                temp->prev->next = temp->next;

            // 2- Set the next item's previous value
            if (NULL != temp->next) // If it is NOT the last item
                temp->next->prev = temp->prev;

            if (head == temp)
                head = temp->next;

            free(temp);
        }
    }
    return head;
}
/*--------------------------------------------------------------------------------------------------------------------*/
DLLI* ReverseList(DLLI* head){
 DLLI* temp=NULL;
 DLLI* curr;

  if (NULL == head)
        return curr;


 curr=head;
 printf("First curr = %s\n",curr->name);
 printf("First curr = %s\n",curr->surname);
 printf("First curr = %d\n",curr->id);
 printf("First curr = %lf\n",curr->gpa);

 while (curr !=  NULL)
     {
         temp=curr->prev;
         curr->prev=curr->next;
         curr->next=temp;

         curr=curr->prev;///EN:To move here,TR:Bu da burayı ilerletmek için
     }
     if(temp != NULL )
        curr= temp->prev;

 return curr;
}
/*
DLLI* RecoursiveReverseList(DLLI* head){ ///EN:Nearly Same with Standart Linked ListTR:Normal Linked listtekinin nerdeyse aynısı

// BASE CASE
    if (NULL == head)
        return head;

    // MAKING PROGRESS TOWARDS THE CASE
    DLLI* temp = RecoursiveReverseList(head->next); //OLAY BURASI
    return AddItemToEnd(temp, head->data);
    }
    */
/**EN:There's a alternative TR:Bide şöle bi tane daha var
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



DLLI* AddItemToFront(DLLI* head, DLLI* dataToAdd){
  DLLI*  pItem;
  pItem=(DLLI*)malloc(sizeof(DLLI));
  if (NULL == pItem) {
        printf("Cannot allocate memory for the new item!!!\n");
        exit(1);
    }

       strcpy(pItem->name , dataToAdd->name);
     strcpy(pItem->surname , dataToAdd->surname);
      pItem->id = dataToAdd->id;
       pItem->gpa = dataToAdd->gpa;
    pItem->next = head;
    pItem->prev= NULL;

    return pItem;

}


DLLI* OrderedAddItem(DLLI* head, DLLI* dataToAdd){ ///ORDER BY ID
  DLLI*  pItem;
  pItem=(DLLI*)malloc(sizeof(DLLI));
  if (NULL == pItem) {
        printf("Cannot allocate memory for the new item!!!\n");
        exit(1);
    }
    strcpy(pItem->name , dataToAdd->name);///array olduğu için bu sıkıntıyı öyle çözebildim,string kütüphanesini de eklemeyi unutma
     strcpy(pItem->surname , dataToAdd->surname);
      pItem->id = dataToAdd->id;
       pItem->gpa = dataToAdd->gpa;
    pItem->prev=NULL;
    pItem->next=NULL;

      if (NULL == head)//EMPTY
      {
           return pItem;
      }

      /**EN:I'm not %100 sure,TR:BURADAN DA EMİN OLAMADIM */
      if(dataToAdd->id < head->id){ //EN:Situation about less than first one that means root changes  TR:ilk elemandan kucuk durumu
			//EN:Root changes, TR:root degisiyor

			pItem->next= head;
			head->prev= pItem;

			return pItem;
	}

DLLI*  temp=head;
	while(temp->next !=NULL && temp->next->id < dataToAdd->id){
        temp=temp->next;
	}
	pItem->next=temp->next;
	temp->next=pItem;
	pItem->prev=temp;


	if(pItem->next !=NULL){///EN:This situation is adding to end because if it's last one then its next must NULL ,TR:SONA EKLENME DURUMU BU ÇÜNKÜ EĞER SONSA Next i NULL dır
	pItem->next->prev=pItem;///EN:We did it that front one's prev to link pItem ,TR:bunu normalde önde olanın prev ini pItem a bağlanması için yaptık
	}



	return head;
}

// Prints the list
void PrintListRecursive(DLLI* head)
{
    if (NULL != head) {
        printf("(PrintListRecursive) Data : %s\n", head->name);
        printf("(PrintListRecursive) Data : %s\n", head->surname);
        printf("(PrintListRecursive) Data : %d\n", head->id);
        printf("(PrintListRecursive) Data : %lf\n", head->gpa);
        PrintListRecursive(head->next);///EN:That's critic point ,TR:OLAY BURASI
    }
}

// Prints the list in REVERSE order i.e from end to beginning
void PrintListReverse(DLLI* head)
{
    if (NULL == head) // BASE CASE
        return;

    // MAKE PROGRESS TOWARDS THE BASE CASE
    PrintListReverse(head->next); ///EN:That's critic point ,TR:OLAY BURASI
    printf("(PrintListReverse) Data : %s\n", head->name);
      printf("(PrintListReverse) Data : %s\n", head->surname);
        printf("(PrintListReverse) Data : %d\n", head->id);
          printf("(PrintListReverse) Data : %lf\n", head->gpa);

//     if (NULL != head) {
//         PrintListReverse(head->next);
//         printf("(PrintListReverse) Data : %d\n", head->data);
//     }
}
