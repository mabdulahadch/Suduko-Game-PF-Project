#include<iostream>           // main input and output
#include<fstream>            // file handling
#include<windows.h>          // Sleep , Coord
#include<stdlib.h>           // random number
#include<conio.h>            // _getch()
#include<time.h>             // change random 

using namespace std;

// Gloabal declaration of Array
int arr[9][9] = { 0 };               // main game array
int arr1[9][9] = { 0 };
int arr2[9][9] = { 0 };
int arr3[9][9] = { 0 };
int random[9][9];                    //store random fixed number in array
int rand1[9][9];
int rand2[9][9];
int rand3[9][9];

// Best functions
void colorset(int tint)                         // color
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tint);
}                    
void setCord(int x, int y)              
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}                 

// DEFINITIONS
int main();
void menucheck(char choice);
void instructions();
void menu();
void randomnumber();
void startGame(char ch);
bool colomnsearch(int num, int j);
bool rowsearch(int num, int i);
bool blocksearch(int num, int r, int c);
void loadgame();
void pausegame();


int main()
{
	char choice;
	char againchoice;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			arr[i][j] = 0;
		}
	}

	while (true)
	{
		system("cls");
		colorset(12);
		cout << "\t___________________" << endl;
		colorset(6);
		cout << "\t   SODUKU GAME " << endl;
		colorset(12);
		cout << "\t___________________" << endl;
		colorset(15); //white
		cout << "1. Menu  \n";
		cout << "2. Instructions\n";
		cout << "3. Exit\n";
		colorset(12);
		cout << "__________________________________________________________________________________________________\n";

		colorset(6);
		choice = _getch();                                             //cin >> choice;
		cout << choice << endl;

		if (choice == '1' || choice == '2')
		{
			menucheck(choice);
		}
		else if (choice == '3')
		{
			system("cls");
			colorset(8);          //grey
			cout << "\tIt seems that you are not interesting in playing this game " << endl;
			cout << "\tIf you have changed your mind then press '1' " << endl;
			cout << "\tOtherwise press any key " << endl;

			colorset(12);
			cout << "__________________________________________________________________________________________________\n";

			colorset(6);

			againchoice = _getch();
			cout << againchoice << endl;

			if (againchoice == '1')
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "Invalid input \n";
			Sleep(1000);
			continue;
		}
	}

	return 0;
}

void menucheck(char choice)
{
	while (true)
	{
		if (choice == '1')
		{
			menu();
			break;
		}
		else if (choice == '2')
		{
			system("cls");
			instructions();
			break;
		}
		else
		{
			break;
		}
	}
}

void instructions()
{
	char s;

	colorset(15);
	cout << "Instructions \n";
	colorset(8);
	cout << "\t1. Sudoku is played on a grid of 9 x 9 spaces.\n";
	cout << "\t2. Within these 9 rows and columns there are 3 x 3 spaces.\n";
	cout << "\t3. Each row, column, square (9 spaces each) needs to be filled out with the numbers 1-9.\n";
	cout << "\t4. Without repeating any numbers within the row, column or square.\n";

	colorset(12);
	cout << "__________________________________________________________________________________________________\n";

	colorset(7);
	cout << "Press any key to continue\n";
	colorset(6);
	s = _getch();
}

void menu()
{
	char choice;
	char chrr = '0';
	do
	{
		system("cls");
		colorset(12);
		cout << "\t___________________" << endl;
		colorset(6);
		cout << "\t       MENU        " << endl;
		colorset(12);
		cout << "\t___________________" << endl;
		colorset(15);  // white
		cout << "1. Start New Game\n";
		cout << "2. Load Previous\n";
		cout << "3. Back\n";
		colorset(12); // DARK RED
		cout << "__________________________________________________________________________________________________\n";
		colorset(6);   // white
		choice = _getch();
		cout << choice;

		if (choice == '1')
		{
			system("cls");
			startGame(chrr);
		}
		else if (choice == '2')
		{
			system("cls");
			loadgame();
		}
		else if (choice == '3')
		{
			break;
		}
		else
		{
			cout << "Invaid Input " << endl;
			Sleep(1000);
			continue;
		}

	} while (true);
}

