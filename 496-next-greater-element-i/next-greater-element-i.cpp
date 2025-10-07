class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(nums1.size(), -1);
        for(int k = 0; k<nums1.size(); k++){
            for(int i = 0; i<n; i++){
                if(nums1[k] == nums2[i]){
                    for(int j = i+1; j<n; j++){
                        if(nums2[j] > nums2[i]){
                            ans[k] = (nums2[j]);
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};