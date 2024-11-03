class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1 = s.size();
        int n2 = goal.size();

        if(n1 != n2){
            return false;
        }

        string doubleString = s + s;

        return (doubleString.find(goal)!=string::npos)?true:false;
    }
};