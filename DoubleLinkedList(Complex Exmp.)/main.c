#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedListComp.h"
///I didn't use all of funcitons that I wrote.You may look DoubleLinkedListComp.h and DoubleLinkedListComp.c in this folder
int main()
{
    int student_count,i,*x,k;
    DLLI* student_dynamic_array=NULL;
    DLLI* head=NULL;

  printf("How many students will be registered for this course : ");
    scanf("%d", &student_count);

    student_dynamic_array = (DLLI*) malloc(sizeof(DLLI) * student_count);
    if (NULL == student_dynamic_array) {
        printf("Cannot do allocation");
        exit(1);
    }

    printf("Please enter sutdents info\n");
    printf("\n");
    fflush(stdin);
/*
    for(i=0;i<student_count;i++){
      printf("Name\n");scanf("%s",(student_dynamic_array+i)->name);///buradaki syntax lar önemli
      printf("SurName\n");scanf("%s",(student_dynamic_array+i)->surname);
      printf("id\n");scanf("%d",&(student_dynamic_array+i)->id);
      printf("gpa\n");scanf("%lf",&(student_dynamic_array+i)->gpa);
            }
    printf("*********************\nNormal :\n");
for(i=0;i<student_count;i++){
        printf("%s\n",(student_dynamic_array+i)->name);
      printf("%s\n",(student_dynamic_array+i)->surname);
     printf("%d\n",(student_dynamic_array+i)->id);
     printf("%lf\n\n",(student_dynamic_array+i)->gpa);
            }
*/
             printf("-----------\nAs DOUBLE  : \n");
             for(i=0;i<student_count;i++){

        printf("Name\n");scanf("%s",(student_dynamic_array+i)->name);///EN:Syntaxes here very important,TR:buradaki syntax lar önemli
    //    printf("%s\n",(student_dynamic_array+i)->name);
      printf("SurName\n");scanf("%s",(student_dynamic_array+i)->surname);
      printf("id\n");scanf("%d",&(student_dynamic_array+i)->id);
      printf("gpa\n");scanf("%lf",&(student_dynamic_array+i)->gpa);

               // head= AddItemToEnd(head,(student_dynamic_array+i));
               head=OrderedAddItem(head,(student_dynamic_array+i)); //Order byID
             }
             printf("..............................................\n");
             PrintList(head);
             printf("..............................................\n");
             PrintListRecursive(head);
             printf("..............................................\n");
             PrintListReverse(head);
             printf("..............................................ReverseList\n");
             head=ReverseList(head);
             PrintList(head);
             printf("..............................................\n");
             printf("Lets Delete one\n");
             head=DeleteItemOptimized(head,111);//WE MUST DELETE with ID 111.If There's no ıd with 111 then nothing will be deleted
             PrintList(head);
              printf("..............................................\n");

    return 0;
}
