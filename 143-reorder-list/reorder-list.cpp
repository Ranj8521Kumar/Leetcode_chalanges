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

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         // Find Middle
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast && fast->next){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         stack<ListNode*> st;
//         ListNode* tempSlow = slow;
//         while(slow->next){
//             st.push(slow->next);
//             slow = slow->next;
//         }

//         tempSlow->next = nullptr;

//         ListNode *temp = head;
//         while(!st.empty()){
//             ListNode *node = st.top(); st.pop();
//             ListNode *t = temp->next;
//             temp->next = node;
//             node->next = t;

//             temp = temp->next->next;
//         }
//     }
// };



// -------------------------------------------------------- //

class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

    void reorderList(ListNode* head) {
        // Find Middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tempSlow = slow;
        tempSlow->next = reverse(slow->next);

        ListNode *temp = head;
        while(tempSlow->next){
            ListNode *node = temp->next;
            temp->next = tempSlow->next;
            tempSlow->next = tempSlow->next->next;
            temp->next->next = node;

            temp = temp->next->next;
        }
    }
};