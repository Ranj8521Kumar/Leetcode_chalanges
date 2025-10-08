class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force Approach:
        // int n = nums2.size();
        // vector<int> ans(nums1.size(), -1);
        // for(int k = 0; k<nums1.size(); k++){
        //     for(int i = 0; i<n; i++){
        //         if(nums1[k] == nums2[i]){
        //             for(int j = i+1; j<n; j++){
        //                 if(nums2[j] > nums2[i]){
        //                     ans[k] = (nums2[j]);
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }

        // return ans;



        // Optimized Approach, using increasing monostack
        int n = nums2.size();
        int m = nums1.size();

        stack<int> st;
        vector<int> temp(n, -1);

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }

            if(st.empty()){
                st.push(nums2[i]);
            }

            if(nums2[i] < st.top()){
                temp[i] = st.top();
                st.push(nums2[i]);
            }
        }

        unordered_map<int, int> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums2[i]] = i;
        }

        vector<int> ans(m, -1);

        for(int i = 0; i<m; i++){
            int idx = mpp[nums1[i]];
            ans[i] = temp[idx];
        }


        return ans;
    }
};