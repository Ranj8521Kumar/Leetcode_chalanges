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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;

        if(root){
            que.push(root);
        }

        while(!que.empty()){
            int len = que.size();

            TreeNode* lastNodeOfLevel;
            while(len--){
                TreeNode* node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

                lastNodeOfLevel = node;
            }

            result.push_back(lastNodeOfLevel->val);
        }

        return result;
    }
};