class BrowserHistory {
    int pointer;
    vector<string>sites;
public:
    BrowserHistory(string homepage) {
        pointer=0;
        sites.push_back(homepage);
    }
    
    void visit(string url) {
        int last=sites.size()-1;
        while(last!=pointer) {
            sites.pop_back();
            last--;
        }
        sites.push_back(url);
        pointer=sites.size()-1;
    }
    
    string back(int steps) {
        int prev=max(0,pointer-steps);
        pointer=prev;
        return sites[pointer];
    }
    
    string forward(int steps) {
        int next=min((int)sites.size()-1,pointer+steps);
        pointer=next;
        return sites[pointer];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */