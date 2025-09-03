class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int  n = points.size();
        int count = 0;

        sort(points.begin(), points.end(), [&](auto &a, auto &b){
            return (a[0] == b[0]) ? a[1] >= b[1] : a[0] <= b[0];
        });

        for(int i = 0; i<n; i++){
            auto &point1 = points[i]; // Alice
            int prev = INT_MIN;
            for(int j = i + 1; j<n; j++){
                auto &point2 = points[j]; // Bob

                int x = point1[0];
                int y = point1[1];

                int nx = point2[0];
                int ny = point2[1];

                if((ny <= y && prev < ny)){
                    count++;
                    prev = ny;
                }
            }
        }

        return count;
    }
};