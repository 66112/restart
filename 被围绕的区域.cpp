//LeetCode 112题 https://leetcode-cn.com/problems/surrounded-regions/submissions/
class Solution {
public:
	void dfs(vector<vector<char>>& board, int i, int j)
	{
		if (i<0 || j<0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#')
			return;
		board[i][j] = '#';
		dfs(board, i - 1, j);
		dfs(board, i + 1, j);
		dfs(board, i, j - 1);
		dfs(board, i, j + 1);
	}
	void solve(vector<vector<char>>& board) {
		if (board.size() < 3)
			return;
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i<row; i++){
			for (int j = 0; j<col; j++){
				bool flag = (i == 0 || i == row - 1 || j == 0 || j == col - 1);	  //只判断第一行，第一列，最后一行，最后一列
				if (flag && board[i][j] == 'O')
					dfs(board, i, j);
			}
		}
		for (int i = 0; i<row; i++){
			for (int j = 0; j<col; j++){
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == '#'){
					board[i][j] = 'O';
				}
			}
		}
		return;
	}
};