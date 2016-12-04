/*
Node is defined as

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

node * insert(node * root, int value)
{
   if (root == NULL) {
       node * current = new node();
       current->data = value;
       current->left = NULL;
       current->right = NULL;
       return current;
   }
   if (value < root->data) {
       root->left = insert(root->left, value);
   } else if (value > root->data) {
       root->right = insert(root->right, value);
   }
   return root;
}
