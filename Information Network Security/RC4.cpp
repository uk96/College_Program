#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
int s[256],mess[300],key1[300],t[256];
void Initial(char* key)
{
	int i,m;
	for(i=0;i<256;i++)
	{
		s[i]=i;
	}
	m=strlen(key);
	for(i=0;i<m;i++)
	{
		key1[i]=(int)key[i];
	}
	for(i=0;i<256;i++)
	{
		t[i]=key1[(i%m)];
	}
}
void Initial_Permutation()
{
	int i,j,temp;
	j=0;
	for(i=0;i<256;i++)
	{
		j=(j+s[i]+t[i])%256;
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}
}
char* Stream_Generation(char* message,char* key)
{
	int i,n,m,j=0,temp,ku,val;
	n=strlen(message);
	m=strlen(key);
	for(i=0;i<n;i++)
	{
		mess[i]=(int)message[i];
	}
	i=0;
	j=0;
	for(ku=0;ku<n;ku++)
	{
		i=(i+1)%256;
		j=(j+s[i])%256;
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
		val=s[(s[i]+s[j])%256];
		mess[ku]=mess[ku]^val;
		message[ku]=(char)mess[ku];
	}
	return message;
}
void main()
{
	int choice,flag;
	char text[100],key[100];
	clrscr();
	do{
		cout<<"1.Encrypt."<<endl;
		cout<<"2.Decrypt."<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"Choice:";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter text to be encrypted:";
			cin>>text;
			cout<<"Enter key:";
			cin>>key;
			Initial(key);
			Initial_Permutation();
			Stream_Generation(text,key);
			cout<<text<<endl;
		}
		else if(choice==2)
		{
			cout<<"Enter text to be Decrypted:";
			cin>>text;
			cout<<"Enter key:";
			cin>>key;
			Initial(key);
			Initial_Permutation();
			Stream_Generation(text,key);
			cout<<text<<endl;
		}
	}while(choice!=3);
	getch();
}