class Solution {
public:
    bool isAdjacent(string str1, string str2){
        int diff = 0;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                if(diff==0){
                    diff++;
                }
                else return false;
            }
        }
        return diff==1 ? true: false;
    }
    
    void backTrace(unordered_map<string,vector<string>> parent, string beginWord,string endWord, vector<vector<string>>& result,vector<string> path){
        if(endWord == beginWord){
            path.push_back(beginWord);
            reverse(path.begin(),path.end());
            result.push_back(path);
            return;
        }
        for(int i=0;i<parent[endWord].size();i++){
            vector<string> curr_path = path;
            curr_path.push_back(endWord);
            backTrace(parent, beginWord, parent[endWord][i], result, curr_path);
        }
        
        
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> notvisited(wordList.begin(), wordList.end());
        unordered_map<string,vector<string>> parent;
        queue<string> possible;
        possible.push(beginWord);
        int flag = 0;
        while(!possible.empty()){
            unordered_set<string> adj;
            int size = possible.size();
            for(int i=0;i<size;i++){
                string currWord = possible.front();
                if(currWord == endWord){
                    flag = 1;
                    break;
                }
                possible.pop();
                
                auto it = notvisited.begin();
                while(it!=notvisited.end()){
                    auto curr= it++;
                    if(isAdjacent(currWord,*curr)){
                        adj.insert(*curr);
                        parent[*curr].push_back(currWord);
                    }   
                }
            }
            if(flag==1){
                break;
            }
            //cout<<adj.size()<<endl;
            for(auto it = adj.begin();it!=adj.end();it++){
                possible.push(*it);
                notvisited.erase(*it);
            }
            
        }
        vector<vector<string>>result;
        vector<string> path;
      
        backTrace(parent, beginWord,endWord,result,path);
        return result;
    }
};