
struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int find(vector<int>& inorder, int cur)
{
	for (int i = 0; i<inorder.size(); i++){
		if (inorder[i] == cur){
			return i;
		}
	}
	return -1;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (inorder.empty() || postorder.empty()) return nullptr;
	if (inorder.size() < 2 || postorder.size() < 2) return new TreeNode(inorder[0]);
	int cur = postorder[postorder.size() - 1];
	TreeNode* root = new TreeNode(cur);
	int pos = find(inorder, cur);
	vector<int> inorder_left(inorder.begin(), inorder.begin() + pos);
	vector<int> inorder_right(inorder.begin() + pos + 1, inorder.end());
	vector<int> postorder_left(postorder.begin(), postorder.begin() + inorder_left.size());
	vector<int> postorder_right(postorder.begin() + inorder_left.size(), postorder.begin() + postorder_left.size() + inorder_right.size());
	root->left = buildTree(inorder_left, postorder_left);
	root->right = buildTree(inorder_right, postorder_right);
	return root;
}