/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * 主要思路：
 *      先创建一个头节点（最后删去）
 *      将l1,l2这两个链表进行比较，小的按照尾插法插到头节点之后
 *      l1,l2之间必有一个先全部插入完毕，剩下的一个直接连接到结果尾部就行
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2)
            return NULL;
        else if (l1&&!l2)
            return l1;
        else if (l2&&!l1)
            return l2;
        ListNode *result = new ListNode(0);
        ListNode *end = result;
        ListNode *pl1=l1,*pl2=l2;
        while(pl1&&pl2){
            if(pl1->val < pl2->val){
                end->next = pl1;
                // end=end->next;
                pl1=pl1->next;
            }
            else
            {
                end->next = pl2;
                // end=end->next;
                pl2=pl2->next;
            }
            end=end->next; //放里放外都可
        }
        if(pl1){//剩下的连接到尾部
            end->next = pl1;
        }else if(pl2){
            end->next = pl2;
        }
        result = result->next;
        return result;
    }
};

