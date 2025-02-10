class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(auto &ch: s){
            if(!isdigit(ch)){
                st.push(ch);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }

        string result = "";

        while(!st.empty()){
            int ch = st.top();
            st.pop();
            result += ch;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};