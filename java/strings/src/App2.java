import java.lang.Math;

public class App2 {
    private static int[] x = new int[10];
    private static int[][] y = new int[][]{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 0}};

    
    public static void main(String[] args) 
    {
        boolean check = "Name".contains("ame");
        System.out.println(check);
        System.out.println(Math.ceil(10.01));

        for(int i = 0; i < y.length; i++)
        {
            for(int j = 0; j < y[i].length; j++)
            {
                System.out.println(y[i][j]);
            }   
        }
    }    
}
