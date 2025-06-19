class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int result = INT_MIN;

        int i = 0;
        int j = n-1;

        while(i < j){
            result = max(result, (j-i) * min(height[i], height[j]));
            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }
        }

        return result;
    }
};