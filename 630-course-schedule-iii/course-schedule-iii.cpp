class Solution {
public:
    struct comp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.first < b.first;
        }
    };

    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        int lastTime = 0;

        for(auto &course: courses){
            int duration = course[0];
            int lastDay = course[1];

            int currDuration = duration + lastTime;

            if(currDuration <= lastDay){
                lastTime += duration;
                pq.push({duration, lastDay});
            }else{
                if(!pq.empty() && pq.top().first > duration){
                    lastTime -= pq.top().first;
                    pq.pop();

                    pq.push({duration, lastDay});
                    lastTime += duration;
                }
            }
        }

        return pq.size();
    }
};