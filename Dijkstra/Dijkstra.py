from math import inf
'''
다익스트라 코드를 만들 예정
input : graph, start node
graph는 n*n matrix를 표현하기 위하여, n개의 element를 가지는 list를 n개 생성하여 넣으면 된다.
기본적으로 다익스트라 알고리즘을 돌리기 위해서 음의 가중치를 가지는 cycle은 없는 코드를 사용한다고 가정하며,
방향성이 있는 directed graph를 기준으로 할 것이다.
graph[i][j]는 node i 에서 node j로 가는 길이 있으면 숫자가 있을 것이고 아닐 경우에는 math.inf가 들어간다.
output : start node에서 부터 각 노드에 가는데 필요한 최소경로의 list
'''
def dijstra(graph = [[0,2,3,inf,1],[2, 0, 4, 5, inf],[3, 4, 0, 6, inf], [inf, 5, 6, 0, inf], [1, inf, inf, inf, inf]], start = 0):
    n = len(graph)
    res = [inf]*n
    return res

print(dijstra())