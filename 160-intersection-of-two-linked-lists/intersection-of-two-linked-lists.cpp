/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* detectCycle(ListNode* head){
        ListNode *slow = head;
        ListNode *fast = head;

        bool hasCycle = false;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                hasCycle = true;
                break;
            }
        }

        if(!hasCycle){
            return nullptr;
        }

        slow = head;
        while(slow != fast){
            slow  = slow->next;
            fast = fast->next;
        }

        return slow;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode* mover = headA;
        while(mover->next != nullptr){
            mover = mover->next;
        }

        mover->next = headA;

        ListNode* result = detectCycle(headB);

        mover->next = nullptr;

        return result;
    }
};