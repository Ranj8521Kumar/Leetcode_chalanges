class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int  n = points.size();
        int count = 0;

        sort(points.begin(), points.end(), [&](auto &a, auto &b){
            return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
        });

        for(int i = 0; i<n; i++){
            auto &point1 = points[i]; // Alice
            for(int j = i + 1; j<n; j++){
                auto &point2 = points[j]; // Bob

                int x = point1[0];
                int y = point1[1];

                int nx = point2[0];
                int ny = point2[1];

                if(nx >= x && ny <= y){
                    bool isInside = false;
                    for(int k = i+1; k <= j-1; k++){
                        auto &point3 = points[k];
                        int x1 = point3[0];
                        int y1 = point3[1];

                        if((x1 >= x && x1 <= nx) && (y1 >= ny && y1 <= y)){
                            isInside = true;
                            break;
                        }
                    }

                    if(isInside == false){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};