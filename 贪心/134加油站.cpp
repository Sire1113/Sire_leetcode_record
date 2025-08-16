class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur{},sum{};
        int start{};
        for (int i=0; i<gas.size(); i++){
            cur += (gas[i]-cost[i]);
            sum += (gas[i]-cost[i]);
            if (cur < 0){
                cur = 0;
                start = i+1;
            }
        }
        if (sum < 0)
            return -1;
        return start;
    }
};