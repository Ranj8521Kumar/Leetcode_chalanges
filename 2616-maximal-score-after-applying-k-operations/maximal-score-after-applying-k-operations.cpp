class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<long long> pq(nums.begin(), nums.end());
        while(k--){
            long long  topElem = pq.top();
            pq.pop();
            score += topElem;
            long long replacedValue = ceil((double)topElem / 3);
            pq.push(replacedValue);
        }
        return score;
    }
};