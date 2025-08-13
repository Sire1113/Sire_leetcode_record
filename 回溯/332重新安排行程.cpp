class Solution {
public:
    vector<string> res;
    unordered_map<string, map<string, int>> target;
    bool findItineraryHelper(vector<vector<string>>& tickets){
        if (res.size()==tickets.size()+1)
            return true;
        for (auto& [dest,times]:target[res[res.size()-1]]){
            if (times==0)
                continue;
            res.push_back(dest);
            times--;
            if (findItineraryHelper(tickets))
                return true;
            res.pop_back();
            times++;
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& elem:tickets)
            target[elem[0]][elem[1]]++;
        res.push_back("JFK");
        findItineraryHelper(tickets);
        return res;
    }
};