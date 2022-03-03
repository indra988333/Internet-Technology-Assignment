int main()
{
    cout << "enter number of nodes ";
    int n = 0;
    cin >> n;
    n = n + 1; // to make it 1 indexing graph   
    vector<int> adj[n];
    cout << "enter number of edges ";
    int e = 0;
    cin >> e;
    cout << "enter a edge as (sourch_node  destination_node) \n";
    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        adj[s].push_back(d);
    }
    cout << "enter sorce ";
    int s;
    cin >> s;
    cout << "enter destination ";
    int d;
    cin >> d;
    cout << "DEPTH FIRST SEARCH :\n";
    dfs(adj, n, s, d);
    cout << endl;
    cout << "BREDTH FIRST SEARCH :\n";
    bfs(adj, n, s, d);
    cout << endl;
    cout << "DEPTH LIMITED SEARCH :\n";
    cout << "enter limit ";
    int l;
    cin >> l;
    dls(adj, n, s, d, l);
    cout << endl;

    return 0;
}