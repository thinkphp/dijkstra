/**
 *  Author           -> Adrian Statescu <mergesortv@gmail.com> <http://thinkphp.ro>
 *  Operating System -> Ubuntu
 *  Environments     -> Wim
 *  Compile          -> g++ -std=c++11 algorithm-dijkstra.cpp -o dij
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"
#define oo ((1LL<<31)-1)
#define MAXN 50005

using namespace std;

int nodes,
    edges;

vector<pair<int,int > > Graph[ MAXN ];
int distMin[ MAXN ];

queue<int> Queue;
bitset<MAXN> inQueue;

void readData() {

     int x,
         y,
         cost; 

     freopen(FIN, "r", stdin);

     scanf("%d %d", &nodes, &edges);

     while(edges--){

           scanf("%d %d %d", &x, &y, &cost);

           Graph[ x ].push_back({y,cost}); 
     }
 
     fclose( stdin );
};

void Dijkstra() {

     for(int i = 2; i <= nodes; i++) distMin[ i ] = oo;

     distMin[ 1 ] = 0;

     Queue.push( 1 );

     inQueue[ 1 ] = true;

     while( !Queue.empty() ) {

            int node = Queue.front();

            Queue.pop();

            inQueue[ node ] = false;

            for(auto it : Graph[ node ]) {

                if(distMin[ it.first ] > distMin[ node ] + it.second) {

                   distMin[ it.first ] = distMin[ node ] + it.second;

                   if(!inQueue[ it.first ]) {

                       Queue.push( it.first );  

                       inQueue[ it.first ] = true;
                   }
                }
            } 
     }
};


void writeData() {

     freopen(FOUT, "w", stdout);

     for(int i = 2; i <= nodes; i++) 

         printf("%d ", (distMin[ i ] < oo ? distMin[ i ] : 0));  

     fclose( stdout );
};


int main() {

 readData();
 Dijkstra();
 writeData();

 return(0);   
};