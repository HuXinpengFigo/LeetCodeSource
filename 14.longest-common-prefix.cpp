/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.13%)
 * Total Accepted:    427.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string result = {""};
        bool flag = true;
        int min_length = 100;
        if(s.size()==1){
            return s[0];
        }
        for(int i = 0;i < s.size();i++){
            if(s[i].size()<min_length){
                min_length = s[i].size();
            }
        }
        for(int i=0;flag && i<min_length;i++){
            for(int j=1;j<s.size();j++){
                
                if(result.size()<=i){ //先将本次出现的头一个字母加入result中
                    result+=s[j][i];
                }
                if(s[j][i]!=s[j-1][i]){ //若出现有哪个单词的该位置字母不同，则将该位置字母从result中剔除
                    result.pop_back();
                    flag = false;
                    break;      //有问题！！
                }
            }
        }
        return result;
    }
};

