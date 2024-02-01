

/* #include <iostream>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin >> n;
    string s, f;
    cin >> s >> f;
    int count1 = 0, ans = 0;
    for (auto x : s) if (x == '1') count1++;
    for (int i = 0; i < n; i++){
        if (f[i] == '1'){
            if (s[i] == '0') ans++;
            count1--;
        }
    }
    if (count1 > 0) ans += count1;
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
} */



/* #include <iostream>
using namespace std;

void ZeroInt(int* ptr) {
    ptr = new int(0);
}

int main(int argc, char** argv) {
    int* intPtr = nullptr;
    ZeroInt(intPtr);
    cout << *intPtr << '\n';
} */



/* #include<iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1005
vector <int> adj[MAX];      // adjacency matrix, where adj[i] is a list, which denotes there are edges from i to each vertex in the list adj[i]
bool visited[MAX];          // boolean array, hacing value true / false, which denotes if a vertex 'i' has been visited or not.


void init() {                // initialization function
    int i;
    for (i = 0; i < MAX; i++) {
        visited[i] = false; // marking all vertex as unvisited
        adj[i].clear();     // clearing all edges
    }
}

void BFS(int start) {
    init();
    queue <int> q;
    q.push(start);

    int iterator, current_node, next_node;
    cout << "BFS Traversal is:\n";

    while (q.empty() == false) {
        current_node = q.front();
        q.pop();
        if (visited[current_node] == true) continue;

        cout << current_node << " ";
        visited[current_node] = true;

        for (iterator = 0; iterator < adj[current_node].size(); iterator++) {
            next_node = adj[current_node][iterator];
            if (visited[next_node] == false) q.push(next_node);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter Number of Vertices:\n";
    cin >> vertices;
    cout << "Enter number of edges:\n";
    cin >> edges;

    int i;
    int source, destination;
    cout << "Enter Edges as (source) <space> (destination):\n";
    for (i = 0; i < edges; i++) {
        cin >> source >> destination;
        if (source > vertices || destination > vertices) {
            cout << "Invalid Edge";
            i--;
            continue;
        }
        adj[source].push_back(destination);
        adj[destination].push_back(source);
    }

    int start;
    cout << "Enter Starting Vertex:";
    cin >> start;

    BFS(start);
} */ 


/* #include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1005
vector<int> adj[MAX];
bool visited[MAX];

void init() {
    int i;
    for (i = 0; i < MAX; i++) {
        visited[i] = false;
        adj[i].clear();
    }
}

void BFS(int start) {
    init();
    queue<int>q;
    q.push(start);

    int iterator, current_node, next_node;
    cout << "BFS Traversal:\n";

    while (q.empty() == false) {
        current_node = q.front();
        q.pop();
        if (visited[current_node] == true) continue;
        cout << current_node << " ";
        visited[current_node] = true;
        for (iterator = 0; iterator < adj[current_node].size(); iterator++) {
            next_node = adj[current_node][iterator];
            if (visited[next_node] == false) q.push(next_node);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices:\n";
    cin >> vertices;
    cout << "Enter number of edges:\n";
    cin >> edges;
    int i;
    int source, destination;
    cout << "Enter Edges as: (source) <space> (destination):\n";
    for (i = 0; i < edges; i++) {
        cin >> source >> destination;
        if (source > vertices || destination > vertices) {
            cout << "Invalid edges.\n";
            i--;
            continue;
        }
        adj[source].push_back(destination);
        adj[destination].push_back(source);
    }
    int start;
    cout << "Enter Starting vertex:\n";
    cin >> start;
    BFS(start);
} */


/* #include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs(v, adj, visited);
    cout << "Done visiting node : " << u + 1 << endl;
}

int main() {
    int nodes, edges, u, v;
    cin >> nodes >> edges;
    vector<vector<int> > adj(nodes);
    vector<bool> visited(nodes);
    for (int i = 1; i <= edges; ++i) {
        cin >> u >> v;
        --u, --v;       //there is an undirected edge between u and v (0 based)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, adj, visited);   //assume root is always node 0
    return 0;
} */ 


/* #include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (auto v : adj[u])
        if (!visited[v]) dfs(u, adj, visited);
    cout << "Done visiting node: " << u + 1 << '\n';
}

int main() {
    int nodes, edges, u, v;
    cin >> nodes >> edges;
    vector<vector<int>> adj(nodes);
    vector<bool> visited(nodes);
    for (int i = 1; i <= edges; i++) {
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, adj, visited);
} */ 



/* #include <iostream>
using namespace std;
char a[200][200];

int main() {
    int n, m, cnt = 0, x = -1, y = -1;
    cin >> n >> m;
    bool c[200][200];
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 200; j++)
            c[i][j] = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '*') { cnt++; c[i][j] = true; }
            if (a[i][j] == 'S') { x = i; y = j; }
        }
    string s = "";
    while (cnt--) {
        if (a[x + 1][y] == '*' && x + 1 < n && c[x + 1][y]) { x += 1; s += 'D'; c[x][y] = false; }
        else if (a[x][y + 1] == '*' && y + 1 < m && c[x][y + 1]) { y += 1; s += 'R'; c[x][y] = false; }
        else if (a[x - 1][y] == '*' && x - 1 >= 0 && c[x - 1][y]) { x -= 1; s += 'U'; c[x][y] = false; }
        else if (a[x][y - 1] == '*' && y - 1 >= 0 && c[x][y - 1]) { y -= 1; s += 'L'; c[x][y] = false; }
    }
    if (a[x + 1][y] == 'S') s += 'D';
    else if (a[x - 1][y] == 'S')s += 'U';
    else if (a[x][y - 1] == 'S') s += 'L';
    else s += 'R';
    cout << s<<'\n';
} */



#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << a * (b / 2) << '\n';
    }
}








