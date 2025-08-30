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
        int len = 0;
        ListNode* temp = head;

        if(!head) return head;

        while(temp){
            len++;
            temp = temp->next;
        }

        if(len == 1){
            return nullptr;
        }

        if(len == n) return head->next;

        int n1 = len - n - 1; // Now (n + 1)th node from begining
        ListNode* curr = head;
        while(n1--){
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return head;
    }
};