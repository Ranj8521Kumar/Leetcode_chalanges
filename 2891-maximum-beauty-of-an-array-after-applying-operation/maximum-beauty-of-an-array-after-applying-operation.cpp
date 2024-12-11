class Solution {
private:
    int binarySearch(vector<int> &nums, int y){
        int left = 0;
        int right = nums.size() - 1;

        int result;

        while(left<=right){
            int mid = left + (right - left)/2;

            if(nums[mid]<=y){
                result = mid;
                left  = mid+1; //for farthest point from x, which satisfy the condition for y<=x+2*k
            }else{
                right = mid - 1;
            }
        }
        return result;
    }


public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int maxBeauty = 0;

        int n = nums.size();
        for(int i = 0; i<n; i++){
            int x = nums[i];
            int y = x + 2*k;

            int j = binarySearch(nums, y);

            maxBeauty = max(maxBeauty, j - i + 1);
        }

        return maxBeauty;
    }
};