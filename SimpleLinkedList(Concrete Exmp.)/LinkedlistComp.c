#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedlistComp.h"

void PrintListReverse(SLLI* head){
  if (NULL == head) // BASE CASE
        return;

    // MAKE PROGRESS TOWARDS THE BASE CASE
    PrintListReverse(head->next);///RECOURSİVE
      printf("(PRINTLISTREVERSE)Name :%s \n", head->data.name);
      printf("(PRINTLISTREVERSE)SURName :%s \n", head->data.surname);
        printf("(PRINTLISTREVERSE)ID :%d \n", head->data.id);
        printf("(PRINTLISTREVERSE)GPA :%lf \n\n", head->data.gpa);
    //     if (NULL != head) {
//         PrintListReverse(head->next);
//         printf("(PrintListReverse) Data : %d\n", head->data);
//     }


}

void PrintListRecursive(SLLI* head){
        if (NULL != head) {
        printf("(PRINTLISTRecoursive)Name :%s \n", head->data.name);
      printf("(PRINTLISTRecoursive)SURName :%s \n", head->data.surname);
        printf("(PRINTLISTRecoursive)ID :%d \n", head->data.id);
        printf("(PRINTLISTRecoursive)GPA :%lf \n\n", head->data.gpa);
        PrintListRecursive(head->next);
    }
}



void printList(SLLI* head){
     while(NULL != head) {
       printf("Name :%s \n", head->data.name);
      printf("SURName :%s \n", head->data.surname);
        printf("ID :%d \n", head->data.id);
        printf("GPA :%lf \n\n", head->data.gpa);
        head = head->next;// proceed to the next item
    }
}


SLLI* DeleteFromList(SLLI* head, int id)
{
    // If the list contains item(s)
    if (NULL != head) {
        SLLI* temp = head;
        SLLI* prev = NULL;

        // If the list contains item(s) and if the current item is NOT the one I would like to find, proceed to the next item
        while (NULL != temp && temp->data.id != id) {/// OLAY BURASI ZATEN temp->data.id != id
            prev = temp;
            temp = temp->next;
        }

        // I have to understand why that while loop did brake?
        // Because it has 2 different conditions
        // 1st condition : Item not found!
        // 2nd condition : Item found!

        if (NULL == temp){ // Item NOT found!
            printf("\tThere s no data about this element !\n");
            return head;
        }
        else { // ITEM FOUND!!!
            // We should understand which item we have found!
            // Is it first, last, or an inner item?

            // Case 1-) First item will be removed!
            if (temp == head) {
                SLLI* newHead = temp->next; // head->next
                free(temp);
                return newHead;
            } else {
                // Case 2-) If it is the INNER item to remove!
                // Case 3-) If it is the last item of the list!

//                 if (NULL != temp->next) {
//                     prev->next = temp->next;
//                     free(temp);
//                 } else /*if (NULL == temp->next)*/{ // Case 3-) The last item
//                     //prev->next = NULL; // equal to prev->next = temp->next;
//                     prev->next = temp->next;
//                     free(temp);
//                 }
                prev->next = temp->next;
                free(temp);

                return head;
            }

        }
    }// outer if

    return head;
}

SLLI* ReverseList(SLLI* head){
        // BASE CASE
    if (NULL == head)
        return head;

    // MAKING PROGRESS TOWARDS THE CASE
    SLLI* temp = ReverseList(head->next);
    return AddItemToEnd(temp, head);
    /** EN:No need to them but you may use,TR:Burdaki allta düşündüklerimin hiç birine gerek kalmadı
       // AddItemToEnd(temp->data.name, head->data.name);
       // AddItemToEnd(temp->data.id, head->data.);
       // AddItemToEnd(temp->data.gpa, head->data.gpa);
    */
}


SLLI* AddNewItemToFront(SLLI* head, SLLI* pItem)
{
    pItem->next = head;

    return pItem;
}

