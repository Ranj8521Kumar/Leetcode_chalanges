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
    void solve(ListNode* prev){
        if(!prev->next || !prev->next->next){
            return;
        }

        ListNode* first = prev->next;
        ListNode* second = first->next;

        //swapping
        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;

        solve(prev);
    }

    ListNode* swapPairs(ListNode* head) {
        // ListNode* dummy = new ListNode(-1);
        // dummy->next = head;

        // ListNode* prev = dummy;

        // while(prev->next && prev->next->next){
        //     ListNode* first = prev->next;
        //     ListNode* second = first->next;

        //     // Swapping
        //     first->next =second->next;
        //     second->next = first;
        //     prev->next = second;

        //     prev = first;
        // }

        // return dummy->next;




        // Recursion Approach:
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        
        solve(prev);

        return dummy->next;
    }
};