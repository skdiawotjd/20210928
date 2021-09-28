#include <iostream>
#include <windows.h> //windows 헤더파일 include
#include <cstdlib> //rand()
#include <ctime>	//time()


using namespace std;	

//엔진회사
char Input();
bool Process(char Key);
void Draw();
void Initialize();
void Terminate();

//엔진회사
void CustomInitialze();
void CustomTerminate();
bool CustomProcess(char Key);
void CustomDraw();

//개발자
bool ProcessBingo(char Key);

void InitializeBingoPlayerMap();
void DrawBingo();

int Gold = 0;

int BingoPlayerMap[9];


int main()
{
	bool bGameState = true;
	Initialize();

	while (bGameState)
	{
		char Key = Input();
		bGameState = Process(Key);
		Draw();
	}
	Terminate();

	return 0;
}



char Input()
{
	char Key;

	cin >> Key;

	return Key;
}

bool Process(char Key)
{
	if (Key == 'q' || Key == 'Q')
	{
		return false;
	}

	return CustomProcess(Key);
}

void Draw()
{
	//		system("cls");
	cout << "그린다." << endl;

	CustomDraw();
}

void Initialize()
{
	//초기화
	CustomInitialze();
}

void Terminate()
{
	CustomTerminate();
	//종료
}



//개발자
void CustomInitialze()
{
	InitializeBingoPlayerMap();
}

void CustomTerminate()
{

}

bool CustomProcess(char Key)
{
	return ProcessBingo(Key);
}

void CustomDraw()
{
	DrawBingo();
}

bool ProcessBingo(char Key)
{
	//빙고판에서 찾은 칸에 마킹한다
	for (int i = 0; i < 9; i++)
	{
		if (BingoPlayerMap[i] == Key - 48)
		{
			BingoPlayerMap[i] = 'X';
			break;
		}
	}

	//가로 빙고인지 확인한다
	for (int i = 0; i <= 6; i = i + 3)
	{
		if (BingoPlayerMap[i] == 'X' &&
			BingoPlayerMap[i + 1] == 'X' &&
			BingoPlayerMap[i + 2] == 'X')
		{
			cout << "bingo!" << endl;
			return false;
		}
	}
	//세로 빙고인지 확인한다
	for (int i = 0; i <= 2; i++)
	{
		if (BingoPlayerMap[i] == 'X' &&
			BingoPlayerMap[i + 3] == 'X' &&
			BingoPlayerMap[i + 6] == 'X')
		{
			cout << "bingo!" << endl;
			return false;
		}
	}
	//대각선 빙고인지 확인한다
	if (BingoPlayerMap[0] == 'X' &&
		BingoPlayerMap[4] == 'X' &&
		BingoPlayerMap[8] == 'X')
	{
		cout << "bingo!" << endl;
		return false;
	}
	else if (BingoPlayerMap[2] == 'X' &&
		BingoPlayerMap[4] == 'X' &&
		BingoPlayerMap[6] == 'X')
	{
		cout << "bingo!" << endl;
		return false;
	}

	return true;
}

void DrawBingo()
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i != 0)
		{
			cout << endl;
		}
		if (BingoPlayerMap[i] == 88)
		{
			cout << "X" << " ";
		}
		else
		{
			cout << "O" << " ";
		}
	}
	cout << endl;
}

void InitializeBingoPlayerMap()
{
	for (int i = 0; i < 9; ++i)
	{
		BingoPlayerMap[i] = i + 1;
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	//Shuffle
	for (int i = 0; i < 100; i++)
	{
		//rand
		int Index1 = rand() % 9;
		int Index2 = rand() % 9;

		int Temp = BingoPlayerMap[Index1];
		BingoPlayerMap[Index1] = BingoPlayerMap[Index2];
		BingoPlayerMap[Index2] = Temp;
	}
}
