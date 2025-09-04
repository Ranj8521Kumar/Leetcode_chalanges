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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int n = 0;
        ListNode* curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }

        curr = head;
        ListNode* dummyHead = head;
        k = k % n;
        int cnt = n - k - 1;
        while(cnt > 0){
            curr = curr->next;
            cnt--;
        }

        bool first = true;
        while(curr->next){
            if(first){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                temp->next = head;
                head = temp;
                dummyHead = temp;
                first = false;
            }else{
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                ListNode* temp1 = dummyHead->next;
                dummyHead->next = temp;
                dummyHead = dummyHead->next;
                dummyHead->next = temp1;
            }
        }

        return head;
    }
};