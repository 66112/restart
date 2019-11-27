//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//void func(vector<string>& res, string str, int l, int r, int n)
//{
//	if (l > n || r > n || r > l) return;
//	if (l == n && r == n) {
//		res.push_back(str);
//		return;
//	}
//	func(res, str + '(', l + 1, r, n);
//	func(res, str + ')', l, r + 1, n);
//}
//vector<string> generateParenthesis(int n) {
//	vector<string> ret;
//	func(ret, "", 0, 0, n);
//	return ret;
//}
//
//int main()
//{
//	generateParenthesis(2);
//	return 0;
//}