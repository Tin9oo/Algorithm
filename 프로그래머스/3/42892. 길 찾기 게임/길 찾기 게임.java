import java.io.*;
import java.util.*;

class Solution {
    /* [스택 방식]
    순서대로 스택에 넣어볼까?
    탐색은 전위 혹은 후위 순으로 따라가되
    선택된 노드의 반대편 노드를 스택에 넣어서 현재 탐색을 마치면 탐색할 노드로 선택한다.
    부모 노드를 경계로 삼아서 반복 중에 현재 노드를 넘어가지 않도록 한다.
    */
    
    /* [연결 방식]
    각 노드를 클래스로 만들어서 부모와 자식을 표현한다.
    */
    
    static class Node {
        int n;
        int x, y;
        Node lc, rc;
        
        Node() {
            
        }
        
        Node(int n, int x, int y) {
            this.n = n;
            this.x = x;
            this.y = y;
            this.lc = null;
            this.rc = null;
        }
    }
    
    public int[][] solution(int[][] nodeinfo) {
        int[][] answer = {};
        
        int n = nodeinfo.length;
        List<Node> nodes = new ArrayList<>();
        
        for(int i = 0; i < n; i++) {
            nodes.add(new Node(i+1, nodeinfo[i][0], nodeinfo[i][1]));
        }
        
        nodes.sort((a, b) -> {
            if(a.y == b.y) {
                return a.x - b.x;
            }
            return b.y - a.y;
        });
        
        Node root = buildTree(nodes);
        
        List<Integer> preorderList = new ArrayList<>();
        List<Integer> postorderList = new ArrayList<>();
        
        preorderTraversal(root, preorderList);
        postorderTraversal(root, postorderList);

        Collections.reverse(postorderList);
        
        answer = new int[2][n];
        for(int i = 0; i < n; i++) {
            answer[0][i] = preorderList.get(i);
            answer[1][i] = postorderList.get(i);
        }
        
        return answer;
    }
    
    static Node buildTree(List<Node> nodes) {
        if(nodes.isEmpty()) return null;
        
        Node root = nodes.get(0);
        List<Node> leftNodes = new ArrayList<>();
        List<Node> rightNodes = new ArrayList<>();
        
        for(int i = 0; i < nodes.size(); i++) {
            if(nodes.get(i).x < root.x) {
                leftNodes.add(nodes.get(i));
            } else if(nodes.get(i).x > root.x) {
                rightNodes.add(nodes.get(i));
            }
        }
        
        root.lc = buildTree(leftNodes);
        root.rc = buildTree(rightNodes);
        
        return root;
    }
    
    static void preorderTraversal(Node node, List<Integer> traversal) {
        if(node == null) return;
        
        traversal.add(node.n);
        preorderTraversal(node.lc, traversal);
        preorderTraversal(node.rc, traversal);
    }
    
    static void postorderTraversal(Node node, List<Integer> traversal) {
        if(node == null) return;
        
        traversal.add(node.n);
        postorderTraversal(node.rc, traversal);
        postorderTraversal(node.lc, traversal);
    }
}