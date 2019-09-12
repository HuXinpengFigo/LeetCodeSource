/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos;
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]<target)  //大于和等于的情况都是返回i
                continue;
            else
                return i;
        }
        return i;   //target大于nums中所以元素的情况
    }
};