void startGame(char ch)
{
	char end;

	if (ch == '1')
	{

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				arr[i][j] = arr1[i][j];
				random[i][j] = rand1[i][j];
			}
		}

	}
	else if (ch =='2')
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				arr[i][j] = arr2[i][j];
				random[i][j] = rand2[i][j];

			}
		}
	}
	else if (ch == '3')
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				arr[i][j] = arr3[i][j];
				random[i][j] = rand3[i][j];

			}
		}
	}
	else if (ch == '0')
	{
		for (int i = 0; i < 9; i++)    // initialize tthe random array
		{
			for (int j = 0; j < 9; j++)
			{
				random[i][j] = 69;
			}
		}
		
		randomnumber();                     // Calling random numbers 
	}



	while (true)                    //1- Boarder  2- Progress 3- Input
	{

		system("cls");
		setCord(0, 0);
		colorset(12);
		cout << "\t___________________" << endl;
		colorset(6);
		cout << "\t   SODUKU GAME " << endl;
		colorset(12);
		cout << "\t___________________" << endl;


		colorset(7);        //white

		cout << endl << endl;
		cout << "   ";
		for (int i = 0; i < 9; i++)
		{
			cout << i << "   ";             // 0 1 2 ||3 4 5 ||6 7 8  
			if (i == 2 || i == 5)
			{
				cout << char(186);
			}
		}
		cout << endl;

		colorset(7);
		cout << "  ";
		cout << char(201);                  // boundary upper
		for (int i = 0; i < 38; i++)
		{
			if (i == 12 || i == 25)
			{
				cout << char(203);
			}
			else
			{
				cout << char(205);
			}
		}
		cout << char(187);
		cout << endl;

		for (int i = 0; i < 9; i++)              // start of 1st row
		{
			colorset(7);
			cout << i << " ";


			colorset(7);
			cout << char(186);                  // ||


			for (int j = 0; j < 9; j++)         // print array on concole
			{
				if (arr[i][j] == 0)
				{
					colorset(13);               //purple

					cout << "-   ";
				}
				else
				{
					colorset(10);               //green
					cout << arr[i][j] << "   ";
				}
				if (j == 2 || j == 5)
				{
					colorset(7);
					cout << char(186);
				}
			}
			colorset(7);
			if (i == 2 || i == 5)
			{
				cout << char(186);                //  last border
				cout << endl;
			}
			else
			{
				cout << char(186);                 // ||        //"|"
			}
			cout << endl;
		}

		colorset(7);
		cout << "  ";
		cout << char(200);                  // boundary lower
		for (int i = 0; i < 38; i++)
		{
			if (i == 12 || i == 25)
			{
				cout << char(202);
			}
			else
			{
				cout << char(205);
			}
		}
		cout << char(188);
		cout << endl;

		colorset(6);        // yellow
		for (int i = 0; i < 45; i++)
		{
			cout << "-";
		}
		cout << endl;

		//"_________________________________________________________________________________________\n";







		int filled = 0;
		int remaining = 0;


		for (int k = 0; k < 9; k++)
		{
			for (int h = 0; h < 9; h++)
			{
				if (arr[k][h] != 0)
				{
					filled++;
				}
				else
				{
					remaining++;
				}

			}
			if (filled == 81)
			{
				goto end;

			}
		}



		colorset(3);           //aqua
		cout << "Filled box     ";
		colorset(2);           //green
		cout << filled << endl;
		colorset(3);
		cout << "Remaing Box    ";
		colorset(2);           //green
		cout << remaining << endl;

		int progress = ((filled * 100) / 81);
		colorset(2);           //aqua
		cout << "Progress       ";
		colorset(3);
		cout << progress << "% " << endl;


		colorset(6);        // yellow
		for (int i = 0; i < 45; i++)
		{
			cout << "-";
		}
		cout << endl;

		//"_________________________________________________________________________________________\n";


		char roww;
		char colomnn;
		char numm;

		colorset(4);         //red
		cout << "        Press 'p' to pause the game" << endl;


		colorset(7);        //white
		cout << "Enter ROW number :";
		colorset(8);       //red
		roww = _getch();
		cout << roww << endl;

		if (roww == 'p')
		{
			pausegame();
			continue;
		}

		if (roww > '8' || roww < '0')   //validity for row and colomn
		{
			colorset(6);
			cout << "Invalid input " << endl;
			Sleep(1000);
			system("cls");
			continue;
		}

		colorset(7);    //white
		cout << "Enter COLOMN number :";
		colorset(8);     //DARK RED
		colomnn = _getch();
		cout << colomnn << endl;

		if (colomnn == 'p')
		{
			pausegame();
			continue;
		}

		if (colomnn > '8' || colomnn < '0')   //validity for row and colomn
		{
			colorset(6);
			cout << "Invalid input " << endl;
			Sleep(1000);
			system("cls");
			continue;
		}

		colorset(7);   //white
		cout << "Now enter number to add : ";
		colorset(8);      //DARK RED
		numm = _getch();
		cout << numm << endl;

		if (numm == 'p')
		{
			pausegame();
			continue;
		}

		if (numm <= '0' || numm > '9')   //validity for row and colomn
		{
			colorset(6);
			cout << "Invalid input " << endl;
			Sleep(1000);
			system("cls");
			continue;
		}

		int row = int(roww - '0');                       // convert char into int 
		int colomn = int(colomnn - '0');
		int num = int(numm - '0');

		bool goal = blocksearch(num, row, colomn);
		bool flag1 = colomnsearch(num, colomn);
		bool flag2 = rowsearch(num, row);

		if (flag1 || flag2 || goal)
		{
			colorset(6);
			cout << num << " number Already exsist " << endl;

			Sleep(1000);
			system("cls");
			continue;
		}
		if (arr[row][colomn] == random[row][colomn])     // random number should not be changed
		{                                                
			colorset(6);   //yelloew
			cout << "You can't change the fixed random number " << endl;
			Sleep(1500);
			system("cls");
			continue;
		}

		arr[row][colomn] = num;

		system("cls");
	}

