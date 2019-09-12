/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        bool flagLast=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ')//防止“a  ”这种情况出现影响结果
                flagLast=true;
            if(flagLast){
                if(s[i]==' ')
                    break;
                count++;
            }
        }
        return count;
    }
};

