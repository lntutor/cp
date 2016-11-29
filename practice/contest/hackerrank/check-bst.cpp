//https://www.hackerrank.com/challenges/ctci-is-binary-search-tree


#define MAX 1<<31 - 1
#define MIN -MAX

bool checkBST(Node* root, int min, int max) {
    if (root == NULL) return true;
    return root->data > min && root->data < max
        && checkBST(root->left, min, root->data)
        && checkBST(root->right, root->data, max);

}
bool checkBST(Node* root) {
    return checkBST(root, MIN, MAX);
}
