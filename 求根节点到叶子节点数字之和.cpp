//https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/submissions/
void sumLeves(TreeNode* root, int ret, int& sum)
{
	if (!root) return;
	if (!root->left && !root->right){
		sum += (ret * 10 + root->val);
		return;
	}
	sumLeves(root->left, ret * 10 + root->val, sum);
	sumLeves(root->right, ret * 10 + root->val, sum);
}
int sumNumbers(TreeNode* root) {
	if (!root) return 0;
	int ret = 0;
	sumLeves(root, 0, ret);
	return ret;
}