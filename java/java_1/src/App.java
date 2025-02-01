public class App {
    public static void main(String[] args) throws Exception {
        int ten = 10;
        long mil = 1_000_000;
        double point = 10.02;
        long conv = (long)point;
        //System.out.println(ten);
        //System.out.println(mil);
        //System.out.println(point);
        //System.out.println(conv);

        int[] list = new int[]{1, 2, 3, 4};
       // System.out.println(list.length);

        for(int i: list)
        {
            //System.out.println(list[i-1]);
        }
        int n = 10;
        int k = 2*n -2 ;

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j<k; j++){System.out.print(" ");}
            k = k - 1;
            for(int j = 0; j<= i; j++){System.out.print("* ");}
            System.out.println();
        }
    }
    
}
