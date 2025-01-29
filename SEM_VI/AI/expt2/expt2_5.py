tree = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F', 'G'], 'D': [], 'E': [], 'F': [], 'G': []}
start = input("Enter start node: ").strip().upper()
goal = input("Enter the goal state: ").strip().upper()
maxD = int(input("Enter the maximum depth: "))
path=[] 
level = 0 
def dldfs(start,goal,tree,level,path,maxD):
    print("\nCurrent level is",level)
    path.append(start)
    if start == goal:
        print("Search ends")
        return path
    if level == maxD:
        return False
    print("Expanding current node",start)
    neighbour = tree[start]

    for i in neighbour:
        if dldfs(i,goal,tree,level+1,path,maxD):
            return True
        path.pop() 
    return False
    
def iddfs(start,goal,tree,maxD):
    for i in range(maxD):
        print("Iteration: ",i)
        path=[]
    if dldfs(start,goal,tree,level,path,i):
        print("Goal exists")
        print("Path: ",path)
        return True
    return False

iddfs(start,goal,tree,maxD)


