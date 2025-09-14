class Solution {
public:
    int n;
    int t[50001];

    int nextIndex(vector<vector<int>> &arr, int l, int currJobEnd){
        int r = n-1;
        int result = n+1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(arr[mid][0] >= currJobEnd){
                result = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return result;
    }

    int solve(int i, vector<vector<int>> &arr){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1) return t[i];

        int next = nextIndex(arr, i+1, arr[i][1]);
        int take = arr[i][2] + solve(next, arr);

        int notTake = solve(i+1, arr);

        return t[i] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(t, -1, sizeof(t));

        vector<vector<int>> arr(n, vector<int> (3, 0));

        for(int i = 0; i<n; i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        return solve(0, arr);
    }
};