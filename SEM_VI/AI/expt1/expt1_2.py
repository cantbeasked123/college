tree = { 'A':['B', 'C'], 'B':['D', 'E'], 'C':['F', 'G'], 'D':[], 'E':[], 'F':[], 'G':[] }
start = input("Enter the Start node: ")
goal = input("Enter Goal State: ")

def bfs(tree, start, goal):
    open_list = [start]
    close_list = []

    if start == goal:
        print("Start state is goal state")
        return close_list

    close_list.append(start)
    while open_list:
        node = open_list.pop(0)
        neighbour = tree[node]
        
        for i in neighbour:
            if i not in close_list:
                close_list.append(i)
                open_list.append(i)
                if i == goal:
                    return close_list
    print("Goal not found")
    return []

print("Traversal is:", bfs(tree, start, goal))
