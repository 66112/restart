//三种情况：a+b+c, a+b+a的父节点, a+c+a的父节点
int result;
int maxPathSum(TreeNode* root) {
	if (!root) return 0;
	result = root->val;
	dfs(root);
	return result;
}

int dfs(TreeNode* root){
	if (!root) return 0;
	int left = max(dfs(root->left), 0);  //子树的最大和
	int right = max(dfs(root->right), 0);
	result = max(root->val + left + right, result);  //第一种情况
	return root->val + max(0, max(left, right));    //返回a+b或a+c
}