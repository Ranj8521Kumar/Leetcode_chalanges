class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        int k = extraStudents;
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;

        for(int i = 0; i<n; i++){
            vector<int> Class = classes[i];
            double increase = ((double)(Class[0] + 1)) / (Class[1] + 1) - ((double)(Class[0])) / (Class[1]);
            pq.push({increase, i});
        }

        while(k--){
            int idx = pq.top().second;
            pq.pop();

            vector<int> &Class = classes[idx];

            Class[0] += 1;
            Class[1] += 1;

            double increase = ((double)(Class[0] + 1)) / (Class[1] + 1) - ((double)(Class[0])) / (Class[1]);
            pq.push({increase, idx});
        }

        double result = 0;

        for(int i = 0; i<n; i++){
            vector<int> Class = classes[i];
            result += ((double)(Class[0])) / (Class[1]);
        }

        return result/n;
    }
};