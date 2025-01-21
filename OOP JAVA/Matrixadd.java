import java.util.Scanner;
public class Matrixadd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i,j;
        int m,n;
        System.out.println("Enter rows and columns for matrices:- ");
        m = scanner.nextInt();
        n = scanner.nextInt();
        int[][] mat1 = new int[m][n];
        int[][] mat2 = new int[m][n];
        //Input Matrix1
        System.out.println("Enter elements for matrix 1:- ");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                mat1[i][j] = scanner.nextInt();
            }
        }
        //Input Matrix 2
        System.out.println("Enter elements for matrix 2:- ");
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                mat2[i][j] = scanner.nextInt();
            }
        }
        //Addition
        int[][] mat3 = new int[m][n];
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        //Printing new matrix
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                System.out.print(mat3[i][j]);
            }
            System.out.println();
        }
        scanner.close();

    }
}
