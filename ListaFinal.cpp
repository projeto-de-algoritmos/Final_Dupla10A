
#include <vector>
#include <iostream>
#include <list>
using namespace std;

class Grafo
{
  int T;
  list<int> *adj;

public:
  Grafo(int T)
  {
    this->T = T;
    adj = new list<int>[T];
  }
  ~Grafo() { delete[] adj; }

  void addEdge(int v, int w);
  void GrafoColorido();
};

int caixeiroViajante(int grafo[][4], int s)
{

  vector<int> vertice;
  for (int i = 0; i < 4; i++)
    if (i != s)
      vertice.push_back(i);

  int min_path = INT_MAX;
  do
  {

    int current_pathweight = 0;

    int k = s;
    for (int i = 0; i < vertice.size(); i++)
    {
      current_pathweight += grafo[k][vertice[i]];
      k = vertice[i];
    }
    current_pathweight += grafo[k][s];

    min_path = min(min_path, current_pathweight);

  } while (next_permutation(vertice.begin(), vertice.end()));

  return min_path;
}

void Grafo::addEdge(int v, int w)
{
  adj[v].push_back(w);
  adj[w].push_back(v);
}

void Grafo::GrafoColorido()
{
  int resultado[T];
  resultado[0] = 0;
  bool disponivel[T];

  for (int u = 1; u < T; u++)
    resultado[u] = -1;

  for (int cr = 0; cr < T; cr++)
    disponivel[cr] = false;

  for (int u = 1; u < T; u++)
  {

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
      if (resultado[*i] != -1)
        disponivel[resultado[*i]] = true;

    int cr;
    for (cr = 0; cr < T; cr++)
      if (disponivel[cr] == false)
        break;

    resultado[u] = cr;

    for (i = adj[u].begin(); i != adj[u].end(); ++i)
      if (resultado[*i] != -1)
        disponivel[resultado[*i]] = false;
  }

  for (int u = 0; u < T; u++)
    cout << "Vertice: " << u << " ---> Cor: "
         << resultado[u] << endl;
}

int main()
{
  Grafo g1(4);
  int grafo[][4] = {{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}};
  int s = 0;
  int x;
  cout << "Trabalho final abordando os problemas do Caixeiro viajante e Coloração de Grafos." << endl;
  cout << "Para iniciarmos nossa solução iremos trabalhar com um grafo não-direcionado de 4 nós.\nSendo eles '0,1,2,3'" << endl;
  cout << "Digite quantas ligações você irá fazer:" << endl;

  cin >> x;
  cout << "\n\nAgora digite as N ligações com seus devidos pesos.\nOs pesos serão necessários para o algoritimo do Caixero viajante!" << endl;
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
  cout << caixeiroViajante(grafo, s) << endl;
  cout << "\n\nE a coloração do Grafo ficaria assim: \n";
  g1.GrafoColorido();

  return 0;
}
