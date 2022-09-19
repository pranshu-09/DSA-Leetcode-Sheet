class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;

        for(auto x : paths) {
            
            stringstream ss(x);
            string root;
            string s;
            getline(ss, root, ' ');
            
            while (getline(ss, s, ' ')) {
                string name = root + '/' + s.substr(0, s.find('('));
                string content = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                m[content].push_back(name);
            }
        }

        for (auto x : m){
            if (x.second.size() > 1){
                ans.push_back(x.second);
            }
        }

        return ans;
    }
};