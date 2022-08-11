import java.lang.reflect.Array;
import java.util.*;
public class longestString {


    public static void main(String[] args) {
        String []str = {"ELEPHANT","CAT","TRUNK","KNIFE","TABLE","BOOK"};

        TreeMap<String,ArrayList<String>> mp =  new TreeMap<String,ArrayList<String>>();

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
            mp.put(str[i],list);
        }

        //printing
        ArrayList<String> list;
        int max = 0;
        String maxKey =  null;

        for(Map.Entry<String,ArrayList<String>> entry: mp.entrySet()){
            list =  entry.getValue();
            if(max < list.size()){
                max =  list.size();
                maxKey = entry.getKey();
            }
        }
        System.out.println("\n\n"+mp.get(maxKey));
    }
}
