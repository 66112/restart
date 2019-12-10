#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int minDepth(TreeNode* root) {
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
	int left = minDepth(root->left), right = minDepth(root->right);
	return (left && right) ? 1 + min(left, right) : 1 + left + right;
}
int main()
{
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	cout << minDepth(root) << endl;
	return 0;
}