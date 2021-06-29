#include "file.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    Node* root = NULL;
    int data[] = { 4, 6, 2, 5, 3, 1, 7 };


    for (i = 0; i < 7; ++i)
        root = AddItemToTree(root, data[i]);

    PrintTree(root);
    int height =tree_height(root);
    printf("\n height= %d",height);

}

