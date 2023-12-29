#include<iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct player 
{
	int experience;
	int health;
	int level;
	string _class;
};

player my_player;

void level_up();
void experience();
void display_level();
void health_increase();
void display_health();
int damage(int damg);
void display_data();

void class_choice(string &player_class);

	int main() 
	{
		string clas;
		class_choice(clas);
		my_player._class = clas;
		cout << "end";
	}
	
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
		int damage_health;
		damage_health = 100 - my_player.health;
		
		if(my_player.health <100)
		{
			if(damage_health >= 50)
			{
				my_player.health += 50 ;
			}
			else if(damage_health <= 50)
			{
				my_player.health = 100;
			}
		}
	}
	
	void display_health()
	{
		cout << "\nHealth : " << my_player.health;
	}
	
	int damage(int damg)
	{
		return rand() % damg + 1;
	}
	
	void display_data()
	{
		cout << "\nQuest Completed";
		experience();
		level_up();
		display_level();
		display_health();
		health_increase();
		if(my_player.health < 100)
		{
			cout << "\nYou get health bonus";
			display_health();
		}
	}
	
	void class_choice(string &player_class)
	{
		
		bool check = false;
		do
		{
			system("cls");
			check = false;
			char user_choice;
			cout << "\nYou need to select your class.";
			cout << "\n1 : Mage";
			cout << "\n    Attack Damage = 5-10";
			cout << "\n    Health = 100";
			cout << "\n2 : Rogue";
			cout << "\n    Attack Damage = 10-15";
			cout << "\n    Health = 120";
			cout << "\n3 : Worrior";
			cout << "\n    Health = 150";
			cout << "\n    Attack Damage = 15-20";
			cout << "\n\n\nEnter Your Choice : ";
			user_choice = _getche();
			
			if(user_choice == '1')
			{
				player_class = "Mage";
			}
			else if(user_choice == '2')
			{
				player_class = "Rouge";
			}
			else if(user_choice == '3')
			{
				player_class = "Worrior";
			}
			else
			{
				cin.clear();
				check = true;
			}
			
		}while(check);
	}
		
