class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Brute Force Approach
        // int n = points.size();
        // int count = 0;
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         if(i == j) continue;
        //         auto point1 = points[i];
        //         auto point2 = points[j];

        //         int x = point1[0];
        //         int y = point1[1];

        //         int nx = point2[0];
        //         int ny = point2[1];

        //         if(nx >= x && ny <= y){
        //             bool inside = false;
        //             for(int k = 0; k<n; k++){
        //                 if(k == i || k == j) continue;

        //                 auto point3 = points[k];
        //                 int x1 = point3[0];
        //                 int y1 = point3[1];

        //                 if((x1 >= x && x1 <= nx) && (y1 >= ny && y1 <= y)){
        //                     inside = true;
        //                 }
        //             }

        //             if(inside == false) count++;
        //         }
        //     }
        // }

        // return count;


        // // Let's Optimize:
        // int n = points.size();
        // int count = 0;
        // sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b){
        //     if(a[0] == b[0]){
        //         return a[1] >= b[1];
        //     }

        //     return a[0] <= b[0];
        // });

        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         auto point1 = points[i];
        //         auto point2 = points[j];

        //         int x = point1[0];
        //         int y = point1[1];

        //         int nx = point2[0];
        //         int ny = point2[1];

        //         if(ny <= y){
        //             bool inside = false;
        //             for(int k = i+1; k<j; k++){
        //                 auto point3 = points[k];
        //                 int x1 = point3[0];
        //                 int y1 = point3[1];

        //                 if((y1 >= ny && y1 <= y)){
        //                     inside = true;
        //                 }
        //             }

        //             if(inside == false) count++;
        //         }
        //     }
        // }

        // return count;




        // Let's Optimize to O(n^2):
        int n = points.size();
        int count = 0;
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]){
                return a[1] >= b[1];
            }

            return a[0] <= b[0];
        });

        for(int i = 0; i<n; i++){
            int prev = INT_MIN;
            for(int j = i+1; j<n; j++){
                auto point1 = points[i];
                auto point2 = points[j];

                int x = point1[0];
                int y = point1[1];

                int nx = point2[0];
                int ny = point2[1];

                if(ny <= y){
                    if((prev >= ny && prev <= y)){
                        continue;
                    }

                    count++;
                    prev = ny;
                }
            }
        }

        return count;
    }
};