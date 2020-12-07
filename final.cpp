#include <bits/stdc++.h>
#include <iostream>
#include <list>

#define V 4
using namespace std;

int travllingSalesmanProblem(int grafo[][V], int s)
{

  vector<int> vertex;
  for (int i = 0; i < V; i++)
    if (i != s)
      vertex.push_back(i);

  int min_path = INT_MAX;
  do
  {

    int current_pathweight = 0;

    int k = s;
    for (int i = 0; i < vertex.size(); i++)
    {
      current_pathweight += grafo[k][vertex[i]];
      k = vertex[i];
    }
    current_pathweight += grafo[k][s];

    min_path = min(min_path, current_pathweight);

  } while (next_permutation(vertex.begin(), vertex.end()));

  return min_path;
}

class Graph
{
  int T;
  list<int> *adj;

public:
  Graph(int T)
  {
    this->T = T;
    adj = new list<int>[T];
  }
  ~Graph() { delete[] adj; }

  void addEdge(int v, int w);

  void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
  adj[w].push_back(v);
}

void Graph::greedyColoring()
{
  int result[T];

  // Assign the first color to first vertex
  result[0] = 0;

  for (int u = 1; u < T; u++)
    result[u] = -1;

  bool available[T];
  for (int cr = 0; cr < T; cr++)
    available[cr] = false;

  for (int u = 1; u < T; u++)
  {

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
      if (result[*i] != -1)
        available[result[*i]] = true;

    int cr;
    for (cr = 0; cr < T; cr++)
      if (available[cr] == false)
        break;

    result[u] = cr;

    for (i = adj[u].begin(); i != adj[u].end(); ++i)
      if (result[*i] != -1)
        available[result[*i]] = false;
  }

  for (int u = 0; u < T; u++)
    cout << "Vertice: " << u << " ---> Cor: "
         << result[u] << endl;
}

int main()
{
  Graph g1(4);
  int grafo[][V] = {{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}};
  int s = 0;
  cout << "\n\n-----------------------\n\n\nBem vindo ao nosso trabalho Final!" << endl;
  cout << "Como último trabalho, iremos atacar problemas considerados difíceis\ne talvez inacabados dentro do conteúdos de GRAFOS\n\n"
       << endl;

  cout << "Os famosos 'Graph Coloring' e 'Traveling Salesman'\n"
       << endl;

  cout << "Iremos trabalhar com um grafo que apresenta 4 nós.\nOs nós '0,1,2,3'" << endl;
  cout << "A seguir, digite quantas ligações você irá fazer (considere como grafos não-direcionados)" << endl;
  int x;
  cin >> x;
  cout << "\n\nAgora digite as N ligações com seus devidos pesos.\nOs pesos serão necessários para o algoritimo do caixero viajante!" << endl;
  cout << "Por exemplo, se a ligação entre o nó 0 e 1 valer 15 de peso, digite: 0 1 15\n"
       << endl;

  while (x--)
  {
    int n1, n2, p;
    cin >> n1 >> n2 >> p;
    g1.addEdge(n1, n2);
    grafo[n1][n2] = p;
    grafo[n2][n1] = p;
  }

  cout << "\n\nO caminho com menor valor, que passe por todas as cidades custa: ";
  cout << travllingSalesmanProblem(grafo, s) << endl;

  /*  Graph g1(5);
  g1.addEdge(0, 1);
  g1.addEdge(0, 2);
  g1.addEdge(1, 2);
  g1.addEdge(1, 3);
  g1.addEdge(2, 3);
  g1.addEdge(3, 4);*/
  cout << "\n\nE a coloração do Grafo ficaria assim: \n";
  g1.greedyColoring();

  return 0;
}
