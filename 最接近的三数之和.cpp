//方法一
int threeSumClosest(vector<int>& nums, int target) {
	int small = INT_MAX;
	int ret = 0;
	int one = nums[0], two = nums[1];
	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size() - 2; i++){
		for (int j = i + 1; j<nums.size() - 1; j++){
			for (int k = j + 1; k<nums.size(); k++){
				int tmp = nums[i] + nums[j] + nums[k];
				if (tmp == target)
					return target;
				else{
					if (abs(tmp - target) < small){
						small = abs(tmp - target);
						ret = tmp;
					}
				}
			}
		}
	}
	return ret;
}

//方法二
int threeSumClosest(vector<int>& nums, int target) {
	int ret = nums[0] + nums[1] + nums[2];
	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size() - 2; i++){
		int left = i + 1, right = nums.size() - 1;
		while (left < right){
			int tmp = nums[i] + nums[left] + nums[right];
			if (abs(tmp - target) < abs(ret - target))
				ret = tmp;
			if (tmp > target)
				right--;
			else if (tmp < target)
				left++;
			else
				return tmp;
		}
	}
	return ret;
}

