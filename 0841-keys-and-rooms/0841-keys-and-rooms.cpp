
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> key;
        key.push(0);

        unordered_set<int> visited;
        visited.insert(0);

        while (!key.empty()) {
            int temp = key.top();
            key.pop();

            for (int j = 0; j < rooms[temp].size(); j++) {
                int room = rooms[temp][j];

                if (visited.find(room) == visited.end()) {
                    visited.insert(room);
                    key.push(room);
                }
            }
        }

        return visited.size() == rooms.size();
    }
};
