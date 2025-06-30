class RecentCounter {
public:
    queue<int> hist;
public:
    RecentCounter() = default;
    int ping(int t) {
        hist.push(t);
        while (hist.front() < t-3000)
            hist.pop();
        return hist.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */