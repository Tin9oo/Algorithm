import java.io.*;
import java.util.*;

class Solution {
    static final boolean log = false;
    static int[][] dp;
    static final int INF = Integer.MAX_VALUE / 2;
    
    static class Node {
        int n;
        Node lc, rc;
        
        int depth = 0;
        
        int num;
        
        Node(int n, int num, int depth) {
            this.n = n;
            this.num = num;
            this.depth = depth;
        }
        
        Node(int n, Node lc, Node rc, int num) {
            this.n = n;
            this.lc = lc;
            this.rc = rc;
            this.num = num;
        }
    }
    
    public int solution(int k, int[] num, int[][] links) {
        int answer = 0;

        // 변수 설정
        boolean[] flag = new boolean[num.length];

        int root_num = -1;
        Node root;
        
        int left = Arrays.stream(num).max().getAsInt();
        int right = Arrays.stream(num).sum();
        int mid;
        
        // 루트 노드 찾기
        for(int[] l: links) {
            if(l[0] != -1 && !flag[l[0]]) flag[l[0]] = true;
            if(l[1] != -1 && !flag[l[1]]) flag[l[1]] = true;
        }
        
        for(int i = 0; i < flag.length; i++) {
            if(!flag[i]) {
                root_num = i;
                break;
            }
        }
        
        root = new Node(root_num, num[root_num], 0);
        
        // 트리 구성
        makeTree(root, num, links);
        if(log) printTree(root);
        
        // 파나메트릭 서치
        while(left < right) {
            mid = (left + right) / 2;
            if(log) System.out.println();
            if(log) System.out.println("left: " + left + ", right: " + right);
            if(log) System.out.println("mid: " + mid);            
            
            dp = new int[num.length][2];
            for(int[] row: dp) Arrays.fill(row, -1);
            
            int groups = canDivide(root, mid);
            if(log) System.out.println("groups: " + groups);
            
            if(groups <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // 결과 반환
        answer = right;
        
        return answer;
    }
    
    static void makeTree(Node node, int[] num, int[][] links) {
        if(node == null) return;
        
        int lcn = links[node.n][0];
        int rcn = links[node.n][1];
        
        Node lc = lcn == -1 ? null : new Node(lcn, num[lcn], node.depth+1);
        Node rc = rcn == -1 ? null : new Node(rcn, num[rcn], node.depth+1);
        
        node.lc = lc;
        node.rc = rc;
        
        makeTree(lc, num, links);
        makeTree(rc, num, links);
    }
    
    static int canDivide(Node node, int limit) {
        if(node == null) return 0;
        
        if(dp[node.n][0] != -1) return dp[node.n][0];
        
        int lg = canDivide(node.lc, limit);
        int rg = canDivide(node.rc, limit);
                
        int tot = node.num + (node.lc != null ? dp[node.lc.n][1] : 0) + (node.rc != null ? dp[node.rc.n][1] : 0);
        
        if(node.lc == null && node.rc == null) {
            if(tot <= limit) {
                dp[node.n][0] = 1;
                dp[node.n][1] = node.num;
            } else {
                dp[node.n][0] = INF;
                dp[node.n][1] = INF;
            }
        } else if(node.lc != null && node.rc != null) {
            if(tot <= limit) {
                dp[node.n][0] = lg + rg - 1;
                dp[node.n][1] = tot;
            } else if(node.num + Math.min(dp[node.lc.n][1], dp[node.rc.n][1]) <= limit) {
                dp[node.n][0] = lg + rg;
                dp[node.n][1] = node.num + Math.min(dp[node.lc.n][1], dp[node.rc.n][1]);
            } else if(node.num <= limit) {
                dp[node.n][0] = lg + rg + 1;
                dp[node.n][1] = node.num;
            } else {
                dp[node.n][0] = INF;
                dp[node.n][1] = INF;
            }
        } else {
            if(node.lc != null) {
                if(node.num + dp[node.lc.n][1] <= limit) {
                    dp[node.n][0] = lg;
                    dp[node.n][1] = node.num + dp[node.lc.n][1];
                } else if(node.num <= limit) {
                    dp[node.n][0] = lg + 1;
                    dp[node.n][1] = node.num;
                } else {
                    dp[node.n][0] = INF;
                    dp[node.n][1] = INF;
                }
            } else if(node.rc != null) {
                if(node.num + dp[node.rc.n][1] <= limit) {
                    dp[node.n][0] = rg;
                    dp[node.n][1] = node.num + dp[node.rc.n][1];
                } else if(node.num <= limit) {
                    dp[node.n][0] = rg + 1;
                    dp[node.n][1] = node.num;
                } else {
                    dp[node.n][0] = INF;
                    dp[node.n][1] = INF;
                }
            }
        }
        
        if(log) System.out.println("dp: " + node.n + ", " + dp[node.n][0] + ", " + dp[node.n][1]);
        return dp[node.n][0];
    }
    
    static void printTree(Node root) {
        if(root == null) return;
        
        System.out.print(root.n + "\t");
        printTree(root.lc);
        System.out.println();
        for(int i = 0; i <= root.depth; i++) System.out.print("\t");
        printTree(root.rc);
    }
}