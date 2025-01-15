tree = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F', 'G'], 'D': [], 'E': [], 'F': [], 'G': []}
start = input("Enter start node: ")
goal = input("Enter goal node: ")
def dfs(tree):
    open_list = [start]
    close_list = []
    
    if start == goal:
        print("Start itself is the goal node")
        return open_list
    
    while open_list:
        node = open_list.pop()
        
        if node not in close_list:
            close_list.append(node)
            
        neighbors = tree[node]
        for neighbor in neighbors:
            open_list.append(neighbor)
            
            if neighbor == goal:
                close_list.append(neighbor)
                return close_list
    
    print("Goal node not found")
print("DFS traversal:", dfs(tree))
