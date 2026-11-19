#include <stdio.h>
#include <stdlib.h>
// AVL Node Structure
struct Node {
int key;
struct Node *left;
struct Node *right;
int height;
};
// Utility function to get height
int height(struct Node *N) {
if (N == NULL)
return 0;
return N->height;
}
// Utility function to get maximum
int max(int a, int b) {
return (a > b) ?a : b;
}
// Create new node
struct Node* newNode(int key) {
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->key = key;
node->left = NULL;
node->right = NULL;
node->height = 1;
return node;
}
// Right Rotation (LL Case)
struct Node* rightRotate(struct Node *y) {
struct Node *x = y->left;
struct Node *T2 = x->right;
x->right = y;
y->left = T2;
y->height = max(height(y->left), height(y->right)) + 1;


x->height = max(height(x->left), height(x->right)) + 1;
return x;
}
// Left Rotation (RR Case)
struct Node* leftRotate(struct Node *x) {
struct Node *y = x->right;
struct Node *T2 = y->left;
y->left = x;
x->right = T2;
x->height = max(height(x->left), height(x->right)) + 1;
y->height = max(height(y->left), height(y->right)) + 1;
return y;
}
// Get Balance Factor
int getBalance(struct Node *N) {
if (N == NULL)
return 0;
return height(N->left) - height(N->right);
}
// Insert Node
struct Node* insert(struct Node* node, int key) {
// Normal BST Insert
if (node == NULL)
return newNode(key);
if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
else
return node; // No duplicates
// Update height
node->height = 1 + max(height(node->left), height(node->right));
int balance = getBalance(node);
// LL Case
if (balance > 1 && key < node->left->key)
return rightRotate(node);
// RR Case
if (balance < -1 && key > node->right->key)
return leftRotate(node);
// LR Case
if (balance > 1 && key > node->left->key) {
node->left = leftRotate(node->left);
return rightRotate(node);
}
// RL Case
if (balance < -1 && key < node->right->key) {
node->right = rightRotate(node->right);
return leftRotate(node);
}
return node;
}
// Find minimum node (used in deletion)
struct Node* minValueNode(struct Node* node) {
struct Node* current = node;
while (current->left != NULL)
current = current->left;
return current;
}
// Delete Node
struct Node* deleteNode(struct Node* root, int key) {
if (root == NULL)
return root;
if (key < root->key)
root->left = deleteNode(root->left, key);
else if (key > root->key)
root->right = deleteNode(root->right, key);
else {
if ((root->left == NULL) || (root->right == NULL)) {
struct Node *temp = root->left ? root->left : root->right;
if (temp == NULL) {
temp = root;
root = NULL;
} else
*root = *temp;
free(temp);
} else {
struct Node* temp = minValueNode(root->right);
root->key = temp->key;
root->right = deleteNode(root->right, temp->key);
}
}
if (root == NULL)
return root;
root->height = 1 + max(height(root->left), height(root->right));
int balance = getBalance(root);
// LL
if (balance > 1 &&getBalance(root->left) >= 0)
return rightRotate(root);
// LR
if (balance > 1 &&getBalance(root->left) < 0) {
root->left = leftRotate(root->left);
return rightRotate(root);
}
// RR
if (balance < -1 &&getBalance(root->right) <= 0)
return leftRotate(root);
// RL
if (balance < -1 &&getBalance(root->right) > 0) {
root->right = rightRotate(root->right);
return leftRotate(root);
}
return root;
}
// Search
int search(struct Node* root, int key) {
if (root == NULL)
return 0;
if (root->key == key)
return 1;
if (key < root->key)
return search(root->left, key);
else
return search(root->right, key);
}
// Inorder Traversal
void inorder(struct Node *root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->key);
inorder(root->right);
}
}
// Main Function
int main() {
struct Node* root = NULL;
int choice, key;
while (1) {
printf("\n--- AVL Tree Menu ---\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Search\n");
printf("4. Display (Inorder)\n");
printf("0. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter key to insert: ");
scanf("%d", &key);
root = insert(root, key);
break;
case 2:
printf("Enter key to delete: ");
scanf("%d", &key);
root = deleteNode(root, key);
break;
case 3:
printf("Enter key to search: ");
scanf("%d", &key);
if (search(root, key))
printf("Key found\n");
else
printf("Key not found\n");
break;
case 4:
printf("Inorder Traversal: ");
inorder(root);
printf("\n");
break;
case 0:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}
	
	   
	      
	
     
   
