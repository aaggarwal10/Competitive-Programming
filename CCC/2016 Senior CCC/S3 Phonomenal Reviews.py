import sys,collections
sys.setrecursionlimit(100005)

n,m=map(int,input().split())
pho=[0]*n#list that contains if the restaurant at an index is a pho restaurant ( 1 for yes, 0 for no)
for i in map(int,input().split()):
    pho[i]=1

g=[set() for _ in range(n)]#list of sets where index is a restaurant and values in set are the direct neighbours of that particular restaurant
for _ in range(n-1):
    a,b=map(int,input().split())
    g[a].add(b)
    g[b].add(a)
print(g)
# keep deleting irrelevant leaves
edgecount=n-1
for i in range(n):
    while pho[i]==0 and len(g[i])==1:#if restaurant is not pho and is only connected to onw other restaurant that means it will not be on a path in between two pho restaurants, thus it can be removed
        j=g[i].pop()#pop it
        g[j].remove(i)#remove it from restaurant it is attached to
        i=j#check the same condition for the restaurant it was attached to
        edgecount-=1#remove the edge between the extra leaf and the new node

# get diameter

# dfs 1
start=0#starting restaurant
while pho[start]==0: start+=1#loop until u hit a pho
dfs=collections.deque()
dfs.append(start)#add it to queue
remain=[1]*n
remain[start]=0
end=start
while dfs:#while queis not empty
    end=dfs.popleft()#pop first item
    for v in g[end]:#for every node it is connected to
        if remain[v]:#if it should remain there
            remain[v]=0#set it to fales
            dfs.append(v)#add it

# dfs 2
dist=[-1]*n#distances
start=end
dist[start]=0
dfs.append(start)
#go through process again and get distances
while dfs:
    end=dfs.popleft()
    for v in g[end]:
        if dist[v]==-1:
            dist[v]=dist[end]+1
            dfs.append(v)

# answer is edgecount times two minus graph diameter to get minimum time
print(edgecount*2-dist[end])
