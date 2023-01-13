#include <iostream>
#include <iomanip>
#include <string>

#include <chrono>
#include <thread>

using namespace std;

using namespace std::this_thread;	  // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

string Student[100][8];
int count_St = 0;
string Field[10];
int k = -1;

void Welcome();					 // OK
void Menu();					 // OK
void Cout1();					 // OK
void Cout2(int);				 // OK
void Cout3(int, string);		 // OK
void Add();						 // OK
void Add_Test();				 // OK
void Edit();					 // OK
void Delete();					 // OK
void Search();					 // OK
void Show();					 // OK
void Exit();					 // OK
void S_Std_Num();				 // OK
void S_Name();					 // OK
void S_Field();					 // OK
void S_All();					 // OK
void S_Test();					 // OK
string repeat(string, int, int); // OK

int main()
{
	system("color E");

	Welcome();
	while (true)
	{
		Menu();
	}

	return 0;
}

void Welcome()
{
    system("clear");

	cout << endl;
	cout << "                _________________________________________              " << endl;
	cout << "               |                                         |             " << endl;
	cout << "               |             Student Project             |             " << endl;
	cout << "               |_________________________________________|             " << endl;
	cout << "                                                                       " << endl;
	cout << endl;

	sleep_for(3s);

    while (true)
    {
        Menu();
    }
}

void Menu()
{
	int key;
	while (true)
	{
		system("clear");
		cout << endl;
		cout << "  +-------------------------------------------------------------------+" << endl;
		cout << "  |                                                                   |" << endl;
		cout << "  |  1 - Enter Student information.                                   |" << endl;
		cout << "  |                                                                   |" << endl;
		cout << "  |  2 - Enter Student information (Presentation test).               |" << endl;
		cout << "  |                                                                   |" << endl;
		cout << "  |  3 - Edit Student information.                                    |" << endl;
		cout << "  |                                                                   |" << endl;
		cout << "  |  4 - Delete Student information.                                  |" << endl;
		cout << "  |                                                                   |" << endl;
		cout << "  |  5 - Search for Student information.                              |" << endl;
		cout << "  |                                                                   |" << endl;
		cout << "  |  6 - Show Student information                                     |" << endl;
		cout << "  |                                                                   |" << endl;
		cout << "  |  0 - Exit.                                                        |" << endl;
		cout << "  |                                                                   |" << endl;
		cout << "  +-------------------------------------------------------------------+" << endl;
		cout << "\n\n  Insert the key : ";
		cin >> key;

		switch (key)
		{
		case 1:
			Add();
			break;
		case 2:
			Add_Test();
			break;
		case 3:
			Edit();
			break;
		case 4:
			Delete();
			break;
		case 5:
			Search();
			break;
		case 6:
			Show();
			break;
		case 0:
			Exit();
			break;
		default:
			Menu();
			break;
		}
	}
}

void Cout1()
{

	//     +------------+--------------+----------------+---------------+-----------+-----------+
	//     |   St-num   | NationalCode |   First name   |   Last name   |   Field   |   Turn    |
	//     +------------+--------------+----------------+---------------+-----------+-----------+
	//     | 9821973101 |  1451597398  | mohammad javad |  ahmadi hadi  | computer  |  Roozane  |
	//     +------------+--------------+----------------+---------------+-----------+-----------+

	cout << endl;
	cout << "\t +------------+--------------+----------------+---------------+-----------+-----------+" << endl;
	cout << "\t |   " << "St_num";
	cout << "   | " << "NationalCode";
	cout << " |   " << "First name";
	cout << "   |   " << "Last name";
	cout << "   |   " << "Field";
	cout << "   |   " << "Turn" << "    |" << endl;
	cout << "\n\t +------------+--------------+----------------+---------------+-----------+-----------+";
}

void Cout2(int i)
{
	int a;

	if (Student[i][7] == "1")
	{
		cout << "\n\t |";

		Cout3(12, Student[i][0]);
		Cout3(14, Student[i][1]);
		Cout3(16, Student[i][2]);
		Cout3(15, Student[i][3]);
		Cout3(11, Student[i][4]);
		Cout3(11, Student[i][5]);

		cout << "\n\t +------------+--------------+----------------+---------------+-----------+-----------+";
	}
}