end:
	cout << "\tCongrats Puzzle have compeleted !\n";
	cout << "Press any key to continue\n";
	end = _getch();

	main();
}

void loadgame()
{
	char choice;

	while (true)
	{
		colorset(12);
		cout << "\t___________________" << endl;
		colorset(6);
		cout << "\t     LOAD GAME     " << endl;
		colorset(12);
		cout << "\t___________________" << endl;

		colorset(8);
		cout << "1. Load Game 1 \n";
		cout << "2. Load Game 2 \n";
		cout << "3. Load Game 3 \n";
		cout << "4. Back \n";

		colorset(12);
		cout << "__________________________________________________________________________________________________\n";

		colorset(15);
		cout << "Enter your choice \n";
		colorset(6);
		choice = _getch();
		//cout << choice << endl;

		if (choice == '1')
		{
			ifstream filer("loadGame1.txt");

			filer.seekg(0, ios::end);           // cursore to end
			int length = filer.tellg();         // tell length of file

			filer.seekg(0);                     //pointer to 1st index

			filer.close();

			if (length == 0)
			{
				cout << "File is empty \n";
				Sleep(1500);
			}
			else
			{
				ifstream filer("loadGame1.txt");

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						filer >> arr1[i][j];
					}
				}

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						filer >> rand1[i][j];
					}
				}

				filer.close();

				startGame(choice);
			}
		}
		else if (choice == '2')
		{
			ifstream filer("loadGame2.txt");

			filer.seekg(0, ios::end);
			int length = filer.tellg();

			filer.seekg(0);

			filer.close();

			if (length == 0)
			{
				cout << "File is empty \n";
				Sleep(1500);
			}
			else
			{
				ifstream filer("loadGame2.txt");

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						filer >> arr2[i][j];
					}
				}

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						filer >> rand2[i][j];
					}
				}

				filer.close();

				startGame(choice);
			}
		}
		else if (choice == '3')
		{
			ifstream filer("loadGame3.txt");

			filer.seekg(0, ios::end);
			int length = filer.tellg();

			filer.seekg(0);

			filer.close();

			if (length == 0)
			{
				cout << "File is empty \n";
				Sleep(1500);
			}
			else
			{
				ifstream filer("loadGame3.txt");

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						filer >> arr3[i][j];
					}
				}

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						filer >> rand3[i][j];
					}
				}

				filer.close();

				startGame(choice);
			}
		}
		else if (choice == '4')
		{
			break;
		}
		system("cls");
		continue;
	}
}

