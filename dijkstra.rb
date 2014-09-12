class Dijkstra

      def initialize(filename, startpoint, endpoint)

         #start node
         @start = startpoint
          
         #end node
         @end = endpoint

         #in this vector we will hold the shortest path 
         @path = []
 
         #PInfinit
         @PInfinit = 88

         #read and init the father array, selected array and road array
         readAndInit(filename)

         #Dijkstra's algorithm in action and good luck
         dijkstra()
         
      end  

      # This method determines the minimum cost of the shortest path
      def getCost()
          @R[@end] 
      end

      # get the shortest path
      def getShortestPath()
          ROAD(@end)
          @path
      end

      def ROAD(node) 
          if @F[node] != 0
             ROAD(@F[node])
          end 

          @path.push(node)
      end

      def dijkstra()
  
          start = @start
          min = @PInfinit
          posMin = @PInfinit

          (1..@nodes-1).each do |i|
              @R[i] = @road[start][i]
              if i != start 
                 if @R[i] < @PInfinit
                    @F[i] = start 
                 end
              end
          end
  
          #for debug 
          #print @R    
  
          @S[start] = 1

          #for debug
          #print @S

          (1..@nodes-2).each do |d|
               
              min = @PInfinit

              (1..@nodes-1).each do |i|
                  if @S[i] == 0
                     if @R[i] < min
                         min = @R[i]
                         posMin = i
                     end
                  end  
              end     

              @S[posMin] = 1  

              (1..@nodes-1).each do|j|
                  if @S[j] == 0
                           if @R[j] > @R[posMin] + @road[posMin][j] 
                              @R[j] = @R[posMin] + @road[posMin][j]
                              @F[j] = posMin
                           end 
                  end
              end  
               
          end 

      end 

      def readAndInit(file)

          arr = []

          File.open(file, "r").each_line { |line| arr << line.split(' ').map {|c| c.to_i} }

          @nodes = arr[0][0] + 1

          n = arr.size()-1

          @road = Array.new(@nodes) { Array.new(@nodes) }
          @R = Array.new(@nodes)
          @S = Array.new(@nodes)
          @F = Array.new(@nodes)

          (0..@nodes-1).each do |i|
              @R[i] = 0 
          end

          (0..@nodes-1).each do |i|
              @S[i] = 0 
          end

          (0..@nodes-1).each do |i|
              @F[i] = 0 
          end

          (0..@nodes-1).each do |i|
              (0..@nodes-1).each do |j|
                  if i == j
                     @road[i][j] = 0 
                  else
                     @road[i][j] = @PInfinit
                  end 
              end  
           end 
  
           (1..n).each do |i|
                  x = arr[i][0]
                  y = arr[i][1]
                  c = arr[i][2]
                  @road[x][y] = c
           end 
          
      end
end

start_point = 1
end_point = 3

ob = Dijkstra.new('dijkstra.in', start_point, end_point)

print "Cost = ", ob.getCost(), "\n"
print "Shortest Path = ", ob.getShortestPath()