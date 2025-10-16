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



// class Solution {
//   public:
//     void inorder(TreeNode* root, vector<int> &result){
//         if(root == nullptr) return;
//         inorder(root->left, result);
//         result.push_back(root->val);
//         inorder(root->right, result);
//     }
  
  
//     // Function to return a list containing the inorder traversal of the tree.
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         inorder(root, result);
//         return result;
//     }
// };



// ------------------------------------------------------------- //
// Using morris Traversal: No recursion and stack used here
class Solution {
  public:
  
    void morrisTraversal(TreeNode* root, vector<int> &result){
        TreeNode* curr = root;

        while(curr){
            if(curr->left == NULL){ // ydi current ka left null hai to curr ko visit kar lo aur uske right me chale jao
                result.push_back(curr->val);
                curr = curr->right;
            }else{// otherwise curr ke left ke rightmost Nodeknown as predecessor) pe chale jao aur rightmost node ke right ko curr se link kar do aur phir curr ko curr ke left me move karke curr ke left ko null mark kar do, means delete kar do
                TreeNode* predecessor = curr->left;
                while(predecessor->right != nullptr){
                    predecessor = predecessor->right;
                }

                predecessor->right = curr;
                TreeNode* temp = curr->left;
                curr->left = nullptr;
                curr = temp;
            }
        }
    }
  
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        morrisTraversal(root, result);
        return result;
    }
};