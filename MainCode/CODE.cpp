#include<iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

struct player 
{
	string name;
	int experience;
	int health;
	int max_health;
	int level;
	string _class;
	int hi_damg;
	int low_damg;
};
struct quest_check
{
	bool q1,q2,q3,q4,q5;
};

quest_check quest;

player my_player;
bool battle;

//--------------------------------------------------------------------------------
void level_up();
void experience();
void display_level();
void health_increase();
void display_health();
int damage(int damg_hi, int damg_low);
void display_data();

void class_choice();

void battle_system(bool difficalty, int enemy_health, string enemy_name, bool &battle);

void player_data();

void quest_1();
void quest_2();
void quest_3();
void quest_4();
void quest_5();

//-------------------------------------------------------------------------------

	int main() 
	{
		player_data();
		quest_1();
		if(quest.q1)
		{
			quest_2();
		}
		
		if(quest.q2)
		{
			quest_3();
		}
		
		if(quest.q3)
		{
			quest_4();
		}
		
		if(quest.q4)
		{
			quest_5();
		}
		
		if(quest.q5)
		{
			system("cls");
			cout << "\n\n\t\t\t\t\t\tTHE END";
		}
		_getch();
		return 0;
	}
//-------------------------------------------------------------------------------
	
	void experience()
	{
		my_player.experience += 5 ;
	}

	void level_up() 
	{
		if(my_player.experience == 10)
		{
			my_player.level++;
			my_player.experience = 0 ; 
		}
	}
	
	void display_level()
	{
		cout << "\nLEVEL : " << my_player.level ;
	}
	
	void health_increase()
	{
		if(my_player.health < my_player.max_health)
		{
			if(my_player.health <= 50)
			{
				my_player.health += 50;
				cout << "\nYou get health bonus";
				display_health();
			}
			else if(my_player.health > 50) 
			{
				if(my_player._class == "Mage")
				{
					if(my_player.health > 50 && my_player.health < 100)
					{
						my_player.health += 50;
						cout << "\nYou get health bonus";
						display_health();
					}
					else if(my_player.health >= 100)
					{
						my_player.health = 130;
						cout << "\nYou get health bonus";
						display_health();
					}
				}
				else if(my_player._class == "Rouge")
				{
					if(my_player.health > 50 && my_player.health <= 70)
					{
						my_player.health += 50;
						cout << "\nYou get health bonus";
						display_health();
					}
					else
					{
						my_player.health = 120;
						cout << "\nYou get health bonus";
						display_health();
					}
				}
				else if(my_player._class == "Worrior")
				{
					if(my_player.health > 50 && my_player.health <= 100)
					{
						my_player.health += 50;
						cout << "\nYou get health bonus";
						display_health();
					}
					else
					{
						my_player.health = 150;
						cout << "\nYou get health bonus";
						display_health();
					}
				}
			}
		}
	}
	
	void display_health()
	{
		cout << "\nHealth : " << my_player.health;
	}
	
	int damage(int damg_hi, int damg_low)
	{
		return rand() % damg_hi + damg_low;
	}
	
	void display_data()
	{
		cout << "\n\n\n\n\n\nQuest Completed";
		experience();
		level_up();
		display_level();
		display_health();
		health_increase();
		cout << "\nPress any key to Continue . . .";
		_getch();
	}
	
	void class_choice()
	{
		
		bool check;
		do
		{
			system("cls");
			check = false;
			char user_choice;
			cout << "\nYou need to select your class.";
			cout << "\n> : Mage                   (1)" ;
			cout << "\n    Attack Damage = 5-10";
			cout << "\n    Health = 130";
			cout << "\n> : Rogue                  (2)";
			cout << "\n    Attack Damage = 10-15";
			cout << "\n    Health = 120";
			cout << "\n> : Worrior                (3)";
			cout << "\n    Health = 150";
			cout << "\n    Attack Damage = 15-20";
			cout << "\n\n\nEnter Your Choice : ";
			user_choice = _getche();
			
			if(user_choice == '1')
			{
				my_player._class = "Mage";
				my_player.health = 130;
				my_player.max_health = 130;
				my_player.hi_damg = 10;
				my_player.low_damg = 5;
			}
			else if(user_choice == '2')
			{
				my_player._class = "Rouge";
				my_player.health = 120;
				my_player.max_health = 120;
				my_player.hi_damg = 15;
				my_player.low_damg = 10;
			}
			else if(user_choice == '3')
			{
				my_player._class = "Worrior";
				my_player.health = 150;
				my_player.max_health = 150;
				my_player.hi_damg = 20;
				my_player.low_damg = 15;
			}
			else
			{
				check = true;
			}
			
		}while(check);
		system("cls");
	}
	
	void battle_system(bool difficalty, int enemy_health, string enemy_name,bool &battle)
	{
		char choice;
		int temp_enemy_health = enemy_health;
		int temp_health = my_player.health;
		short a;
		a = 1;
		do
		{	
			system("cls");
			display_health();
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << enemy_name << " Health : " << enemy_health;
			cout << "\n\n\n\n\n\n\n\t\t" << my_player.name << "\t\t\t\t\t\t\t\t\t\t\t\t" << enemy_name;
			cout << "\n\n\n\n\n\n\nPress 'a' to attack and wait for your turn";
			
			if(a == 1)
			{
				cout << "\n\n\t\t\t\t\t\t\t\tYour Turn";
				char user_press;
				
				user_press = _getch();
				
				if(user_press == 'a')
				{
					enemy_health = enemy_health - (difficalty == true ? (damage(my_player.hi_damg , my_player.low_damg) * 0.7) : damage(my_player.hi_damg , my_player.low_damg) ); 
					a = 2;
				}
				else
				{
					cin.clear();
				}
			}
			else if(a == 2)
			{
				cout << "\n\n\t\t\t\t\t\t\t\t"<< enemy_name << " Turn";
				Sleep(1250);
				my_player.health = my_player.health - damage(difficalty == true ? 20 : 10, 1);
				a = 1;
			}
			
			if(my_player.health <= 0)
			{
				system("cls");
				cout << "\nYou lose! Do you want to continue?(y for yes)";
				choice = _getch();
				if(choice == 'y')
				{
					my_player.health = temp_health + rand() % 30 + 1;
					enemy_health = temp_enemy_health;
				}
			}
				
		}while(my_player.health > 0 && enemy_health > 0);
		
		if(my_player.health > 0)
		{
			system("cls");  
			cout << "\n\n\t\t\t\t\t\t\tGood Job, now move to the next point.";
			battle = true;
			cout << "\nPress any key to Continue . . .";
			_getch();
		}
		else
		{
			battle = false;
		}
	}
			
	void player_data()
	{
		cout << "\nEnter your name : ";
		getline(cin,my_player.name);
		class_choice();
	}
	
	void quest_1()
	{
		cout << "\nSoldiers! I am Sergeant Kaddafi. \nWe are going to attack on Zohad's Kindom, Be ready for battle.";
		cout << "\nPress any key to Continue . . .";
		_getch();
		system("cls");
		cout << "\nKaddafi : " << my_player.name << "! there is an enemy go ahead and fight him";
		battle_system(false,70,"Shareef",battle);
		if(battle)
		{
			display_data();
			quest.q1 = true;
		}
	}
	
	void quest_2()
	{
		system("cls");
		cout << "\n\nKaddafi : " << my_player.name << " Watch out! There is a river behind you.";
		cout << "\nKaddafi : Fight with the oponent, and be careful, don't fall in river.";
		cout << "\nPress any key to Continue . . .";
		_getch();
		system("cls");
		battle_system(false,80,"Methic",battle);
		if(battle)
		{
			system("cls");
			cout << "\n\nKaddafi : Watch your back.";
			cout << "\nBammmp!";
			cout << "\nPress any key to Continue . . .";
			_getch();
			display_data();
			quest.q2 = true;
		}
	}	
	
	void quest_3()
	{
		system("cls");
		cout << "\n\nYou fell into a river and flowed to a village where a monster lives, attacking people.";
		Sleep(1000);
		cout << "\nVillager : Who are you.";
		Sleep(1000);
		cout << "\nYou :   My name is " << my_player.name << ". I am a " << my_player._class << ", and I fell in river and found myself there.";
		cout << "\n\tI am on battle and going to conquer Zohad's Kingdom.";
		cout << "\n\tZohad is a Cruel King.";
		Sleep(1000);
		cout << "\nVillager : There is a monster who kill people. So be careful.";
		Sleep(1000);
		cout << "\nTakeee!";
		Sleep(1000);
		cout << "\nVillager : Mounsterrr, Run Run Run.";
		Sleep(1000);
		cout << "\nYou : I am a " << my_player._class << " man, I an trained to do or die.";
		Sleep(1000);
		cout << "\nPress any key to Continue . . .";
		_getch();
		battle_system(false,150,"Lurkizard",battle);
		if(battle)
		{
			cout << "\nYou : That was easy.";
			Sleep(1000);
			cout << "\nVillager : Thank You Sir, we are all thankful to you.";
			Sleep(1000);
			cout << "\nYou : No Problem! That is my job.";
			Sleep(1000);
			cout << "\nVillager : You can follow the river to reach the Zohad's Kingdom.";
			cout << "\nPress any key to Continue . . .";
			_getch();
			display_data();
			quest.q3 = true;
		}
	}
	
	void quest_4()
	{
		system("cls");
		cout << "\nVillager : Be careful there is a monster in the river that is more dangerous than the previous one";
		Sleep(1000);
		cout << "\nYou : Let see.";
		Sleep(1000);
		cout << "\nYou : Come on, lite monster, fight with me.";
		cout << "\nPress any key to Continue . . .";
		_getch();
		battle_system(true,130,"Aquanox",battle);
		if(battle)
		{
			cout << "\nYou : ooooh! That one is difficult.";
			cout << "\nYou : What ever, I win.";
			cout << "\nPress any key to Continue . . .";
			_getch();
			display_data();
			quest.q4 = true;
		}
	}
	
	void quest_5()
	{
		system("cls");
		cout << "\nYou : Finaly, I am there.";
		Sleep(1000);
		cout << "\nKaddafi : I attcept that you died " << my_player.name;
		Sleep(1000);
		cout << "\nYou : I am a " << my_player._class << ". How you supposed, i am dead.";
		Sleep(1000);
		cout << "\nKaddafi : Hahaha! I know that.";
		Sleep(1000);
		cout << "\n          Lets beat the Zohad.";
		cout << "\nPress any key to Continue . . .";
		_getch();
		battle_system(true, 150,"Zohad",battle);
		if(battle)
		{
			cout << "\nHureee.";
			cout << "\nYou : Thats how you can do this.";
			Sleep(1000);
			cout << "\nKaddafi : Well done soldiers ";
			cout << "\n          We win the war.";
			cout << "\nPress any key to Continue . . .";
			_getch();
			quest.q5 = true;
		}
	}
	
