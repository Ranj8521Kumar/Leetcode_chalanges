class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; // Store Indices

        // When Talking about the circular array then think about "Doing the size of the array" and proceed ahead
        for(int i = 2*n-1; i>=0; i--){
            int idx = i % n;
            while(!st.empty() && nums[idx] >= nums[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                result[idx] = nums[st.top()];
            }

            st.push(idx);
        }

        return result;
    }
};