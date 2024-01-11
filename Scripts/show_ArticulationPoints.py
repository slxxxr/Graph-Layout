import networkx as nx
import matplotlib.pyplot as plt

G = nx.MultiGraph()
n=0
m=0

def read_graph():
    f=open("D:\\GraphLayout\\TextFiles\\input_graph.txt",'r')
    global n,m,G
    n,m=map(int,f.readline().split())
    G.add_nodes_from(range(n))
    for i in range(m):
        v,u=map(int,f.readline().split())
        G.add_edge(v-1,u-1)
    f.close()


def show_graph_articulation_points():
    f=open("D:\\GraphLayout\\TextFiles\\ArticulationPoints.txt",'r')
    points = list(map(int,f.readline().split()))
    f.close()
    colors = ['lightblue' for i in range(n)]
    for i in points:
        colors[i-1] = 'red'
    labels = dict()
    for i in range(n):
        labels[i] = i+1

    plt.figure(figsize = (10, 8))
    pos = nx.spring_layout(G, k = 2)
    nx.draw(G,labels = labels , node_color = colors,node_size=500,pos=pos)
    plt.savefig("D:\\GraphLayout\\Images\\ArticulationPoints.png")
    #plt.show()

def main():
    read_graph()
    show_graph_articulation_points()

main()




