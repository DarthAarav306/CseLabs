class Main
{
    static char prompt(String prompt) throws java.io.IOException
    {
        System.out.println(prompt);
        char ch = (char)System.in.read();
        return ch;
    }
    public static void main (String[] args) {
        char ch;
        try
        {
            ch = prompt("Input a character:- ");
        }
        catch(java.io.IOException exc)
        {
            ch = 'X';
        }
        System.out.println("You pressed:- "+ch);
    }
    
}