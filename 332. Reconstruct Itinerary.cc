/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/

class Solution {
public:
    void dfs(map<string, multiset<string>>& m, string s, vector<string>& res) {
        while (m[s].size() > 0) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin()); 
            dfs(m, t, res);
        }
        res.push_back(s);
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, multiset<string>> m; 
        vector<string> res; 
        for (auto a : tickets) {
            m[a.first].insert(a.second);
        }
        
        dfs(m, "JFK", res);
        return vector<string> (res.rbegin(), res.rend());
    }
    
};