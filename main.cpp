#include <iostream>

using namespace std;

typedef struct tagPlayer
{
public:
	char szPlayerName[32];
	unsigned int uHP;
	unsigned int uAttackDam;
} PLAYER, MONSTER;

void Start_Screen();
void Stat_Screen(PLAYER _player);
void Choose_Action_Screen(PLAYER _player);
void Choose_Level_Screen(PLAYER _player);
void Battle_Screen(PLAYER _player, MONSTER _monster);
void Do_Battle(PLAYER _player, MONSTER _monster);

PLAYER Create_Player(int _iKeyPress);


enum
{
	���� = 1,
	������,
	����,
	�ʱ�,
	�߱�,
	���,
	���ܰ�,
	END
};

int main()
{
	int iKeyPress(0);

	Start_Screen();
	cin >> iKeyPress;

	PLAYER* player = new PLAYER(Create_Player(iKeyPress));

	while (true)
	{
		system("cls");
		Choose_Action_Screen(*player);
		cin >> iKeyPress;

		if (iKeyPress == 2 || iKeyPress == 0)
			break;

		while (true)
		{
			system("cls");
			Choose_Level_Screen(*player);
			cin >> iKeyPress;
			iKeyPress += 3;

			if (iKeyPress == ���ܰ�)
				break;

			MONSTER monster = Create_Player(iKeyPress);

			while (iKeyPress != 2)
			{
				system("cls");
				Battle_Screen(*player, monster);
				cin >> iKeyPress;

				if (iKeyPress == 1)
				{
					if (player->uHP <= monster.uAttackDam)
					{
						cout << " �� �� " << endl;
						system("pause");
						player->uHP = 100;
						break;
					}
					if (monster.uHP <= player->uAttackDam)
					{
						player->uHP -= monster.uAttackDam;
						cout << " �¸� " << endl;
						system("pause");
						break;
					}
					else
					{
						player->uHP -= monster.uAttackDam;
						monster.uHP -= player->uAttackDam;
					}
				}
			}
		}
	}

	delete player;
	player = nullptr;

	return 0;
}

void Start_Screen()
{
	cout << " =============txt RPG============= " << endl;
	cout << " Press 0 to quit the game " << endl;

	cout << " ������ �����ϼ��� " << endl;
	cout << " 1. ����\t 2. ������\t 3. ����" << endl;
}

PLAYER Create_Player(int _iKeyPress)
{
	PLAYER player = {};

	switch (_iKeyPress)
	{
	case (����):
		strncpy_s(player.szPlayerName, "����", sizeof(player.szPlayerName) - 1);
		player.uHP = 100;
		player.uAttackDam = 10;
		break;
	case (������):
		strncpy_s(player.szPlayerName, "������", sizeof(player.szPlayerName) - 1);
		player.uHP = 100;
		player.uAttackDam = 10;
		break;
	case (����):
		strncpy_s(player.szPlayerName, "����", sizeof(player.szPlayerName) - 1);
		player.uHP = 100;
		player.uAttackDam = 10;
		break;
	case (�ʱ�):
		strncpy_s(player.szPlayerName, "�ʱ�", sizeof(player.szPlayerName) - 1);
		player.uHP = 20;
		player.uAttackDam = 3;
		break;
	case (�߱�):
		strncpy_s(player.szPlayerName, "�߱�", sizeof(player.szPlayerName) - 1);
		player.uHP = 40;
		player.uAttackDam = 5;
		break;
	case (���):
		strncpy_s(player.szPlayerName, "���", sizeof(player.szPlayerName) - 1);
		player.uHP = 60;
		player.uAttackDam = 10;
		break;
	default:
		break;
	}

	return player;
}

void Stat_Screen(PLAYER _player)
{
	cout << "=====================================" << endl;
	cout << "�̸� : " << _player.szPlayerName << endl;
	cout << "HP : " << _player.uHP << '\t' << "���ݷ� : " << _player.uAttackDam << endl;
}

void Choose_Action_Screen(PLAYER _player)
{
	Stat_Screen(_player);
	cout << "\n1. �����\t2.���� : " << endl;
}

void Choose_Level_Screen(PLAYER _player)
{
	Stat_Screen(_player);
	cout << "\n1. �ʱ�\t2.�߱�\t3. ���\t4. �� �ܰ� : " << endl;
}

void Battle_Screen(PLAYER _player, MONSTER _monster)
{
	Stat_Screen(_player);
	Stat_Screen(_monster);
	cout << "\n1. ����\t2.���� : " << endl;
}

void Do_Battle(PLAYER _player, MONSTER _monster)
{

}