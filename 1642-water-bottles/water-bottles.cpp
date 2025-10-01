class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        while((numBottles / numExchange) > 0){
            result += (numBottles / numExchange);
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }

        return result;
    }
};