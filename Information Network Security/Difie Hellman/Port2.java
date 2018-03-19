import java.util.*;
import java.io.*;
import java.net.*;
class Port2
{
	public static void main (String args[])throws Exception
	{
		
		Scanner sc= new Scanner(System.in);
		Port2 p2= new Port2();
		System.out.println("Enter the value of b for USER2");
		int b=sc.nextInt();
		
		Socket s2 = new Socket("localhost",1000); 
		BufferedReader brp = new BufferedReader(new InputStreamReader(s2.getInputStream()));
		String PString=brp.readLine();
		int p=Integer.parseInt(PString); 
	
		String GString=brp.readLine();
		int g=Integer.parseInt(GString); 
			
		int Rb=modular(g,b,p);
		System.out.print("The Rb :"+Rb+"\n");
		
		OutputStreamWriter Rb2 = new OutputStreamWriter(s2.getOutputStream());
		PrintWriter outRb = new PrintWriter(Rb2);
		outRb.println(Rb);
		Rb2.flush();
		
		String RaString=brp.readLine();
		int Ra=Integer.parseInt(RaString); 
		int SAB=modular(Ra,b,p);
		System.out.print("The SAB for USER2 is "+SAB+"\n");		
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
	
}