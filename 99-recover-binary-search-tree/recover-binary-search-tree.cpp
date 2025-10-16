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
    void inOrder(TreeNode* root, vector<TreeNode*>& nodes){
        if(!root) return;

        inOrder(root->left, nodes);
        nodes.push_back(root);
        inOrder(root->right, nodes);
    }

    void recoverTree(TreeNode* root) {
        if(!root) return;

        vector<TreeNode*> nodes;

        inOrder(root, nodes);

        int n = nodes.size();
        TreeNode* firstNode = nullptr;
        TreeNode* secondNode = nullptr;

        for(int i = 0; i<n-1; i++){
            if(nodes[i]->val > nodes[i+1]->val){
                if(!firstNode){
                    firstNode = nodes[i];// Store the first misplaced Node
                }

                secondNode = nodes[i+1];// Store the last misplaced Node
            }
        }

        if(firstNode && secondNode){
            swap(firstNode->val, secondNode->val);
        }
    }
};