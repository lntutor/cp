/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node class is defined as follows:
    class Node {
        int data;
        Node left;
        Node right;
     }
*/
    boolean checkBST(Node root, int min, int max) {
        if (root == null) return true;
        if (min >= root.data || max <= root.data) return false;
        return checkBST(root.left, min, root.data) && checkBST(root.right, root.data, max);
    }
    boolean checkBST(Node root) {
        return checkBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
