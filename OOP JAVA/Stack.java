import java.util.Scanner;
public class Stack {
    int[] stack;
    int tos;
    void tos()
    {
        this.tos= -1;
    }
    void push(int element)
    {
        if(this.tos==this.stack.length-1)
        {
            System.out.println("Overflow");
        }
        else
        {
            this.stack[tos]=element;
            this.tos++;
        }
    }
    int pop()
    {
        if(this.tos==-1)
        {
            System.out.println("Underflow");
            return  -1;
        }
        else
        {
            int ele = this.stack[tos];
            this.stack[tos]=0;
            this.tos--;
            return ele;
        }
    }
    void display()
    {
        for(int i=tos;i>=0;i--)
        {
            System.out.println(this.stack[i]);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n,ch,ele;
        System.err.println("Enter size of stack:- ");
        n = scanner.nextInt();
        Stack stkobj = new Stack();
        stkobj.stack = new int[n];
        while (true) { 
            System.out.println("What do you want to do:- ");
            System.out.println("1.Push\n2.Pop\n3.Display\n4.Exit");
            ch = scanner.nextInt();
            switch(ch)
            {
                case 1:
                System.out.println("Enter element to push");
                ele = scanner.nextInt();
                stkobj.push(ele);
                break;
                case 2:
                int poppedele = stkobj.pop();
                System.out.println("Popped element is: "+poppedele);
                break;
                case 3:
                System.err.println("Stack is:- ");
                stkobj.display();
                break;
                case 4:
                System.err.println("Exiting...");
                scanner.close();
                return;
                default:
                System.err.println("Invalid");
            }
        }

    }
}
