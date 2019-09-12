/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 * 主要方法：
 *      使用一个记录当前出现目标值的数量count，记录好之后就可以
 *      利用该count值将之后出现的非目标值往前移动以覆盖目标值在
 *      数组中的位置，达到只扫描一遍数组就全部去掉目标值。
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int count=0;
        int length = nums.size();
        for(int i = 0; i<nums.size();i++){
            if(nums[i]==val){
                count++;
                continue;
            }
            nums[i-count]=nums[i];
        }
        length = length - count;
        return length;   
    }
};

