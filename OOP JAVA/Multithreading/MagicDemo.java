import java.util.Scanner;

class CheckUnique implements Runnable {
    Thread t;
    int[][] mat;
    boolean unique = true;

    CheckUnique(int[][] mat) {
        this.mat = mat;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        int k = 0;
        int[] flatmat = new int[mat.length * mat[0].length];
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                flatmat[k] = mat[i][j];
                k++;
            }
        }
        for (int i = 0; i < flatmat.length - 1; i++) {
            for (int j = i + 1; j < flatmat.length; j++) {
                if (flatmat[j] == flatmat[i]) {
                    unique = false;
                    break;
                }
            }
        }
    }
}

class RowSum implements Runnable {
    int[] row;
    int sum = 0;
    Thread t;

    RowSum(int[] row) {
        this.row = row;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        for (int i : row) {
            sum += i;
        }
    }
}

class ColSum implements Runnable {
    int[] col;
    int sum = 0;
    Thread t;

    ColSum(int[] col) {
        this.col = col;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        for (int i : col) {
            sum += i;
        }
    }
}

class PrincDiagSum implements Runnable {
    int[][] mat;
    int sum = 0;
    Thread t;

    PrincDiagSum(int[][] mat) {
        this.mat = mat;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        for (int i = 0; i < mat.length; i++) {
            sum += mat[i][i]; // Summing principal diagonal
        }
    }
}

class SecondDiagSum implements Runnable {
    int[][] mat;
    int sum = 0;
    Thread t;

    SecondDiagSum(int[][] mat) {
        this.mat = mat;
        t = new Thread(this);
        t.start();
    }

    public void run() {
        for (int i = 0; i < mat.length; i++) {
            sum += mat[i][mat.length - i - 1]; // Summing secondary diagonal
        }
    }
}

public class MagicDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m, n;
        boolean magic = true;

        System.out.println("Enter number of rows (m): ");
        m = scanner.nextInt();
        System.out.println("Enter number of columns (n): ");
        n = scanner.nextInt();

        if (m != n) {
            System.out.println("Not a square matrix. Cannot be a magic square.");
            magic = false;
        }

        int[][] mat = new int[m][n];
        System.out.println("Enter matrix elements: ");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = scanner.nextInt();
            }
        }

        // Initialize the threads
        CheckUnique uniqueThread = new CheckUnique(mat);
        PrincDiagSum princDiag = new PrincDiagSum(mat);
        SecondDiagSum secDiag = new SecondDiagSum(mat);

        RowSum[] rowSums = new RowSum[m];
        ColSum[] colSums = new ColSum[n];

        // Create row and column sum threads
        for (int i = 0; i < m; i++) {
            rowSums[i] = new RowSum(mat[i]);
        }

        for (int j = 0; j < n; j++) {
            int[] col = new int[m];
            for (int i = 0; i < m; i++) {
                col[i] = mat[i][j];
            }
            colSums[j] = new ColSum(col);
        }

        try {
            // Wait for all threads to complete
            uniqueThread.t.join();
            princDiag.t.join();
            secDiag.t.join();

            for (int i = 0; i < m; i++) {
                rowSums[i].t.join();
            }

            for (int j = 0; j < n; j++) {
                colSums[j].t.join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Check if all sums are equal and unique condition holds
        int targetSum = princDiag.sum;
        if (secDiag.sum != targetSum) {
            magic = false;
        }

        for (int i = 0; i < m; i++) {
            if (rowSums[i].sum != targetSum) {
                magic = false;
            }
        }

        for (int j = 0; j < n; j++) {
            if (colSums[j].sum != targetSum) {
                magic = false;
            }
        }

        if (!uniqueThread.unique) {
            magic = false;
        }

        if (magic) {
            System.out.println("The matrix is a magic square.");
        } else {
            System.out.println("The matrix is not a magic square.");
        }
    }
}
