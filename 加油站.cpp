#include <vector>
using namespace std;
bool Can(int begin, vector<int>& gas, vector<int>& cost){
	int curgas = 0;
	int i = 0;
	int pos = begin;
	while (i < gas.size()){
		curgas += gas[pos];
		if (cost[pos] > curgas)
			return false;
		curgas -= cost[pos];
		pos++, i++;
		pos %= gas.size();
	}
	return true;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	for (int i = 0; i<gas.size(); i++){
		if (Can(i, gas, cost))
			return i;
	}
	return -1;
}

int main()
{
	vector<int> gas = { 3, 3, 4 };
	vector<int> cost = { 3, 4, 4 };
	int a = canCompleteCircuit(gas, cost);
	return 0;
}