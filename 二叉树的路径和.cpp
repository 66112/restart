#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> vv;
void path(TreeNode* root, int sum, vector<int> tmp){
	if (!root) return;
	tmp.push_back(root->val);
	if (!root->left && !root->right){
		if (sum == root->val)
			vv.push_back(tmp);
		return;
	}
	if (root->left) path(root->left, sum - root->val, tmp);
	if (root->right) path(root->right, sum - root->val, tmp);
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<int> tmp;
	path(root, sum, tmp);
	return vv;
}