#best first search
graph = {
    'A':[('B', 12), ('C', 4)],
    'B':[('D', 7), ('E', 3)],
    'C':[('F', 8), ('G', 2)],
    'D':[],
    'E':[('H',0)],
    'F':[('H',0)],
    'G':[('H',0)],
    'H':[]
}

start = input("Enter start: ")
goal = input("Enter goal: ")
def bfs(start, goal, graph, open=[], close=[]):
    if start not in close:
        print(start)
        close.append(start)
        for x in graph[start]:
            if x[0][0] not in open:
                open.append(x)
    open.sort(key=lambda x:x[1])
    if open[0][0] == goal:
        print(open[0][0])
    else:
        node=open[0]
        open.remove(node)
        bfs(node[0], goal, graph, open, close)
bfs(start, goal, graph)
