#include<iostream>
#include <list>

using namespace std;

// Этот класс представляет ориентированный граф, используя смежные списки
class Graph {
    int V;

    // Указатель на массив со смежными списками
    list<int> *adj;

    public:
        Graph(int V);  // Конструктор

        // Добавляет ребро в граф
        void addEdge(int v, int w);

        // Печатает обход графа
        void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    // Отметить все вершины как непосещенные
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Создаем очередь
    list<int> queue;

    // Отмечаем текущий узел как посещенный, и добавляем его в очередь
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty()) {
        // Удаляем вершину из очереди и выводим ее
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Получаем все смежные вершины в удаленной вершине.
        // Если соседний объект не был посещен, отметим его как посещенный и добавим в очередь
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main() {
    // Создаем граф
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
