class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;

        if(n % 2 == 0){
            for(int i = -(n/2); i<=(n/2); i++){
                if(i == 0) continue;

                result.push_back(i);
            }
        }else{
            for(int i = -(n/2); i<=(n/2); i++){
                result.push_back(i);
            }
        }

        return result;
    }
};