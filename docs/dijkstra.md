Class: Dijkstra {#Dijkstra}
===========================================

Dijkstra's algorithm, conceived by computer scientist Edsger Dijkstra, is a graph search algorithm that solves in single-source shortest path problem for a graph with non-negative edge path costs, producing a shortest path tree.

### Syntax:

    var dij = new Dijkstra(start_point, end_point, matrix_of_road)

### Arguments:

- start_point (Integer) start node
- end_point   (Integer) end node 
- matrix_of_road ((int x int) -> float )(Matrix = Array of Array) - matrix of roads

Dijkstra Method: getCost {#Dijkstra: getCost}
-------------------------------------------------------------

Get the cost for shortest path.

### Syntax: dij.getShortestPath();

### Arguments:

- void

### Returns:

- returns `Integer` a cost shortest parth.


Dijkstra Method: getShortestPath {#Dijkstra: getShortestPath}
-------------------------------------------------------------

Get the cost for shortest path.

### Syntax: dij.getShortestPath();

### Arguments:

- void

### Returns:

- returns `Array' an array shortest path


# Example:

   
       //matrix of roads
       var road = [[1, 2, 1],
                  [1, 3, 9],
                  [1, 5, 3],
                  [2, 4, 3],
                  [2, 3, 7],
                  [4, 3, 2],
                  [4, 1, 1],
                  [5, 2, 4],
                  [5, 4, 2]], 

       //start node I mean from where you want to go
       start = 1, 

       //end node I mean where you want to get to, where you want to arrive
       end = 3;

       //create an object of this class
       var dij = new Dijkstra(start, end, road);

       //display the cost of the path
       console.log("Cost = " + dij.getCost() ) 
      //output -> Cost = 7

       //display the shortest path
       console.log("Shortest path from the node "+ start + " to "+ end + " -> "+ dij.getShortestPath() )
       //output ->Shortest path from the node 1 to 3 -> 1 2 4 3
   