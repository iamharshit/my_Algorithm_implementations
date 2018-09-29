class Node:
    def __init__(self, point, value, G=0, H=0, parent=None):
        self.point = (point[0],point[1])
        self.value = value
        self.G = G
        self.H = H
        self.F = self.G+self.H
        self.parent = parent

class astar:
    def __init__(self, start, destination, grid):
        self.start = start
        self.destination = destination
        self.grid = grid
    
    #Helper function
    def in_bounds(self, child):
        horizontal_len, vertical_len = len(self.grid[0]), len(self.grid)
        if(child[0]>=0 and child[0]<=vertical_len-1 and child[1]>=0 and child[1]<=horizontal_len-1):
            return True
        return False
        
    #Helper Function
    def is_movable(self, child):
        if(self.grid[child[0]][child[1]]=='#'):
            return False
        return True
    
    #Helper Function
    def get_children(self, node):
        y,x = node.point
        return [child for child in [(y,x-1),(y-1,x),(y,x+1),(y+1,x)] if(self.in_bounds(child) and self.is_movable(child)) ]        
    
    #Helper Function
    def search_by_value(openset, node):
        for i in openset:
            if i.point == node.point:
                return True, i
        return False, -1
    
    #Helper Function
    def manhattan(self, point):
        return abs(point[0]-self.destination[0]) + abs(point[1]-self.destination[1])            
        
    #Helper Function
    def move_cost(self, point):
        return grid[point[0]][point[1]]
    
    #Helper Function
    def trace_path(self,current):
        path = []
        while(current.parent):
            path.append(current.point)
            current = current.parent
        path.append(current.point)
        
        return path[::-1]

    def search(self, sett, node):
        for item in sett:
            if(item.point == node.point):
                return (True,item)
        return False, -1
    
    #Main Function
    def astar(self):
        start=self.start
        openset = set()
        closedset = set()
        
        start = Node(start, self.grid[start[0]][start[1]], 0+self.move_cost(start), self.manhattan(start), None)           
        openset.add(start)
            
        while openset:
            current = min(openset, key=lambda x: x.G+x.H)
            if current.point==self.destination:
                return self.trace_path(current)
            
            openset.remove(current)
            closedset.add(current)
            
            for child in self.get_children(current):
                child_node = Node(child, self.grid[child[0]][child[1]], current.G+self.move_cost(child), self.manhattan(child), current)
                if self.search(closedset, child_node)[0]==True:
                    continue
                
                if self.search(openset,child_node)[0]==True:
                    node = self.search(openset,child_node)[1]
                    if child_node.F < node.F:
                        openset.remove(node)
                        openset.add(child_node)
                else:
                    openset.add(child_node)
        
        return 'No path possible'


grid = [[1  , 1,  1 ],
        [5  , 1, '#'],
        ['#', 1, '#'],
        [1  , 1,  1 ]
       ]

start = (3,0)           #in-format: (y,x)
destination = (0,0)     #in-format: (y,x)

print astar(start, destination, grid).astar()
'''
Output: [(3, 0), (3, 1), (2, 1), (1, 1), (0, 1), (0, 0)]
'''
