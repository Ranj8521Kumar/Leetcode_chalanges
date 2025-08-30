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
    // ListNode* merge(ListNode* head1, ListNode* head2){
    //     ListNode* dummyNode = new ListNode(-1);
    //     ListNode* current = dummyNode;

    //     while(head1 && head2){
    //         if(head1->val <= head2->val){
    //             current->next = head1;
    //             head1 = head1->next;
    //         }else{
    //             current->next = head2;
    //             head2 = head2->next;
    //         }
    //         current = current->next;
    //     }

    //     while(head1){
    //         current->next = head1;
    //         current = current->next;
    //         head1 = head1->next;
    //     }

    //     while(head2){
    //         current->next = head2;
    //         current = current->next;
    //         head2 = head2->next;
    //     }

    //     return dummyNode->next;
    // }

    ListNode* mergeRecursion(ListNode* head1, ListNode* head2){
        if(head1 == nullptr) return head2;
        if(head2 == nullptr) return head1;

        if(head1->val <= head2->val){
            head1->next = mergeRecursion(head1->next, head2);
            return head1;
        }else{
            head2->next = mergeRecursion(head1, head2->next);
            return head2;
        }
    }

    ListNode* partionAndMerge(int s, int e, vector<ListNode*>& lists){
        if(s == e){
            return lists[e];
        }

        int mid = s + (e - s)/2;

        ListNode* l1 = partionAndMerge(s, mid, lists);
        ListNode* l2 = partionAndMerge(mid + 1, e, lists);

        return mergeRecursion(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // int k = lists.size();
        // ListNode* list1 = nullptr;

        // for(auto &list2 : lists){
        //     list1 = merge(list1, list2);
        // }

        // return list1;


        //Let's try more efficient Approach using merge sort
        int k = lists.size();

        if(k == 0) return nullptr;

        return partionAndMerge(0, k-1, lists);
    }
};