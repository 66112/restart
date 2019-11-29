#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	if (intervals.size() < 2)
		return intervals;
	//依次按元素升序排列，
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> res;
	res.push_back(intervals[0]);
	for (int i = 1; i < intervals.size(); i++){
		//前一段区间的最大值和后一段区间的最小值比较
		if (res.back()[1] >= intervals[i][0]){
			res.back()[1] = max(res.back()[1], intervals[i][1]);
		}
		else{
			res.push_back(intervals[i]);
		}
	}
	return res;
}
int main()
{
	vector<vector<int>> vv({ { 4, 5 }, { 2, 4 }, { 4, 6 }, { 3, 4 }, { 0, 0 }, { 1, 1 }, { 3, 5 }, { 2, 2 } });
	vv = merge(vv);
	return 0;
}