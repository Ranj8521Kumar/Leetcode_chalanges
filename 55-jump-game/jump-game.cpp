class Solution {
public:
    int n;
    int t[10001];
    bool solve(int i, vector<int> &nums){
        if(i != n-1 && nums[i] == 0) return false;
        if(i == n-1) return true;

        if(t[i] != -1) return t[i];
        
        // int j = 1;
        // while(j<=nums[i]){
        //     if(solve(i + j, nums) == true){
        //         return true;
        //     }

        //     j++;
        // }

        for(int j = 1; j<=nums[i]; j++){
            if(solve(i + j, nums) == true){
                return t[i] = true;
            }
        }

        return t[i] = false;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums);
    }
};