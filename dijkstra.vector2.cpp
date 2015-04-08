#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define MAXN 50005
#define oo ((1LL<<31)-1)
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"

using namespace std;

vector<int> V[ MAXN ];
vector<int> C[ MAXN ];
int distMin[ MAXN ];
queue<int> Queue;
bitset<MAXN> inQueue(0);

int nodes,
    edges;

//prototpes functions
void readData();
void Dijkstra();
void writeData();
void printV();

//main function
int main() {

    readData();
    Dijkstra();
    writeData();

    return(0);
};

void readData() {

     int x,
         y,
         cost;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &nodes, &edges);

     for(int ed = 1; ed <= edges; ed++) {

         scanf("%d %d %d", &x, &y, &cost);

         V[ x ].push_back( y ); 
         C[ x ].push_back( cost ); 
     }

     fclose( stdin );
};

void Dijkstra() {

     for(int i = 2; i <= nodes; i++) distMin[ i ] = oo;

     distMin[ 1 ] = 0;
  
     Queue.push( 1 );

     inQueue[ 1 ] = true;

     while(!Queue.empty()) {

            int curr = Queue.front();

            Queue.pop();

            inQueue[ curr ] = false;    

            for(int i = 0; i < V[ curr ].size(); i++) {

                    int y = V[ curr ][ i ];

                    int cost = C[ curr ][ i ];

                    if(distMin[ y ] > distMin[ curr ] + cost) {

                       distMin[ y ] = distMin[ curr ] + cost;

                       if(!inQueue[ y ]) {

                           Queue.push( y );

                           inQueue[ y ] = true;
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

