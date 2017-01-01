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
def dijstra(graph = [[0,2,3,inf,inf],[inf, 0, 4, 5, inf],[inf, inf, 0, 6, inf], [inf, inf, inf, 0, inf], [1, inf, inf, inf, 0]], start = 0):
    n = len(graph) #n은 node의 갯수
    res = [inf]*n #result list 초깃값은 infinite로 지정
    prev = [None]*n
    res[start] = 0
    Q = []
    def get_min(Q, res):
        temp = inf
        ret = None
        for node in Q:
            if temp>res[node]:
                temp = res[node]
                ret = node
        if ret:
            Q.remove(ret)
        return ret
    for i in range(n):
        if i!=start:
            Q.append(i)
    while True:
        for i in range(n):
            if i in Q and graph[start][i]!=inf:
                if res[i]>res[start]+graph[start][i]:
                    res[i] = res[start]+graph[start][i]
                    prev[i] = start
        start = get_min(Q, res)
        if len(Q)==0 or start==None:
            break
    return res, prev

print(dijstra())
print(dijstra([[0,2,3,1,10],[inf, 0, inf, 2, inf],[inf, inf, 0, 1, 1],[inf, inf, inf, 0, 3],[inf, inf, inf, inf, inf]],0))