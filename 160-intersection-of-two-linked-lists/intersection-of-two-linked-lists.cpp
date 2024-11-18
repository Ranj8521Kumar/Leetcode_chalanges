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
    

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }

        int len1 = 0;
        int len2 = 0;

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA){
            len1++;
            tempA = tempA->next;
        }

        while(tempB){
            len2++;
            tempB = tempB->next;
        }

        if(len1 > len2){
            int diff = len1 - len2;
            while(diff--){
                headA = headA->next;
            }
        }else{
            int diff = len2 - len1;
            while(diff--){
                headB = headB->next;
            }
        }

        while(headA){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};