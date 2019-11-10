import java.util.*;
public class mybinarytree{
    
    public static class Node{
        private int data = 0;
        private Node left = null;
        private Node right = null;
     
         
         public Node(int data)
         {
             this.data = data;
         }
         public Node(int data, Node left, Node right)
         {
             this.data = data;
             this.left = left;
             this.right = right;
         }
     }

    public static Node root = null;
    
    
    public static void preorder(Node node)
    {
        if(node == null)
        {
            return ;
        }
        System.out.println(node.data);
        preorder(node.left);
        preorder(node.right);
        
    }

    public static void inorder(Node node)
    {
        if(node == null)
        {
            return ;
        }
        inorder(node.left);
        System.out.println(node.data);
        inorder(node.right);
        
    }

    public static void postorder(Node node)
    {
        if(node == null)
        {
            return ;
        }
       
        System.out.println(node.data);
        postorder(node.left);
        postorder(node.right);
        
    }
    
    public int countnodes(Node node)
    {
        if(node == null)
        {
             return 0;
        }
         
        return countnodes(node.left) + countnodes(node.right) + 1;
     }
     

     public static int height(Node node)
     {
         if(node == null)
         {
             return 0;
         }

         return Math.max(height(node.left) , height(node.right)) + 1;
     }
    public static Node construct(int[] arr, Node idx)
    {
        if(idx.data >= arr.length || arr[idx.data] == -1)
        {
            idx.data++;
            return null;
        }

        Node newnode = new Node(arr[idx.data],null,null);
        idx.data++;
        newnode.left = construct(arr,idx);
        newnode.right = construct(arr,idx);
        return newnode;

    }
    public static void display(Node node)
     {
         if(node == null)
         {
            return;
         }
 
         StringBuilder sb = new StringBuilder();
 
         sb.append(node.left!=null ? node.left.data : ".");
         sb.append(" -> " + node.data + " <- ");
         sb.append(node.right != null ? node.right.data : ".");
 
         System.out.println(sb.toString());
 
         display(node.left);
         display(node.right);
     }



    public static boolean find(Node node, int data)
    {
        if(node == null)
        {
            return false;
        }
        if(node.data == data)
        {
            return true;
        }
        return find(node.left , data) || find(node.right,data);
        
    }

    public static int findmin(Node node)
    {
        if(node == null)
        {
            return Integer.MAX_VALUE;
        }

        return Math.min(node.data, Math.min(findmin(node.left) , findmin(node.right)));
    }

    public static int findmax(Node node)
    {
        if(node == null)
        {
            return Integer.MIN_VALUE;
        }

        return Math.max(node.data, Math.max(findmax(node.left) , findmax(node.right)));
    }


    //Root to Node Path =============================

    public static boolean rootToNodePath_01(Node node, int data,ArrayList<Node> path){
        if(node == null)
        {
            return false;
        }
        if(node.data == data)
        {
            path.add(node);
            return true;
        }


        boolean leftside = rootToNodePath_01(node.left, data, path);
        boolean rightside = rootToNodePath_01(node.right, data, path);

        if(leftside || rightside)
        {
            path.add(node);
        }

        return leftside || rightside;
    }
    
    public static ArrayList<Node> rootToNodePath(Node node , int data)
    {
        if(node == null)
        {
            ArrayList<Node> arr = new ArrayList<>();
            return arr;
        }

        if(node.data == data)
        {
            ArrayList<Node> arr = new ArrayList<>();
            arr.add(node);
            return arr;
        }

        ArrayList<Node> leftside = rootToNodePath(node.left, data);

        ArrayList<Node> rightside = rootToNodePath(node.right, data);

        if(leftside.size() > 0 && rightside.size() >  0)
        {
            if(leftside.size() < rightside.size())
            {
                leftside.add(node);
                return leftside;
            }
            else
            {
                rightside.add(node);
                return rightside;
            }
        }
        else if(leftside.size() > 0)
        {
            leftside.add(node);
            return leftside;
        }
        else if(rightside.size() > 0)
        {
            rightside.add(node);
            return rightside;
        }
        else{
            return leftside;
        }
    }

    //Print Leaf Nodes ===============================
    public static void printleafnode(Node node)
    {
        if(node == null)
        {
            return;
        }
        if(node.left == null && node.right == null)
        {
            System.out.println(node.data);
            return;
        }

        printleafnode(node.left);
        printleafnode(node.right);
    }
    
    
    //Level-Order Traversal==================================
    public static void levelOrder_01(Node root)
    {
        LinkedList<Node> ll = new LinkedList<>();

        ll.addLast(root);

        while(ll.size() > 0)
        {
            Node curr = ll.get(0);
            System.out.print(curr.data + " ");
            if(curr.left != null)
            {
                ll.addLast(curr.left);
            }
            if(curr.right != null)
            {
                ll.addLast(curr.right);
            }
            ll.removeFirst();
        }
    }

    //line-wise ===========

    //count method
    public static void levelOrder_02(Node root)
    {
        LinkedList<Node> ll = new LinkedList<>();
        ll.addLast(root);
        while(!ll.isEmpty())
        {
            int c = ll.size();
            while(c > 0)
            {
                Node curr = ll.get(0);
                ll.removeFirst();
                System.out.print(curr.data + " ");
                if(curr.left != null)
                {
                    ll.addLast(curr.left);
                }
                if(curr.right != null)
                {
                    ll.addLast(curr.right);
                }
                c--;
            }
            System.out.println();
        }
    }

    // 2 queue method
    public static void levelOrder_03(Node root)
    {
        LinkedList<Node> q1 = new LinkedList<>();
        LinkedList<Node> q2 = new LinkedList<>();
        q1.addLast(root);
        while(!q1.isEmpty() || !q2.isEmpty())
        {
            while(!q1.isEmpty())
            {
                Node curr = q1.removeFirst();
                System.out.print(curr.data + " ");
                if(curr.left != null)
                {
                    q2.addLast(curr.left);
                }
                if(curr.right != null)
                {
                    q2.addLast(curr.right);
                }
            }
            System.out.println();
            LinkedList<Node> t = new LinkedList<>();
            t = q1;
            q1 = q2;
            q2 = t;
        }
    }


    // ZigZag Order Traversal
    public static void zigzagtraversal(Node root)
    {
        LinkedList<Node> q1 = new LinkedList<>() , q2 = new LinkedList<>();
        q1.addLast(root);
        while(!q1.isEmpty() || !q2.isEmpty())
        {
            (!q1.isEmpty())
            {
                Node curr = q1
            }
        }
    }

    public static void main(String[] args)
    {
        int [] arr= {10,20,40,80,-1,-1,90,-1,-1,50,100,-1
            ,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1}; 
            Node idx = new Node(0);
            root = construct(arr, idx);
           // display(root);

     //      preorder(root);
        //    System.out.println(height(root));
           // System.out.println(findmax(root));
            // ArrayList<Node> arrans = new ArrayList<>();
            //  arrans = rootToNodePath(root, 50);
            //  Collections.reverse(arrans);     // To reverse an array
            //     for(Node n : arrans)
            //     {
            //         System.out.println(n.data);
            //     }
            
        //    printleafnode(root);
        levelOrder_03(root);
    
    }
}