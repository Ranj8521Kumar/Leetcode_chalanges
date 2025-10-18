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
    void fillStack(TreeNode* root, stack<TreeNode*>& st){
        if(!root) return;
        
        fillStack(root->right, st);
        st.push(root);
        fillStack(root->left, st);
    }

    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;

        fillStack(root, st);

        TreeNode* newRoot = st.top();
        TreeNode* temp = newRoot;
        st.pop();

        while(!st.empty()){
            TreeNode* node = st.top(); st.pop();
            temp->left = nullptr;
            temp->right = node;

            temp = temp->right;
        }

        temp->left = nullptr;
        temp->right = nullptr;
        return newRoot;
    }
};