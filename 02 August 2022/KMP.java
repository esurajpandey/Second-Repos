import java.util.*;
public class KMP {
    static int[] prefix_function(String s){
        int n = s.length();
        //List<Integer> pi = new ArrayList<Integer>();
        int []pi = new int[n];
        for(int i=1;i<n;i++){
            int j = pi[i-1];

            while(j>0 && s.charAt(i) != s.charAt(j)){
                j = pi[j-1];
            }

            //S[0...i-1] = abc.ab
            //pi[i-1] = 2
            //S[0...i] = abc.abc
            //pi[i] = j++
            if(s.charAt(i) == s.charAt(j)){//if matching then increase
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String: ");
        String str = sc.next();

        System.out.print("Enter pattern: ");
        String pat = sc.next();

        int pos = -1;//index where found
        int i = 0,j=0;

        int[] prefix = prefix_function(pat);
        while(i<str.length()){
            if(str.charAt(i) == pat.charAt(j)){
                j++;
                i++;
            }else{
                if(j!= 0){
                    j = prefix[j-1];
                }else{
                    i++;
                }
            }
            if(j== pat.length()){
                pos = i - pat.length();
                break;
            }
        }
        System.out.println(pos);
        try{
            sc.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    
}
