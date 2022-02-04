void preOrder(node* root) {
	if (root == nullptr)return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(node* root) {
	if (root == nullptr)return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}

void inOrder(node* root) {
	if (root == nullptr)return;
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

void levelOrder(node* root) {
	if (root == nullptr) return;
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			node* x = q.front();
			q.pop();
			if (x->left) q.push(x->left);
			if (x->right) q.push(x->right);
			cout << x->val << " ";
		}
		cout << endl;
	}
}