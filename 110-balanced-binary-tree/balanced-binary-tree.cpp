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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root){
            que.push(root);
        }
        int level = 0;

        while(!que.empty()){
            int len =que.size();

            while(len--){
                auto node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            level++;
        }

        return level;
    }

    bool isBalanced(TreeNode* root) {
        queue<TreeNode*> que;
        if(!root){
            return true;
        }

        que.push(root);

        while(!que.empty()){
            auto node = que.front(); que.pop();

            int heightOfLeftSubtree = maxDepth(node->left);
            int heightOfRightSubtree = maxDepth(node->right);

            if(abs(heightOfRightSubtree - heightOfLeftSubtree) > 1){
                return false;
            }

            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }

        return true;
    }
};