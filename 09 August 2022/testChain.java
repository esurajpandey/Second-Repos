import java.lang.reflect.Array;
import java.util.*;
public class testChain {


    public static void main(String[] args) {
        String []str = {"ELEPHANT","CAT","TRUNK","KNIFE","TABLE","BOOK"};

        ArrayList<String> res = new ArrayList<String>();
        int max = 0;
        for(int i=0;i<str.length;i++){
            char eChar =  str[i].charAt(str[i].length()-1);

            ArrayList<String> list = new ArrayList<String>();

            list.add(str[i]);
            for(int j=0;j<str.length;j++){
                for(int k=0;k<str.length;k++){
                    if(eChar == str[k].charAt(0) && !list.contains(str[k])){
                        list.add(str[k]);
                        eChar =  str[k].charAt(str[k].length()-1);
                    }
                }
            }
            if(max < list.size()){
                max =  list.size();
                res.clear();
                res = list;
            }
        }
        System.out.println("\n\n"+res+"\n");
    }
}
