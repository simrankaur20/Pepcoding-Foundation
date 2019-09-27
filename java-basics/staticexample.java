// in java
// static variable

public class staticexample{


    int x; // instance variable
    static int y; // static member variable
    
    public void fun1() {
        
        //   function le andar static nahi bana sakte
     }  //instance member function
    public static void fun2() {} // static member function

     // we can have static inner class

     static class test{
        public static String country = "INDIA";
     }


     public static void main(String[] args) {
         staticexample ex1 = new staticexample();
         staticexample ex2 = new staticexample();
         staticexample.y = 5;
         staticexample.fun2();
         ex1.x = 2;
         ex2.x = 3;

         System.out.println(staticexample.test.country);
     }
}


//static variables are declared in a class using static keyword

// agar hum staticexample ka object na bhi banaye , to bhi static members bannege aur instances 0 se initialise ho jayenge

// static member function sirf static members ko access kr sakta h