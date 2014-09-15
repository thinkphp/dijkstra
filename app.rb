require './lib/dijkstra.rb'

r = [[5],
     [1,2,1],
     [1,3,9],
     [1,5,3],
     [2,4,3],
     [2,3,7],
     [4,3,2],
     [4,1,1],
     [5,2,4],
     [5,4,2]]

start_point = 1
end_point = 3

ob = Dijkstra.new(start_point, end_point, r)

print "Cost = ", ob.getCost(), "\n"
print "Shortest Path = ", ob.getShortestPath()

ob.writeToFile("shortestpath.out")