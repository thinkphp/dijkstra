#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define MAXN 50005
#define oo ((1LL<<31)-1)
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"

using namespace std;

struct Node {

       int y,
           cost;
       bool operator < (const Node& n) const {

            return cost > n.cost;
       } 
};

vector<Node> Graph[ MAXN ];
int distMin[ MAXN ];
queue<Node> Queue;
bitset<MAXN> inQueue(0);

int nodes,
    edges;

//prototpes functions
void readData();
void Dijkstra();
void writeData();

//main function
int main() {

    readData();
    Dijkstra();
    writeData();

    return(0);
};

void readData() {

     int x;

     Node node;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &nodes, &edges);

     for(int ed = 1; ed <= edges; ed++) {

         scanf("%d %d %d", &x, &node.y, &node.cost);

         Graph[ x ].push_back( node ); 
     }

     fclose( stdin );
};

void Dijkstra() {

     Node node, 
          aux, 
          auxNode; 
     int  k;  

     for(int i = 2; i <= nodes; i++) distMin[ i ] = oo;

     distMin[ 1 ] = 0;
  
     node.y = 1;

     node.cost = 0;

     Queue.push( node );

     inQueue[ 1 ] = true;

     while(!Queue.empty()) {
 
            aux = Queue.front();

            k = aux.y;

            Queue.pop();

            inQueue[ aux.y ] = false;

            for(vector<Node>::iterator it = Graph[ aux.y ].begin();it != Graph[ aux.y ].end(); it++ ) {

                              if(distMin[ it->y ] > distMin[ k ] + it->cost) {

                                 distMin[ it->y ] = distMin[ k ] + it->cost;

                                 if(!inQueue[ it->y ]) {

                                     auxNode.y = it->y;

                                     auxNode.cost = it->cost;

                                     Queue.push(auxNode);

                                     inQueue[ it->y ] = true;  
                                 }                            
                              }   
            }
     }
};

void writeData() {

     freopen(FOUT, "w", stdout);

     for(int i = 2; i <= nodes; i++) printf("%d ", (distMin[ i ] < oo) ? distMin[ i ] : 0);

     fclose( stdout );
};

