class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        vector<string> v;
        int j = 0;
        while(i < words.size()){
            int len = 0;
            string s = "";
            j = i;
            len += words[j].size();
            int cnt = 0;
            int wordsLen = words[j].size();
            while(j + 1 < words.size() && len + 1 + words[j + 1].size() <= maxWidth){
                j++;
                len += words[j].size();
                len++;
                wordsLen += words[j].size();
                cnt++;
                cout << len << " " << wordsLen << " " << j <<" " << i<< endl;
            }
            if(cnt && j != words.size() - 1) {
                int space = (maxWidth - wordsLen) / cnt;
                int rem = (maxWidth - wordsLen) % cnt;
                s += words[i];
                i++;
                for(int k = 0; k < cnt; k++){
                    if(rem){
                        s += string(space + 1, ' ');
                        s += words[i];
                        i++;
                        rem--;
                    }
                    else {
                        s += string(space, ' ');
                        s += words[i];
                        i++;
                    }
                }
            }
            else if(j == words.size() - 1){
                s = words[i];
                i++;
                while(i <= j){
                    s += " ";
                    s += words[i];
                    i++;
                }
                s += string(maxWidth - s.size(), ' ');
            }
            else {
                s = words[i];
                i++;
                s += string(maxWidth - s.size(), ' ');
            }
            v.push_back(s);
            cout << s << " "<< i << endl;
        }
        return v;
    }
};