import java.util.Scanner;

class CheckUnique implements Runnable {
    int[][] matrix;
    Boolean isUnique = true;
    int[] flatArray;
    Thread t;

    CheckUnique(int[][] matrix) {
        this.matrix = matrix;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        flatArray = new int[matrix[0].length * matrix.length];
        int k = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                flatArray[k] = matrix[i][j];
                k++;
            }
        }
        for (int i = 0; i < flatArray.length - 1; i++) {
            for (int j = i + 1; j < flatArray.length; j++) {
                if (flatArray[j] == flatArray[i]) {
                    isUnique = false;
                }
            }
        }
    }
}

class RowSum implements Runnable {
    int[] row;
    int rowsum;
    Thread t;

    RowSum(int[] row) {
        this.row = row;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        rowsum = 0;
        for (int i : row) {
            rowsum += i;
        }
    }
}

class ColSum implements Runnable {
    int[] col;
    int colsum;
    Thread t;

    ColSum(int[] col) {
        this.col = col;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        colsum = 0;
        for (int i : col) {
            colsum += i;
        }
    }
}

class PrincipalDiagonalSum implements Runnable {
    Thread t;
    int principalDiagonalSum;
    int[][] matrix;

    PrincipalDiagonalSum(int[][] matrix) {
        this.matrix = matrix;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        principalDiagonalSum = 0;
        for (int i = 0; i < matrix.length; i++) {
            principalDiagonalSum += matrix[i][i];
        }
    }

}

class SecondaryDiagonalSum implements Runnable {
    Thread t;
    int secondaryDiagonalSum;
    int[][] matrix;

    SecondaryDiagonalSum(int[][] matrix) {
        this.matrix = matrix;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        secondaryDiagonalSum = 0;
        for (int i = 0; i < matrix.length; i++) {
            secondaryDiagonalSum += matrix[i][matrix.length - i - 1];
        }
    }
}

class Main {
    public static void main(String[] args) {
        Boolean isMagic = true;
        Scanner sc = new Scanner(System.in);
        int m;
        System.out.print("Enter number of rows/columns:- ");
        m = sc.nextInt();
        System.out.println();
        int[][] matrix = new int[m][m];
        System.out.println("Enter elements:- ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        CheckUnique checkUniqueThread = new CheckUnique(matrix);
        PrincipalDiagonalSum principalDiagonalSumThread = new PrincipalDiagonalSum(matrix);
        SecondaryDiagonalSum secondaryDiagonalSumThread = new SecondaryDiagonalSum(matrix);
        RowSum[] rowSumThreads = new RowSum[matrix.length];
        ColSum[] colSumThreads = new ColSum[matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            rowSumThreads[i] = new RowSum(matrix[i]);
        }
        int[][] transpose = new int[matrix.length][matrix.length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix.length; j++) {
                transpose[i][j] = matrix[j][i];
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            colSumThreads[i] = new ColSum(transpose[i]);
        }
        try {
            checkUniqueThread.t.join();
            principalDiagonalSumThread.t.join();
            secondaryDiagonalSumThread.t.join();
            for (int i = 0; i < matrix.length; i++) {
                rowSumThreads[i].t.join();
                colSumThreads[i].t.join();
            }
        } catch (InterruptedException exc) {
            exc.printStackTrace();
        }
        if (!checkUniqueThread.isUnique) {
            isMagic = false;
        }
        for (int i = 0; i < rowSumThreads.length; i++) {
            if (rowSumThreads[i].rowsum != principalDiagonalSumThread.principalDiagonalSum) {
                isMagic = false;
            }
        }
        for (int i = 0; i < colSumThreads.length; i++) {
            if (colSumThreads[i].colsum != principalDiagonalSumThread.principalDiagonalSum) {
                isMagic = false;
            }
        }
        if (secondaryDiagonalSumThread.secondaryDiagonalSum != principalDiagonalSumThread.principalDiagonalSum) {
            isMagic = false;
        }
        if (isMagic) {
            System.out.println("Matrix is magic");
        } else {
            System.out.println("Matrix ain't magical");
        }
    }

}