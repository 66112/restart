#include <vector>
#include <string>
using namespace std;

vector<vector<string>> ret;
vector<string> v;

bool IsString(string& s)
{
	int i = 0, j = s.size() - 1;
	while (i < j){
		if (s[i] != s[j])
			return false;
		i++, j--;
	}
	return true;
}
void func(string& s, int a, int b)
{
	if (a > b){
		ret.push_back(v);
		return;
	}
	//iΪ���±�a����β���ַ�������
	for (int i = 1; i <= b - a + 1; i++){
		string tmp = s.substr(a, i);
		if (IsString(tmp)){
			v.push_back(tmp);
			//�ټ��������벿��
			func(s, a + i, b);
			v.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	func(s, 0, s.size() - 1);
	return ret;
}
int main()
{
	partition("aab");
	return 0;
}