void Cout3(int n, string key)
{
	int a;

	a = n - key.length();

	cout << setw((a / 2) + (n - a)) << key;

	if (a % 2 == 1)
		cout << " ";

	a = (a / 2) + 1;

	cout << setw(a) << "|";
}

void Add()
{
	string _N_Code, _F_Name, _L_Name, _Year, _St_num, _Turn, _Field, p;
	float _Average;


	cin.ignore();
	cout << "\n  Enter Student number : ";
	getline(cin, _St_num);

	_St_num = repeat(_St_num, count_St, 0);

	cout << "\n  Enter National code :  ";
	getline(cin, _N_Code);

	_N_Code = repeat(_N_Code, count_St, 1);

	cout << "\n  Enter First name :     ";
	getline(cin, _F_Name);

	if (isupper(_F_Name[0]))
		_F_Name[0] = tolower(_F_Name[0]);

	cout << "\n  Enter Last name :      ";
	getline(cin, _L_Name);

	if (isupper(_L_Name[0]))
		_L_Name[0] = tolower(_L_Name[0]);

	cout << "\n  Which year did you enter University ? 13";
	cin >> _Year;

	int flag = 1;

	if (k >= 0)
	{
		cout << "\n  Select your field :";
		for (int i = 0; i <= k; i++)
			cout << "\n   " << i + 1 << " - " << Field[i] << " ";

		cout << "\n   0 - Other " << "\n  ";
		cin >> _Field;

		if (_Field == "0")
			flag = 0;
		else
			_Field = Field[stol(_Field) - 1];
	}
	else
		flag = 0;

	if (flag == 0)
	{
		k++;
		cout << "\n  Insert your field : ";
		cin >> Field[k];
		cout << "\n  New field added :)\n";
		_Field = Field[k];

		if (isupper(_Field[0]))
			_Field[0] = tolower(_Field[0]);
	}

	cout << "\n  Select your turn : ";
	cout << "\n   1 - Roozane ";
	cout << "\n   2 - Shabane ";
	cout << "\n  Turn ";
	cin >> _Turn;

	if (_Turn == "1")
		_Turn = "Roozane";
	else if (_Turn == "2")
		_Turn = "Shabane";

	cout << "\n  Information successfully saved :)";

	Student[count_St][0] = _St_num;
	Student[count_St][1] = _N_Code;
	Student[count_St][2] = _F_Name;
	Student[count_St][3] = _L_Name;
	Student[count_St][4] = _Year;
	Student[count_St][5] = _Field;
	Student[count_St][6] = _Turn;
	Student[count_St][7] = "1";

	count_St++;

	cin.ignore();
	cout << "\n\n Press enter to continue to main menu ";
	getline(cin, p);
}

