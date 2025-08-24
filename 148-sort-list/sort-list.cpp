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
    ListNode* sortList(ListNode* head) {
        //Simple Brute Force Approach:
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        sort(arr.begin(), arr.end());

        int n = arr.size();
        temp = head;

        for(int i = 0; i<n; i++){
            temp->val = arr[i];
            temp = temp->next;
        }

        return head;
    }
};