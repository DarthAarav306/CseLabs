/*Write a program that uses a loop to print a list
of 100 numbers consisting of alternating 1’s and
-1’s starting with 1.*/
public class alternating1 {
    public static void main(String[] args) {
        int num=1;
        for(int i=0;i<100;i++)
        {
            System.out.println(num+" ");
            num = -num;
        }
    }
}
