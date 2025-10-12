class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> temp(n, 0);

        for(int i = 1; i<=n; i++){
            temp[i-1] = i;
        }

        int start = 0;
        while(temp.size() != 1){
            int del = (start + k - 1) % temp.size();
            temp.erase(temp.begin() + del);

            start = del;
        }

        return temp[0];
    }
};