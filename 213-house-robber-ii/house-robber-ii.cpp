class Solution {
public:
//using buttom - up approach
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];

        vector<int> t(n+1, -1);
        t[0] =  0;

        for(int i = 1; i<=n-1; i++){//if steal first house
            int steal = nums[i-1] + ((i>=2)?t[i-2]:0);
            int skip = t[i-1]; 

            t[i] = max(steal, skip);
        }

        int stealFirstHouse = t[n-1];

        //skip first house - have we taken last house
        t = vector<int> (n+1, -1);
        t[0] =  0;
        t[1] = 0; //since sip first house

        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + (t[i-2]);
            int skip = t[i-1];

            t[i] = max(steal, skip);
        }

        int skipFirstHouse = t[n];

        return max(stealFirstHouse, skipFirstHouse);
    }
};