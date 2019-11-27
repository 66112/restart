#include <iostream>
#include <string>
#include <vector>
using namespace std;
int findNum(string& s, int start){
	for (int i = start; i < s.length(); i++){
		if (s[i] >= '0' && s[i] <= '9')
			return i;
	}
	return -1;
}
int findFlag(string& s, int start){
	for (int i = start; i < s.length(); i++){
		if (s[i] == '-')
			return i;
	}
	return -1;
}
void get_val(vector<pair<int, int>>& v, string& S){
	int i = 0, j = findFlag(S, 0);	//i是一组数据的开头，j是结尾的下一个
	int deep = 0, val = stoi(S.substr(0, j));
	v.push_back(make_pair(deep, val));
	while (j >= 0 && j < S.length()){
		i = j;
		deep = findNum(S, i) - i;
		int start = i + deep;
		j = findFlag(S, start);
		val = stoi(S.substr(start, j - start));
		v.push_back(make_pair(deep, val));
	}
}
int main()
{
	string s = "12----3--4-5--6--7";
	vector<pair<int, int>> v;
	get_val(v, s);
	return 0;
}