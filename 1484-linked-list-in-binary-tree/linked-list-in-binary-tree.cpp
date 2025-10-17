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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(ListNode* head, TreeNode* root){
        if(head == nullptr) return true;
        if(root == nullptr) return false;

        if(head->val != root->val){
            return false;
        }

        return check(head->next, root->left) || check(head->next, root->right);
    }



    bool solve(ListNode* head, TreeNode* root, ListNode* temp){
        if(temp == nullptr){
            return true;
        }

        if(root == nullptr){
            return false;
        }

        // If match then continue matching:
        if(root->val == temp->val){
            //temp = temp->next; // Problem: reset temp to head inside the recursion, which breaks the ongoing match when the value mismatches mid-way.

            if((solve(head, root->left, temp->next) || solve(head, root->right, temp->next))){
                return true;
            }
        }

        // start new matching from this node again
        return (solve(head, root->left, head) || solve(head, root->right, head));
        
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        // This Approach gives TLE:

        // ListNode* temp  = head;
        // return solve(head, root, temp);















        // -------------------------------------------------- //
        if(!root ) return false;

        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};