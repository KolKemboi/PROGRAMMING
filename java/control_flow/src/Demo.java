public class App {
    private static int[] array;
    public static void main(String[] args) throws Exception {
        
        printout(10);
        //for_loops();
        int lesser = if_conds(1, 2);
        System.out.println(lesser);
        array = new int[]{1, 2, 3, 4};
        array_out(array);
    }

    private static void printout(int a)
    {
        System.out.println(a);
    }
    private static void for_loops()
    {
        for(int i = 0; i <= 10; i++)
        {
            System.out.println(i);
        }
        int t1 = 0, t2 = 1;
        for(int i = 1; i <= 10; ++i)
        {
            System.out.print(t1 + " + ");
            int sum = t1+t2; t1 = t2;
            t2 = sum;
        }
        System.out.println();
    }
    private static int if_conds(int a, int b)
    {
        if(a < b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    private static void array_out(int[] array_in)
    {
        System.out.println("arrays");
        for(int i: array_in)
        {
            System.out.println(array_in[i - 1]);
        }
    }
}

public class Demo
{
    public static 
}