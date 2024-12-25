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
    vector<int> largestValues(TreeNode* root) {
        //level order traversal or BFS
        vector<int> result;
        queue<TreeNode*> que;
        
        if(root != nullptr){
            que.push(root);
        }

        while(!que.empty()){
            int len = que.size();

            vector<int> level;
            while(len--){
                auto u = que.front();
                que.pop();
                level.push_back(u->val);

                //push node of next level in the queue
                if(u->left){
                    que.push(u->left);
                }

                if(u->right){
                    que.push(u->right);
                }
            }

            int maxElem = INT_MIN;
            for(auto &it: level){
                maxElem = max(maxElem, it);
            }

            result.push_back(maxElem);
        }

        return result;
    }
};