SLLI* ReverseListUsignAddItemToFront(SLLI* head)
{

    SLLI* newHead = NULL;

    while (NULL != head) {
        SLLI* next = head->next;
        head->next = NULL; ///Head i boşa çıkardık böylelikle
        newHead = AddNewItemToFront(newHead, head);
        head = next;
    }
    return newHead;
}

SLLI* DestructivelyReverseList(SLLI* head){

 /**EN:That'S better but not recoursive TR:bu daha güzel olan ama recoursive değil o yüzden
    SLLI* prev = NULL;
    SLLI* current = head;
    SLLI* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev; ///EN:Hence I pointed head which we've started to null value and other to behind it TR:Böylelike İlk başladığımız head i null değerine işaret ettirdim,sonrakilerde bir arkasına

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    return current;
*/
if (head == NULL || head->next == NULL)
            return head;
            /* reverse the rest list and put
          the first element at the end */
         SLLI* temp =head->next; ///EN:store one in front og head 1 hence  i may link last node to old head ,TR: head 1 önündeki elementi depoluyorum ki onun ucunu eski head e yeni son nodul olrak bağlayabilem
        SLLI* rest =  DestructivelyReverseList(head->next); ///EN:rotate all of them except first one,TR:ilki hariç hepsini döndürtme yapıyorum
        temp->next = head;///EN:I link as I did 2 line before hence old head can be last node TR:burdada 2 satır üstte yaptığım olayın ucuna buna bağlıyom ki eski head yeni son node olsun

        /* tricky step -- see the diagram */
        head->next = NULL; ///EN:I reset here so that i do not change last node  TR:bununda ucunu sıfırlıyorum ki son nodul olma kuralı değişmesin

        /* fix the head pointer */
        return rest;
}




SLLI* AddItemToFront(SLLI* head, Student* dataToAdd)
{
    // STEP 1-) Allocate memory for the new item
    //------------------------------------------
    // 1-) Allocate memory for a new SLLI item
    SLLI* pItem = (SLLI*) malloc(sizeof(SLLI));
    if (NULL == pItem) {
        printf("Cannot allocate memory for the new item!!!\n");
        exit(1);
    }
    // 2-) Put data into SLLI item
  strcpy(pItem->data.name , dataToAdd->name);///EN:I make solition wiht this.Do not forget to include string librarby TR:array olduğu için bu sıkıntıyı öyle çözebildim,string kütüphanesini de eklemeyi unutma
     strcpy(pItem->data.surname , dataToAdd->surname);
      pItem->data.id = dataToAdd->id;
       pItem->data.gpa = dataToAdd->gpa;

    // STEP 2-) Add new item in front of the list!
    //--------------------------------------------
    pItem->next = head;

    // return the new item's address as the new HEAD of the list!
    return pItem;
}

SLLI* AddItemToEnd(SLLI* head, Student* dataToAdd)
{
    SLLI* last;

    // 1-) Allocate memory for a new SLLI item
    SLLI* pItem = (SLLI*) malloc(sizeof(SLLI));
    if (NULL == pItem) {
        printf("Cannot allocate memory for the new item!!!\n");
        exit(1);
    }
    // 2-) Put data into SLLI item
    strcpy(pItem->data.name , dataToAdd->name);///EN:I make solition wiht this.Do not forget to include string librarby TR:array olduğu için bu sıkıntıyı öyle çözebildim,string kütüphanesini de eklemeyi unutma
     strcpy(pItem->data.surname , dataToAdd->surname);
      pItem->data.id = dataToAdd->id;
       pItem->data.gpa = dataToAdd->gpa;

    //3-) Set the next item as NULL (Because the new item will be the last item in the list!)
    pItem->next = NULL;


    //Case 0-) If the list doesn't have any items â€“ EMPTY LIST
    if (NULL == head)
        return pItem;

	//Case 1-) If the linked list has at least one item
	// STEP 1-) Proceed to the last item in the list
	last = head;
	while (NULL != last->next)
        last = last->next;
    // After while loop "last" point the last item in the list

	// STEP 2-) Create the new SLLI item
    // pItem has already been created at the beginning of the function !!!

	// STEP 3-) Add new item after the last item!
    last->next = pItem;

    return head;
}
