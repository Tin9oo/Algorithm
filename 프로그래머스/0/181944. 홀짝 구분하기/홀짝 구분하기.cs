using System;

public class Example
{
    public static void Main()
    {
        String[] s;

        Console.Clear();
        s = Console.ReadLine().Split(' ');

        int a = Int32.Parse(s[0]);
        
        string res = (a % 2 == 0) ? "even" : "odd";
        
        Console.Write(a + " is " + res);
    }
}