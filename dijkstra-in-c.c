#include <stdio.h>
#include <stdlib.h>
#define FIN "dijkstra.in"
#define FOUT "dijkstra.out"
#define oo ((1LL<<31) - 1)
#define MAXN 50005

int nodes,
    edges; 

typedef struct NODE {
        int y,
            cost;
        struct Node *next;  
} *PNODE, NODE;

PNODE ListNodes[ MAXN ];

int distMin[ MAXN ];
char selectedNode[ MAXN ];

void ADDEdge(const int x, const int y, const int cost) {

     PNODE newNode = ( PNODE )calloc(1, sizeof( NODE ) );
           newNode->y = y;
           newNode->cost = cost;
           newNode->next = ListNodes[ x ]; 
           ListNodes[ x ] = newNode;
};

void readData() {

     int x,
         y,
         c;

     freopen(FIN, "r", stdin);

     scanf("%d %d", &nodes, &edges);

     for(;edges; edges--) {

         scanf("%d %d %d", &x, &y, &c);
  
         ADDEdge(x, y, c);
     }

     fclose( stdin ); 
}; 

void dijkstra() {

     PNODE prim = NULL,
           last = NULL,
           p;
     int i,
         curr;

     for(i = 2; i <= nodes; i++) distMin[ i ] = oo;

     distMin[ 1 ] = 0;

     selectedNode[ 1 ] = 1;

     prim = last = (PNODE)calloc(1,sizeof(NODE));

     prim->y = 1;

     prim->next = NULL;

     while( prim ) {

            curr = prim->y;

            selectedNode[ curr ] = 0;

            for(p = ListNodes[ curr ]; p; p = p->next) {

                if(distMin[ p->y ] > distMin[ curr ] + p->cost) {

                   distMin[ p->y ] = distMin[ curr ] + p->cost;

                   if(!selectedNode[ p->y ]) {

                       selectedNode[ p->y ] = 1;

                       PNODE o = (PNODE)calloc(1, sizeof(NODE));
                             o->y = p->y;
                             o->cost = p->cost;
                             o->next = NULL;
                             last->next = o;
                             last = last->next;
                   }
                }
            }      

            PNODE aux = prim;
            prim = prim->next;      
            free( aux );   
     }
};

void writeData() {

     freopen(FOUT, "w", stdout);

     int i;
     for(i = 2; i <= nodes; i++) printf("%d ", distMin[ i ] < oo ? distMin[ i ] : 0);

     fclose( stdout );
}

int main() {

    readData();
    dijkstra(); 
    writeData(); 

 return(0);
};