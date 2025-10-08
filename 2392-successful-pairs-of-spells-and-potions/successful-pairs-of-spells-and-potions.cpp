class Solution {
public:
    void binarySearch(vector<int>& nums, long long num, int low, int high, int &result){
        while(low <= high){
            int mid = low + (high - low)/2;

            if(1LL*nums[mid] >= num){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
    }

    int findIdx(vector<int>& nums, long long num){
        int result = -1;
        binarySearch(nums, num, 0, nums.size() - 1, result);

        return result;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Brute Force Approach: TLE
        // int n = spells.size();
        // int m = potions.size();
        // vector<int> ans;

        // for(auto &it1: spells){
        //     int cnt = 0;
        //     for(auto &it2: potions){
        //         if(1LL*it1*it2 >= success){
        //             cnt++;
        //         }
        //     }

        //     ans.push_back(cnt);
        // }

        // return ans;


        int n = spells.size();
        int m = potions.size();
        vector<int> ans;

        sort(potions.begin(), potions.end());

        for(auto &it: spells){
            long long num = (success%it) == 0 ? (success/it): (success/it) + 1;
            int idx = findIdx(potions, num);

            if(idx == -1){
                ans.push_back(0);
            }else{
                ans.push_back(m - idx);
            }
        }

        return ans;
    }
};