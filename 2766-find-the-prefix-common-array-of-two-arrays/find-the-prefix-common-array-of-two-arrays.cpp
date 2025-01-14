class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        unordered_set<int> st1;
        unordered_set<int> st2;

        vector<int> result;

        int count = 0;
        for(int i = 0; i<n; i++){
            st1.insert(A[i]);
            st2.insert(B[i]);

            for(int j = 0; j<=i; j++){
                if(st1.count(A[j]) && st2.count(A[j])){
                    count++;
                }
            }

            result.push_back(count);
            count = 0;
        }

        return result;
    }
};