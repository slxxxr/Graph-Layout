import networkx as nx
import numpy as np

f=open("D:\\GraphLayout\\TextFiles\\input_graph.txt",'r')
n,m=map(int,f.readline().split())
G = nx.Graph()
G.add_nodes_from(range(n))
for i in range(m):
    v,u=map(int,f.readline().split())
    G.add_edge(v,u)
f.close()

pos = nx.spiral_layout(G)

f=open("D:\\GraphLayout\\TextFiles\\output.txt",'w')
for i in pos.keys():
    f.write(str(i)+' ')
    s=np.array2string(pos[i],formatter={'float_kind':lambda x: "%.5f" % x})
    f.write(s[1:-1])
    f.write('\n')
f.close()



