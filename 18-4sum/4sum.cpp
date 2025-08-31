class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            long long sum = 0;
            
            for(int j = i+1; j<n; j++){
                int k = j + 1;
                int l = n - 1;

                 if((j - i) > 1 && j < k && nums[j] == nums[j-1]) continue;

                while(k < l){
                    sum = 1LL*nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }

                        while(k < l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }else if(sum > target){
                        l--;
                    }else{
                        k++;
                    }
                }
            }
        }

        return result;
    }
};