tree = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F', 'G'], 'D': [], 'E': [], 'F': [], 'G': []}
start = input("Enter start node: ")
goal = input("Enter goal node: ")

def dfs(tree):
    open = [start]
    close = []

    if start == goal:
        print("Start itself is the goal node")
        return open

    while open:
        path = open.pop()
        node = path[-1]

        if node not in close:
            close.append(node)
            neighbour = tree[node]

            for i in neighbour:
                new_path = list(path)
                new_path.append(i)
                open.append(new_path)

                if i == goal:
                    return new_path
    print("Goal node not found")

print("Dfs traversal:", dfs(tree))
