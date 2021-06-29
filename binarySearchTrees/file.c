#include <stdio.h>
#include <stdlib.h>
#include "file.h"
///aranan rakamı bul, max ,min, sil bi solundakinde(Şadi Evren deki) var






// root means the current node in this function and
// you may think that each node can be considered as a root for its own sub-tree
Node* AddItemToTree(Node* root, int dataToAdd)
{
    // This statement works for 2 purposes
    // 1-) If the tree is EMPTY
    // 2-) BASE CASE : We found an empty place
    if (NULL == root) {
        Node* pNewNode;
        pNewNode = (Node*) malloc(sizeof(Node));
        if (NULL == pNewNode) {
            printf("AddItemToTree - Can NOT allocate memory\n");
            exit(EXIT_FAILURE);
        }

        // Prepare a leaf node!
        pNewNode->data = dataToAdd;
        pNewNode->left = NULL;
        pNewNode->right = NULL;

        return pNewNode;
    } else {
        // Assignments below will create link if there is NOT one,
        // BUT they will keep the link "as is" if there was already one!
        if (root->data < dataToAdd)
            root->right = AddItemToTree(root->right, dataToAdd);// GO RIGHT!
        else
            root->left = AddItemToTree(root->left, dataToAdd);// GO LEFT!
        return root;
    }
}

// root means the current node in this function and
// you may think that each node can be considered as a root for its own sub-tree
void PrintTree(Node* root)
{
    // BASE CASE
    if (NULL == root)
        return;

    // 1-) We will GO LEFT FIRST
    // 2-) Print data when you come back from left
    // 3-) Go RIGHT

    printf("Data : %d\n", root->data);
    PrintTree(root->left);
    PrintTree(root->right);


//     PrintTree(root->right);
//     printf("Data : %d\n", root->data);
//     PrintTree(root->left);

}


/// max depth ile height ayni sey sanirsam

int tree_height(Node* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);/// bu ayni zamanda left depth
        int right_height = tree_height(root->right);/// bu ayni zamanda right depth
        if (left_height >= right_height)return left_height + 1;
       return right_height + 1;
	   	///ASLINDA BU ÇOK DAHA SIK DURUR. int max = (left_Height > right_Height) ? left_Height : right_Height;
    }
}

