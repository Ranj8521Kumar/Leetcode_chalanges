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
    vector<TreeNode*> solve(int start, int end){
        if(start > end) return {nullptr};

        if(start == end){
            return {new TreeNode(start)};
        }

        vector<TreeNode*> result;

        for(int i = start; i<=end; i++){ // make each node as a root
            vector<TreeNode*> left = solve(start, i-1); // left possible comination
            vector<TreeNode*> right = solve(i+1, end); // right possible combination

            // All cominations of left and right
            for(auto &l: left){
                for(auto &r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;

                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};