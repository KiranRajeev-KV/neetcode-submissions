class Solution {
public:
    string encode(vector<string>& strs) {
        string code = "";

        for (string str : strs) {
            code += to_string(str.size());
            code += '#';
            code += str;
        }

        return code;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        int n = s.length();

        while (i < n) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            i = j + 1;
            string word = s.substr(i, len);
            result.push_back(word);
            i += len;
        }

        return result;
    }
};