class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& I) {
        int numIntervals = I.size();
        vector<tuple<int, int, int, int>> intervalsWithId(numIntervals);
        for(int idx = 0; idx < numIntervals; ++idx) {
            intervalsWithId[idx] = {I[idx][0], I[idx][1], I[idx][2], idx};
        }
        sort(intervalsWithId.begin(), intervalsWithId.end());
        
        vector<int> sortedStarts(numIntervals);
        for(int idx = 0; idx < numIntervals; ++idx) {
            sortedStarts[idx] = get<0>(intervalsWithId[idx]);
        }
        
        using StatePair = pair<long long, vector<int>>;
        vector<vector<StatePair>> dpTable(numIntervals + 1, vector<StatePair>(5, {0, {}}));
        
        for(int idx = numIntervals - 1; idx >= 0; --idx) {
            auto [start, end, weight, originalId] = intervalsWithId[idx];
            int nextIndex = upper_bound(sortedStarts.begin(), sortedStarts.end(), end) - sortedStarts.begin();
            
            for(int subsetSize = 1; subsetSize <= 4; ++subsetSize) {
                StatePair chooseCurrent = dpTable[nextIndex][subsetSize - 1];
                chooseCurrent.first += weight;
                chooseCurrent.second.push_back(originalId);
                sort(chooseCurrent.second.begin(), chooseCurrent.second.end());
                
                StatePair skipCurrent = dpTable[idx + 1][subsetSize];
                
                if(chooseCurrent.first > skipCurrent.first || 
                  (chooseCurrent.first == skipCurrent.first && 
                  (skipCurrent.second.empty() || chooseCurrent.second < skipCurrent.second))) {
                    dpTable[idx][subsetSize] = chooseCurrent;
                } else {
                    dpTable[idx][subsetSize] = skipCurrent;
                }
            }
        }
        
        return dpTable[0][4].second;
    }
};
