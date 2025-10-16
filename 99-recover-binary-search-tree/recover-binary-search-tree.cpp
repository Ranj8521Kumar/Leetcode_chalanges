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
// public:
//     void inOrder(TreeNode* root, vector<TreeNode*>& nodes){
//         if(!root) return;

//         inOrder(root->left, nodes);
//         nodes.push_back(root);
//         inOrder(root->right, nodes);
//     }

//     void recoverTree(TreeNode* root) {
//         if(!root) return;

//         vector<TreeNode*> nodes;

//         inOrder(root, nodes);

//         int n = nodes.size();
//         TreeNode* firstNode = nullptr;
//         TreeNode* secondNode = nullptr;

//         for(int i = 0; i<n-1; i++){
//             if(nodes[i]->val > nodes[i+1]->val){
//                 if(!firstNode){
//                     firstNode = nodes[i];// Store the first misplaced Node
//                 }

//                 secondNode = nodes[i+1];// Store the last misplaced Node
//             }
//         }

//         if(firstNode && secondNode){
//             swap(firstNode->val, secondNode->val);
//         }
//     }
// };




// ---------------------------------------------------- //
// Second Approach, without using the extra space
class Solution {
public:
//     TreeNode* firstNode = nullptr;
//     TreeNode* secondNode = nullptr;
//     TreeNode* prevNode = new TreeNode(INT_MIN);

//     void inOrder(TreeNode* root){
//         if(!root) return;

//         inOrder(root->left);
//         if(prevNode && prevNode->val > root->val){
//             if(!firstNode){
//                 firstNode = prevNode;
//             }
//             secondNode = root;
//         }
//         prevNode = root;

//         inOrder(root->right);
//     }

//     void recoverTree(TreeNode* root) {
//         if(!root) return;
//         inOrder(root);

//         if(firstNode && secondNode){
//             swap(firstNode->val, secondNode->val);
//         }
//     }






    // --------------------------------------------------- //
    // Using Morris Traversal: for getting O(1) space:
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = new TreeNode(INT_MIN);

        while(curr){
            if(curr->left == nullptr){
                if(prev && prev->val > curr->val){
                    if(!first){
                        first = prev;
                    }

                    second = curr;
                }

                prev = curr;
                curr = curr->right;
            }else{
                TreeNode* pre = curr->left;
                while(pre->right != nullptr && pre->right != curr){
                    pre = pre->right;
                }

                if(pre->right == nullptr){
                    pre->right = curr;
                    curr = curr->left;
                }else{
                    pre->right = nullptr;

                    if(prev && prev->val > curr->val){
                        if(!first){
                            first = prev;
                        }
                        second = curr;
                    }

                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        if(first && second){
            swap(first->val, second->val);
        }
    }
};