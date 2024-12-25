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
    //DFS Approach

    void DFS(TreeNode* root, int depth, vector<int>& result){
        if(root == nullptr){
            return;
        }

        if(result.size() == depth){//first time visit to that depth
            result.push_back(root->val); 
        }else{//already visited to that depth
            result[depth] = max(result[depth], root->val);
        }

        if(root->left){
            DFS(root->left, depth+1, result);
        }

        if(root->right){
            DFS(root->right, depth+1, result);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> result;

        DFS(root, 0, result);// 0  -> current depth

        return result;
    }
};