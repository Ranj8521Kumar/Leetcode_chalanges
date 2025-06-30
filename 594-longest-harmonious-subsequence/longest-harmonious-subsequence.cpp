class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int length = 0;
        
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++;
        }

        for(int i = 0; i<n; i++){
            int nxt = nums[i] + 1;
            if(mpp[nxt] > 0){
                length = max(length, mpp[nums[i]] + mpp[nxt]);
            }
        }

        return length;
    }
};