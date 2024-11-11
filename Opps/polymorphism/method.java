public class method 
{
    protected void show()
    {
         System.out.println("I am main");
         
    }
   public static void main(String[] args) 
   {
          B obj =  new B();
          obj.show();
   }    
}

class B extends method
{
    public void show()
    {
    
        System.out.println("I am inside B");
    }
}
