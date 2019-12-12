//LeetCode:https ://leetcode-cn.com/problems/string-to-integer-atoi/submissions/
#include <string>
using namespace std;

int flag = 1;
long long ret = 0;
bool IsDigit(char c)
{
	return c >= '0' && c <= '9';
}

int DoMinus(string str)
{
	if (str.empty() || !IsDigit(str[0])) return 0;
	for (int i = 0; i<str.size(); i++){
		if (IsDigit(str[i])){
			ret = ret * 10 + str[i] - '0';
			ret *= -1;
			if (ret <= INT_MIN)
				return INT_MIN;
			else
				ret *= -1;
		}
		else
			break;
	}
	ret *= flag;
	return ret < INT_MIN ? INT_MIN : ret;
}

int DoPosti(string str)
{
	if (str.empty() || !IsDigit(str[0])) return 0;
	for (int i = 0; i<str.size(); i++){
		if (IsDigit(str[i])){
			ret = ret * 10 + str[i] - '0';
			if (ret >= INT_MAX)
				return INT_MAX;
		}
		else
			break;
	}
	return ret > INT_MAX ? INT_MAX : ret;
}

int myAtoi(string str) {
	if (str.empty()) return 0;
	for (int i = 0; i<str.size(); i++){
		if (str[i] == '-'){
			flag = -1;
			return DoMinus(str.substr(i + 1));    //第一个有效字符是 '-'
		}
		else if (str[i] == '+'){
			return DoPosti(str.substr(i + 1));    //第一个有效字符是 '+'
		}
		else if (IsDigit(str[i])){
			return DoPosti(str.substr(i));        //第一个有效字符是数字
		}
		else if (str[i] == ' '){
			continue;
		}
		else{
			return 0;
		}
	}
	return 0;
}