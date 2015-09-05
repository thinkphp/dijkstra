#include <cstdio>
#include <queue>
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"
#define INF ((1LL<<31)-1)
#define MAXN 50005

using namespace std;

struct Node {

       int y,
           cost;
       Node *next;
};

Node *V[ MAXN ];
bool inQueue[ MAXN ];
queue< int > Queue;
int distMin[ MAXN ];

int nodes,
    edges;

void addEdge(const int x, const int y, const int cost) {

     Node *node;

           node = new Node;
           node->y = y;
           node->cost = cost;
           node->next = V[ x ];
           V[ x ] = node;               
};

void readInput() {

     int x, 
         y, 
         c;

     FILE *fin = fopen(FIN, "r");

     fscanf(fin, "%d %d", &nodes, &edges);

     for(int i = 0; i < edges; ++i) {

         fscanf(fin, "%d %d %d", &x, &y, &c);
  
         addEdge(x, y, c);
     }

     fclose( fin ); 
};

void solve() {

     for(int i = 2; i <= nodes; i++) distMin[ i ] = INF;

     distMin[ 1 ] = 0;

     Queue.push( 1 );

     inQueue[ 1 ] = true;

     while( !Queue.empty() ) {

            int node = Queue.front();

            Queue.pop();

            inQueue[ node ] = false;

            for( Node *p = V[ node ]; p; p = p->next ) {

                if( distMin[ p->y ] > distMin[ node ] + p->cost ) {

                   distMin[ p->y ] = distMin[ node ] + p->cost;

                   if(!inQueue[ p->y ]) {

                       Queue.push(  p->y );

                       inQueue[ p->y ] = true; 
                   }
                }
            } 
     };  
};

void writeOutput() {

     FILE *fout = fopen(FOUT, "w");

     for(int i = 2; i <= nodes; i++) fprintf(fout, "%d ", distMin[ i ] < INF ? distMin[ i ] : 0); 

     fclose( fout );
};

int main() {

   readInput();
   solve();
   writeOutput();

 return(0); 
};