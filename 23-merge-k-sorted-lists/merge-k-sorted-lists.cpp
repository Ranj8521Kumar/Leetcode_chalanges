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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;

        while(head1 && head2){
            if(head1->val <= head2->val){
                current->next = head1;
                head1 = head1->next;
            }else{
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }

        while(head1){
            current->next = head1;
            current = current->next;
            head1 = head1->next;
        }

        while(head2){
            current->next = head2;
            current = current->next;
            head2 = head2->next;
        }

        return dummyNode->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* list1 = nullptr;

        for(auto &list2 : lists){
            list1 = merge(list1, list2);
        }

        return list1;
    }
};