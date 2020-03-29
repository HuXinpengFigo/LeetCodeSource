/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (37.23%)
 * Likes:    2880
 * Dislikes: 223
 * Total Accepted:    456.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 * 主要方法：
 *      主要的想法还是得先对其进行你想要的排序，来将无序的数据变成部分有序的数据。
 *      这里主要学习到了的是自定义sort()函数的比较因子，这是重点。
 *      其次也看到来vector容器的直接用地址进行操作的方法，也得熟记。
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        bool flag = false;
        vector<vector<int>> res;
        if(intervals.size()==0||intervals.size()==1)
            return intervals;

        sort(intervals.begin(),intervals.end(),cmp);

        res.push_back(intervals[0]);
        int i = 1;
        while(i < intervals.size()){
            vector<int>& last = res.back(); //注意这里是用的取址符号&
            if(last[1] < intervals[i][0]){
                res.push_back(intervals[i]);
            }else{
                last[1] = max(intervals[i][1],last[1]); //注意这里也要进行一次比较
            }
            i++;
        }
        return res;
    }
};
// @lc code=end

