class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int maxMD = 0;
        
        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == 'E'){
                east++;
            }else if(s[i] == 'W'){
                west++;
            }else if(s[i] == 'N'){
                north++;
            }else if(s[i] == 'S'){
                south++;
            }

            int steps = (i+1);

            int md = abs(east - west) + abs(north - south);
            int wasteSteps = steps - md;

            int extra = 0;
            if(wasteSteps != 0){
                extra = min(2*k, wasteSteps);
            }

            maxMD = max(maxMD, extra + md);
        }

        return maxMD;
    }
};