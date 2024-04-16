#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(int u,int v,bool direction){
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an edge from u to v
        adjList[u].push_back(v);
        if(direction == 0){
            // undirected edge
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList(){
        for(auto node: adjList){
            cout << node.first << "-> ";
            for(auto neighbours: node.second){
                cout << neighbours << ", ";
            }
            cout << endl;
        }
    }

     void bfs(T src){
        queue<T> q;
        unordered_map<T,bool> visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout << node << " ";

            for(auto neighbour : adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        cout << endl;
    }

};

int main()
{
    // * Graphs-I
    // ! Directed Graph : edges pointed hoti h
    // ! Undirected Graph : edges pointed nhi hoti h and bidirectional hoti h
    // ! Degree: Kitni edges judi hui hai

    // int n;
    // cout<<"Enter number of nodes: "<<endl;
    // cin>>n;

    // vector<vector<int> >adj(n,vector<int>(n,0));

    // int e;
    // cout<<"Enter number of edges: "<<endl;
    // cin>>e;

    // for (int i = 0; i < e; i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     // mark 1
    //     adj[u][v]=1;
    // }
    
    // // Printing
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    // Graph g;

    // ! Directed edge input
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(0,2,1);
    // cout<<endl;
    // g.printAdjacencyList();

    // ! Undirected edge input
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // cout<<endl;
    // g.printAdjacencyList();


    Graph<int> g;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,1);
    cout << endl;
    g.printAdjacencyList();

    cout << "BFS traversal starting from node 0:" << endl;
    g.bfs(0);


    return 0;
}