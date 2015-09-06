#include <cstdio>
#include <vector>
#include <queue>
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"

using namespace std;

class Dijkstra {

  public:
  Dijkstra(int N, int M): nodes( N ), 
                          edges( M ), 
                          Graph(2 * N + 1), 
                          distMin(2 * N + 1), 
                          inQueue(N + 1) {}    

  void addEdge(int x, int y, int cost) {
      
       Graph[ x ].push_back(make_pair(y, cost));
  }

  void solve() {

       for(int i = 2; i <= nodes; i++) distMin[ i ] = oo;

       distMin[ 1 ] = 0; 

       Queue.push( 1 );

       inQueue[ 1 ] = true;

       while( !Queue.empty() ) {

            int node = Queue.front();

                Queue.pop();

                inQueue[ node ] = false;

                for(auto G : Graph[ node ]) {

                    if(distMin[ G.first ] > distMin[ node ] + G.second) {

                       distMin[ G.first ] = distMin[ node ] + G.second;

                       if(!inQueue[ G.first ]) {

                           Queue.push( G.first );

                           inQueue[ G.first ] = true;
                       } 
                    }
                }
       } 
  }

  void getDistMin() {

       freopen(FOUT, "w", stdout);

       for(int i = 2; i <= nodes; i++) {

           printf("%d ", distMin[ i ] < oo ? distMin[ i ] : 0);
       }

       fclose( stdout );
  }

  void printGraph() {

       printf("\n");

       for(int i = 1 ; i <= nodes; i++) {

           printf("%d - > ", i);

           for(auto v : Graph[ i ]) {

               printf("%d ", v.first);
           }

           printf("\n");
       } 
           printf("\n");

  }

  private:
  int nodes, edges;
  vector<vector<pair<int, int> > > Graph;
  vector<int> distMin;
  queue<int> Queue;
  vector<bool> inQueue;
  int oo = ((1LL<<31)-1);
};

int main() {
     
    int n, 
        m,
        x, 
        y, 
        cost;

    freopen(FIN, "r", stdin);

    scanf("%d %d", &n, &m);

    Dijkstra dij(n, m);

    while(m--){

          scanf("%d %d %d", &x, &y, &cost);
          dij.addEdge(x, y, cost);
    }
   
    dij.solve();

    dij.getDistMin();
    
    fclose( stdin );

 return(0);
};