class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> result;
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";


        // string comb = "";

        // for(int i = 0; i<n; i++){
        //     comb += mpp[digits[i]];
        // }

        if(n == 1){
            string a = mpp[digits[0]];
            for(auto &ch1: a){
                result.push_back(string(1, ch1));
            }
        }else if(n == 2){
            string a = mpp[digits[0]];
            string b = mpp[digits[1]];

            for(auto &ch1: a){
                for(auto &ch2: b){
                    result.push_back(string(1, ch1) + ch2);
                }
            }
        }else if(n == 3){
            string a = mpp[digits[0]];
            string b = mpp[digits[1]];
            string c = mpp[digits[2]];

            for(auto &ch1: a){
                for(auto &ch2: b){
                    for(auto &ch3: c){
                        result.push_back(string(1, ch1) + ch2  + ch3);
                    }
                }
            }
        }else{
            string a = mpp[digits[0]];
            string b = mpp[digits[1]];
            string c = mpp[digits[2]];
            string d = mpp[digits[3]];

            for(auto &ch1: a){
                for(auto &ch2: b){
                    for(auto &ch3: c){
                        for(auto &ch4: d){
                            result.push_back(string(1, ch1) + ch2  + ch3 + ch4);
                        }
                    }
                }
            }
        }

        return result;
    }
};