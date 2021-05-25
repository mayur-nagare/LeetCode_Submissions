class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        k +=1
        adj = [[None for j in range(n)] for i in range(n)]
        for fromSrc, to, price in flights:
            adj[fromSrc][to] = price
        dp = [[math.inf for j in range(k + 1)] for i in range(n)]
        for j in range(k + 1):
            dp[src][j] = 0
            
        for j in range(1, k + 1):
            for i in range(n):
                best = math.inf
                for vertex in range(n):
                    if adj[vertex][i] != None and dp[vertex][j -1] + adj[vertex][i] < best:
                        best = dp[vertex][j - 1] + adj[vertex][i]
                dp[i][j] = min(dp[i][j], best, dp[i][j - 1])
                
        return dp[dst][k] if dp[dst][k] != math.inf else -1