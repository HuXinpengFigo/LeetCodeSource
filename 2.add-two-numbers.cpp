/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *  主要难点：
 *         注意进位的特殊情形，下代码旁有列出
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=l1;
        int carry = 0;
        ListNode* pre=l1;
        while(l1&&l2){
            l1->val=l1->val+l2->val+carry;
            if(l1->val>9){
                carry = 1;
                l1->val=l1->val%10;
            }else{
                carry = 0;
            }
            pre=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){      //针对[9,2]+[1]情形，使得l1进位正常
            if(carry==1){
                l1->val=l1->val+carry;
                carry=0;
            }
            if(l1->val>9){
                carry = 1;
                l1->val=l1->val%10;
            }
            pre=l1;
            l1=l1->next;
        }
        if(l2){
            pre->next=l2;
        }
        while(l2){      //针对[1]+[9,2]情形，使得l2进位正常
            if(carry==1){
                l2->val=l2->val+carry;
                carry=0;
            }
            if(l2->val>9){
                carry = 1;
                l2->val=l2->val%10;
            }
            pre=l2;
            l2=l2->next;
        }
        if(carry==1&&!l1&&!l2){ //针对[1]+[9]（或[1]+[9,9]的最后一位进位）情形，开辟一个新结点，专门存放进位
            ListNode* over=new ListNode(1);
            pre->next=over;
        }
        return result;
    }
};

