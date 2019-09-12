/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.21%)
 * Total Accepted:    636.3K
 * Total Submissions: 2.5M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
class Solution {
public:
    int reverse(long int x) {
    long long int result = 0;
    long long int newResult;
    while(x!=0){
        int tail = x%10;
        newResult = result*10 + tail;
        // if((newResult-tail)/10 != result)
        //     return 0; //此处会拖慢时间，但是空间占用很小，可以全部用int
        result = newResult;
        x /= 10;
    }
    if(result > __INT32_MAX__||result <= -__INT32_MAX__-1)
        return 0;
    return result;
    }
};

