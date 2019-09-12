/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *  主要思路：
 *      遇到前后两个元素不同，就把后面的不同的元素赋值给nums[count]位置上
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        if(nums.size()){
            count++;
            for(int i=0;i< nums.size()-1;i++){ //  取巧方法：不管最后元素如何，只看前面的元素
                if(nums[i]!=nums[i+1]){         // ，因为有不同元素，所以count肯定小于等于计数i
                    nums[count++]=nums[i+1];
                }
            }
        }
        return count;
    }
};

