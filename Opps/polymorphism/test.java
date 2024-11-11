public class test 
{
    void show(int a, float b)
    {
         System.out.println("inside int float");
    }
    void show(float a, int b)
    {
        System.out.println("float, int");
    }
   public static void main(String[] args) 
   {    
        test obj = new test();
        obj.show(10.0f, 20);
        obj.show(10, 20.1f);
        // obj.show(10.21f, 20.0123f);;
   }  

}

