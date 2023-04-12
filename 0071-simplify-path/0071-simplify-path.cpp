class Solution {
public:
    string simplifyPath(string path) 
    {
        string res,temp;
    vector<string>stack;
    stringstream ss(path);
        //breaks string path into parts seperated by '/' 
        
    while(getline(ss,temp,'/')) 
    {
        if (temp==""||temp==".") 
            continue;
        
        if (temp==".."&&!stack.empty()) 
            stack.pop_back();
        
        else if(temp!="..") 
            stack.push_back(temp);
    }
        
    for(auto &x:stack) 
        res += "/"+x;
        
    return res.empty()?"/":res;
    }
};