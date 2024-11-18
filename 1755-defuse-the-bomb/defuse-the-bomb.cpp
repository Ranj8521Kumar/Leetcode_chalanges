class Solution {
public:
    vector<int> decrypt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result(n, 0); 
        if(k == 0){
            return result;
        }else if(k>0){
            for(int i = 0; i<n; i++){
                int sum =  0;
                int j =  i+1;
                int count = k;
                while(count--){
                    sum += arr[j%n];
                    j++;
                }
                result[i] = sum;
            }
        }else{
            for(int i = 0; i<n; i++){
                int sum =  0;
                int j =  i-1;
                int count = -k;
                while(count--){
                    sum += arr[(j+n)%n];
                    j--;
                }
                result[i] = sum;
            }
        }
        return result;
    }
};