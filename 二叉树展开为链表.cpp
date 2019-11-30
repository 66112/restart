/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	void exchang(TreeNode* root)
	{
		if (!root) return;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		exchang(root->left);
		exchang(root->right);
	}
	void flatten(TreeNode* root) {
		if (!root) return;
		//生成左链表
		dfs(root);
		//交换成右链表
		exchang(root);
	}
	//每次返回左子树的最后一个节点
	TreeNode* dfs(TreeNode* root){
		if (!root->left && !root->right)
			return root;
		if (!root->left && root->right){
			root->left = root->right;
			root->right = nullptr;
			return dfs(root->left);
		}
		if (root->left && !root->right){
			return dfs(root->left);
		}
		TreeNode* lastNode = dfs(root->left);
		lastNode->left = root->right;
		root->right = nullptr;
		return dfs(lastNode->left);
	}
};