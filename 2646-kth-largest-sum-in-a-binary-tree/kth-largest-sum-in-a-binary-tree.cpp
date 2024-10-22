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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root){
            return -1;
        }

        priority_queue<long long, vector<long long>, greater<long long>> sumQueue;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            while(size>0){
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                size--;
            }

            sumQueue.push(sum);
            if(sumQueue.size() > k){
                sumQueue.pop();
            }
        }
        return sumQueue.size()<k?-1:sumQueue.top();
    }
};