'''Breadth first search:'''
tree = { 'A':['B', 'C'], 'B':['D', 'E'], 'C':['F', 'G'], 'D':[], 'E':[], 'F':[], 'G':[] }
start = input("Enter the Start node: ")

def bfs(tree, start):
    open_list = [start]
    close_list = []
    while open_list:
        node = open_list.pop(0)
        if node not in close_list:
            close_list.append(node)
            neighbour = tree[node]
            for i in neighbour:
                open_list.append(i)
    return close_list

print("Traversal is", bfs(tree, start))
