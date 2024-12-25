class Solution {
public:
//using buttom - up approach with constant space complexity
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];//if only one house

        //steal first house - have we not taken last house
        int prevPrev =  0;
        int prev = nums[0];
        int maxProfit = max(nums[0], nums[1]);

        for(int i = 2; i<=n-1; i++){//if steal first house
            int steal = nums[i-1] + prevPrev;
            int skip = prev; 

            maxProfit = max(steal, skip);

            prevPrev = prev;
            prev = maxProfit;
        }

        int stealFirstHouse = maxProfit;

        //skip first house - have we taken last house
        prevPrev =  0;
        prev = 0; //since sip first house

        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + (prevPrev);
            int skip = prev;

            maxProfit = max(steal, skip);

            prevPrev = prev;
            prev = maxProfit;
        }

        int skipFirstHouse = maxProfit;

        return max(stealFirstHouse, skipFirstHouse);
    }
};