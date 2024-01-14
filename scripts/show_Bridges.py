import networkx as nx
import matplotlib.pyplot as plt


G = nx.MultiGraph()
n=0
m=0

def read_graph():
    global n, m, G
    f=open("..\\..\\TextFiles\\input_graph.txt",'r')
    n,m=map(int,f.readline().split())
    G.add_nodes_from(range(n))
    for i in range(m):
        v,u=map(int,f.readline().split())
        G.add_edge(v-1,u-1)
    f.close()

def show_graph_bridges():
    global n, m, G
    f = open("..\\..\\TextFiles\\Bridges.txt",'r')
    cnt = int(f.readline().rstrip())
    bridges = set()
    for i in range(cnt):
        v,u = map(int, f.readline().rstrip().split())
        bridges.add((v-1,u-1))
        bridges.add((u-1,v-1))
    f.close()

    edge = list(G.edges())
    edge_colors = ['black' for i in range(m)]
    for i in range(m):
        if(edge[i] in bridges):
            edge_colors[i] = 'red'

    labels = dict()
    for i in range(n):
        labels[i] = i + 1

    plt.figure(figsize = (10, 8))
    pos = nx.spring_layout(G, k = 2)
    nx.draw(G,labels = labels, edge_color = edge_colors,node_size=500,pos = pos)
    plt.savefig("..\\..\\Images\\Bridges.png")
    #plt.show()

def main():
    read_graph()
    show_graph_bridges()

main()

