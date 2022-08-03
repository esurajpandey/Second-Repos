import java.util.*;
class Node{
        int data;
        Node left,right;
        Node(int data){
            this.data = data;
            left = null;
            right = null;
        }
}

public class verticalOrder{
    Node root;
    verticalOrder(){
        root = null;
    }
    Node insert(Node root,int data){
        if(root==null){
            return new Node(data);
        }
        if(root.data>data){
            root.left = insert(root.left,data);
        }else if(root.data < data){
            root.right = insert(root.right,data);
        }
        return root;
    }
    static ArrayList<Integer> vertical(Node root){
        Queue<Pair> q =  new ArrayDeque<>();
        Map<Integer,ArrayList<Integer>>map = new TreeMap<>();
        
        q.add(new Pair(0,root));
        while(!q.isEmpty()){
            Pair cur = q.poll();
            if(map.containsKey(cur.hd)){
                map.get(cur.hd).add(cur.node.data);
            }else{
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(cur.node.data);
                map.put(cur.hd,temp);
            }
            
            if(cur.node.left != null){
                q.add(new Pair(cur.hd-1,cur.node.left));
            }
            if(cur.node.right != null){
                q.add(new Pair(cur.hd+1,cur.node.right));
            }
        }
        ArrayList<Integer> res = new ArrayList<>();
        for(Map.Entry<Integer,ArrayList<Integer>> entry:map.entrySet()){
            res.addAll(entry.getValue());
        }
        return res;
    }
    static class Pair{
        Node  node;
        int hd;
        public Pair(int hd,Node node){
            this.node = node;
            this.hd = hd;
        }
    }
    
    public static void main(String[] args) {
    	int data;
        int ch;
        verticalOrder b = new verticalOrder();
        Scanner sc = new Scanner(System.in);
        do{
            System.out.println("\n1. Insert\n2. vertical Order Traversal\n3. Exit\nYour Choice: ");
            ch = sc.nextInt();
            switch (ch){
                case 1:
                    System.out.println("Insert values [STOP by -ve value]");
                    do{
                        data = sc.nextInt();
                        if(data<0){//if data is less than zero the insertion will be stop
                            break;
                        }
                        b.root = b.insert(b.root,data);
                    }while(data>0);
                    break;
                case 2: System.out.println("\nVertical Order Traversal :\n");
                        ArrayList<Integer> ar = vertical(b.root);
                        for (int i = 0; i < ar.size(); i++) 
                            System.out.print(ar.get(i) + " "); 
                        break;
            }
        }while(ch!=3);
        sc.close();
	}
}





