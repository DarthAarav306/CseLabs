/*Write and execute a java program to create five threads, the first thread checking the 
uniqueness of matrix elements, the second calculating row sum, the third calculating the column sum, 
the fourth calculating principal diagonal sum, the fifth calculating the secondary diagonal sum of a given matrix. 
The main thread reads a square matrix from keyboard \
and will display whether the given matrix is magic square or not by obtaining the required data from sub threads. */

import java.util.Scanner;

class CheckUniqueThread implements Runnable
{
    int[][] matrix;
    Thread t;
    boolean isUnique=true;
    CheckUniqueThread(int[][] matrix)
    {
        this.matrix = matrix;
        Thread t = new Thread(this);
        t.start();
    }
    public void run()
    {
        int[] flatArr = new int[matrix.length*matrix[0].length];
        int k=0;
        for(int i=0;i<matrix.length;i++)
        {
            for(int j=0;j<matrix[0].length;j++)
            {
                flatArr[k] = matrix[i][j];
                k++;
            }
        }
        for(int i=0;i<flatArr.length-1;i++)
        {
            for(int j=i+1;j<flatArr.length;j++)
            {
                if(flatArr[j]==flatArr[i])
                {
                    isUnique = false;
                    break;
                }
            }
        }
    }
}

class RowSumThread implements Runnable
{
    Thread t;
    int[] row;
    int sum=0;
    RowSumThread(int[] row)
    {
        this.row = row;
        t = new Thread(this);
        t.start();
    }
    public void run()
    {
        for(int i=0;i<row.length;i++)
        {
            sum+=i;
        }
    }
}

class ColumnSumThread implements Runnable
{
    int[][] matrix;
    int[] columnsums;
    Thread t;
    ColumnSumThread(int[][] matrix)
    {
        this.matrix = matrix;
        t = new Thread(this);
        t.start();
    }
    public void run()
    {
        columnsums = new int[matrix[0].length];
        for(int j=0;j<matrix[0].length;j++)
        {
            for(int i=0;i<matrix.length;i++)
            {
                columnsums[j]+=matrix[i][j]; 
            }
        }
    }
}

class PrincipleDiagonalSum implements Runnable
{
    int sum=0;
    Thread t;
    int[][] matrix;
    PrincipleDiagonalSum(int[][] matrix)
    {
        this.matrix = matrix;
        t = new Thread(this);
        t.start();
    }
    public void run()
    {
        for(int i=0;i<matrix.length;i++)
        {
            sum+= matrix[i][i];
        }
    }
}

class SecondaryDiagonalSum implements Runnable
{
    int sum = 0;
    Thread t;
    int[][] matrix;
    SecondaryDiagonalSum(int[][] matrix)
    {
        this.matrix = matrix;
        t = new Thread(this);
        t.start();
    }
    public void run()
    {
        for(int i=0;i<matrix.length;i++)
        {
            sum+= matrix[i][matrix[0].length - i -1];
        }
    }
}

public class Practice
{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the square matrix (n for an n x n matrix): ");
        int n = scanner.nextInt();
        int[][] matrix = new int[n][n];
        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("Element at (" + i + "," + j + "): ");
                matrix[i][j] = scanner.nextInt();
            }
        }
        CheckUniqueThread cut = new CheckUniqueThread(matrix);
        RowSumThread[] rowSums = new RowSumThread[matrix.length];
        for(int i=0;i<matrix.length;i++)
        {
            rowSums[i] = new RowSumThread(matrix[i]); 
        }
        for(int i=0;i<rowSums.length;i++)
        {
            try
            {
                rowSums[i].t.join();
            }
            catch(InterruptedException exc)
            {
                exc.printStackTrace();
            }
        }
        ColumnSumThread cst = new ColumnSumThread(matrix);
        PrincipalDiagonalSum pds = new PrincipalDiagonalSum(matrix);
        SecondaryDiagonalSum sds = new SecondaryDiagonalSum(matrix);
        try
        {
            cut.t.join();
            cst.t.join();
            pds.t.join();
            sds.t.join();
        }
        catch(InterruptedException exc)
        {
            exc.printStackTrace();
        }
        boolean isMagic = true;
        if(!cut.isUnique)
        {
            isMagic = false;
        }
        int princDiagSum = pds.sum;
        if(princDiagSum!=sds.sum)
        {
            isMagic = false;
        }
        for(int i=0;i<rowSums.length;i++)
        {
            if(rowSums[i].sum!=princDiagSum)
            {
                isMagic = false;
            }
        }
        int[] colSums = cst.columnsums;
}