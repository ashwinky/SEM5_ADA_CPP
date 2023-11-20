# def F(N):
#     count = 0

#     for I in range(1, N + 1):
#         for J in range(1, I + 1):
#             for K in range(1, J + 1):
#                 count += 1

#     return count


# for N in [1, 2, 3, 4, 5, 10, 100, 1000]:
#     print("N = %6d, F(N) = %15d" % (N, F(N)))


class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def isBipartite(self, src):
        colorArr = [-1] * self.V
        colorArr[src] = 1
        queue = []
        queue.append(src)
        while queue:
            u = queue.pop()
            if self.graph[u][u] == 1:
                return False
            for v in range(self.V):
                if self.graph[u][v] == 1 and colorArr[v] == -1:
                    colorArr[v] = 1 - colorArr[u]
                    queue.append(v)
                elif self.graph[u][v] == 1 and colorArr[v] == colorArr[u]:
                    return False
        return True


g = Graph(4)
g.graph = [
    #A  B  C  D  E  F  G
    [0, 0, 0, 0, 0, 0, 0], # A
    [0, 0, 1, 0, 0, 0, 0], # B
    [0, 1, 0, 1, 1, 0, 0], # C
    [0, 0, 1, 0, 0, 0, 0], # D
    [0, 0, 1, 0, 0, 0, 0], # E
    [0, 0, 0, 0, 0, 0, 1], # F
    [0, 0, 0, 0, 0, 1, 0], # G
]

print("Yes" if g.isBipartite(0) else "No")
