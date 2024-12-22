class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //using monotonic stack
        //and optimixed approach

        int n = prices.size();
        stack<int> st;
        vector<int> result(n);

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }

            if(!st.empty()){
                result[i] = prices[i] - st.top();
            }else{
                result[i] = prices[i];
            }

            st.push(prices[i]);
        }

        return result;
    }
};