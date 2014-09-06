# Dijkstra's algorithm conceived by computer scientist Edsger Dijkstra in 1956 and published in 1959
# is a graph search algorithm that solves the single-source shortest path problem for a graph with 
# non-negative edge path costs, producing a shortest path tree.
# O(N^3) Running Time complexity

class Dij: 

      #matrix of roads
      road = [[]]        

      #infinity
      infinit = 9999 

      #array of costs
      D = []

      #array of selected nodes
      S = []

      #array of fathers
      T = []
   
      #number of nodes  
      nodes = -1

      #output
      output = []

      def __init__(self, start):

          #read the graph from FILE.in  
          self.readGraph()

          #start node
          self.r = start

          #assign again
          r = self.r

          #step 1 you must to mark the selected start node in the utility vector called S 
          self.S[ r ] = 1    

          #step 2
          for j in range(1, self.nodes + 1):

              self.D[ j ] = self.road[r][j]

          #step 3
          for j in range(1, self.nodes+1):

              if self.D[ j ]:

                 self.T[ j ] = r 

          for i in range(1, self.nodes):

              #find the nodes that is the close to started node
              min = 9999

              #at nest step you must walk through array and find out which one is the minimum cost from start node.
              for j in range(1, self.nodes + 1):

                #if not selected
                if self.S[ j ] == 0:

                  if self.D[j] < min:

                     min = self.D[j]
                     pos = j

              self.S[ pos ] = 1
         
              #next step
              for j in range(1, self.nodes + 1):

                  if self.S[ j ] == 0:
                     if self.D[ j ] > self.D[ pos ] + self.road[ pos ][ j ]:
                        self.D[ j ] = self.D[ pos ] + self.road[ pos ][ j ]
                        self.T[ j ] = pos
     
          f = open('road.out','w')
           
          for k in range(1, self.nodes + 1):
              if k is not r:
                 if self.T[ k ]:

                    print "Road from ", r, " to ", k

                    self.draw(k)

                    print self.output

                    f.write("Road from {} to {} => {}".format(r,k,str(self.output)))

                    f.write("\n")

                    self.output = []

                 else:
                    print "There is not exists road"
                                
          f.close() 

      def draw(self, node):

          if self.T [ node ]:

             self.draw( self.T[ node ] )

          print node
          self.output.append(node)

      def readGraph(self):

          counter = 0

          input = []
  
          with open('graph.in', 'r') as file:

               for a_line in file:

                   counter += 1 
                   
                   if counter == 1:

                      number_of_nodes = int(a_line.rstrip())

                   else:

                      input.append(a_line.rstrip()) 

          size = len( input )

          self.nodes = number_of_nodes

          self.road = [[0 for i in range(0, number_of_nodes + 1)] for j in range(0, number_of_nodes + 1)]

          for i in range(0, self.nodes + 1):

              for j in range(0, self.nodes + 1):

                  if i == j:

                     self.road[i][j] = 0

                  else:

                     self.road[i][j] = self.infinit    

          for i in range(0, size):

              component = input[i]
              node1 = int(component[0])
              node2 = int(component[2])
              cost = int(component[4])  

              self.road[node1][node2] = cost

          #init
          self.D = [ 0 ]* (number_of_nodes + 1)
          self.S = [ 0 ]* (number_of_nodes + 1)
          self.T = [ 0 ]* (number_of_nodes + 1)
 


ob = Dij(2)
