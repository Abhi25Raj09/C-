//rock paper scissors in c++

#include <bits/stdc++.h>

using namespace std;

//generate a random number
int generateRandomNumber(int n)
{
	srand(time(NULL));
	return rand() % n;  //rand return a random number
}

//comparion of winner
int winner(char c1, char c2)
{
	if (c1 == c2)
	{
		return -1;
	}
	
	else if ((c1 == 'r') && (c2 == 's'))
	{
		return 1;
	}
	else if ((c1 == 's') && (c2 == 'r'))
	{
		return 0;
	}
	
	else if ((c1 == 'p') && (c2 == 'r'))
	{
		return 1;
	}
	else if ((c1 == 'r') && (c2 == 'p'))
	{
		return 0;
	}
	
	else if ((c1 == 's') && (c2 == 'p'))
	{
		return 1;
	}
	else if ((c1 == 'p') && (c2 == 's'))
	{
		return 0;
	}
}

int main()
{
	int playerscore = 0, compscore = 0, temp, n;
	char playerchar, compchar;
	char dict[] = {'r', 'p', 's'};
	
	cout<<"Welcome to Rock, Paper, Scissors."<<endl<<endl;
	
	cout<<"Enter the number of rounds you want to play : ";
	cin>>n;
	cout<<endl;
	
	for (int i = 0; i < n; i++)
	{
		//players turn
		cout<<"Player's Turn : "<<endl;
		cout<<"Choose 1 for Rock, 2 for Paper, 3 for Scissors : ";
		cin>>temp;
		playerchar = dict[temp-1];
		cout<<"You Chose "<<playerchar<<endl;
		
		//CPU turn
		cout<<"Computer's Turn : "<<endl;
		temp = generateRandomNumber(3) + 1;
		compchar = dict[temp-1];
		cout<<"Computer Chose "<<compchar<<endl<<endl;
		
		//comparing the scores
		if (winner(compchar, playerchar) == 1)
		{
			compscore += 1;
			cout<<"Computer gets the score"<<endl<<endl;
		}
		else if (winner(compchar, playerchar) == -1)
		{
			playerscore += 1;
			compscore += 1;
			cout<<"It's a draw"<<endl<<endl;
		}
		else
		{
			playerscore += 1;
			cout<<"You gets the score"<<endl<<endl;
		}
		
		//showing current score
		cout<<"Current Score : You - "<<playerscore<<". Computer - "<<compscore<<"."<<endl<<endl;
	}
	
	//final conclusion
	if (playerscore > compscore)
	{
		cout<<"You win the game"<<endl;
	}
	else if (playerscore < compscore)
	{
		cout<<"Computer win the game"<<endl;
	}
	else
	{
		cout<<"It's a draw"<<endl;
	}
	
	
	return 0;
}
