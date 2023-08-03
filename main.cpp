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
	전사 = 1,
	마법사,
	도적,
	초급,
	중급,
	고급,
	전단계,
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

			if (iKeyPress == 전단계)
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
						cout << " 패 배 " << endl;
						system("pause");
						player->uHP = 100;
						break;
					}
					if (monster.uHP <= player->uAttackDam)
					{
						player->uHP -= monster.uAttackDam;
						cout << " 승리 " << endl;
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

	cout << " 직업을 선택하세요 " << endl;
	cout << " 1. 전사\t 2. 마법사\t 3. 도적" << endl;
}

PLAYER Create_Player(int _iKeyPress)
{
	PLAYER player = {};

	switch (_iKeyPress)
	{
	case (전사):
		strncpy_s(player.szPlayerName, "전사", sizeof(player.szPlayerName) - 1);
		player.uHP = 100;
		player.uAttackDam = 10;
		break;
	case (마법사):
		strncpy_s(player.szPlayerName, "마법사", sizeof(player.szPlayerName) - 1);
		player.uHP = 100;
		player.uAttackDam = 10;
		break;
	case (도적):
		strncpy_s(player.szPlayerName, "도적", sizeof(player.szPlayerName) - 1);
		player.uHP = 100;
		player.uAttackDam = 10;
		break;
	case (초급):
		strncpy_s(player.szPlayerName, "초급", sizeof(player.szPlayerName) - 1);
		player.uHP = 20;
		player.uAttackDam = 3;
		break;
	case (중급):
		strncpy_s(player.szPlayerName, "중급", sizeof(player.szPlayerName) - 1);
		player.uHP = 40;
		player.uAttackDam = 5;
		break;
	case (고급):
		strncpy_s(player.szPlayerName, "고급", sizeof(player.szPlayerName) - 1);
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
	cout << "이름 : " << _player.szPlayerName << endl;
	cout << "HP : " << _player.uHP << '\t' << "공격력 : " << _player.uAttackDam << endl;
}

void Choose_Action_Screen(PLAYER _player)
{
	Stat_Screen(_player);
	cout << "\n1. 사냥터\t2.종료 : " << endl;
}

void Choose_Level_Screen(PLAYER _player)
{
	Stat_Screen(_player);
	cout << "\n1. 초급\t2.중급\t3. 고급\t4. 전 단계 : " << endl;
}

void Battle_Screen(PLAYER _player, MONSTER _monster)
{
	Stat_Screen(_player);
	Stat_Screen(_monster);
	cout << "\n1. 공격\t2.도망 : " << endl;
}

void Do_Battle(PLAYER _player, MONSTER _monster)
{

}