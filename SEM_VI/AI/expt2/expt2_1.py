tree={'A':['B','C'],'B':['D','E'],'C':['F','G'],'D':[],'E':[],'F':[],'G':[]}
start=input("Enter start node:")
def dfs(tree):
    open=[start]
    close=[]
    while open:
        node=open.pop()
        if node not in close:
            close.append(node)
        neighbour=tree[node]
        for i in neighbour:
            open.append(i)
    return close
print("Dfs traversal:", dfs(tree))
