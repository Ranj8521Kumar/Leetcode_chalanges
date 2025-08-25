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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int flip = true;
        queue<TreeNode*> que;
        if(!root) return {};
        que.push(root);

        while(!que.empty()){
            int len = que.size();
            vector<int> temp;

            while(len--){
                auto node = que.front(); que.pop();
                temp.push_back(node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            if(flip){
                result.push_back(temp);
            }else{
                reverse(temp.begin(), temp.end());
                result.push_back(temp);
            }

            flip = !flip;
        }

        return result;
    }
};