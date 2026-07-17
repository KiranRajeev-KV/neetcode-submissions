class TimeMap {
   public:
    TimeMap() {}
    unordered_map<string, vector<pair<int, string>>> mp;

    void set(string key, string value, int timestamp) { mp[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        int l = 0;
        int r = mp[key].size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (mp[key][mid].first == timestamp) return mp[key][mid].second;

            if (mp[key][mid].first < timestamp) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (r < 0) {
            return "";
        }

        return mp[key][r].second;
    }
};
