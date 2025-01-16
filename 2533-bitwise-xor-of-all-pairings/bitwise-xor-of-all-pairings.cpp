class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int xorNums1 = 0;
        int xorNums2 = 0;

        for(int i = 0; i<m; i++){
            xorNums1 ^= nums1[i];
        }

        for(int i = 0; i<n; i++){
            xorNums2 ^= nums2[i];
        }
        
        int x = m%2;
        int y = n%2;

        if(x==0 && y==0){
            return 0;
        }else if(x==0 && y!=0){
            return xorNums1;
        }else if(x!=0 && y==0){
            return xorNums2;
        }else{
            return xorNums1^xorNums2;
        }

    }
};