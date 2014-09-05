/*
 * Dijkstra's algorithm.   
 */
#include <stdio.h>

int output[50], ind = 0;

const long PInfinit = 888;

int n;//in this variable we hold the number of nodes.

int road[50][50], R[50], F[50], S[50];

FILE *fin, *fout; //FILE I/O handler for files

int ender;

//prototypes
void read(const char *);
void writeToFile(const char *);
void dijkstra();
void solution(int);
void get(int);

int main() {

    printf("Arrival Node=");
    scanf("%d",&ender);
     
    read("road.in");
    dijkstra();
    solution( ender );

    writeToFile("dijkstra.out");

    return(0);
}

void read(const char* filename) {

     int i,j,x,y;
     float c;

     fin = fopen(filename, "r");

     fscanf(fin, "%d", &n);

     for(i=1;i<=n;i++) {

         for(j=1;j<=n;j++) {

             if(i == j) {

                  road[i][j] = 0; 

             } else {

                 road[i][j] = PInfinit;  
             }
         }
     }
     
     while(!feof(fin)) { 
            fscanf(fin, "%d %d %f", &x, &y, &c); 
            road[x][y] = c;
     }

     for(i=1;i<=n;i++) {

         for(j=1;j<=n;j++) {

             printf("%5d ", road[i][j]);
         }
             printf("\n");
     }    
}

void dijkstra() {
     int i,j,k,
           start,
                min,
                    pos = 0;

     start = 1;
      
     for(i=1;i<=n;i++) {
         R[i] = road[start][i];

         if(i!=start) 
            if(R[i] < PInfinit) F[i] = start;  
     }      
  
     S[start] = 1; 
   
     //execute n-1 times
     for(i=1;i<=n-1;i++) {
        
         min = PInfinit;

         for(j=1;j<=n;j++) {
            if(S[j] == 0)
             if(R[j]<min){
                min = R[j];
                pos = j;
             } 
         }        

         S[ pos ] = 1;

         for(j=1;j<=n;j++) {

             if(S[j] == 0) 

                if(R[ j ] > R[ pos ] + road[ pos ][ j ]) {

                   R[ j ] = R[ pos ] + road[ pos ][ j ]; 

                   F[ j ] = pos;
                }
         }
     } 
}

void solution( node ) {
     
     int i;

     get(node);

     printf("The cost from 1 to %d = %d\nThe shortest path is -> ", ender, R[ender]);
 
     for(i=0;i<n;i++) {

         if(output[i]) printf("%d ", output[i]);
     }  
}

void get( node ) {

     if(F[ node ]) get( F[ node ] );

     output[ind++] = node;
}

void writeToFile(const char *filename) {

     int i;

     fout = fopen(filename,"w");

     fprintf(fout, "The cost from 1 to %d is %d\n The shortest path is -> \n", ender, R[ender]);
 
     for(i=0;i<n;i++) {

         if(output[i]) fprintf(fout, "%d ", output[i]);
     }
    
     fclose( fout );

}





