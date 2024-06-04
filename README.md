Dijkstra
========

Dijkstra's algorithm, conceived by computer scientist Edsger Dijkstra, is a graph search algorithm that solves in single-source
shortest path problem for a graph with non-negative edge path costs, producing a shortest path tree. 

![Screenshot](https://miro.medium.com/v2/resize:fit:566/0*LMTm4lzv_xuTGq8J.png)

How to use
----------

Include the latest version MooTools Framework, then dijkstra.js into the page:

<script src="http://ajax.googleapis.com/ajax/libs/mootools/1.5.0/mootools-yui-compressed.js"></script>
<script type="text/javascript" src="dijkstra-min.js"></script>


Sample
-------

  #JS

     var road = [[1, 2, 1],
                [1, 3, 9],
                [1, 5, 3],
                [2, 4, 3],
                [2, 3, 7],
                [4, 3, 2],
                [4, 1, 1],
                [5, 2, 4],
                [5, 4, 2]]

    var start = 1, 
        end   = 3;

    var dij = new Dijkstra(start, end, road );

    console.log("Cost = " + dij.getCost() )

    console.log("Shortest path from the node "+ start + " to "+ end + " -> "+ dij.getShortestPath() )



#### Problem Set

https://infoarena.ro/problema/dijkstra

## References

  http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
