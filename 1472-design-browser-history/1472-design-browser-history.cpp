#define pb push_back
class BrowserHistory {
public:
    int ele;
    vector<string> vc;
    BrowserHistory(string homepage) {
        vc.pb(homepage);
        ele  =0;
    }
    
    void visit(string url) {
        int l = vc.size()-1;
        while(l>ele){
            vc.pop_back();
            l--;
        }
        ele++;
        vc.pb(url);
    }
    
    string back(int steps) {
        ele-=steps;
        if(ele<0) ele=0;
        return vc[ele];
    }
    
    string forward(int steps) {
        ele +=steps;
        if(ele>=vc.size()) ele = vc.size()-1;
        return vc[ele];
    }
};
