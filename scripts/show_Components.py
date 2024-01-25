import networkx as nx
import matplotlib.pyplot as plt
import matplotlib
import numpy as np


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

def show_graph_components():
    global n, m, G
    f = open("..\\..\\TextFiles\\Components.txt",'r')
    cnt = int(f.readline().rstrip())
    node_colors = ['' for i in range(n)]

    if(cnt > 5):
        all_colors = [name for name, hex in matplotlib.colors.CSS4_COLORS.items()]
    else:
        all_colors = [name for name, hex in matplotlib.colors.TABLEAU_COLORS.items()]

    np.random.shuffle(all_colors)
    bad_colors = ['black', 'darkseagreen', 'darkslateblue', 'darkslategray', 'darkslategrey', 'midnightblue', 'darkblue', 'navy', 'indigo']
    for i in range(cnt):
        while(all_colors[-1] in bad_colors): #maximum 9(bad_colors len) iterations
            all_colors.pop()
        color = all_colors[-1]
        all_colors.pop()
        nodes = list(map(int,f.readline().rstrip().split()))
        for node in nodes:
            node_colors[node-1] = color
    f.close()

    labels = dict()
    for i in range(n):
        labels[i] = i + 1

    pos = nx.circular_layout(G)
    plt.figure(figsize = (10, 8))
    nx.draw(G,pos = pos, labels = labels, node_color = node_colors,node_size=500)
    plt.savefig("..\\..\\Images\\Components.png")
    #plt.show()


def main():
    read_graph()
    show_graph_components()

main()

