import java.util.Scanner;


public class TicTacToe {
	
	int board[]=new int[10];
	char one='X',two='O';
	void Initialize(){
		for(int i=0;i<9;i++){
			board[i]=0;
		}
	}
	char Check(int i){
		if(board[i]==0)
		{
			char u=(char) ('0'+i);
			return u;
		}
		else if(board[i]==1)
			return one;
		else
			return two;
	}
	void board(){
		for(int i=0;i<9;i=i+3)
		{
			System.out.println("| "+Check(i)+" | "+Check(i+1)+" | "+Check(i+2)+" |");
		}
	}
	int Rules(){
		for(int i=0;i<9;i=i+3){
			int win=1;
			for(int j=i;j<(i+3);j++){
				if(board[j]==0)
					win=0;
			}
			for(int j=i+1;j<(i+3);j++){
				if(board[j]!=board[j-1])
					win=0;
			}
			if(win==1)
				return board[i];
		}
		
		for(int i=0;i<3;i=i+1){
			int win=1;
			for(int j=i;j<9;j=j+3){
				if(board[j]==0)
					win=0;
			}
			for(int j=i+3;j<9;j=j+3){
				if(board[j]!=board[j-3])
					win=0;
			}
			if(win==1)
				return board[i];
		}
		int val=0;
		for(int i=0;i<9;i=i+4){
			if(board[i]==0)
				val=1;
		}
		int win;
		if(val==1)
			win=0;
		else
			win=1;
		for(int i=4;i<9&&val==0;i=i+4){
			if(board[i]!=board[i-4])
				win=0;
		}
		if(win==1)
			return board[0];
		val=0;
		for(int i=2;i<7;i=i+2){
			if(board[i]==0)
				val=1;
		}
		if(val==1)
			win=0;
		else
			win=1;
		for(int i=4;i<7&&val==0;i=i+2){
			if(board[i]!=board[i-2])
				win=0;
		}
		if(win==1)
			return board[2];
		return 0;
	}
	void mark(int n,int c){
		
		board[n]=c;
	}
	
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		TicTacToe t=new TicTacToe();
		int choice;
		do{
			System.out.println("1.Play Tic Tac Toe");
			System.out.println("2.Exit");
			choice=sc.nextInt();
			if(choice==1)
			{
				int flag=0;
				t.Initialize();
				System.out.print("Enter 1 for player 1 and 2 for player 2 for X");
				int val=sc.nextInt();
				if(val==1){
					t.one='X';
					t.two='O';
				}else{
					t.one='O';
					t.two='X';
				}
				for(int i=0+(val-1);i<(9+(val-1))&&flag==0;i++){
					t.board();
					if(i%2==0){
						System.out.println("Player 1");
						System.out.println("Enter number from 0 to 8");
						int y1=0;
						y1=sc.nextInt();
						//System.out.println(y1);
						t.mark(y1,1);
						//System.out.println(y1);
					}else{
						System.out.println("Player 2");
						System.out.println("Enter number from 0 to 8");
						int y1=0;
						y1=sc.nextInt();
						//System.out.println(y1);
						t.mark(y1,2);
						//System.out.println(y1);
					}
					flag=t.Rules();
					//System.out.println(flag);
				}
				t.board();
				if(flag==1)
					System.out.println("Player 1 wins");
				else if(flag==2)
					System.out.println("Player 2  wins");
				else
					System.out.println("Draw");
			}
		}while(choice!=2);
		sc.close();
	}
}
