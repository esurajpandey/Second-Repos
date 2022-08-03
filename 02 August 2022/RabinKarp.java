import java.util.*;
public class RabinKarp
{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the string");
		String s=sc.nextLine();
		System.out.println("Enter the pattern");
		String p=sc.nextLine();
		int pHash=0,tHash=0;
		List<Integer> lst=new ArrayList<>();
		for(int i=0;i<p.length();i++)
		{
		    pHash+=(p.charAt(i)-'a'+1)*Math.pow(3,i);
		}
		int j;
		for(j=0;j<p.length();j++)
    	{
    		 tHash+=(s.charAt(j)-'a'+1)*Math.pow(3,j);
    		   
    	}
    	 System.out.println(tHash);
    	if(tHash==pHash)
    	    lst.add(0);
    	 j=0;
    	 int k=p.length();
        while(k<s.length())
    	{
    	       
    	        tHash=tHash-(s.charAt(j)-'a'+1);
    	        tHash=tHash/3;
    		  tHash+=((s.charAt(k)-'a'+1)*Math.pow(3,p.length()-1));
    		  if(tHash==pHash)
    		    lst.add(j+1);
    		  j++;
    		  k++;
    	}
    		   
		System.out.println(lst);
	}
}