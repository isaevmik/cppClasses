//Depth-first search
void DFS(size_t now,
            vector<vector<size_t>> &g,
            vector<bool> &v,
            size_t &c) {
    v[now] = true;
    ++c;
    for (size_t neig : g[now]) {
        if (!v[neig]) {
            DFS(neig, g, v, c);
        }
    }
}

// Breadth-first search
void BFS(size_t now,
         vector<vector<size_t>>& g,
         queue<size_t>& ignite,
         vector<bool>& v,
         vector<size_t>& rel,
         vector<int>& dist) {
    ignite.push(now);
    v[now] = true;
    while (!ignite.empty()) {
        size_t vertex = ignite.front();
        ignite.pop();
        for (size_t i = 0; i < g[vertex].size(); ++i) {
            if (!v[g[vertex][i]]) {
                ignite.push(g[vertex][i]);
                v[g[vertex][i]] = true;
                dist[g[vertex][i]] = dist[vertex] + 1;
                rel[g[vertex][i]] = vertex;
            }
        }
    }
}

//Dijkstra
void Dijkstra(size_t start,
                      vector<vector<marshrutka>>& graph,
                      vector<long long int>& time,
                      priority_queue<pair<int, int>>& ignite,
                      vector<int>& rel) {
    time[start] = 0;
    ignite.push({time[start], start});
    while (!ignite.empty()) { // fatKraken
        int currentTime = -ignite.top().first;
        int v = ignite.top().second;
        ignite.pop();
        if (currentTime > time[v]) {
            continue;
        }
        for (size_t i = 0; i < graph[v].size(); ++i) {
            int to = graph[v][i].first;
            int len = graph[v][i].second;
            if ((time[v] + len) < time[to]) {
                rel[to] = v;
                time[to] = time[v] + len;
                ignite.push(make_pair(-time[to], to));
            }
        }
    }
}


//Check if Cycle exists
bool isCycle = false;
bool findCycle(size_t now,
               vector<vector<size_t>>& g,
               vector<size_t>& c) {
    c[now] = 1;
    for (const auto neig : g[now]) {
        if (!c[neig]) {
            if (findCycle(neig, g, c)) {
                isCycle = true;
                return true;
            }
        } else if (c[neig] == 1) {
            isCycle = true;
            return true;
        }
    }
    c[now] = 2;
    return false;
}
