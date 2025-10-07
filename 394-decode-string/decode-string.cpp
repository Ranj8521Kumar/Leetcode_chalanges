class Solution {
public:
    string decodeString(string s) {
        int n = s.size();

        stack<int> repeatNum;
        stack<string> st;
        int num = 0;
        string curr = "";

        string str = "";

        for(int i = 0; i<n; i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }else if(s[i] == '['){
                repeatNum.push(num);
                num = 0;

                st.push(curr);
                curr = "";
            }else if(s[i] == ']'){
                string temp = curr;
                curr = st.top();
                st.pop();

                int repeat = repeatNum.top();
                repeatNum.pop();

                while(repeat--) curr += temp;
            }else{
                curr += s[i];
            }
        }

        return curr;
    }
};