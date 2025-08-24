class Solution {
public:
    int binarySearch(vector<int> &nums, int target,  int low, int high, int idx){
        int mid = (high - low)/2 + low;
        int tempMid = (mid + idx) % (nums.size());

        while(low <= high){
            if(nums[tempMid] == target) return tempMid;
            else if(nums[tempMid] < target){
                return binarySearch(nums, target, mid+1, high, idx);
            }else{
                return binarySearch(nums, target, low, mid-1, idx);
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int idx = 0;
        for(int k = 0; k<n-1; k++){
            if(nums[k] > nums[k+1]){
                idx = k + 1;
                break;
            }
        }

        int targetIdx = binarySearch(nums,  target, 0, n-1, idx);

        return targetIdx;
    }
};