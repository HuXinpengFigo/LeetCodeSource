/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 * 
 * 主要注意：
 *      注意出现进位的情况。
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        digits[digits.size()-1]++;
        if(digits[digits.size()-1]>9){
            carry=1;
            digits[digits.size()-1]%=10;
        }
        for(int i=digits.size()-2;i>=0;i--){
            digits[i]=digits[i]+carry;
            carry=0;
            if(digits[i]>9){    //出现进位，向前加一
                carry=1;
                digits[i]%=10;
            }
        }
        if(carry==1){   //最高位也出现进位，digits头部插入一个1
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

