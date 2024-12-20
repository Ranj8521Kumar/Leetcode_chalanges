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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int level = 0; // Start from the root level
        
        while (!que.empty()) {
            vector<TreeNode*> currentLevel; // Nodes at the current level
            int len = que.size(); // Number of nodes in the current level
            
            // Process all nodes at this level
            while (len--) {
                TreeNode* node = que.front();
                que.pop();
                currentLevel.push_back(node);
                
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            
            // Reverse values for alternate levels
            if (level % 2 != 0) {
                int left = 0, right = currentLevel.size() - 1;
                while (left < right) {
                    swap(currentLevel[left]->val, currentLevel[right]->val);
                    left++;
                    right--;
                }
            }
            level++; // Move to the next level
        }

        return root;
    }
};