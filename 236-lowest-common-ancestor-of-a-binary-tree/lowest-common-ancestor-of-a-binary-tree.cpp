/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findAncestors(TreeNode* root, TreeNode* p, vector<TreeNode*> &ancestors){
        if(!root) return false;

        ancestors.push_back(root);

        if(root == p){
            return true;
        }

        if(findAncestors(root->left, p, ancestors) || findAncestors(root->right, p, ancestors)){
            return true;
        }

        ancestors.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pAncestors, qAncestors;

        findAncestors(root, p, pAncestors);
        findAncestors(root, q, qAncestors);

        int i = 0;
        int m = pAncestors.size();
        int n = qAncestors.size();

        while(i<m && i<n && pAncestors[i] == qAncestors[i]){
            i++;
        }

        return pAncestors[i-1];
    }
};