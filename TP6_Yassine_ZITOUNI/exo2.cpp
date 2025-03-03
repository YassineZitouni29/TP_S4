#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;
class Graph{
    private:
        unordered_map<string,vector<string>*>* myGraph = new unordered_map<string, vector<string>*>{};
    public:
        void addEdge(const string& vertex, const string& neighbor){
            if (myGraph->find(vertex)==myGraph->end()){
                (*myGraph)[vertex] = new vector<string>;
            }
            (*myGraph)[vertex]->push_back(neighbor);
        }
        void DFS(const string& source){
            unordered_set<string> visited{source};
            stack<string> stack;
            stack.push(source);
            while (stack.size()){
            string vertex = stack.top();
            stack.pop();
            cout << vertex << "==>";
            if (myGraph->count(vertex) == 0) continue;
            for (auto it = myGraph->at(vertex)->begin(); it != myGraph->at(vertex)->end(); it++){
                if (!visited.count(*it)){
                    stack.push(*it);
                    visited.insert(*it);
                }  
            }
        }
    }
    ~Graph() {
        for (auto& [node, neighbors] : *myGraph) {
            delete neighbors;
        }
        delete myGraph;
    }
};
int main(){
    Graph G;
    G.addEdge("a","b");
    G.addEdge("b","d");
    G.addEdge("c","a");
    G.DFS("c");
}