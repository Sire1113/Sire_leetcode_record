class BrowserHistory {
public:
    string cur_url;
    stack<string> hists;
    stack<string> forward_hist;
public:
    BrowserHistory(string homepage) {
        this->cur_url = homepage;
        hists.push(homepage);
    }

    void visit(string url) {
        this->cur_url = url;
        hists.push(url);
        forward_hist = {};
    }

    string back(int steps) {
        steps = steps > hists.size()-1? hists.size()-1: steps;
        while (steps--){
            forward_hist.push(hists.top());
            hists.pop();
        }
        cur_url = hists.top();
        return cur_url;
    }

    string forward(int steps) {
        steps = steps > forward_hist.size()? forward_hist.size(): steps;
        while (steps--){
            hists.push(forward_hist.top());
            forward_hist.pop();
        }
        cur_url = hists.top();
        return cur_url;

    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */