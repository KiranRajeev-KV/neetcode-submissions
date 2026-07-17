class TimeMap {
   public:
    TimeMap() {}
    unordered_map<string, map<int, string>> mp;

    // here set takes O(log n)
    void set(string key, string value, int timestamp) { mp[key][timestamp] = value; }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        // const because we dont modify data in get
        // & saves space by not copying the whole set of entries again
        const map<int, string>& timestamps = mp.find(key)->second;

        string ans = "";

        // const here because the entry does not change at all
        // & saves space by not copying each and every entry.
        for (const auto& entry : timestamps) {
            if (entry.first > timestamp) {
                break;
            }

            ans = entry.second;
        }

        return ans;
    }
};
