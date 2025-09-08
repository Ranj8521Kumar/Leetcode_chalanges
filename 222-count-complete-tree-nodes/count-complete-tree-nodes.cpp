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
    // int getDepth(TreeNode* root){
    //     int depth = 0;
    //     while(root){
    //         root = root->left;
    //         depth++;
    //     }

    //     return depth;
    // }

    // int countNodes(TreeNode* root) {
    //     if(!root) return 0;

    //     int leftDepth = getDepth(root->left);
    //     int rightDepth = getDepth(root->right);

    //     if(leftDepth == rightDepth){
    //         return (1 << leftDepth) + countNodes(root->right);
    //     }else{
    //         return (1 << rightDepth) + countNodes(root->left);
    //     }
    // }













    // Another Approach, More robust and understandable:
    int getRightHeight(TreeNode* root){
        TreeNode* temp = root;
        int height = 0;

        while(temp){
            height++;
            temp = temp->right;
        }

        return height;
    }


    int getLeftHeight(TreeNode* root){
        TreeNode* temp = root;
        int height = 0;
        
        while(temp){
            height++;
            temp = temp->left;
        }

        return height;
    }



    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        if(leftHeight == rightHeight){
            // return pow(2, leftHeight) - 1;
            return (1 << leftHeight) - 1;
        }else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};