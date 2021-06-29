#ifndef file
#define file
typedef struct tagNode {
    int data;
    // struct Student data;
    // struct Student* data;
    struct tagNode* left;
    struct tagNode* right;
}Node;
Node* AddItemToTree(Node* root, int dataToAdd);
void PrintTree(Node* root);
int tree_height(Node* root);
#endif
