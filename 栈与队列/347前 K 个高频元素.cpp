class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 小顶堆的优先队列
        auto mycmp = [](pair<int, int>& left, pair<int, int>& right){
            return left.second > right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(mycmp)> que(mycmp);
        unordered_map<int, int> cnt;
        vector<int> res(k);
        for (auto& elem: nums)
            cnt[elem]++;
        for (auto& kv: cnt){
            que.push(kv);
            if (que.size()>k)
                que.pop();
        }
        for (int i = k - 1; i >= 0; i--) {
            res[i] = que.top().first;
            que.pop();
        }
        return res;
    }
};