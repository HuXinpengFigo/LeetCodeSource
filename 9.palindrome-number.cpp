/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (42.40%)
 * Total Accepted:    533.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
class Solution
{
  public:
    bool isPalindrome(int p)
    {
        if(p == 0)
            return true;
        if (p < 0 || p % 10 == 0)
        {
            cout << "not" << endl;
            return false;
        }
        int array[100];
        int level = 0;
        for (int i = 0; p != 0; i++)
        {
            int tem = p % 10;
            array[i] = tem;
            p = p / 10;
            level++;
        }
        for (int i = 0; i < level / 2; i++)
        {
            if (array[i] != array[level - 1 - i])
            {
                // cout << "not" << endl;
                return false;
            }
        }
        // cout << "yes" << endl;
        return true;
    }
};
