import java.util.*;
public class RabinKarp{
	public final static int ch = 256;//all characters
	
	// a prime number for hash fun
	static List<Integer> search(String txt,String pat,int q){
		
		int m = pat.length();
		int n = txt.length();
		int i,j;
		List<Integer> res= new ArrayList<Integer>();
		int p = 0; //hasVal for pattern
		int t = 0; //hasval for text
		int h = 1;
		for(i=0;i<m-1;i++){//cala hasvalue
			h = (h * ch) % q;
		}

		//calculate the hash value of pattern and first text range
		for(i = 0 ;i <m ;i++){
			p = (ch *p + pat.charAt(i) % q);
			t = (ch*t + txt.charAt(i)%q);
		}

		for(i =0;i<n-m;i++){
			//check the hashvalue if matched then start comparing the character
			if(p == t){
				for(j=0;j<m;j++){
					if(txt.charAt(i+j) != pat.charAt(j)){
						break;//if not then break;
					}
				}
				if( j== m){
					res.add(i);
				}
			}
			if(i < n - m){
				t = (ch *( t - txt.charAt(i) + txt.charAt(i+m))%q);
				if(t<0)
					 t = t+ q;
			}
		}
		return res;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter String: ");
		String str = sc.next();
		System.out.print("\nEnter pat: ");
		String pat = sc.next();

		List<Integer> res = search(str, pat, 3);
		System.out.println(res);
		sc.close();
	}

}