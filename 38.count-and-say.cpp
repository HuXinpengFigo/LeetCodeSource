/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *  主要方法：
 *      递归，每次利用递归上一次操作return的string，对该string进行分析
 */
class Solution {
public:
    string countAndSay(int n) {
        string out = "";
        if(n==1){
            return "1";
        }
        int count = 1;
        string str=countAndSay(n-1)+"*";
        if(str.size()==1){
            return out = out + to_string(count) + str;
        }
        for(int i=0;i<str.size()-1;i++){
            if(str[i]==str[i+1]){
                count++;
            }else
            {
                out = out + to_string(count) + str[i];
                count = 1;
            }
        }
        return out;
    }
};

