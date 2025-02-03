public class App {
    private static String str = "Value";
    private static String str2 = new String("new string");
    

    public static void main(String[] args) throws Exception {
        strOps(str);
        strOps(str2);
        Demo.demo();
        StrOps.out();
    }
    private static void strOps(String strn)
    {
        System.out.println(strn);

    }
    
}

class StrOps
{
    private static void run()
    {
        System.out.println("null");
    }

    public static void out()
    {
        run();
    }
}

class Demo
{
    public static void demo() 
    {
        System.out.println("jkdsf");
    }
}
