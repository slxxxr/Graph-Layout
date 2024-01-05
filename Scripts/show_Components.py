import networkx as nx
import matplotlib.pyplot as plt
import matplotlib
import numpy as np


G = nx.MultiGraph()
n=0
m=0

def read_graph():
    global n, m, G
    f=open("D:\\GraphLayout\\TextFiles\\input_graph.txt",'r')
    n,m=map(int,f.readline().split())
    G.add_nodes_from(range(n))
    for i in range(m):
        v,u=map(int,f.readline().split())
        G.add_edge(v,u)
    f.close()

def show_graph_components():
    global n, m, G
    f = open("D:\\GraphLayout\\TextFiles\\Components.txt",'r')
    cnt = int(f.readline().rstrip())
    node_colors = ['' for i in range(n)]

    if(cnt > 5):
        all_colors = [name for name, hex in matplotlib.colors.CSS4_COLORS.items()]
        np.random.shuffle(all_colors)
    else:
        all_colors = [name for name, hex in matplotlib.colors.TABLEAU_COLORS.items()]

    used_colors = set(['black', 'darkseagreen', 'darkslateblue', 'darkslategray', 'darkslategrey', 'midnightblue', 'darkblue', 'navy', 'indigo'])
    for i in range(cnt):
        color = np.random.choice(all_colors)
        while(color in used_colors):
            color = np.random.choice(all_colors)
        used_colors.add(color)

        nodes = list(map(int,f.readline().rstrip().split()))
        for node in nodes:
            node_colors[node] = color
    f.close()

    labels = dict()
    for i in range(n):
        labels[i] = i + 1

    pos = nx.circular_layout(G)
    plt.figure(figsize = (10, 8))
    nx.draw(G,pos = pos, labels = labels, node_color = node_colors,node_size=500)
    plt.savefig("D:\\GraphLayout\\Images\\Components.png")
    #plt.show()


def main():
    read_graph()
    show_graph_components()

main()
