#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"
#define MAXN 50005
#define oo ((1LL << 31) - 1)

using namespace std;

vector< pair<int, int> > Graph[ MAXN ];
queue< int > Q;

int nodes,//number of nodes
    edges;//number of edges

int distMin[ MAXN ];
bitset<MAXN> in_Queue(0);   

void readData() {

     int x,
         y,
         c;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &nodes, &edges);

     while(edges--) {

           scanf("%d %d %d", &x, &y, &c);

           Graph[ x ].push_back(make_pair(y, c));
     } 

     fclose(stdin);
};

void Dijkstra(){

     for(int i = 2; i <= nodes; i++) distMin[ i ] = oo;

     distMin[ 1 ] = 0; 

     Q.push( 1 );

     in_Queue[ 1 ] = true;

     while( !Q.empty() ) {

             int node = Q.front();

             Q.pop();

             in_Queue[ node ] = false;  

             for(vector< pair<int,int> >::iterator it = Graph[ node ].begin(); it != Graph[ node ].end(); it++) {

                       if( distMin[ it->first ] > distMin[ node ] + it->second ) {

                           distMin[ it->first ] = distMin[ node ] + it->second;

                           if( !in_Queue[ it->first ] ) {

                                Q.push(it->first);

                                in_Queue[ it->first ] = true;
                           }
                       }
             }
     } 
};

void writeData(){

     freopen(FOUT, "w", stdout);

     for(int i = 2; i <= nodes; i++) printf("%d ", (distMin[ i ] < oo) ? distMin[ i ] : 0); 

     fclose( stdout );
};


int main() {

 readData();
 Dijkstra();
 writeData();

 return(0);
};
