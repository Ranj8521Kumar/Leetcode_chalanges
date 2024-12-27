class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //using maxHeap or Priority Queue
        priority_queue<int> maxHeap; //since by default prioroty queue is a max Heap
        int n = values.size();
        int maxScore = INT_MIN;

        for(int i = 1; i<n; i++){
            maxHeap.push(values[i-1] + (i-1));
            
            int maxValue =  maxHeap.top();
            maxScore = max(maxScore, maxValue + (values[i] - i));
        }

        return maxScore;
    }
};