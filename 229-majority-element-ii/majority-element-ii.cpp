class Solution {
public:
    // This is most efficient Approach:
    vector<int> majorityElement(vector<int>& nums) {
        // Here use the extended version of Boyer - Moore Voting Algorithm:
        // Since n/3 + n/3 + n/3 = n, so accordingly at most two majority elements is possible, so we have tomaintain the count and voting for both two

        int n = nums.size();
        int cnt1 = 0;
        int majority1 = nums[0];

        int cnt2 = 0;
        int majority2 = nums[0];

        for(auto &num: nums){
            if(num == majority1){
                cnt1++;
            }else if(num == majority2){
                cnt2++;
            }else if(cnt1 == 0){
                majority1 = num;
                cnt1 = 1;
            }else if(cnt2 == 0){
                majority2 = num;
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }


        // veify that both are possible to be majority or not:
        cnt1 = cnt2 = 0;
        for(auto &num: nums){
            if(num == majority1){
                cnt1++;
            }else if(num == majority2){
                cnt2++;
            }
        }

        vector<int> result;

        if(cnt1 > (n/3)) result.push_back(majority1);
        if(cnt2 > (n/3)) result.push_back(majority2);

        return result;
    }
};