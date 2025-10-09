class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<vector<long long>> temp(m, vector<long long> (n, 0));

        // 0th row
        for(int j = 0; j<n; j++){
            int x = (j == 0) ? j: (j-1);
            temp[0][j] = temp[0][x] + 1LL * mana[0]*skill[j];
        }

        for(int i = 1; i<m; i++){
            for(int j = 0; j<n; j++){
                if(j == 0){
                    temp[i][j] = temp[i-1][j] + 1LL * mana[i]*skill[j];
                }else{
                    temp[i][j] = max(temp[i][j-1], temp[i-1][j]) + 1LL * mana[i]*skill[j];
                }
                
            }

            // backtrack for update the optimal time
            for(int j = n-2; j>=0; j--){
                temp[i][j] = temp[i][j+1] - 1LL * mana[i]*skill[j+1];
            }
        }

        return temp[m-1][n-1];
    }
};