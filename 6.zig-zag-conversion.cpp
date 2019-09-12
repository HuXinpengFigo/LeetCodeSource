/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 * 
 * 两种方法：
 *      一：
 *          将字符串按照每个zigzagSize(实际上并不是一个完整的z，少了最后一撇)分组
 *          分组之后，先将z字的第一撇和斜边分开想，分别从一个组的顺序和反序进行思考，
 *          最后按规律加入要返回的数组。
 *      二：
 *          首先按字符串s长度创建好要返回的字符串数组，暂且先都填上空格
 *          之后按照序号将s中对应位置的元素填入要返回的字符串数组。
 * 
 * 个人思维以及性能都偏向第二种方法。
 * 
 * 第二种方法中的重点算式(*)推导过程：
 * numsRow:       4             5
 *          0    A             A
 *          1    B (+4)-> F    B (+6)-> H
 *          3    C (+2)-> E    C (+4)-> G
 *          4    D             D (+2)-> F
 *          5                  E  ↑
 *          ↑                  由此得出*2
 *     由此可以得出(i+1)
 *     最终算式为  += (numsRow - (i+1))*2
 */
class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int n = s.size();
        if(numRows<=1 || n == 0) //重点，numRows<=1时zigzagSize计算异常，会导致之后i,j异常更新
            return s;
        int zigzagSize = 2*numRows - 2;
        int position;
        for(int row=0;row<numRows;row++){
            position = numRows -2;
            for(int i=row, j=zigzagSize-row/*j是重点*/;i<n;i+=zigzagSize,j+=zigzagSize){
                res=res+s[i];
                if(row>0&&row<numRows-1&&j<n){
                    res=res+s[j];
                }
            }
        }
        return res;
    }
};


/******第二种方法*******/

class Solution2 {
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1) return s;
        string result(s.size(), ' ');
        int count = 0;//count指向要返回的字符串result的元素位置
        for (int i = 0; i < numRows; ++i) 
        {
            for (int j = i; j < s.size(); j += 2*numRows-2/*zigzagSize*/)
            {
                if (i != 0 && i != numRows-1) 
                {
                    result[count] = s[j];
                    ++count;
                    if (j+ 2*(numRows-i-1) < s.size()) //重点算式(*)
                    { 
                        result[count] = s[j + 2*(numRows-i-1)];
                        ++count;
                    }
                }
                else
                {
                    result[count] = s[j];
                    ++ count;
                }
            }
        }
        return result;
    }
};

