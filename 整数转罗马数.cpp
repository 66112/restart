vector<int> store = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
vector<string> strs = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
string intToRoman(int num) {
	string ret;
	for (int i = 0; i<store.size(); i++){
		while (num >= store[i]){
			ret.append(strs[i]);
			num -= store[i];
		}
	}
	return ret;
}