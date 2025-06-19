class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = INT_MAX;
        int result = 0;
        int n = nums.size();

        for(int i = 0; i<=n-3; i++){
            for(int j = i+1; j<=n-2; j++){
                for(int k = j+1; k<=n-1; k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(abs(sum - target) < closest){
                        closest = abs(sum - target);
                        result = sum;
                    }
                }
            }
        }

        return result;
    }
};