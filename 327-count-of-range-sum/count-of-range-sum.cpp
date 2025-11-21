int seg[400004 * 3];
void pointUpdate(int idx, int lo, int hi, int pos, int delta) {
    if (lo == hi) {
        seg[idx] += delta;
        return;
    }
    int mid = (lo + hi) / 2;
    if (pos <= mid)
        pointUpdate(2 * idx + 1, lo, mid, pos, delta);
    else
        pointUpdate(2 * idx + 2, mid + 1, hi, pos, delta);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int rangeQuery(int idx, int lo, int hi, int L, int R) {
    if (R < lo || hi < L)
        return 0;
    if (L <= lo && hi <= R)
        return seg[idx];
    int mid = (lo + hi) / 2;
    return rangeQuery(2 * idx + 1, lo, mid, L, R) +
           rangeQuery(2 * idx + 2, mid + 1, hi, L, R);
}

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];

        // coordinate compression
        vector<long long> coords;
        for (auto &s : prefix) {
            coords.push_back(s);
            coords.push_back(s + lower - 1);
            coords.push_back(s + upper);
        }
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
        int M = coords.size();

        unordered_map<long long, int> idxOf;
        for (int i = 0; i < M; ++i)
            idxOf[coords[i]] = i;

        // update freqency of initial prefixs
        memset(seg, 0, sizeof(seg));
        for (auto &s : prefix) {
            pointUpdate(0, 0, M - 1, idxOf[s], 1);
        }

        int result = 0;
        for (auto &s : prefix) {
            // remove this prefix
            pointUpdate(0, 0, M - 1, idxOf[s], -1);

            // now we count frequencies starting from next index
            // count <= s+upper
            int hiId = idxOf[s + upper];
            int cntHi = rangeQuery(0, 0, M - 1, 0, hiId);

            // count <= s+lower-1
            int loId = idxOf[s + lower - 1];
            int cntLo = rangeQuery(0, 0, M - 1, 0, loId);

            result += (cntHi - cntLo);
        }
        return result;
    }
};