//·½·¨Ò»
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