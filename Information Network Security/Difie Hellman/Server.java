import java.util.*;
import java.io.*;
import java.net.*;
class Server
{
	public static void main (String args[])throws Exception
	{
		Server d = new Server();

		Scanner sc = new Scanner(System.in);
		
		ServerSocket ssu1 = new ServerSocket(9999);
		Socket Ss1 = ssu1.accept();
		BufferedReader bru1 = new BufferedReader(new InputStreamReader(Ss1.getInputStream()));

		ServerSocket ssu2 = new ServerSocket(1000);
		Socket Ss2 = ssu2.accept();
		BufferedReader bru2 = new BufferedReader(new InputStreamReader(Ss2.getInputStream()));

		OutputStreamWriter Sos1 = new OutputStreamWriter(Ss1.getOutputStream());
		PrintWriter out1 = new PrintWriter(Sos1);

		OutputStreamWriter Sos2 = new OutputStreamWriter(Ss2.getOutputStream());
		PrintWriter out2 = new PrintWriter(Sos2);

		String p=bru1.readLine();
		System.out.println("User1 connected to Server p : "+p);
		
		out2.println(p);
		Sos2.flush();		

		String g=bru1.readLine();
		System.out.println("User1 connected to Server g : "+g);
		
		out2.println(g);
		Sos2.flush();

		String Ra=bru1.readLine();
		System.out.println("User1 connected to Server Ra : "+Ra);
		
		out2.println(Ra);
		Sos2.flush();
		
		String Rb=bru2.readLine();
		System.out.println("User2 connected to Server Rb : "+Rb);
		
		out1.println(Rb);
		Sos1.flush();
		
	}
	
	
}