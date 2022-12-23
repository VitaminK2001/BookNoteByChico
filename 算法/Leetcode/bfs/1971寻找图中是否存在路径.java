package 算法.Leetcode.bfs;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

class Solution{
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        List<Integer>[] adj = new List[n];
        for(int i = 0; i < n; ++i){
            adj[i] = new ArrayList<>();
        }
        for(int[] edge : edges){
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }
        Queue<Integer> queue = new ArrayDeque<>();
        boolean[] isvisited = new boolean[n];
        queue.add(source);
        while(!queue.isEmpty()){
            int cur = queue.poll();
            if(cur == destination) return true;
            isvisited[cur] = true;
            for(int next : adj[cur]){
                if(isvisited[next] != true){
                    queue.add(next);
                }
            }
        }
        return false;
    }
}