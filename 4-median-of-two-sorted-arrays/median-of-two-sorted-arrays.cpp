// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> sortedArray;

//         int i = 0; int j = 0;
//         int m = nums1.size();
//         int n = nums2.size();

//         while(i<m && j<n){
//             if(nums1[i] <= nums2[j]){
//                 sortedArray.push_back(nums1[i++]);
//             }else{
//                 sortedArray.push_back(nums2[j++]);
//             }
//         }

//         while(i<m){
//             sortedArray.push_back(nums1[i++]);
//         }

//         while(j<n){
//             sortedArray.push_back(nums2[j++]);
//         }

//         if((m+n) % 2 != 0){
//             return sortedArray[(m+n)/2];
//         }else{
//             return ((double)sortedArray[(m+n)/2 - 1] + (double)sortedArray[(m+n)/2])/2;
//         }
//     }
// };



// ------------------------------------------------------ //
// Most Efficient Approach -> using Binary Search

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double result = 0.0;

        if(m > n){
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            swap(m, n);
        }

        bool oddLength = false;
        if((m + n) % 2 != 0){
            oddLength = true;
        }

        int len; //firstHalfLegth
        if(oddLength){
            len = (m + n + 1) / 2;
        }else{
            len = (m + n) / 2;
        }

        int low = 0;
        int high = m;

        while(low <= high){
            int px = low + (high - low) / 2;

            int x1 = (px)?nums1[px-1]:INT_MIN;
            int x3 = (px == m)?INT_MAX:nums1[px];

            int x2 = ((len-px) == 0)?INT_MIN:nums2[len-px-1];
            int x4 = ((len-px) == n)?INT_MAX:nums2[len-px];

            if(x1 > x4){
                high = px - 1;
            }else if(x2 > x3){
                low = px + 1;
            }

            if(x1 <= x4 && x2 <= x3){
                if(oddLength){
                    result = (max(x1, x2));
                }else{
                    result = (double)(max(x1, x2) + min(x3, x4)) / 2;
                }

                break;
            }
        }

        return result;
    }
};