class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";

        while (!pq.empty()) {
            auto first = pq.top(); pq.pop();
            int count1 = first.first;
            char char1 = first.second;

            if (result.size() >= 2 && result.back() == char1 && result[result.size() - 2] == char1) {
                if (pq.empty()) break;

                auto second = pq.top(); pq.pop();
                result += second.second;
                if (--second.first > 0) pq.push(second);
                pq.push(first);
            } else {
                result += char1;
                if (--count1 > 0) pq.push({count1, char1});
            }
        }

        return result;
    }
};
