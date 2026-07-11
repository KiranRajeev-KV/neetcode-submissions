class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.empty() || needle.empty()) {
             return -1;
        }
        int left = 0; int right = 0; int first = 0;
        while(left<haystack.size()) {
            if(haystack[left] == needle[right]) {
                cout<<haystack[left]<<" "<<needle[right]<<" "<<"true"<<endl;
                left++;
                right++;
                
                if (right == needle.size()){
                    cout<< right << endl;
                    return left - needle.size();
                }
            } else if(haystack[left] != needle[right]) {
                left = left - right + 1;
                right = 0;
            }
        }
        return -1;
    }
};