void Add_Test()
{
	string _N_Code, _F_Name, _L_Name, _Year, _St_num, _Turn, p, _Field, temp;
	int flag = 1, flag1 = 1, n;
	float _Average;

	cin.ignore();
	cout << "\n  Enter Student number : ";
	getline(cin, _St_num);

	_St_num = repeat(_St_num, count_St, 0);

	cout << "\n  Enter National code :  ";
	getline(cin, _N_Code);

	_N_Code = repeat(_N_Code, count_St, 1);

	cout << "\n  Enter First name :     ";
	getline(cin, _F_Name);

	if (isupper(_F_Name[0]))
		_F_Name[0] = tolower(_F_Name[0]);

	cout << "\n  Enter Last name :      ";
	getline(cin, _L_Name);

	if (isupper(_L_Name[0]))
		_L_Name[0] = tolower(_L_Name[0]);

	cout << "\n  Which year did you enter University ? 13";
	cin >> _Year;

	if (k >= 0)
	{
		cout << "\n  Select your field :";
		for (int i = 0; i <= k; i++)
			cout << "\n   " << i + 1 << " - " << Field[i] << " ";

		cout << "\n   0 - Other "
			 << "\n  ";
		cin >> _Field;

		if (_Field == "0")
			flag = 0;
		else
			_Field = Field[stol(_Field) - 1];
	}
	else
		flag = 0;

	if (flag == 0)
	{
		k++;
		cout << "\n  Insert your field "
			 << "\n  ";
		cin >> Field[k];
		cout << "\n  New field added :)\n";
		_Field = Field[k];

		if (isupper(_Field[0]))
			_Field[0] = tolower(_Field[0]);
	}

	cout << "\n  Select your turn : ";
	cout << "\n   1 - Roozane ";
	cout << "\n   2 - Shabaneh ";
	cout << "\n  Turn ";
	cin >> _Turn;

	if (_Turn == "1")
		_Turn = "Roozane";
	else if (_Turn == "2")
		_Turn = "Shabane";

	cout << "\n  Information successfully saved :)";

	n = count_St / 2;

	for (int i = count_St; i >= n; i--)
		for (int z = 0; z < 8; z++)
		{
			temp = Student[i][z];
			Student[i][z] = Student[i + 1][z];
			Student[i + 1][z] = temp;
		}

	Student[n][0] = _St_num;
	Student[n][1] = _N_Code;
	Student[n][2] = _F_Name;
	Student[n][3] = _L_Name;
	Student[n][4] = _Year;
	Student[n][5] = _Field;
	Student[n][6] = _Turn;
	Student[n][7] = "1";

	count_St++;

	cin.ignore();
	cout << "\n\n Press enter to continue to main menu ";
	getline(cin, p);
}

void Edit()
{
	int flag = 0, _key, co = 1;
	string _st_number, p, _St_num, _N_Code;
	char a;
	cout << "\n  Enter student number : ";
	cin >> _st_number;
	for (int i = 0; i < count_St; i++)
	{
		if (Student[i][0] == _st_number && Student[i][7] == "1")
		{
			flag = 1;
			while (co == 1)
			{
				system("clear");
				cout << "\n\n   Student Number :    " << Student[i][0];
				cout << "  \n   National code :     " << Student[i][1];
				cout << "  \n   First name :        " << Student[i][2];
				cout << "  \n   Last name :         " << Student[i][3];
				cout << "  \n   Year inter :        " << Student[i][4];
				cout << "  \n   Field :             " << Student[i][5];
				cout << "  \n   Turn :              " << Student[i][6];
				cout << "\n\n  ----------------------------------    ";
				cout << "\n\n   Which part you want to edit ? ";
				cout << "  \n   1 - Student number       ";
				cout << "  \n   2 - National code        ";
				cout << "  \n   3 - First name           ";
				cout << "  \n   4 - Last name            ";
				cout << "  \n   5 - Year inter           ";
				cout << "  \n   6 - Field                ";
				cout << "  \n   7 - Turn                 ";
				cout << "  \n   0 - Back to main menu    ";

				cout << "\n\n   Enter the key : ";
				cin >> _key;

				switch (_key)
				{
				case 1:
					cout << "\n   New Student number : ";
					cin.ignore();
					getline(cin, _St_num);
					Student[i][0] = repeat(_St_num, i, 0);
					break;
				case 2:
					cout << "\n   New National code : ";
					cin.ignore();
					getline(cin, _N_Code);
					Student[i][1] = repeat(_N_Code, i, 1);
					break;
				case 3:
					cout << "\n   New First name : ";
					cin.ignore();
					getline(cin, Student[i][2]);
					break;
				case 4:
					cout << "\n   New Last name : ";
					cin.ignore();
					getline(cin, Student[i][3]);
					break;
				case 5:
					cout << "\n   New Year inter : ";
					cin.ignore();
					getline(cin, Student[i][4]);
					break;
				case 6:
					cout << "\n   New Field : ";
					cin.ignore();
					getline(cin, Student[i][5]);
					break;
				case 7:
					cout << "\n   New Turn : ";
					cin.ignore();
					getline(cin, Student[i][6]);
					break;
				}

				if (_key == 0)
					break;

				cout << "  \n   Information successfully changed :) ";
				cout << "\n\n   Do you want to continue editing ( Y/N ) ? ";
				cin >> a;
				if (a == 'Y' || a == 'y')
					co = 1;
				else if (a == 'N' || a == 'n')
					co = 0;
			}

			break;
		}
	}

	if (flag == 0)
		cout << "\n\n   Not Found :( ";

	cin.ignore();
	cout << "\n\n  Press enter to continue to main menu ";
	getline(cin, p);
}

