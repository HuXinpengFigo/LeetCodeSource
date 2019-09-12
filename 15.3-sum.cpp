/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 * 主要方法为：
 *      先从小到大排序好，之后从第一个开始，选取第一个为基准，在之后的部分
 *      参照快排的思想，选首尾元素来查找是否有匹配的元素。
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	std::vector<vector<int>> result;
	if (nums.empty()) {
		return result;
	}

	std::size_t n_size = nums.size();
	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < n_size; ++i) {
		// all numbers from now on will be greater than 0, no point in continuing
        //全为正数之后不可能出现三个相加为0的情况
		if (nums[i] > 0) break;

		// we have seen this number & combo before; skip
        //去重，重复出现的原因就是排序好的元素有相等的存在
		if (i > 0 and nums[i] == nums[i-1]) continue;

		int left = i+1, right = n_size - 1;
		while (left < right) {
			int sum = nums[i] + nums[left] + nums[right];
			if (sum < 0) {
				++left;
			} else if (sum > 0) {
				--right;
			} else {
				result.push_back({nums[i], nums[left], nums[right]});
				int last_left = nums[left], last_right = nums[right];
				// we have seen this number & combo before; skip
                //此处重要，必须要移动首位指向的元素，且防止相同元素重复push进vector
				while (left < right && nums[left] == last_left) ++left;
				while (left < right && nums[right] == last_right) --right;
			}
		}

	}
	return result;
}
};

