public class Node {

	int node;
	Node left;
	Node right;

	public Node(int node) {
		this.node = node;
		this.left = null;
		this.right = null;
	}

	public static Node createMockupTree(){

		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);
		return root;

	}

	private static void printTree(Node root) {
		if (root != null) System.out.println(root.node);
		if (root.left != null) printTree(root.left);
		if (root.right != null) printTree(root.right);
	}

}