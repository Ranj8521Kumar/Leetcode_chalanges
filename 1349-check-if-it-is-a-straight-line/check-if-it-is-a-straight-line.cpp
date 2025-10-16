class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // Straight Line: y = mx + c
        // int n = coordinates.size();
        // if(n == 2) return true;

        // sort(coordinates.begin(), coordinates.end());
        
        // bool yAxis = true;
        // int temp = coordinates[0][0];
        // for(auto &vec: coordinates){
        //     if(vec[0] != temp){
        //         yAxis = false;
        //         break;
        //     }
        // }

        // if(yAxis){
        //     return true;
        // }

        // int dx = coordinates[1][0] - coordinates[0][0];
        // int dy = coordinates[1][1] - coordinates[0][1];

        // double m = (double)dy/dx;
        // double c = (double)coordinates[0][1] - m*coordinates[0][0];

        // for(int i = 2; i<n; i++){
        //     double y = (double)coordinates[i][1];
        //     double x = (double)coordinates[i][0];

        //     if(y != (m*x + c)){
        //         return false;
        //     }
        // }

        // return true;





        // --------------------------------------------- //
        // Most optimized: Using only comaparision of slopes
        // slope must be same, for any two points

        int n = coordinates.size();

        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        for(int i = 2; i<n; i++){
            int x3 = coordinates[i][0];
            int y3 = coordinates[i][1];

            if((x2 - x1)*(y3 - y1) != (x3 - x1)*(y2 - y1)){
                return false;
            }
        }

        return true;
    }
};