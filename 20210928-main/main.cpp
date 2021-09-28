#include <iostream>
#include <windows.h> //windows ������� include
#include <cstdlib> //rand()
#include <ctime>	//time()


using namespace std;	

//����ȸ��
char Input();
bool Process(char Key);
void Draw();
void Initialize();
void Terminate();

//����ȸ��
void CustomInitialze();
void CustomTerminate();
bool CustomProcess(char Key);
void CustomDraw();

//������
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
	cout << "�׸���." << endl;

	CustomDraw();
}

void Initialize()
{
	//�ʱ�ȭ
	CustomInitialze();
}

void Terminate()
{
	CustomTerminate();
	//����
}



//������
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
	//�����ǿ��� ã�� ĭ�� ��ŷ�Ѵ�
	for (int i = 0; i < 9; i++)
	{
		if (BingoPlayerMap[i] == Key - 48)
		{
			BingoPlayerMap[i] = 'X';
			break;
		}
	}

	//���� �������� Ȯ���Ѵ�
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
	//���� �������� Ȯ���Ѵ�
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
	//�밢�� �������� Ȯ���Ѵ�
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