void Delete()
{
	int flag = 0, i;
	string _number, p;
	char a;

	cout << "\n  Enter student number : ";
	cin >> _number;

	for (i = 0; i <= count_St; i++)
		if (Student[i][0] == _number && Student[i][7] == "1")
		{
			flag = 1;

			Cout1();
			Cout2(i);

			cout << "\n\n  Do you want to delete the information ( Y/N ) ? ";
			cin >> a;

			if (a == 'y' || a == 'Y')
			{
				for (int j = i; j < count_St - 1; j++)
					for (int z = 0; z <= 7; z++)
						Student[i][z] = Student[i + 1][z];
				//       -------------------------------------------------------------------
				//              Student[i][7] = "0";

				count_St--;

				cout << "\n  Information successfully removed ;)";
			}
			else if (a == 'n' || a == 'N')
				cout << "\n  Information didn't remove :)";

			break;
		}

	if (flag == 0)
		cout << "\n\n  Not found :(";

	cin.ignore();
	cout << "\n\n Press enter to continue to main menu ";
	getline(cin, p);
}

void Search()
{
	int flag = 0;
	string _st_number, p;

	cout << "\n  Enter student number : ";
	cin >> _st_number;

	for (int i = 0; i <= count_St; i++)
		if (Student[i][0] == _st_number)
		{
			flag = 1;

			Cout1();
			Cout2(i);

			break;
		}

	if (flag == 0)
		cout << "\n  Not found :(";

	cin.ignore();
	cout << "\n\n Press enter to continue to main menu ";
	getline(cin, p);
}

void Show()
{
	int key, flag = 0;
	while (true)
	{
		system("clear");
		{
			cout << "  +-------------------------------------------------------------------+" << endl;
			cout << "  |                                                                   |" << endl;
			cout << "  |  1 - Sort by Student number                                       |" << endl;
			cout << "  |                                                                   |" << endl;
			cout << "  |  2 - Sort by Name                                                 |" << endl;
			cout << "  |                                                                   |" << endl;
			cout << "  |  3 - Show Student information in a field.                         |" << endl;
			cout << "  |                                                                   |" << endl;
			cout << "  |  4 - Show All students                                            |" << endl;
			cout << "  |                                                                   |" << endl;
			cout << "  |  5 - sort (Presentation test)                                     |" << endl;
			cout << "  |                                                                   |" << endl;
			cout << "  |  0 - Back to main menu                                            |" << endl;
			cout << "  |                                                                   |" << endl;
			cout << "  +-------------------------------------------------------------------+" << endl;

			cout << "\n\n  Insert the key : ";
			cin >> key;

			switch (key)
			{
			case 1:
				S_Std_Num();
				break;
			case 2:
				S_Name();
				break;
			case 3:
				S_Field();
				break;
			case 4:
				S_All();
				break;
			case 5:
				S_Test();
				break;
			case 0:
				Menu();
				break;
			default:
				Show();
				flag = 1;
				break;
			}

			if (flag == 1)
				system("pause");
		}
	}
}

void Exit()
{
	system("clear");

	cout << "\n                 _________________________________________               ";
	cout << "\n                |                                         |              ";
	cout << "\n                |         ** Have a good time :)**        |              ";
	cout << "\n                |                                         |              ";
	cout << "\n                |           Alireza Ahmadi Hadi           |              ";
	cout << "\n                |_________________________________________|              ";
	cout << "\n                                                                         ";
	cout << "\n\n";

	sleep_for(3s);

	system("clear");
	exit(0);
}

