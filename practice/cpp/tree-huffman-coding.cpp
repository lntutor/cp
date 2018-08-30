/*
   The structure of the node is

   typedef struct node
   {
   int freq;
   char data;
   node * left;
   node * right;

   }node;

*/

void printCharArray(vector<char> input) {
    for (int i = 0; i < input.size(); i++) printf("%c", input[i]);
}

void decode_huff(node * root,string s)
{
    vector<char> result(0);
    if (root == NULL) return;
    int loop = 0;
    node* tmp = root;
    while(loop <= s.length()) {//\n for end input
        if (tmp->left == NULL && tmp->right == NULL) {
            result.push_back(tmp->data);
            tmp = root;
            loop--;
        } else if (s[loop] == '0' && tmp->left) {
            tmp = tmp->left;
        } else if (s[loop] == '1' && tmp->right){
            tmp = tmp->right;
        }
        loop++;
    }
    printCharArray(result);

}
