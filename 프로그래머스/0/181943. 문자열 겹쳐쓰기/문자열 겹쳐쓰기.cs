using System;
using System.Text;

public class Solution {
    public string solution(string my_string, string overwrite_string, int s) {
        string answer = "";
        
        StringBuilder sb = new StringBuilder();
        
        sb.Append(my_string.Substring(0, s)); // front
        
        for(int i = 0; i < overwrite_string.Length; i++) {
            sb.Append(overwrite_string[i]);
        }
        
        sb.Append(my_string.Substring(s+overwrite_string.Length)); // back
        
        answer = sb.ToString();
        
        return answer;
    }
}