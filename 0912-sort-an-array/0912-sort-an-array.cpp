class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int bucketSize = 10;

int mx = *max_element(nums.begin(), nums.end());
int mn = *min_element(nums.begin(), nums.end());

int bucketCount = (mx - mn) / bucketSize + 1;

vector<vector<int>> buckets(bucketCount);

for (int x : nums) {
    int idx = (x - mn) / bucketSize;
    buckets[idx].push_back(x);
}

vector<int> ans;

for (auto &bucket : buckets) {
    sort(bucket.begin(), bucket.end());

    for (int x : bucket)
        ans.push_back(x);
}

return ans;


    }
};