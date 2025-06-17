class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        int n = tokens.size();
        for(int i = 0; i<n; i++){
            if(tokens[i] == "+"){
                if(st.size() >= 2){
                    int n1 = stoi(st.top());
                    st.pop();
                    int n2 = stoi(st.top());
                    st.pop();

                    int res = n2 + n1;
                    st.push(to_string(res));
                }
            }else if(tokens[i] == "-"){
                if(st.size() >= 2){
                    int n1 = stoi(st.top());
                    st.pop();
                    int n2 = stoi(st.top());
                    st.pop();

                    int res = n2 - n1;
                    st.push(to_string(res));
                }
            }else if(tokens[i] == "*"){
                if(st.size() >= 2){
                    int n1 = stoi(st.top());
                    st.pop();
                    int n2 = stoi(st.top());
                    st.pop();

                    int res = n2 * n1;
                    st.push(to_string(res));
                }
            }else if(tokens[i] == "/"){
                if(st.size() >= 2){
                    int n1 = stoi(st.top());
                    st.pop();
                    int n2 = stoi(st.top());
                    st.pop();

                    int res = n2 / n1;
                    st.push(to_string(res));
                }
            }else{
                st.push(tokens[i]);
            }
            
        }

        return stoi(st.top());
    }
};