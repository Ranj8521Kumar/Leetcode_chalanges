class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.size();
        while(true){
            int pos = s.find(part);

            if(pos == string::npos){
                break;
            }else{
                s.erase(pos, m);
            }
        }

        return s;
    }
};