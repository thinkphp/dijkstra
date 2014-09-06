var Dijkstra = function(start_point, end_point, r ){

    var start = start_point, 
          end = end_point; 

    var output = []; 

    //create a matrix
    var createMatrix = function(rows, columns) {

              var mat = new Array( rows );

              for (var i = 0; i < rows; i++) 

                      mat[i] = new Array( columns );
         return mat;
    };

    //just declare and create an array and fill them with a for loop
    var createArray = function( n ) {
 
        var arr = new Array( n )

        for(var i = 0; i< arr.length; i++) 

            arr[i] = 0;

        return arr; 
    }  

    var matrix = r,

        Road = createMatrix(6, 6),

        R = createArray( 6 ),

        F = createArray( 6 ),

        S = createArray( 6 ),

        nodes = 0,

        get = function( node ) {

              if(F[node]) get(F[node])

              output.push(node)
        },

        getCost = function() {
                return (R[end]) 
        },

        getShortestPath = function() {
                             
             get( end );

             return output;
        }, 

        read = (function() {

               var n = r.length, x, y, cost;

               for(var i = 1; i <= 5; i++) {

                       for(var j = 1; j <= 5; j++) {

                           if(i == j) Road[i][j] = 0; 
                               else   Road[i][j] = 88; 
                       }
               }

               for(var i = 0; i < n; i++) {

                   x = matrix[i][0]; 
                   y = matrix[i][1];

                   cost = matrix[i][2];
                   Road[x][y] = cost
               } 
        })(),

        solve = (function() {

                var min, posMin;

                S[start] = 1;
                 
                for(var i = 1; i <= 5; i++) {

                    R[ i ] = Road[ start ][ i ];

                    if( start != i ) 

                        if( R[ i ] < 88) 

                            F[ i ] = start
                }

                //execute n-1 times
                for(var i=1;i<=5-1;i++) {
     
                    min = 88

                    for(var k = 1; k <= 5; k++) {

                        if(S[ k ] == 0) 

                           if(R[ k ] < min) {

                              min = R[ k ]

                              posMin = k
                           }  
                    }

                    //marked the node as selected
                    S[ posMin ] = 1

                    for(var j = 1; j <= 5; j++) {

                        if(S[j] == 0) 

                           if(R[ j ] > R[ posMin ] + Road[ posMin ][ j ]) {

                                     R[ j ] = R[ posMin ] + Road[ posMin ][ j ]
                                     F[ j ] = posMin
                           }  
                    }
                }

        })();
        
     
        return {
               getCost: getCost,
               getShortestPath: getShortestPath
        
        }
}