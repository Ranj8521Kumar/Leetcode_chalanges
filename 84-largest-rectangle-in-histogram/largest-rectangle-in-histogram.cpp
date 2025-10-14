class Solution {
public:
    // vector<int> nextSmallerElem(vector<int>& nums, int n){
    //     vector<int> result(n, -1);
    //     stack<int> st; // store Indices

    //     for(int i=n-1; i>=0; i--){
    //         while(!st.empty() && nums[i] <= nums[st.top()]){
    //             st.pop();
    //         }

    //         if(st.empty()){
    //             result[i] = n;
    //         }else{
    //             result[i] = st.top();
    //         }

    //         st.push(i);
    //     }

    //     return result;
    // }

    // vector<int> prevSmallerElem(vector<int>& nums, int n){
    //     vector<int> result(n, -1);
    //     stack<int> st; // store Indices

    //     for(int i=0; i<n; i++){
    //         while(!st.empty() && nums[i] <= nums[st.top()]){
    //             st.pop();
    //         }

    //         if(st.empty()){
    //             result[i] = -1;
    //         }else{
    //             result[i] = st.top();
    //         }

    //         st.push(i);
    //     }

    //     return result;
    // }

//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> NSE = nextSmallerElem(heights, n); // Store the indices
//         vector<int> PSE = prevSmallerElem(heights, n); // store the indices

//         int maxArea = 0;
//         for(int i = 0; i<n; i++){
//             int height = heights[i];
//             int width = (NSE[i] - PSE[i]) - 1;
//             maxArea = max(maxArea, height*width);
//         }

//         return maxArea;
//     }
// };



// ------------------------------------------------------ //
// Optimized Approach:
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;

        int maxArea = 0;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int nse = i;
                int element =  st.top(); st.pop();
                int pse = (st.empty())?-1:st.top();

                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }

            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int element = st.top(); st.pop();

            int pse = (st.empty())?-1:st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }

        return maxArea;
    }
};