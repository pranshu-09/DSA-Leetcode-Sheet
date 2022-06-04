bool compare(pair<int, string>&a, pair<int, string>&b){
    return a.first < b.first;
}

class TimeMap {
public:
    
    unordered_map<string, vector<pair<int, string>>>ds;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ds[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        int s=0, e=ds[key].size()-1;
        string ans;
        
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(ds[key][mid].first <= timestamp){
                ans = ds[key][mid].second;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */