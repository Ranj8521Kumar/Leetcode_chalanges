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
    // ListNode* reverse(ListNode* prev, ListNode* curr,  ListNode* nxt){
    //     if(curr == nullptr) return prev;

    //     nxt = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = nxt;

    //     return reverse(prev, curr, nxt);
    // }

    ListNode* reverseList(ListNode* head) {
        // ListNode* prev = nullptr;
        // ListNode* curr = head;
        // ListNode* nxt = nullptr;

        // while(curr){
        //     nxt = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nxt;
        // }

        // return prev;


        // using recursion method:
        // ListNode* prev = nullptr;
        // ListNode* curr = head;
        // ListNode* nxt = nullptr;

        // return reverse(prev, curr, nxt);


        //Another way of Recurrsion:
        if(!head || !head->next){
            return head;
        }

        ListNode* headRest = reverseList(head->next);
        ListNode* headTail = head->next;

        headTail->next = head;
        head->next = nullptr;

        return headRest;
    }
};