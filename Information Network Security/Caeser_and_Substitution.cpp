#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
char* Encrption(char* message,int key)
{
	int n=strlen(message),i,val;
	for(i=0;i<n;i++)
	{
	     val=(int)(message[i]-'A');
	     //cout<<val<<" ";
	     val=(val+key)%26;
	     message[i]='A'+val;
	}
	return message;
}
char* Decrption(char* message,int key)
{
	int n=strlen(message),i,val;
	for(i=0;i<n;i++)
	{
	     val=(int)(message[i]-'A');
	     val=(val-key+26)%26;
	     message[i]='A'+val;
	}
	return message;
}
int error(char* message)
{
	int flag=1,i,n=strlen(message);
	for(i=0;i<n;i++)
	{
		if(!('A'<=message[i]&&message[i]<='Z'))
		{
			flag=0;
			break;
		}

	}
	return flag;
}
char* row_per_cipher(char* message,int n,int m,int val[])
{
	char det[100][100],ans[100][100],temp;
	int i,j,k;
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(k<strlen(message))
			{
				det[i][j]=message[k];
				k++;
			}
			else
			{
				det[i][j]=' ';
			}
		}
	}
	for(i=0;i<n;i++)
	{
		temp=val[i];
		for(j=0;j<m;j++)
		{
			ans[i][j]=det[temp][j];
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			message[k]=ans[i][j];
			k++;
		}
	}
	return message;
}

char* column_per_cipher(char* message,int n,int m,int val[])
{
	char det[100][100],ans[100][100],temp;
	int i,j,k;
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(k<strlen(message))
			{
				det[i][j]=message[k];
				k++;
			}
			else
			{
				det[i][j]=' ';
			}
		}
	}
	for(i=0;i<m;i++)
	{
		temp=val[i];
		for(j=0;j<n;j++)
		{
			ans[j][i]=det[j][temp];
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			message[k]=ans[i][j];
			k++;
		}
	}
	return message;
}


char* decrypt_row_per_cipher(char* message,int n,int m,int val[])
{
	char det[100][100],ans[100][100],temp;
	int i,j,k;
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(k<strlen(message))
			{
				det[i][j]=message[k];
				k++;
			}
			else
			{
				det[i][j]=' ';
			}
		}
	}
	for(i=0;i<n;i++)
	{
		temp=val[i];
		for(j=0;j<m;j++)
		{
			ans[temp][j]=det[i][j];
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			message[k]=ans[i][j];
			k++;
		}
	}
	return message;
}

char* decrypt_column_per_cipher(char* message,int n,int m,int val[])
{
	char det[100][100],ans[100][100],temp;
	int i,j,k;
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(k<strlen(message))
			{
				det[i][j]=message[k];
				k++;
			}
			else
			{
				det[i][j]=' ';
			}
		}
	}
	for(i=0;i<m;i++)
	{
		temp=val[i];
		for(j=0;j<n;j++)
		{
			ans[j][temp]=det[j][i];
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			message[k]=ans[i][j];
			k++;
		}
	}
	return message;
}



void main()
{
	int key,choice,flag,key1[100],dimension[10],choice1,i;
	char text[100];
	clrscr();
	do{
		cout<<"1.Encrypt."<<endl;
		cout<<"2.Decrypt."<<endl;
		cout<<"3.Encrypt using permutation."<<endl;
		cout<<"4.Decrypt using permutation."<<endl;
		cout<<"5.Exit."<<endl;
		cout<<"Choice:";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter text to be encrypted:";
			cin>>text;
			cout<<"Enter key:";
			cin>>key;
			flag=error(text);
			if(flag==1)
			{
				Encrption(text,key);
				cout<<text<<endl;
			}
			else
				cout<<"Enter valid input"<<endl;
			key=-1;
		}
		else if(choice==2)
		{
			cout<<"Enter text to be encrypted:";
			cin>>text;
			cout<<"Enter key:";
			cin>>key;
			flag=error(text);
			if(flag==1)
			{
				Decrption(text,key);
				cout<<text<<endl;
			}
			else
				cout<<"Enter valid input"<<endl;
			key=-1;
		}
		else if(choice==3)
		{
			cout<<"Enter text to be encrypted:";
			gets(text);
			cout<<"Enter dimension:";
			cin>>dimension[0]>>dimension[1];
			if((dimension[0]*dimension[1])>=strlen(text))
			{
				cout<<"Enter type:"<<endl;
				cout<<"1.Row"<<endl;
				cout<<"2.Column"<<endl;
				cout<<"Choice:";
				cin>>choice1;
				if(choice1==1)
				{
					cout<<"Enter key:";
					for(i=0;i<dimension[0];i++)
					{
						cin>>key1[i];
					}
					row_per_cipher(text,dimension[0],dimension[1],key1);
					cout<<text<<endl;
				}
				else
				{
					cout<<"Enter key:";
					for(i=0;i<dimension[1];i++)
					{
						cin>>key1[i];
					}
					column_per_cipher(text,dimension[0],dimension[1],key1);
					cout<<text<<endl;
				}
			}
			else
			{
				cout<<"Enter valid dimensions."<<endl;
			}
		}
		else if(choice==4)
		{
			cout<<"Enter text to be encrypted:";
			gets(text);
			cout<<"Enter dimension:";
			cin>>dimension[0]>>dimension[1];
			if((dimension[0]*dimension[1])>=strlen(text))
			{
				cout<<"Enter type:"<<endl;
				cout<<"1.Row"<<endl;
				cout<<"2.Column"<<endl;
				cout<<"Choice:";
				cin>>choice1;
				if(choice1==1)
				{
					cout<<"Enter key:";
					for(i=0;i<dimension[0];i++)
					{
						cin>>key1[i];
					}
					decrypt_row_per_cipher(text,dimension[0],dimension[1],key1);
					cout<<text<<endl;
				}
				else
				{
					cout<<"Enter key:";
					for(i=0;i<dimension[1];i++)
					{
						cin>>key1[i];
					}
					decrypt_column_per_cipher(text,dimension[0],dimension[1],key1);
					cout<<text<<endl;
				}
			}
			else
			{
				cout<<"Enter valid dimensions."<<endl;
			}
		}
	}while(choice!=5);
	getch();
}