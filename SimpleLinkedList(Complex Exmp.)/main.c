#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedlistComp.h"
int main(){

    int student_count,i,*x,k;
    Student* student_dynamic_array;
    Student* newStudent;
    SLLI* head =NULL;

  printf("How many students will be registered for this course : ");
    scanf("%d", &student_count);
    student_dynamic_array = (Student*) malloc(sizeof(Student) * student_count);
    if (NULL == student_dynamic_array) {
        printf("Cannot do allocation");
        exit(1);
    }
    printf("Please enter sutdents info\n");
     printf("Do not enter 133 as id\n"); ///We're trying to delete function that's why I wrote do not enter 133
  fflush(stdin);
    for(i=0;i<student_count;i++){
      printf("Name\n");scanf("%s",(student_dynamic_array+i)->name);///EN:Syntaxes here are very important, TR:buradaki syntax lar önemli
      printf("SurName\n");scanf("%s",(student_dynamic_array+i)->surname);
      printf("id\n");scanf("%d",&(student_dynamic_array+i)->id);
      if(i==0){
        x=(student_dynamic_array+i)->id;
      }
      if(i==student_count-1){
        k=(student_dynamic_array+i)->id;
      }
      printf("gpa\n");scanf("%lf",&(student_dynamic_array+i)->gpa);
            }
             printf("-----------\n");
for(i=0;i<student_count;i++){
        printf("%s\n",(student_dynamic_array+i)->name);
      printf("%s\n",(student_dynamic_array+i)->surname);
     printf("%d\n",(student_dynamic_array+i)->id);
     printf("%lf\n\n",(student_dynamic_array+i)->gpa);
            }

printf("\nLETS MAKE THEM AN SLL\n");
for (i = 0; i<student_count; ++i){
    head= AddItemToEnd(head,(student_dynamic_array+i));
}
printf("Printing as a SSL\n\n");

printList(head);


newStudent= (Student*) malloc(sizeof(Student) * 1);
    if (NULL == newStudent) {
        printf("Cannot do allocation-2");
        exit(1);
    }
strcpy(newStudent->surname , "ali");///EN:It can be change.You may ask user too TR:bu değişebilir aynı şekilde kullanıcıya da sorulabilir.
strcpy(newStudent->name , "veli");
newStudent->id = 133;
newStudent->gpa=1.9;

    head = AddItemToFront(head,newStudent);
printf("--------------\n Printing list after AddFront\n");


printList(head);


printf("--------------------- Printing List (PrintListReverse)\n");

PrintListReverse(head);

printf("--------------------- Printing List (PrintListRecursive) //standart \n");

PrintListRecursive(head);

printf("--------------------- Printing List (ReverseList(SLLI* head))\n");

head = ReverseList(head);
printList(head);

printf("--------------------- Printing List (SLLI* ReverseListUsignAddItemToFront(SLLI* head))\n");

head =ReverseListUsignAddItemToFront(head);
printList(head);

printf("--------------------- Printing List (SLLI* DestructivelyReverseList(SLLI* head))\n");

head = DestructivelyReverseList(head);
printList(head);

printf("****************************\n");

     printf("Remove Manuel is deleted \n\n");
     head = DeleteFromList(head,133);
     printList(head);

/**
     printf("Remove the first item\n");
     printf("%d\n",x);
     head = DeleteFromList(head,x);
     printList(head);
    /*
   printf("Remove an inner item\n");
    printf("%d\n",k);
   head = DeleteFromList(head,k);
   printList(head);
*/
    printf("Remove an item which is NOT in the list\n");
    head = DeleteFromList(head, 133);
    printList(head);

return 0;
}

