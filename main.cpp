//Tic tac toe

//Hello! Welcome to one of my first projects involving c++, for this project, you, the user
//will be playing tic tac toe!

//It is in it's rough stages so bare with me 

#include <iostream>
#include <string>
//using namespace std;
void drawImage();
void setPosition();
bool winDraw();


//Why do we put this in global??
//When using global, the functions can all see these variale T-T

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int row;
int colummn;
char symbol = 'x';
bool tie = false;
std::string n1;
std::string n2;
//^WHY TF ARE WE USING A BOOOOL





void drawImage(){
//These are the spaces in the tic tac toe. 
//char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };


std::cout << "---------------" << std::endl;
std::cout << "     |    |   " << std::endl;
std::cout << "  " << space[0][0] << "  | " << space[0][1] << "  | " <<  space[0][2] << "  \n";
std::cout << "     |    |    " << std::endl;
std::cout << "---------------" << std::endl;
std::cout << "     |    |    " << std::endl;
std::cout << "  " << space[1][0] << "  | " << space[1][1] << "  | " <<  space[1][2] << "  \n";
std::cout << "     |    |    " << std::endl;
std::cout << "---------------" << std::endl;
std::cout << "     |    |    " << std::endl;
std::cout << "  " << space[2][0] << "  | " << space[2][1] << "  | " <<  space[2][2] << "  \n";
std::cout << "     |    |    " << std::endl;
std::cout << "---------------" << std::endl;

//It's cute, but we need to call it a function and then somehow do the rest by ourselves. 
//NOOOOOOOOOOOOOOOOOOOOooo
}

void setPosition(){

	int numSpace;

//WTF IS N1????
	if (symbol == 'x')
	{
		std::cout << n1 << " please enter where you want to place the symbol! ";
		std::cin >> numSpace;

	}

	if (symbol == '0')
	{
		std::cout << n2 << " please enter where you want to place the symbol! ";
		std::cin >> numSpace;

	}

//Basically we are establishing the numSpaces in their respected collumns and rows.

	if (numSpace == 1)
	{
		row = 0;
		colummn = 0;
	}
	if (numSpace == 2)
	{
		row = 0;
		colummn = 1;
	}
	if (numSpace == 3)
	{
		row = 0;
		colummn = 2;
	}
	if (numSpace == 4)
	{
		row = 1;
		colummn = 0;
	}
	if (numSpace == 5)
	{
		row = 1;
		colummn = 1;
	}
	if (numSpace == 6)
	{
		row = 1;
		colummn = 2;
	}
	if (numSpace == 7)
	{
		row = 2;
		colummn = 0;
	}
	if (numSpace == 8)
	{
		row = 2;
		colummn = 1;
	}
	if (numSpace == 9)
	{
		row = 2;
		colummn = 2;
	}

	else if(numSpace < 1 || numSpace > 9){
		std::cout << "Error! try again.\n";
	}

//Okay here we finally implement the symbols and then add them to our little tic tac toe lol

	if((symbol == 'x' && space[row][colummn] != 'x') && space[row][colummn] != '0')
	{
		space[row][colummn] = 'x';
		symbol = '0';
	}

	else if((symbol == '0' && space[row][colummn] != 'x') && (space[row][colummn] != '0'))
	{
		space[row][colummn] = '0';
		symbol = 'x';
	}
	else{

		std::cout <<"There is no empty space...\n";
		setPosition();
	}

	drawImage();
}

//I wanted to say winOrDraw but I felt like it would  be to much..
bool winDraw()
{

//IM NOT WRITING THAT FOR LOOP LIKE THAT!! It's so ugly 
//I like this one better >:3

	for(int i = 0; i < 3; i++)
	{
		if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || (space[0][i] == space[1][i] && space[0][i] == space[2][i]))
		//{
			return true;
		//}
	}
	if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
	{
		return true;
	}
		
		//Use of setting up te diagonal pairs 
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if (space[i][j] != 'x' && space[i][j] != '0')
			{
					return false;
			}
		}
	}

	tie = true;

	return true;
}


int main()
{

	std::cout << "First player! Please enter your name : \n";
		std::getline(std::cin, n1);
	std::cout << "Second player! Enter your name...I guess : \n";
		std::getline(std::cin, n2);

		std::cout << n1 << "It's your time to shine! \n";

	while(!winDraw())
	{
		drawImage();
		setPosition();
		winDraw();
	}

	if (symbol == 'x' && tie == false)
	{
		std::cout << n2 << " wins! Good job..I guess.\n";

	}
	else if (symbol == '0' && tie == false)
	{
		std::cout << n1 << " wins!! OMG YOUR SOOOOOOOO COOL \n";
	}
	else
	{
		std::cout << "Its a draw! \n";
	}
}




   

    