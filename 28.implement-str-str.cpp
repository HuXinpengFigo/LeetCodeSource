/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 * 
 * 主要方法：
 *      首先按照needle的第一个元素与haystack的元素依次进行比较，如果出现
 *      相等的情况，则进入一个while循环，看是否整个needle都存在与haystack
 *      中。
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        if(haystack.size()==0||haystack.size()<needle.size()){//注意haystack长度小于needle的特殊情况
            return -1;
        }
        for(int i=0;i<haystack.size()-needle.size()+1;i++){
            int ptr=0;
            while(haystack[i+ptr]==needle[ptr]){
                ptr++;
                if(ptr==needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};

