import java.util.*;

class Solution {
    static class Node {
        String str;
        int cnt;
        
        Node(String str, int cnt) {
            this.str = str;
            this.cnt = cnt;
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        answer = bfs(begin, target, words);
        
        return answer;
    }
    
    static int bfs(String begin, String target, String[] words) {
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(begin, 0));
        
        ArrayList<String> visited = new ArrayList<>();
        
        while(q.isEmpty() == false) {
            Node node = q.poll();
            
            // 정답 반환
            if(node.str.equals(target)) {
                return node.cnt;
            }
            
            for(String word: words) {
                // 방문한적 있는 단어 skip
                if(visited.contains(word)) continue;
                
                int cnt = 0;
                
                for(int i = 0; i < node.str.length(); i++) {
                    if(node.str.charAt(i) != word.charAt(i)) {
                        cnt++;
                    }
                }
                
                if(cnt == 1) {
                    visited.add(word);
                    q.offer(new Node(word, node.cnt+1));
                }
            }
        }
        
        return 0;
    }
}