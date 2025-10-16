class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // Straight Line: y = mx + c
        int n = coordinates.size();
        if(n == 2) return true;
        
        bool yAxis = true;
        int temp = coordinates[0][0];
        for(auto &vec: coordinates){
            if(vec[0] != temp){
                yAxis = false;
                break;
            }
        }

        if(yAxis){
            return true;
        }

        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];

        double m = (double)dy/dx;
        double c = (double)coordinates[0][1] - m*coordinates[0][0];

        for(int i = 2; i<n; i++){
            double y = (double)coordinates[i][1];
            double x = (double)coordinates[i][0];

            if(y != (m*x + c)){
                return false;
            }
        }

        return true;
    }
};