void S_Std_Num()
{
	string p, hold;
	int flag = 1;

	if (count_St == 0)
		cout << "\n\n You didn't insert any student :|";
	else
	{
		for (int i = 0; i < count_St - 1; i++)
		{
			flag = 1;

			for (int j = 0; j < count_St - 1; j++)
				if (Student[j][0] > Student[j + 1][0])
					for (int z = 0; z <= 7; z++)
					{
						flag = 0;
						hold = Student[j + 1][z];
						Student[j + 1][z] = Student[j][z];
						Student[j][z] = hold;
					}

			if (flag == 1)
				break;
		}

		flag = 0;

		for (int i = 0; i < count_St; i++)
		{
			if (flag == 0)
				Cout1();
			flag = 1;

			Cout2(i);
		}
	}

	cin.ignore();
	cout << "\n\n  Press enter to continue to menu ";
	getline(cin, p);
}

void S_Name()
{
	string p, hold;
	int flag = 1;

	if (count_St == 0)
		cout << "\n\n  You didn't insert any student :|";
	else
	{
		for (int i = 0; i < count_St - 1; i++)
		{
			flag = 1;

			for (int j = 0; j < count_St - 1; j++)
				if (Student[j][3] > Student[j + 1][3])
					for (int z = 0; z <= 7; z++)
					{
						flag = 0;
						hold = Student[j + 1][z];
						Student[j + 1][z] = Student[j][z];
						Student[j][z] = hold;
					}
				else if (Student[j][3] == Student[j + 1][3])
					if (Student[j][2] > Student[j + 1][2])
						for (int z = 0; z <= 7; z++)
						{
							flag = 0;
							hold = Student[j + 1][z];
							Student[j + 1][z] = Student[j][z];
							Student[j][z] = hold;
						}
			if (flag == 1)
				break;
		}

		flag = 0;

		for (int i = 0; i < count_St; i++)
		{
			if (flag == 0)
				Cout1();
			flag = 1;

			Cout2(i);
		}
	}

	cin.ignore();
	cout << "\n\n  Press enter to continue to menu ";
	getline(cin, p);
}

void S_Field()
{
	string p, hold, _st_Field;
	int flag = 0, flag1 = 0, count_F = 0;

	if (count_St == 0)
		cout << "\n\n  You didn't insert any student :|";
	else
	{
		cin.ignore();
		cout << "\n\n  Enter student Field : ";
		getline(cin, _st_Field);

		for (int i = 0; i < count_St; i++)
			if (Student[i][5] == _st_Field)
			{
				flag = 1;

				if (flag1 == 0)
					Cout1();
				flag1 = 1;

				count_F++;

				Cout2(i);
			}

		if (flag == 0)
			cout << "\n\n\n  Not found :(";
		else
			cout << "\n\n  There are " << count_F << " students in this field. ";
	}

	cout << "\n\n Press enter to continue to menu ";
	getline(cin, p);
}

void S_All()
{
	string p;
	int flag = 0;

	if (count_St == 0)
		cout << "\n\n  You didn't insert any student :|";
	else
	{
		for (int i = 0; i < count_St; i++)
		{
			if (flag == 0)
				Cout1();
			flag = 1;

			Cout2(i);
		}
	}

	cin.ignore();
	cout << "\n\n Press enter to continue to menu ";
	getline(cin, p);
}

void S_Test()
{
	string temp, p;
	int flag = 0;

	if (count_St == 0)
		cout << "\n\n  You didn't insert any student :|";
	else
	{
		for (int i = 0; i < count_St / 2; i++)
			for (int z = 0; z <= 7; z++)
			{
				temp = Student[i][z];
				Student[i][z] = Student[count_St - i - 1][z];
				Student[count_St - i - 1][z] = temp;
			}

		for (int i = 0; i < count_St; i++)
		{
			if (flag == 0)
				Cout1();
			flag = 1;

			Cout2(i);
		}
	}

	cin.ignore();
	cout << "\n\n Press enter to continue to menu ";
	getline(cin, p);
}

string repeat(string a, int z, int x)
{
	int flag = 1;
	while (flag == 1)
	{
		flag = 0;
		for (int i = 0; i < count_St; i++)
		{
			if (i == z)
				continue;

			if (Student[i][x] == a)
			{
				flag = 1;
				cout << "\n   This student already exist!";

				if (x == 0)
					cout << "\n\n   New Student number : ";
				else if (x == 1)
					cout << "\n\n   New National code :  ";

				getline(cin, a);

				a = repeat(a, z, x);

				break;
			}
		}
	}

	return a;
}