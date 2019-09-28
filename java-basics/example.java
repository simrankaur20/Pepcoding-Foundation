//import java.io.*;
import java.util.ArrayList;
public class example{
    public static void main(String[] args)
    {
        ArrayList<Integer> mylist = new ArrayList<>();
       
        mylist.add(1);
        mylist.add(1);
        mylist.add(1);
        mylist.add(1);
        mylist.add(94);

        for(Integer x : mylist)
        {
            System.out.println(x);
        }

        System.out.println(mylist.size());

        mylist.remove(4);

        System.out.println(mylist.size());

        mylist.set(0,100);

        for(int x : mylist)
        {
            System.out.println(x);
        }
        mylist.clear();
    }
}
