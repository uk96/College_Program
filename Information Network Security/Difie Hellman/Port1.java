import java.util.*;
import java.io.*;
import java.net.*;
class Port1
{
	public static void main (String args[])throws Exception
	{
		Scanner sc= new Scanner(System.in);
		Port1 p1= new Port1();
		System.out.println("Enter the value of a for USER1");
		int a=sc.nextInt();
		int p;
		do
		{		
		 	System.out.println("Enter a Prime no. p");
		 	p=sc.nextInt();
		}while(!p1.isPrime(p));
		int g=p1.findGenerator(p);
		System.out.println("The Generator g is "+g);
		int Ra=modular(g,a,p);
		System.out.print("The Ra :"+Ra+"\n");
		
		
		Socket s1 = new Socket("localhost",9999); 
		OutputStreamWriter Ra1 = new OutputStreamWriter(s1.getOutputStream());
		PrintWriter outRa = new PrintWriter(Ra1);
		
		outRa.println(p);
		Ra1.flush();
		
		outRa.println(g);
		Ra1.flush();

		outRa.println(Ra);
		Ra1.flush();
		
		BufferedReader brp1 = new BufferedReader(new InputStreamReader(s1.getInputStream()));
		String RbString=brp1.readLine();
		int Rb=Integer.parseInt(RbString);
		
		int SAB=modular(Rb,a,p);
		System.out.print("The SAB for USER 1 is "+SAB+"\n");	
	}
	
	static int modular(int x,int y,int m)
	
{
    
		if (y == 0)
        
			return 1;
    
		int val=modular(x,y/2,m)%m;
    
		val=(val*val)%m;
    
    
		if(y%2 == 0)
        
			return val;
    
		else
        
			return (x*val)%m;
	
}
	boolean isPrime(int n)
	{
		
		boolean flag=true;
		for(int i=2;(i*i)<=n;i++)
		{
			if(n%i==0)
			{
				flag=false;
				break;
			}
		}
		return true;
	}
	
    	int findGenerator(int n)
	{
		int i,j,flag=1;
		for(i=1;i<n;i++)
		{
			HashSet<Integer> s=new HashSet<Integer>();
			for(j=0;j<(n-1);j++)
				s.add(modular(i,j,n));
			if(s.size()==(n-1))
			{
				flag=0;
				break;
			}
		}
		return i;
	}
	
}