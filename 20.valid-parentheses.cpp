/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 * 主要思路：
 *      遇到左括号直接入栈，遇到右括号就看现在栈顶是否为其对应的左括号
 *      ，非对应的左括号则直接入栈。
 *      最后看全部操作完成后栈是不是为空，为空则能成功匹配。
 */
class Solution {
public:
    bool isValid(string s) {
        if( s.length()==0)
            return true;
        stack<char> checkS;
        for(int i = 0;i < s.length();i++){
            switch (s[i])
            {
            case '(':
                checkS.push(s[i]);
                continue;
            case '[':
                checkS.push(s[i]);
                continue;
            case '{':
                checkS.push(s[i]);
                continue;
            case ')':
                if(checkS.empty())
                    return false;
                if( checkS.top() == '('){
                    checkS.pop();
                }
                else
                {
                    checkS.push(s[i]);
                }
                continue;
            case ']':
                if(checkS.empty())
                    return false;
                if( checkS.top() == '['){
                    checkS.pop();
                }else
                {
                    checkS.push(s[i]);
                }
                continue;
            case '}':
                if(checkS.empty())
                    return false;
                if( checkS.top() == '{'){
                    checkS.pop();
                }else
                {
                    checkS.push(s[i]);
                }
                continue;
            default:
                break;
            }
        }
        if(!checkS.empty())
            return false;
        return true;
    }
};


/*
    更简洁写法：不用switch，直接使用if
*/

class Solution {
public:
bool isValid(string s) 
{
    if(s.empty())
        return true;
    
    stack<char> st;
    
    for(char c:s)
    {
        if(c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if(st.empty()) return false;
            if(c == ']' && st.top()!= '[') return false;
            if(c == '}' && st.top()!= '{') return false;
            if(c == ')' && st.top()!= '(') return false;
            
            st.pop();
        }
    }
        
    return st.empty();
}
};
