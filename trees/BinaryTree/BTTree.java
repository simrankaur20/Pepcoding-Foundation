public class BTTree{
    private class Node{
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
    Node root = null;

    public BTTree(int[] arr)
    {
        root = construct(arr);
    }

    static int idx = 0;
    public Node construct(int[] arr)
    {
        if(idx >= arr.length || arr[idx] == -1)
        {
            idx++;
            return null;
        }

        Node node = new Node(arr[idx]);
        idx++;
        node.left = construct(arr);
        node.right = construct(arr);
        return node;
    }
    public void display()
    {
        display(this.root);

    }
    public int CountNodes()
    {
        return countnodes(this.root);
    }
    public int countnodes(Node node)
    {
        if(node == null)
        {
            return 0;
        }
        
        return countnodes(node.left) + countnodes(node.right) + 1;
    }
    private void display(Node node)
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
}