void pausegame()
{
	char l;            // choice of pause opt.
	char choose;
	char agchoice;

	while (true)
	{
		system("cls");
		colorset(15);
		cout << "\tWelcome to pause game \n";
		colorset(8);
		cout << "Press 'p' to continue \n";
		cout << "Press 'r' to resume \n";
		colorset(6);
		l = _getch();                           // cin >> l;
		cout << l << endl;

		if (l == 'r')
		{
			break;
		}
		else if (l == 'p')
		{
			colorset(15);
			cout << "\tSelect file to save game\n";
			colorset(8);
			cout << "1. loadGame1.txt\n";
			cout << "2. loadGame2.txt\n";
			cout << "3. loadGame3.txt\n";
			cout << "4. None of these\n";
			
			// "__________________________________________________________________________________________________\n";*/

			colorset(6);
			choose = _getch();
			cout << choose << endl;


			if (choose == '1')
			{
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr1[i][j] = arr[i][j];
						rand1[i][j] = random[i][j];
					}
				}

				ofstream fwrite("loadGame1.txt");

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fwrite << arr1[i][j] << " ";
					}
					fwrite << endl;
				}

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fwrite << rand1[i][j] << " ";
					}
					fwrite << endl;
				}

				fwrite.close();
			}
			else if (choose == '2')
			{
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr2[i][j] = arr[i][j];
						rand2[i][j] = random[i][j];
					}
				}
				ofstream fwrite("loadGame2.txt");

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fwrite << arr2[i][j] << " ";
					}
					fwrite << endl;
				}
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fwrite << rand2[i][j] << " ";
					}
					fwrite << endl;
				}

				fwrite.close();


			}
			else if (choose == '3')
			{
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						arr3[i][j] = arr[i][j];
						rand3[i][j] = random[i][j];
					}
				}

				ofstream fwrite("loadGame3.txt");

				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fwrite << arr3[i][j] << " ";
					}
					fwrite << endl;
				}
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						fwrite << rand3[i][j] << " ";
					}
					fwrite << endl;
				}

				fwrite.close();
			}
			else if (choose == '4')
			{
				goto go;
			}
			else
			{
				continue;
			}

		go:

	    go1:
	        colorset(15);
			cout << "     Press 'm' to go back to menu\n";
			colorset(6);
			agchoice = _getch();
			cout << agchoice << endl;

			if (agchoice == 'm')
			{
				system("cls");
				main();
			}
			else
			{
				colorset(4);
				cout << "Invalid Input " << endl;
				goto go1;
			}

		}
	}
}

bool rowsearch(int num, int i)       //2 ,2
{
	bool flag2 = false;

	for (int j = 0; j < 9; j++)
	{
		if (arr[i][j] == num)
		{
			flag2 = true;
			break;
		}
	}

	return flag2;
}

