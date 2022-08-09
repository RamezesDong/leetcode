/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode psedou(0);
        if(head == nullptr) {
            return nullptr;
        }
        psedou.next = head;
        
        ListNode* h1 = &psedou;
        ListNode* h2 = head;
        int count = 0;
        while(h2 != nullptr && count < n) {
            h2 = h2->next;
            count ++;
        }
        while(h2 != nullptr) {
            h2 = h2->next;
            h1 = h1->next;
        }
        h1->next = h1->next->next;
        return psedou.next;
    }
};
// @lc code=end

