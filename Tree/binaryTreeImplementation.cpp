// Node of a Binary Tree
struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int v) {
		val = v;
		right = left = nullptr;
	}
};

// Build Tree in preorder traversal
Node* buildTree() {
	int v;
	cin >> v;

	if (v == -1) {
		return nullptr;
	}
	Node* n = new Node(v);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

