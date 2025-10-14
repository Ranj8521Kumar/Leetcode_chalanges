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
    void reorderList(ListNode* head) {
        // Find Middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<ListNode*> st;
        ListNode* tempSlow = slow;
        while(slow->next){
            st.push(slow->next);
            slow = slow->next;
        }

        tempSlow->next = nullptr;

        ListNode *temp = head;
        while(!st.empty()){
            ListNode *node = st.top(); st.pop();
            ListNode *t = temp->next;
            temp->next = node;
            node->next = t;

            temp = temp->next->next;
        }
    }
};