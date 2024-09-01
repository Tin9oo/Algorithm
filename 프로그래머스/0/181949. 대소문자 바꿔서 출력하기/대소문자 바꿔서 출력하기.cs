using System;
using System.Text;

public class Example
{
    public static void Main()
    {
        String s;

        Console.Clear();
        s = Console.ReadLine();
        
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < s.Length; i++) {
            char c = s[i];
            
            if(char.IsUpper(c)) sb.Append(char.ToLower(c));
            else sb.Append(char.ToUpper(c));
        }
        
        Console.Write(sb.ToString());
    }
}