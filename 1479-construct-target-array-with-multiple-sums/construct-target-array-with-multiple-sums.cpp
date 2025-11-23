class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        priority_queue<long long> pq(target.begin(), target.end());

        long long sum = 0;
        for(auto &it: target){
            sum += it;
        }

        while(pq.top() != 1){
            long long largest = pq.top(); pq.pop();
            long long diff = sum - largest;

            if(diff == 0 || diff >= largest) return false;

            long long prev = largest % diff;

            if(prev == 0){
                if(diff == 1) return true;
                return false;
            }

            pq.push(prev);
            sum = diff + prev;
        }

        return true;
    }
};