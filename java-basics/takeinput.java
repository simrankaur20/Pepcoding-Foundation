import java.util.*;

class takeinput{
    static Scanner sc = new Scanner(System.in);

    public static void main(String []args)
    {
        System.out.println("enter your name and age");
        
        String name = sc.nextLine(); // input multiword string
        int age  = sc.nextInt();
        System.out.println("name " + name + "age " + age);
    }
}

//Scanner class - a final class used for taking input

//Scanner class is a part of java.util package

// we can read java input from System in using Scanner class


// System.in is an object 

// keyboard se data ek inetrmediate buffer mei jata hai
// system.in vo object hai jo responsible hai keyboard se data buffer mei lane ke lie

// scanner ke constructor mei System.in ka object pass karenge
//Scannner class has a function - nextInt() , ye buffer se data (jo ki raw characters hai) nikalta hai, padta hai aur use inetrger mei convert karta hai
// nextInt() buffer se ek ek character uthayega, till delimiter 
// agar buffer mei data hai hi nahi, to nextInt() hi keyboard se data buffer mei enter karvayega -- screen rok dega till u enter data from keyboard to buffer

/*
   A Scenner breaks its input into tokens using a delimiter pattern, which by default matches whitespace
   
   the resultin tokens may then be converted into values of differnt types using the next various methods

*/
