public class test implements A,B
{
   
      public void show()
      {
           System.out.println("Hello");
      }
     public static void main(String[] args) 
     {
           test obj  = new test();
           obj.show();
     }
     
}

interface  A
{ 
     void show();
}

interface B
{
      void show();
}