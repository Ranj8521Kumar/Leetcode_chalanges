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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrder;

        queue<TreeNode*> que;

        if(!root){
            return levelOrder;
        };
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            vector<int> curr;

            for(int i = 0; i<n; i++){
                auto node = que.front();
                que.pop();

                curr.push_back(node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            levelOrder.push_back(curr);
        }

        return levelOrder;
    }
};