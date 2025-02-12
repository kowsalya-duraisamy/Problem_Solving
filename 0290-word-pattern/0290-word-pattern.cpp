class Solution {
private:
    vector<string> getWords(string& sen) {

        vector<string> words;
        stringstream ss(sen);
        
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        return words;        
    }
public:
    bool wordPattern(string pattern, string s) {
        
        int n = pattern.size();
        unordered_map<char, string> mpp;
        unordered_map<string, char> inverseMpp;
        vector<string> words = getWords(s);

        if (words.size() != pattern.size()) return false;
        
        for (int i = 0; i < n; i++) {
            char ch = pattern[i];
            string word = words[i];

            if (mpp.find(ch) == mpp.end()) {
                if (inverseMpp.find(word) == inverseMpp.end()) {
                    mpp[ch] = word;
                    inverseMpp[word] = ch;
                }
                else {
                    return false;
                }
            }
            else {
                if (mpp[ch] != word) return false;
                if (inverseMpp[word] != ch) return false;
            }
        }

        return true;
    }
};