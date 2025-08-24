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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next; //for getting first middle elment for the even length List

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeList(ListNode* head1, ListNode* head2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(head1 && head2){
            if(head1->val <= head2->val){
                temp->next = head1;
                head1 = head1->next;
            }else{
                temp->next = head2;
                head2 = head2->next;
            }

            temp = temp->next;
        }

        while(head1){
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }

        while(head2){
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }

        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {
        //Simple Brute Force Approach:
        // vector<int> arr;
        // ListNode* temp = head;
        // while(temp){
        //     arr.push_back(temp->val);
        //     temp = temp->next;
        // }
        
        // sort(arr.begin(), arr.end());

        // int n = arr.size();
        // temp = head;

        // for(int i = 0; i<n; i++){
        //     temp->val = arr[i];
        //     temp = temp->next;
        // }

        // return head;


        


        // Let's aplly more optimized approach using merge sort:
        if(head == nullptr || head->next ==  nullptr) return head;

        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeList(left, right);

    }
};