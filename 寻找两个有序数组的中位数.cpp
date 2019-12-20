#include <vector>
#include <algorithm>
using namespace std;
double MedianNums(vector<int>& nums){
	if (nums.size() % 2 == 0){
		return (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
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

//����һ
double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
	if (m > n){		//to m<=n
		vector<int> tmp = nums1;
		nums1 = nums2;
		nums2 = tmp;
		int temp = m;
		m = n;
		n = temp;
	}
	int iMin = 0, iMax = m, halflen = (m + n + 1) / 2;
	while (iMin <= iMax){
		int i = (iMin + iMax) / 2;
		int j = halflen - i;
		if (i<iMax && nums2[j - 1]>nums1[i]){
			iMin = i + 1;
		}
		else if (i > iMin && nums1[i - 1] > nums2[j]){
			iMax = i - 1;
		}
		else{
			int maxleft = 0;
			if (i == 0){
				maxleft = nums2[j - 1];
			}
			else if (j == 0){
				maxleft = nums1[i - 1];
			}
			else{
				maxleft = max(nums1[j - 1], nums2[j - 1]);
			}
			if ((m + n) % 2 == 1) {
				return maxleft;
			}
			int minright = 0;
			if (i == m){
				minright = nums2[j];
			}
			else if (j == n){
				minright = nums1[i];
			}
			else{
				minright = min(nums2[j], nums1[i]);
			}
			return (maxleft + minright) / 2.0;
		}
	}
	return 0.0;
}

//������
//iΪnums1����ʼλ�ã�jΪnums2����ʼλ��
int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
	if (i >= nums1.size()) return nums2[j + k - 1];	//nums1Ϊ��
	if (j >= nums2.size()) return nums1[j + k - 1]; //nums2Ϊ��
	if (k == 1) return min(nums1[i], nums2[j]);
	//�ҵ������еĵ�k/2���Ԫ�أ����û�и����������ֵ
	int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
	int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
	//���nums1���м�ֵС��nums2���м�ֵ������̭nums1��ǰk/2��Ԫ�أ���k���Ϊ��( k - k/2 )�󣬵ݹ�
	if (midVal1 < midVal2)
		return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
	else
		return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
}
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
	int left = (m + n + 1) / 2;
	int right = (m + n + 2) / 2;
	return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
}
int main()
{
	vector<int> nums1 = { 1, 2, 5 };
	vector<int> nums2 = { 3, 4, 6 };
	double ret = findMedianSortedArrays(nums1, nums2);
	double ret1 = findMedianSortedArrays1(nums1, nums2);
	double ret2 = findMedianSortedArrays2(nums1, nums2);
	return 0;
}