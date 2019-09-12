/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 * 
 * 主要方法：
 *      动态规划***很特别的方法，把每一位都看成是自己本身与子问题的解的对比
 *      达到只对数组进行一次遍历便找到答案
 * 状态转移方程：dp[i]=max(nums[i],dp[i-1]+nums[i])
 *      如：[-2,1,-3,4,-1,2,1,-5,4]
 *动态数组：[-2，1，-2，4，3，5，6，1，5]（每个子问题的解都由前一个子问题的解与当前原数组位置本身元素对比得来）
 *  -2:第一个元素为-2，无对比
 *   1:第二元素自己本身为1，先前子问题的解为-2+1=-1，显然自己本身1更优
 *  -2：第三元素自己本身为-3，先前子问题的解为1-3=-2，显然-2更优
 *   以此类推
 * 
 *  还有**分治法**此处暂且不研究
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int ret=nums[0];
        int tem;
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
            if(dp[i]>ret)
                ret=dp[i];
        }
        return ret;
    }
};