bool colomnsearch(int num, int j) 
{
	bool flag1 = false;

	for (int i = 0; i < 9; i++)
	{
		if (arr[i][j] == num)
		{
			flag1 = true;
			break;
		}
	}

	return flag1;
}

bool blocksearch(int num, int r, int c)
{
	bool goal = false;

	if (r >= 0 && r <= 2)
	{
		if (c >= 0 && c <= 2)          //row 0 - 2  col 0 - 2
		{
			for (int i = 0; i <= 2; i++)
			{
				for (int j = 0; j <= 2; j++)
				{
					if (arr[i][j] == num)
					{
						goal = true;
						break;
					}
				}
			}
		}
		else if (c >= 3 && c <= 5)       //row 0 - 2  col 3 - 5
		{
			for (int i = 0; i <= 2; i++)
			{
				for (int j = 3; j <= 5; j++)
				{
					if (arr[i][j] == num)
					{
						goal = true;
						break;
					}
				}
			}
		}
		else if (c >= 6 && c <= 8)       //row 0 - 2  col 6 - 8
		{
			for (int i = 0; i <= 2; i++)
			{
				for (int j = 6; j <= 8; j++)
				{
					if (arr[i][j] == num)
					{
						goal = true;
						break;
					}
				}
			}
		}
	}
	else if (r >= 3 && r <= 5)
	{
		if (c >= 0 && c <= 2)          //row 3 - 5  col 0 - 2
		{
			for (int i = 3; i <= 5; i++)
			{
				for (int j = 0; j <= 2; j++)
				{
					if (arr[i][j] == num)
					{
						goal = true;
						break;
					}
				}
			}
		}
		else if (c >= 3 && c <= 5)       //row 3 - 5  col 3 - 5
		{
			for (int i = 3; i <= 5; i++)
			{
				for (int j = 3; j <= 5; j++)
				{
					if (arr[i][j] == num)
					{
						goal = true;
						break;
					}
				}
			}
		}
		else if (c >= 6 && c <= 8)       //row 3 - 5  col 6 - 8
		{
			for (int i = 3; i <= 5; i++)
			{
				for (int j = 6; j <= 8; j++)
				{
					if (arr[i][j] == num)
					{
						goal = true;
						break;
					}
				}
			}
		}
	}
	else if (r >= 6 && r <= 8)
	{
		if (c >= 0 && c <= 2)           //row 6 - 8  col 0 - 2
		{
			for (int i = 6; i <= 8; i++)
			{
				for (int j = 0; j <= 2; j++)
				{
					if (arr[i][j] == num)
					{
						goal = true;
						break;
					}
				}
			}
		}
		else if (c >= 3 && c <= 5)       //row 6 - 8  col 3 - 5
		{
			for (int i = 6; i <= 8; i++)
			{
				for (int j = 3; j <= 5; j++)
				{
					if (arr[i][j] == num)
					{
						goal = true;
						break;
					}
				}
			}
		}
		else if (c >= 6 && c <= 8)       //row 6 - 8  col 6 - 8
		{
			for (int i = 6; i <= 8; i++)
			{
				for (int j = 6; j <= 8; j++)
				{
					if (arr[i][j] == num)
					{
						goal = true;
						break;
					}
				}
			}
		}
	}

	return goal;
}

void randomnumber()
{
	srand(time(0));

	arr[9][9] = { 0 };
	int rnd = (rand() % (30 - 10 + 1)) + 10; ;                 // int num = (rand() %(upper - lower + 1)) + lower;

	for (int a = 0; a < rnd; )
	{
		int x = rand() % 9;          //row          //2       
		int y = rand() % 9;          //colomn       //5
		int n = rand() % 9 + 1;      //num          // 4      


		bool goal = blocksearch(n, x, y);
		bool rowflag = rowsearch(n, x);
		bool colflag = colomnsearch(n, y);

		if (rowflag || colflag || goal)
		{
			continue;
		}
		else
		{
			arr[x][y] = n;
			random[x][y] = arr[x][y];
			a++;
		}
	}
}