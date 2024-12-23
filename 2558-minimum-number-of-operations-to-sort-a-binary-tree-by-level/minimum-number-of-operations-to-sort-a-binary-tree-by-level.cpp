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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        int count = 0;

        while(!que.empty()){
            int len = que.size();

            vector<int> currentLevel;
            for(int i = 0; i<len; i++){
                TreeNode* node = que.front();
                que.pop();

                currentLevel.push_back(node->val);

                if(node->left) {
                    que.push(node->left);
                }

                if(node->right){
                    que.push(node->right);
                }
            }

            vector<int> sorted(currentLevel.begin(), currentLevel.end());
            sort(sorted.begin(), sorted.end());
            unordered_map<int, int> mpp;
            for(int i = 0; i<len; i++){
                mpp.insert({sorted[i], i});
            }

            for(int i = 0; i<len; ){
                int rightIndex = mpp[currentLevel[i]];
                if(rightIndex != i){
                    swap(currentLevel[rightIndex], currentLevel[i]);
                    count++;
                }else{
                    i++;
                }
            }
        }

        return count;
    }
};