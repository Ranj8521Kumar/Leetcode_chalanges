class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Apply Brute Force: TLE
        // int n = temperatures.size();
        // vector<int> ans(n, 0);

        // for(int i = 0; i<n; i++){
        //     int cnt = 1;
        //     for(int j = i+1; j<n; j++){
        //         if(temperatures[j] > temperatures[i]){
        //             ans[i] = cnt;
        //             break;
        //         }else{
        //             cnt++;
        //         }
        //     }
        // }

        // return ans;




        // Optimized Approach using decreasing monostack:
        // int n = temperatures.size();
        // vector<int> ans(n, 0);
        // stack<int> st; //Store Indices

        // for(int i = 0; i<n; i++){
        //     while(!st.empty() && temperatures[i] > temperatures[st.top()]){
        //         ans[st.top()] = (i - st.top());
        //         st.pop();
        //     }

        //     st.push(i);
        // }

        // return ans;


        // Optimized Approach using increasing monostack:
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; //Store Indices

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }

            if(st.empty()){
                st.push(i);
            }

            if(temperatures[i] < temperatures[st.top()]){
                ans[i] = st.top() - i;
                st.push(i);
            }
        }

        return ans;
    }
};