/*
Node is defined as

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

int my_max(int a, int b) {
    return a > b ? a : b;
}


int my_min(int a, int b) {
    return a < b ? a : b;
}

node * lca(node * root, int v1,int v2)
{
    int max = my_max(v1, v2);
    int min = my_min(v1, v2);
    if (root->data > max) {
        return lca(root->left, v1, v2);
    } else if (root->data < min) {
        return lca(root->right, v1, v2);
    }
    return root;
}
