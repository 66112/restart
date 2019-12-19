#include <vector>
using namespace std;
double MedianNums(vector<int>& nums){
	if (nums.size() % 2 == 0){
		return (nums[nums.size()/2] + nums[nums.size()/2 - 1]) / 2.0;
	}
	else{
		return nums[nums.size() / 2];
	}
}
vector<int> meragNums(vector<int>& nums1, vector<int>& nums2){
	vector<int> ret;
	int i = 0, j = 0;
	while (i<nums1.size() && j<nums2.size()){
		if (nums1[i] < nums2[j]){
			ret.push_back(nums1[i]);
			i++;
		}
		else{
			ret.push_back(nums2[j]);
			j++;
		}
	}
	if (i >= nums1.size()){
		while (j < nums2.size()){
			ret.push_back(nums2[j++]);
		}
		return ret;
	}
	if (j >= nums2.size()){
		while (i < nums1.size()){
			ret.push_back(nums1[i++]);
		}
		return ret;
	}
	return ret;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty()) return MedianNums(nums2);
	if (nums2.empty()) return MedianNums(nums1);
	vector<int> ret = meragNums(nums1, nums2);
	return MedianNums(ret);
}
int main()
{
	vector<int> nums1 = { 1, 2, 4, 6};
	vector<int> nums2 = { 2, 5, 7, 8};
	double ret = findMedianSortedArrays(nums1, nums2);
	return 0;
}