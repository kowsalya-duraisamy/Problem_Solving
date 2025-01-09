class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
    int n=words.size();
    int count=0;
    for(int i=0;i<n;i++){
        string word=words[i];
        if(word.find(pref)==0) count++;
    }  
    return count;
    }
};