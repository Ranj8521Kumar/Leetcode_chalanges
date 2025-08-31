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
    ListNode* reverse(ListNode* head, int d){
        if(!head || !head->next || d == 0) return head;

        ListNode* headRest = reverse(head->next, d-1);
        ListNode* headTail = head->next;

        headTail->next = head;
        head->next = nullptr;

        return headRest;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right) return head;

        //ListNode* prev = nullptr; //this will crete a issue for prev->next, when prev still remain nullptr for line 45, so
        ListNode dummy(0, head);
        ListNode*  prev = &dummy;
        ListNode* temp = head;

        int l = left - 1;
        while(l--){
            prev = temp;
            temp = temp->next;
        }

        int r = right - left + 1;
        ListNode* tail = temp;
        while(r--){
            tail = tail->next;
        }

        ListNode* headRest = reverse(temp, right - left);

        prev->next = headRest;

        // move temp to the last node of reversed sublist
        while(prev->next) prev = prev->next;
        prev->next = tail;

        return dummy.next;
    }
};
