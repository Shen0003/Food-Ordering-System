#include<iostream>
#include<chrono>
#include<thread>
#include<cctype>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int numItems = 0;
const int MAX_ITEMS = 200;

string food_codeList[MAX_ITEMS];
string food_nameList[MAX_ITEMS];
int food_quantityList[MAX_ITEMS];
double food_priceList[MAX_ITEMS];



void introDesign();
void outroDesign();
void titleDesign();
void main_menu();
void foodmenu_options();
void transaction_options();
void loadInventory();
void displayMenu_Transaction();
//9 modules functions
void displayMenu();
void addItem();
void updateItem();
void deleteItem();
void restoreItem();
void view_Transaction();
void add_Transaction();
void clear_Transaction();
void restore_Transaction();


int main() {

	//(I). INTRO
	//to full screen in the console
	introDesign();
	cin.ignore();
	system("cls"); //clear the screen
	loadInventory();
	//(II). MAIN MENU (INCLUDE OPTIONS: a.Food Menu Options, b.Transaction Options, c.Exit Program)
	char option;
	char choice;
	do {
		system("cls");
		main_menu();
		cout << "\t\t\t\t\t\t\t\t\t\tEnter Option: ";
		cin >> option;
		cin.ignore(10000, '\n'); //clear the input by removing max 10000 characters until a newline character is encountered.
		//to prevent user enter the string value and cause the whileloop to loop infinitely because of the unexpected string datatype for the char datatype of options,
		//error validation for option 
		while (toupper(option) != 'A' && toupper(option) != 'B' && toupper(option) != 'Q') {
			cout << "\t\t\t\t\t\t\t\t\t\t\033[31mPlease enter a valid option!\033[0m" << endl;
			this_thread::sleep_for(chrono::seconds(2)); //wait for 2 second
			system("cls");
			main_menu();
			cout << "\t\t\t\t\t\t\t\t\t\tEnter Option: ";
			cin >> option;
			cin.ignore(10000, '\n'); //clear the input by removing max 10000 characters until a newline character is encountered.
		}
		//a.Food Menu Options
		if (toupper(option) == 'A') {
			system("cls");
			foodmenu_options();
			cout << "\t\t\t\t\t\t\t\t\t\tEnter choice: ";
			cin >> choice;
			cin.ignore(10000, '\n'); //clear the input by removing max 10000 characters until a newline character is encountered.

			//error validation for choice 
			while (!isdigit(choice) || choice < '1' || choice > '6') {
				cout << "\n=============================================================================================================================================================================================" << endl <<
					"\n\t\t\t\t\t\t\t\t\t\t\033[31mPlease enter a valid choice!\033[0m\n" << endl <<
					"=============================================================================================================================================================================================" << endl;
				this_thread::sleep_for(chrono::seconds(2));
				system("cls");
				foodmenu_options();
				cout << "\t\t\t\t\t\t\t\t\t\tEnter choice: ";
				cin >> choice;
				cin.ignore(10000, '\n'); //clear the input by removing max 10000 characters until a newline character is encountered.
			}

			//choice statement for a.Food Menu Options
			char displaychoice;
			char addItemchoice;
			char deleteItemchoice;
			char updateItemchoice;

			switch (choice) {
			case '1':
				do {
					system("cls");
					titleDesign();
					displayMenu();
					cout << "\n\t\t\t\t\t\t\t\t\t\tPress e to exit: ";
					cin >> displaychoice;
					cin.ignore(1000, '\n');

					//error validation for exit
					while (toupper(displaychoice) != 'E') {
						cout << "\t\t\t\t\t\t\t\t\t\t\033[31mInvalid input!\033[0m";
						this_thread::sleep_for(chrono::seconds(2));
						system("cls");
						titleDesign();
						displayMenu();
						cout << "\n\t\t\t\t\t\t\t\t\t\tPress e to exit: ";
						cin >> displaychoice;
						cin.ignore(1000, '\n');
					}

				} while (toupper(displaychoice) != 'E');


				break; //exit the switch case if input 'E'
			case '2':

				do {
					system("cls");
					titleDesign();
					displayMenu();
					addItem();
					cout << "\t\t\t\t\t\t\t\t\t\tContinue to add? (Y-Yes, N-No): ";
					cin >> addItemchoice;
					cin.ignore(1000, '\n');

					//error validation for continue
					while (toupper(addItemchoice) != 'Y' && toupper(addItemchoice) != 'N') {
						cout << "\t\t\t\t\t\t\t\t\t\t\033[31mInvalid Input!\033[0m\n";
						cout << "\t\t\t\t\t\t\t\t\t\tContinue to add? (Y-Yes, N-No): ";
						cin >> addItemchoice;
						cin.ignore(1000, '\n');
					}


				} while (toupper(addItemchoice) == 'Y');

				break; //exit the switch case other than input 'Y'

			case '3':
				do {
					system("cls");
					titleDesign();
					displayMenu();
					updateItem();
					cout << "\n\t\t\t\t\t\t\t\t\t\tContinue to update? (Y-Yes, N-No): ";
					cin >> updateItemchoice;
					cin.ignore(1000, '\n');

					//error validation for continue
					while (toupper(updateItemchoice) != 'Y' && toupper(updateItemchoice) != 'N') {
						cout << "\t\t\t\t\t\t\t\t\t\t\033[31mInvalid Input!\033[0m\n";
						cout << "\n\t\t\t\t\t\t\t\t\t\tContinue to update? (Y-Yes, N-No): ";
						cin >> updateItemchoice;
						cin.ignore(1000, '\n');
					}


				} while (toupper(updateItemchoice) == 'Y');

				break; //exit the switch case other than input 'Y'

			case '4':

				do {
					system("cls");
					titleDesign();
					displayMenu();
					deleteItem();
					cout << "\t\t\t\t\t\t\t\t\t\tContinue to delete? (Y-Yes, N-No): ";
					cin >> deleteItemchoice;
					cin.ignore(1000, '\n');

					//error validation for continue 
					while (toupper(deleteItemchoice) != 'Y' && toupper(deleteItemchoice) != 'N') {
						cout << "\t\t\t\t\t\t\t\t\t\t\033[31mInvalid Input!\033[0m\n";
						cout << "\t\t\t\t\t\t\t\t\t\tContinue to delete? (Y-Yes, N-No): ";
						cin >> deleteItemchoice;
						cin.ignore(1000, '\n');
					}


				} while (toupper(deleteItemchoice) == 'Y');

				break; //exit the switch case other than input 'Y'

			case '5':
				system("cls");
				restoreItem();
				break;
			case '6': //if input '6', return to main menu
				break;
			}
			this_thread::sleep_for(chrono::seconds(2));
		}

		//b.Transaction Options
		else if (toupper(option) == 'B') {
			system("cls");
			transaction_options();
			cout << "\t\t\t\t\t\t\t\t\t\tEnter choice: ";
			cin >> choice;
			cin.ignore(10000, '\n'); //clear the input by removing max 10000 characters until a newline character is encountered.

			//error validation for choice
			while (!isdigit(choice) || choice < '1' || choice > '5') {
				cout << "\n=============================================================================================================================================================================================" << endl <<
					"\n\t\t\t\t\t\t\t\t\t\t\033[31mPlease enter a valid choice!\033[0m\n" << endl <<
					"=============================================================================================================================================================================================" << endl;
				this_thread::sleep_for(chrono::seconds(2)); //????
				system("cls");
				transaction_options();
				cout << "\t\t\t\t\t\t\t\t\t\tEnter choice: ";
				cin >> choice;
				cin.ignore(10000, '\n'); //clear the input by removing max 10000 characters until a newline character is encountered.
			}

			//choice statement for b.Transaction Options
			char viewchoice = 'y';
			char addchoice;

			switch (choice) {

			case '1':
				do {
					system("cls");
					titleDesign();
					view_Transaction();
					cout << "\t\t\t\t\t\t\t\t\t\tPress e to exit: ";
					cin >> viewchoice;
					cin.ignore(1000, '\n');

					//error validation for exit
					while (toupper(viewchoice) != 'E') {
						cout << "\t\t\t\t\t\t\t\t\t\t\033[31mInvalid input!\033[0m";
						this_thread::sleep_for(chrono::seconds(2));
						system("cls");
						titleDesign();
						view_Transaction();
						cout << "\t\t\t\t\t\t\t\t\t\tPress e to exit: ";
						cin >> viewchoice;
						cin.ignore(1000, '\n');
					}

				} while (toupper(viewchoice) != 'E');

				break; //exit the switch case if input 'E'

			case '2':

				do {
					system("cls");
					titleDesign();
					displayMenu_Transaction();
					add_Transaction();
					cout << "\t\t\t\t\t\t\t\t\t\tContinue to add? (Y-Yes, N-No): ";
					cin >> addchoice;
					cin.ignore(1000, '\n');

					//error validation for continue
					while (toupper(addchoice) != 'Y' && toupper(addchoice) != 'N') {
						cout << "\t\t\t\t\t\t\t\t\t\t\033[31mInvalid Input!\033[0m\n";
						cout << "\t\t\t\t\t\t\t\t\t\tContinue to add? (Y-Yes, N-No): ";
						cin >> addchoice;
						cin.ignore(1000, '\n');
					}
				} while (toupper(addchoice) == 'Y');

				break; //exit the switch case other than input 'Y'


			case '3':
				system("cls");
				clear_Transaction();
				break;

			case '4':
				system("cls");
				restore_Transaction();
				break;
			case '5':
				break;
			}
			this_thread::sleep_for(chrono::seconds(2));
		}

	} while (toupper(option) != 'Q'); //close the program if user enter q or Q

	//(III). OUTRO
	system("cls");
	outroDesign();
	system("pause");
	exit(0);
}

void introDesign() {
	cout << "\033[1;96;5m\t\t\t\t~~~~~   \t     ~~       __      __       .__         ~~~                      __ ~~                 ~~~~                   ~~~               ~~~\n"
		"\t~~~~    \t\t\t\t        ~~~  /  \\    /  \\ ____ |  |   ____  ____   _____   ____   _/  |_  ____              ~~~~~~~                         ~~~~\n"
		"\t\t\t~~~~~   \t\t   ~~~       \\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\/ __ \\  \\    __\\/  _ \\   ~~                                      ~~~\n"
		"\t\t\t\t\t\t              \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/   |  | (  <_> )                 ~~                   ~~~~~~~~\n"
		"\t\t\t\t  ~~~~~~\t               \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >  |__|  \\____/                     ~~~~~                   ~~\n"
		"\t  ~~~~~~\t\t\t\t         ~~         \\/       \\/          \\/            \\/     \\/        ~~~~~                                         ~~ \n"
		"\t\t\t\t\t\t   ~~~       _________      .__   __             .___ ___________.__       .__            ~~            ~~~~~~~~~~~          ~~         \n"
		"\t\t\t\t~~~~~   \t            /   _____/____  |  |_/  |_  ____   __| _/ \\_   _____/|__| _____|  |__                                             ~~~~~~~~\n"
		"\t~~~     \t\t\t\t            \\_____  \\\\__  \\ |  |\\   __\\/ __ \\ / __ |   |    __)  |  |/  ___/  |  \\            ~~                 \n"
		"\t\t\t~~~   ~~\t\t   ~~~~~    /        \\/ __ \\|  |_|  | \\  ___// /_/ |   |     \\   |  |\\___ \\|   Y  \\    ~~~~~~~                 ~~~~  \n"
		"\t\t~~~~  ~~\t\t\t           /_______  (____  /____/__|  \\___  >____ |   \\___  /   |__/____  >___|  /                 ~~                      ~~~~~\n"
		"  ~~~~  \t\t\t\t\t           ~~~     \\/     \\/               \\/     \\/       \\/            \\/     \\/                 ~~~~~~             \n"
		"\t\t\t\t\t\t   .____                              .__                    _________         _____     ._.     ~~~~               ~~~~          \n"
		"\t\t\t\t\t~~~        |    |    __ __  ____   ____  ____ |  |__   ____   ____   \\_   ___ \\_____ _/ ____\\____| |                          ~~~~\n"
		"\t\t\t\t\t\t   |    |   |  |  \\/    \\_/ ___\\/ __ \\|  |  \\ /  _ \\ /    \\  /    \\  \\/\\__  \\\\   __\\/ __ \\ |      ~~~~                         ~~~~\n"
		"\t\t\t~~~~~~~~\t\t   |    |___|  |  /   |  \\  \\__\\  ___/|   Y  (  <_> )   |  \\/     \\____/ __ \\|  | \\   ___/\\|                   ~~~~~~~~\n"
		"\t~~~     \t\t\t\t   |_______ \\____/|___|  /\\___  >___  >___|  /\\____/|___|  /\\______   (____  /__|  \\___  >__     ~~~        ~~~~~~~~    \n"
		"\t\t\t~~~     \t\t           \\/          \\/     \\/    \\/     \\/            \\/        \\/     \\/           \\/ \\/      ~~~           " << endl;

	cout << "             O   . ~ ~ . ,/{               ~~~~~~~~~                                                                    ~~                      ~~~~~~~\n";
	cout << "         O     .'@ ))ejm'~.~                                  ~~~              ~~                     ~~~~~~~~~~~                                                              ~~~~~~~~~~\n";
	cout << "           o   = - ~``     `         ~~~~                                                                                          ~~~~~~~~\n";
	cout << "                                                  ~~~~          |\\        o         ~~~~~                                                                    ~~~~~ \n";
	cout << "                                  ____                        .-  -.     o                   o           ,      ,                                                             ~~\n";
	cout << "       ~~~                     /\\|    ~~\\                  )\\/  (( o\\  o                         o      . ~ ~ . ,/{    ~~~\n";
	cout << "                             /'  |   ,-. `\\              )/'''''----=                             O   .'@ ))ejm'~.~                   ~~~         O      ,      ,                    ~~~~~   \n";
	cout << "               ~~~~~~       |       | X |  |                                         ~~~              = - ~``     `                             o    . ~ ~ . ,/{ ~~~~~~\n";
	cout << "                           _|________`-'   |X            ~~~~~~                                                                                  O .'@ ))ejm'~.~           ~~~~~     \n";
	cout << "   ~~~~                  /'          ~~~~~~~~~,                         ~~~~~~~~                                                                  o= - ~``     `                               ~~\n";
	cout << "                       /'             ,_____,/_     ~~~                                    ~~~~~~~~~                                           ~~~                 ~~~~\n";
	cout << "                    ,/'        ___,'~~         ;                 O                   ~~                    <>< <><         ~~~                                                       ~~~~~\n";
	cout << "~~~~~~~~|~~~~~~~|---          /  X,~~~~~~~~~~~~,                   o        ,      ,                      <>< <>< <><                                      ~~\n";
	cout << "        |       |            |  XX'____________'                 o       . ~ ~ . ,/{                       <>< <>< <><                 ~~~~~\n";
	cout << "        |       |           /' XXX|            ;                    O  .'@ ))ejm'~.~     ~~~          <>< <>< <>< <>< <><          |\\        o        ~~~~~~~             ~~~~~~\n";
	cout << "        |       |        --x|  XXX,~~~~~~~~~~~~,     ~~~~~             = - ~``     `                       <>< <>< <><           .-  -.        O                   ~~\n";
	cout << "        |       |          X|     '____________'                                                              <>< <><         )\\/  (( o\\  o  ~~~                                             ~~~~~~\n";
	cout << "        |   o   |---~~~~\\__XX\\             |XX                       o       O                                              )/'''''----=         ~~~~~~~                      ~~~~~~ \n";
	cout << "        |       |          XXX`\\          /XXXX                __         O    o          ~~~~~                                                                        o                  \n";
	cout << "~~~~~~~~'~~~~~~~'               `\\xXXXXx/' \\XXX              \\/ o\\  o                                         ~~~~~~~                                      |\\     O                ~~~\n";
	cout << "                                 /XXXXXX\\                    /\\__/  __     o            O      ,      ,                         ~~~~~                      .-  -.      o         \n";
	cout << "            ~~~                /XXXXXXXXXX\\                   __  \\/ o\\  O            o      . ~ ~ . ,/{                                                 )\\/  (( o\\ O        ~~~~~~\n";
	cout << "                      ~~     /XXXXXX/^\\XDCAU\\               \\/ o\\ /\\__/   o            O .'@ ))ejm'~.~                                ~~~~~            )/'''''---=O  ~~\n";
	cout << "     ~~~~~                  ~~~~~~~~   ~~~~~~~              /\\__/                        = - ~``     `            ~~~~~~~\n";
	cout << "============================================================================================================================================================================================\n";
	cout << "\t\t\t____    ____   ___    ___    ___     ___   _  _   _____  ___   ____     _____  ____     ___  ____   _  _   _____   ___   _  _   _  _   ___  \n"
		<< "\t\t\t)  _)\\ /  _ \\ ) __(  (  _(  (  _(   ) __( ) \\/ ( )__ __() __( /  _ \\   )__ __(/ __ \\   / _( / __ \\ ) \\/ ( )__ __( )_ _( ) \\/ ( ) () ( ) __( \n"
		<< "\t\t\t| '__/ )  ' / | _)   _) \\   _) \\    | _)  |  \\ |   | |  | _)  )  ' /     | |  ))__((   ))_  ))__(( |  \\ |   | |   _| |_ |  \\ | | \\/ | | _)  \n"
		<< "\t\t\t)_(    |_()_\\ )___( )____) )____)   )___( )_()_(   )_(  )___( |_()_\\     )_(  \\____/   \\__( \\____/ )_()_(   )_(  )_____()_()_( )____( )___( o o o o o o \n\033[0m";
}

void outroDesign() {
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t__________.__                                                .__  __                         " << endl;
	cout << "\t\t\t\t\t\t\t\\______   \\  |   ____ _____    ______ ____   __  _  _______  |__|/  |_                       " << endl;
	cout << "\t\t\t\t\t\t\t |     ___/  | _/ __ \\\\__  \\  /  ___// __ \\  \\ \\/ \\/ /\\__  \\ |  \\   __\\                      " << endl;
	cout << "\t\t\t\t\t\t\t |    |   |  |_\\  ___/ / __ \\_\\___ \\\\  ___/   \\     /  / __ \\|  ||  |                        " << endl;
	cout << "\t\t\t\t\t\t\t |____|   |____/\\___  >____  /____  >\\___  >   \\/\\_/  (____  /__||__|                        " << endl;
	cout << "\t\t\t\t\t\t\t                    \\/     \\/     \\/     \\/                \\/          ";
	cout << " o O o";
	this_thread::sleep_for(chrono::seconds(1));
	cout << " O o O";
	this_thread::sleep_for(chrono::seconds(1));
	cout << " o O o\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\t\t\t\t\t\t_________ .__               .__                        .__                   __  .__         " << endl;
	cout << "\t\t\t\t\t\t\\_   ___ \\|  |   ____  _____|__| ____    ____     _____|  |__   ____________/  |_|  | ___.__." << endl;
	cout << "\t\t\t\t\t\t/    \\  \\/|  |  /  _ \\/  ___/  |/    \\  / ___\\   /  ___/  |  \\ /  _ \\_  __ \\   __\\  |<   |  |" << endl;
	cout << "\t\t\t\t\t\t\\     \\___|  |_(  <_> )___ \\|  |   |  \\/ /_/  >  \\___ \\|   Y  (  <_> )  | \\/|  | |  |_" << "\\___  |" << endl;
	cout << "\t\t\t\t\t\t \\______  /____/\\____/____  >__|___|  /\\___  /  /____  >___|  /\\____/|__|   |__| |____/ ____|" << endl;
	cout << "\t\t\t\t\t\t        \\/                \\/        \\/ _____/        \\/     \\/                        \\/     ";
	cout << " o O o";
	this_thread::sleep_for(chrono::seconds(1));
	cout << " O o O";
	this_thread::sleep_for(chrono::seconds(1));
	cout << " o O o\n";
	this_thread::sleep_for(chrono::seconds(1));

}

void titleDesign() {
	cout << "=============================================================================================================================================================================================\n";
	cout << "\033[1;96;5m\t\t~~~~    \t\t\t~~~~    \t  _________      .__   __     ~~~     .___ ___________.__       .__	~~		~~~~			~~~~~		\n";
	cout << "\t~~~~~~   \t\t   ~~~~~\t\t\t /   _____/____  |  |_/  |_  ____   __| _/ \\_   _____/|__| _____|  |__	~~~~			~~~~~			~~~	\n";
	cout << "\t\t\t\t~~~~~~  \t\t~~~~     \\_____  \\\\__  \\ |  |\\   __\\/ __ \\ / __ |   |    __)  |  |/  ___/  |  \\			~~~~~			  ~~~~~~\n";
	cout << "   ~~~         \t\t        ~~~~               \t\t /        \\/ __ \\|  |_|  | \\  ___// /_/ |   |    \\    |  |\\___ \\|  Y   \\	   ~~	     ~~~~~~~~\n";
	cout << "\t\t\t\t~~~~    \t\t~~~~~   /_______  (____  /____/__|  \\___  >____ |   \___  /    |__/____  >__|   /	~~~		         ~~~~~		    \n";
	cout << "\t\t\t~~~~~~~~\t\t\t\t        \\/     \\/               \\/     \\/      \\/             \\/    \\_/	~~~			~~~~			~~~\n";
	cout << "\t    ~~~ \t\t\t~~~  ~~~\t.____   ~~~                  .__  ~~~~~                   _________         _____      ~~~~		   ~~     ~~~~~		\n";
	cout << "\t~~~~    \t~~~     \t\t\t|    |    __ __  ____   ____ |  |__   ____  ____   ____   \\_   ___ \\_____ _/ ____\\___	   ~~		         ~~~~    ~~\n";
	cout << "\t\t\t~~~     \t\~~~~~   \t|    |   |  |  \\/    \\_/ ___\\|  |  \\_/ __ \\/  _ \\ /    \\  /    \\  \\/\\__  \\   __\\/ __  \\~~		      ~~~~~\n";
	cout << "\t\t\t\t    ~~~~~\t\t|    |___|  |  /   |  \\  \\___|   Y  \\  ___(  <_> )   |  \\ \\     \\____/ __ \\|  | \\  ___/		~~		  ~~~~~~	~~~~\n";
	cout << "    ~~~~~~~~    \t\t\~~~     \t~~~~~~~ |_______ \\____/|___|  /\\___  >___|  /\\___  >____/|___|  /  \\______  (____  /__|  \___  >		~~~~	~~~~~\n";
	cout << "\t\t\t\t   ~~~~ \t\t ~~~~~  \\/          \\/     \\/     \\/     \\/           \\/          \\/     \\/         \\/	~~~~~~~~	    ~~~        ~~~~~~\n\n\033[0m";
	cout << "=============================================================================================================================================================================================\n\n";
}

void main_menu() {
	titleDesign();
	cout << "\t\t\t\t\t\t\t\t\t\tA. Food Menu Options" << endl <<
		"\t\t\t\t\t\t\t\t\t\tB. Transaction Options" << endl <<
		"\t\t\t\t\t\t\t\t\t\tQ. Quit Program" << endl << endl <<
		"=============================================================================================================================================================================================" << endl << endl;

}

void foodmenu_options() {
	titleDesign();
	cout << "\t\t\t\t\t\t\t\t\t\t1. View Food Menu" << endl <<
		"\t\t\t\t\t\t\t\t\t\t2. Add Item" << endl <<
		"\t\t\t\t\t\t\t\t\t\t3. Update Item" << endl <<
		"\t\t\t\t\t\t\t\t\t\t4. Delete Item" << endl <<
		"\t\t\t\t\t\t\t\t\t\t5. Restore Item" << endl <<
		"\t\t\t\t\t\t\t\t\t\t6. Back to Main Menu" << endl << endl <<
		"=============================================================================================================================================================================================" << endl << endl;
}

void transaction_options() {
	titleDesign();
	cout << "\t\t\t\t\t\t\t\t\t\t1. View Transaction History" << endl <<
		"\t\t\t\t\t\t\t\t\t\t2. Add Transaction" << endl <<
		"\t\t\t\t\t\t\t\t\t\t3. Clear Transaction History" << endl <<
		"\t\t\t\t\t\t\t\t\t\t4. Restore Transaction History" << endl <<
		"\t\t\t\t\t\t\t\t\t\t5. Back to Main Menu" << endl << endl <<
		"=============================================================================================================================================================================================" << endl << endl;

}

void loadInventory() {
	ifstream infile("food_menu.txt");
	if (!infile) {
		cout << "\t\t\t\t\t\t\t\t\t\t\033[31mFood menu file not found!\033[0m" << endl;
		return;
	}

	while (getline(infile, food_codeList[numItems]) &&
		getline(infile, food_nameList[numItems]) &&
		(infile >> food_quantityList[numItems]) &&
		(infile >> food_priceList[numItems])) {
		// Successfully read in one item
		numItems++;
		infile.ignore();
	}

	if (numItems == 0) {
		// File is empty
		cout << "\t\t\t\t\t\t\t\t\t\t\033[31mFood menu file is empty!\033[0m" << endl;
	}

	infile.close();
}

void displayMenu_Transaction() { //Food menu for transaction purpose, item/ food quantity removed
	ifstream infile("food_menu.txt");
	if (infile.is_open()) {
		if (numItems == 0) {
			cout << "\t\t\t\t\t\t\t\t\t\t\033[31mThe food menu is empty!\033[0m" << endl;
		}

		cout << "=============================================================================================================================================================================================" << endl << endl;
		cout << "\t\t\t\t\t\t" << left << setw(20) << "Code" << setw(55) << "Item" << setw(15) << "Price" << endl;
		cout << endl << "=============================================================================================================================================================================================" << endl << endl;

		for (int i = 0; i < numItems; i++) {
			cout << "\t\t\t\t\t\t" << left << setw(20) << food_codeList[i] << setw(55) << food_nameList[i] << setw(2) << fixed << setprecision(2) << "RM " << food_priceList[i] << endl;
		}
		cout << endl << "=============================================================================================================================================================================================" << endl;


		string line;
		while (getline(infile, line)) {
			break;
		}
		infile.close();
	}
	else {
		cout << "\t\t\t\t\t\t\t\t\t\t\033[31mUnable to open file!\033[0m" << endl;
		return;
	}

}


//9 modules function here
void displayMenu() {

	ifstream infile("food_menu.txt");
	if (infile.is_open()) {
		if (numItems == 0) {
			cout << "\t\t\t\t\t\t\t\t\t\t\033[31mThe food menu is empty!\033[0m" << endl;
		}

		else {
			cout << "=============================================================================================================================================================================================" << endl << endl;
			cout << "\t\t\t\t\t\t" << left << setw(20) << "Code" << setw(55) << "Item" << setw(15) << "Quantity" << setw(20) << "Price" << endl;
			cout << endl << "=============================================================================================================================================================================================" << endl << endl;

			for (int i = 0; i < numItems; i++) {
				cout << "\t\t\t\t\t\t" << left << setw(20) << food_codeList[i] << setw(55) << food_nameList[i] << setw(15) << food_quantityList[i] << setw(2) << fixed << setprecision(2) << "RM " << food_priceList[i] << endl;
			}
			cout << endl << "=============================================================================================================================================================================================" << endl;


			string line;
			while (getline(infile, line)) {
				break;
			}

			infile.close();
		}
	}
	else {
		cout << "\t\t\t\t\t\t\t\t\t\t\033[31mUnable to open file!\033[0m" << endl;
		return;
	}

}

void addItem() {
	if (numItems == MAX_ITEMS) {
		cout << "\t\t\t\t\t\t\t\t\033[31mThe food menu is already full, unable to add more food!\033[0m" << endl;
		return;
	}

	string itemCode;
	string itemName;
	int itemQuantity;
	double itemPrice;

	cout << "\n\t\t\t\t\t\t\t\t\t\tEnter New Food Code: ";
	cin >> itemCode;


	for (int i = 0; i < numItems; i++) {
		if (food_codeList[i] == itemCode) {
			cout << "\t\t\t\t\t\t\t\t\t\t\033[31mFood code " << itemCode << " already exists in the food menu!\033[0m" << endl;
			return;
		}
	}

	cout << "\t\t\t\t\t\t\t\t\t\tEnter New Food Name: ";
	cin.ignore();
	getline(cin, itemName);


	for (int i = 0; i < numItems; i++) {
		if (food_nameList[i] == itemName) {
			cout << "\t\t\t\t\t\t\t\t\t\t\033[31mFood name " << itemName << " already exists in the food menu!\033[0m" << endl;
			return;
		}
	}

	cout << "\t\t\t\t\t\t\t\t\t\tEnter New Food Quantity: ";
	cin >> itemQuantity;

	cout << "\t\t\t\t\t\t\t\t\t\tEnter New Food Price: ";
	cin >> itemPrice;

	food_codeList[numItems] = itemCode;
	food_nameList[numItems] = itemName;
	food_quantityList[numItems] = itemQuantity;
	food_priceList[numItems] = itemPrice;

	numItems++;

	ofstream outfile("food_menu.txt");
	for (int i = 0; i < numItems; i++) {
		outfile << food_codeList[i] << endl << food_nameList[i] << endl << food_quantityList[i] << endl << food_priceList[i] << endl;
	}
	outfile.close();


	cout << "\n\t\t\t\t\t\t\t\t====================================================================" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\033[1;92;5m++ New Food Added Successfully! ++\033[0m" << endl;
	cout << "\t\t\t\t\t\t\t\t====================================================================" << endl;
}

void updateItem() {
	if (numItems == MAX_ITEMS) {
		cout << "\t\t\t\t\t\t\t\t\033[31mThe food menu is already full, unable to add more food!\033[0m" << endl;
		return;
	}

	string selecteditemCode;
	string upitemCode;
	string upitemName;
	int upitemQuantity;
	double upitemPrice;
	char choice;
	bool codeExists = false;

	//user enter the food code that they want to update
	cout << "\n\t\t\t\t\t\t\t\t\t\tWhich food want to change?: ";
	cin >> selecteditemCode;
	for (int d = 0; d < numItems; d++) { //check if the entered food code is exist in the food menu or not
		if (food_codeList[d] == selecteditemCode) {
			codeExists = true;
			break;
		}
	}

	if (codeExists) {
		//if the food code entered is exist in the food menu
		for (int i = 0; i < numItems; i++) {
			if (food_codeList[i] == selecteditemCode) {
				//ask the user to input choice of which part do the user want to update
				cout << "\n\t\t\t\t\t\t\tWhich choice want to change? (1-item code, 2-item name, 3-item quantity, 4-item price): ";
				cin >> choice;
				while (choice > '4') {
					cout << "\t\t\t\t\t\t\t\t\t\t\033[31mPlease enter a valid choice!\033[0m" << endl;
					cout << "\n\t\t\t\t\t\t\tWhich choice want to change? (1-item code, 2-item name, 3-item quantity, 4-item price): ";
					cin >> choice;
				}
				switch (choice) {
				case '1':
					cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Updated Food Code: ";
					cin >> upitemCode;
					for (int j = 0; j < numItems; j++) { //check if the updated food code is already exist in the food menu or not
						if (food_codeList[j] == upitemCode) {
							cout << "\t\t\t\t\t\t\t\t\t\t\033[31mFood code " << upitemCode << " already exists in the food menu!\033[0m" << endl;
							return;
						}
					}
					food_codeList[i] = upitemCode; //update the new food code
					cout << "\n\t\t\t\t\t\t\t\t====================================================================" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\033[1;92;5m-- Updated Successfully! --\033[0m" << endl;
					cout << "\t\t\t\t\t\t\t\t====================================================================" << endl;
					break;
				case'2':
					cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Updated Food Name: ";
					cin.ignore();
					getline(cin, upitemName);
					for (int j = 0; j < numItems; j++) { //check if the updated food name is already exist in the food menu or not
						if (food_nameList[j] == upitemName) {
							cout << "\t\t\t\t\t\t\t\t\t\t\033[31mFood name " << upitemName << " already exists in the food menu!\033[0m" << endl;
							return;
						}
					}
					food_nameList[i] = upitemName; //update the new food name
					cout << "\n\t\t\t\t\t\t\t\t====================================================================" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\033[1;92;5m-- Updated Successfully! --\033[0m" << endl;
					cout << "\t\t\t\t\t\t\t\t====================================================================" << endl;
					break;
				case'3':
					cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Updated Food Quantity: ";
					cin >> upitemQuantity;
					food_quantityList[i] = upitemQuantity; //update new food quantity
					cout << "\n\t\t\t\t\t\t\t\t====================================================================" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\033[1;92;5m-- Updated Successfully! --\033[0m" << endl;
					cout << "\t\t\t\t\t\t\t\t====================================================================" << endl;
					break;
				case'4':
					cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Updated Food Price: ";
					cin >> upitemPrice;
					food_priceList[i] = upitemPrice; //update new food price
					cout << "\n\t\t\t\t\t\t\t\t====================================================================" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\033[1;92;5m-- Updated Successfully! --\033[0m" << endl;
					cout << "\t\t\t\t\t\t\t\t====================================================================" << endl;
					break;
				}

			}


		}
		ofstream outfile("food_menu.txt");
		for (int k = 0; k < numItems; k++) {
			outfile << food_codeList[k] << " " << food_nameList[k] << " " << food_quantityList[k] << " " << food_priceList[k] << endl;
		}
		outfile.close();
	}
	//if the food code entered is not exist in the food menu
	else {
		cout << "\t\t\t\t\t\t\t\t\t\t\033[31mFood Code Not Found!\033[0m" << endl;
	}
}

void deleteItem() {
	if (numItems == 0) {
		cout << "\t\t\t\t\t\t\t\t\033[31mThe food menu is already empty, nothing can be deleted anymore!\033[0m" << endl;
		return;
	}

	string itemCode;

	cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Food Code To Be Deleted: ";
	cin >> itemCode;

	bool itemFound = false;

	for (int i = 0; i < numItems; i++) {
		if (food_codeList[i] == itemCode) {
			//store the to be deleted food
			ofstream outFile("foodmenu_backup.txt", ios::app);
			outFile << food_codeList[i] << " " << food_nameList[i] << " " << food_quantityList[i] << " " << food_priceList[i] << endl;
			outFile.close();

			for (int j = i; j < numItems - 1; j++) {
				food_codeList[j] = food_codeList[j + 1];
				food_nameList[j] = food_nameList[j + 1];
				food_quantityList[j] = food_quantityList[j + 1];
				food_priceList[j] = food_priceList[j + 1];
			}

			numItems--;

			cout << "\n\t\t\t\t\t\t\t\t====================================================================" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\033[1;92;5m-- Selected Food Deleted Successfully! --\033[0m" << endl;
			cout << "\t\t\t\t\t\t\t\t====================================================================" << endl;


			itemFound = true;

			break;
		}
	}

	if (!itemFound) {
		cout << "\t\t\t\t\t\t\t\t\t\t\033[31mFood Code Not Found!\033[0m" << endl;
	}

	ofstream outfile("food_menu.txt");
	for (int i = 0; i < numItems; i++) {
		outfile << food_codeList[i] << " " << food_nameList[i] << " " << food_quantityList[i] << " " << food_priceList[i] << endl;
	}

	outfile.close();
}

void restoreItem() {
	ifstream inFile("foodmenu_backup.txt", ios::app);

	string resitemCode;
	string resitemName;
	int resitemQuantity;
	double resitemPrice;
	while (inFile >> resitemCode >> resitemName >> resitemQuantity >> resitemPrice) {
		food_codeList[numItems] = resitemCode;
		food_nameList[numItems] = resitemName;
		food_quantityList[numItems] = resitemQuantity;
		food_priceList[numItems] = resitemPrice;
		numItems++;
	}
	inFile.close();



	ofstream outFile2("food_menu.txt");

	for (int i = 0; i < numItems; i++) {
		outFile2 << food_codeList[i] << " " << food_nameList[i] << " " << food_quantityList[i] << " " << food_priceList[i] << endl;
	}
	outFile2.close();


	ofstream outFile("foodmenu_backup.txt");
	outFile << "";
	outFile.close();

	cout << "\033[1;33;5m\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t__________                 __               .__                \n";
	cout << "\t\t\t\t\t\t\t\t\\______   \\ ____   _______/  |_  ___________|__| ____    ____  \n";
	cout << "\t\t\t\t\t\t\t\t |       _// __ \\ /  ___/\\   __\\/  _ \\_  __ \\  |/    \\  / ___\\ \n";
	cout << "\t\t\t\t\t\t\t\t |    |   \\  ___/ \\___ \\  |  | (  <_> )  | \\/  |   |  \\/ /_/  >\n";
	cout << "\t\t\t\t\t\t\t\t |____|_  /\\___  >____  > |__|  \\____/|__|  |__|___|  /\\___  / \n";
	cout << "\t\t\t\t\t\t\t\t        \\/     \\/     \\/                            \\/ ____/  ";

	this_thread::sleep_for(chrono::seconds(1));
	cout << " o O o";
	this_thread::sleep_for(chrono::seconds(1));
	cout << " O o O";
	this_thread::sleep_for(chrono::seconds(1));
	cout << " o O o\033[0m";
	this_thread::sleep_for(chrono::seconds(1));
	system("cls");
	cout << "\033[1;92;5m\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t  _________                       .__          __             .___._. \n";
	cout << "\t\t\t\t\t\t\t\t\\_   ___ \\  ____   _____ ______ |  |   _____/  |_  ____   __| _/| | \n";
	cout << "\t\t\t\t\t\t\t\t/    \\  \\/ /  _ \\ /     \\\\____ \\|  | _/ __ \\   __\\/ __ \\ / __ | | | \n";
	cout << "\t\t\t\t\t\t\t\t\\     \\___(  <_> )  Y Y  \\  |_> >  |_\\  ___/|  | \\  ___// /_/ | \\|\\|\n";
	cout << "\t\t\t\t\t\t\t\t \\______  /\\____/|__|_|  /   __/|____/\\___  >__|  \\___  >____ | __\n";
	cout << "\t\t\t\t\t\t\t\t        \\/             \\/|__|             \\/          \\/      \\/ \\/\n\033[0m";
}

void view_Transaction() {
	int transaction_num[MAX_ITEMS];
	string selectedfoodcodeList_Trans[MAX_ITEMS];
	string selectedfoodnameList_Trans[MAX_ITEMS];
	string selectedfoodpriceList_Trans[MAX_ITEMS];
	string selectedfoodquantityList_Trans[MAX_ITEMS];
	string date[MAX_ITEMS];
	double totalprice[MAX_ITEMS];
	int count;
	int m = 0;

	ifstream infile("transaction_history.txt");
	if (infile.is_open()) {
		while (infile >> transaction_num[m]) { //while transaction_number can be read from the file, continue the reading process
			infile.ignore();
			getline(infile, selectedfoodcodeList_Trans[m]);
			getline(infile, selectedfoodnameList_Trans[m]);
			getline(infile, selectedfoodpriceList_Trans[m]);
			getline(infile, selectedfoodquantityList_Trans[m]);
			getline(infile, date[m]);
			infile >> totalprice[m];
			m++;
		}
		cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;
		for (count = 0; count < m; count++) {

			cout << right << setfill(' ') << setw(165) << "+--------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << setfill(' ') << setw(105) << "           Transaction Number: " << transaction_num[count] << endl;
			cout << right << setfill(' ') << setw(165) << "+--------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << setfill(' ') << setw(105) << "  Date(dd/mm/yy)           : " << date[count] << endl;
			cout << right << setfill(' ') << setw(165) << "+--------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << setfill(' ') << setw(105) << "  Selected Food Code : " << selectedfoodcodeList_Trans[count] << endl;
			cout << setfill(' ') << setw(105) << "  Selected Food      : " << selectedfoodnameList_Trans[count] << endl;
			cout << setfill(' ') << setw(105) << "  Price              : " << selectedfoodpriceList_Trans[count] << endl;
			cout << setfill(' ') << setw(105) << "  Quantity           : " << selectedfoodquantityList_Trans[count] << endl;
			cout << right << setfill(' ') << setw(165) << "+--------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << setfill(' ') << setw(108) << fixed << showpoint << setprecision(2) << "  Total Price              : RM " << totalprice[count] << endl;
			cout << right << setfill(' ') << setw(165) << "+--------------------------------------------------------------------------------------------------------------------------------------+" << endl << endl;

			cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;
		}

		infile.close();

	}

	else {
		cout << "\t\t\t\t\t\t\t\t\t\t\033[31mUnable to open file!\033[0m" << endl;
		return;

	}

}

void add_Transaction() {

	if (numItems == 0) {
		return; //if the food menu is empty, exit this function immediately
	}
	//input the latest transaction number
	ifstream infile("transaction_number.txt");
	int transaction_num;

	infile >> transaction_num;
	if (infile.fail()) {  // if file is empty and failed to read
		transaction_num = 1;
	}


	infile.close();

	//transaction details
	string selectedfoodcode; //store the food code enter by the user for checking
	string selectedfoodcodeList[MAX_ITEMS]; //store the food code selected by the user
	string selectedfoodnameList[MAX_ITEMS]; //store the food name selected by the user
	double selectedfoodpriceList[MAX_ITEMS]; //store the food price selected by the user
	int selectedfoodquantityList[MAX_ITEMS]; //store the food quantity selected by the user
	string date; //store date
	double food_quantityprice = 0; //store the selected food price * selected quantity
	double totalprice = 0; //store the total food price


	char askmore; //ask the user want to add more food for transaction details or not
	int j = 0;



	cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Date(dd/mm/yy): ";
	cin >> date;

	do {
		bool codeFound = false; //for checking if the entered food code is exist in the menu or not for transaction purpose
		do {
			cout << "\t\t\t\t\t\t\t\t\t\tEnter Food Code: "; //prompt the user to enter food code 
			cin >> selectedfoodcode;


			for (int i = 0; i < numItems; i++) {
				if (food_codeList[i] == selectedfoodcode) { //check until the selected food code is found in the food menu

					selectedfoodcodeList[j] = selectedfoodcode; //save the selected food code based on the food code entered
					selectedfoodnameList[j] = food_nameList[i]; //save the selected food name based on the food code entered
					selectedfoodpriceList[j] = food_priceList[i]; //save the selected food price based on the food code entered

					codeFound = true; //the food code is exist in the menu

					break;
				}
			}

			if (!codeFound) { //the food code is not exist in the menu
				cout << "\t\t\t\t\t\t\t\t\t\t\033[31mFood Code Not Found!\033[0m\n";
			}

		} while (!codeFound); //if the food code is not exist, let the user to enter the food code again

		cout << "\t\t\t\t\t\t\t\t\t\tEnter Food Quantity: "; //prompt the user to enter the food quantity
		cin >> selectedfoodquantityList[j];

		j++;

		//ask user still want to continue to add more food or not
		cout << "\n\t\t\t\t\t\t\t\t\t\tContinue to add more food? (Y-Yes, N-No): ";
		cin >> askmore;
		cin.ignore(1000, '\n');
		while (toupper(askmore) != 'Y' && toupper(askmore) != 'N') {
			cout << "\t\t\t\t\t\t\t\t\t\t\033[31mPlease enter a valid choice!\033[0m";
			cout << "\n\t\t\t\t\t\t\t\t\t\tContinue to add more food? (Y-Yes, N-No): ";
			cin >> askmore;
			cin.ignore(1000, '\n');
		}

	} while (toupper(askmore) == 'Y');

	//display the transaction details
	cout << "\t\t\t\t\t\t\t\t\t+--------------------------------------------------+\n";
	cout << "\t\t\t\t\t\t\t\t\t           Transaction Number: " << transaction_num << "\n";
	cout << "\t\t\t\t\t\t\t\t\t+--------------------------------------------------+\n";

	//food code, food selected, food price, food quantity
	for (int counting = 0; counting < j; counting++) {
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t  Food selected: " << selectedfoodnameList[counting] << endl;
		cout << "\t\t\t\t\t\t\t\t\t  Price: RM " << selectedfoodpriceList[counting] << endl;
		cout << "\t\t\t\t\t\t\t\t\t  Quantity: " << selectedfoodquantityList[counting] << endl;
		cout << endl;
		food_quantityprice = selectedfoodpriceList[counting] * selectedfoodquantityList[counting];
		totalprice += food_quantityprice;
	}
	/////////////////////////////////////////
	//date and total price
	cout << "\t\t\t\t\t\t\t\t\t+--------------------------------------------------+\n";
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t  Date(dd/mm/yy): " << date << endl;
	cout << "\t\t\t\t\t\t\t\t\t  Total price: RM " << totalprice << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\t+--------------------------------------------------+\n";

	//STORE TRANSACTION DETAILS
	ofstream outfile2("transaction_history.txt", ios::app);
	int counter;
	//Write the transaction details to the file
	outfile2 << transaction_num;
	outfile2 << endl;
	outfile2 << "| ";
	for (counter = 0; counter < j; counter++) {
		outfile2 << selectedfoodcodeList[counter] << " | ";
	}
	outfile2 << endl;
	outfile2 << "| ";
	for (counter = 0; counter < j; counter++) {
		outfile2 << selectedfoodnameList[counter] << " | ";
	}
	outfile2 << endl;
	outfile2 << "| ";
	for (counter = 0; counter < j; counter++) {
		outfile2 << fixed << showpoint << setprecision(2) << "RM " << selectedfoodpriceList[counter] << " | ";
	}
	outfile2 << endl;
	outfile2 << "| ";
	for (int counter = 0; counter < j; counter++) {
		outfile2 << selectedfoodquantityList[counter] << " | ";
	}
	outfile2 << endl;
	outfile2 << date << endl;
	outfile2 << totalprice << endl;



	outfile2.close();

	//STORE LATEST TRANSACTION NUMBER
	ofstream outfile("transaction_number.txt");
	outfile << transaction_num + 1 << endl;
	outfile.close();



}

void clear_Transaction() {

	string transaction_numberList[MAX_ITEMS];
	string selectedfoodcodeList_Trans[MAX_ITEMS];
	string selectedfoodnameList_Trans[MAX_ITEMS];
	string selectedfoodpriceList_Trans[MAX_ITEMS];
	string selectedfoodquantityList_Trans[MAX_ITEMS];
	string dateList[MAX_ITEMS];
	string totalpriceList[MAX_ITEMS];
	int counting = 0;

	ifstream inFile("transaction_history.txt");
	ofstream outFile("transaction_history_backup.txt");

	if (inFile.is_open()) {

		//Write the transaction details to the file
		while (getline(inFile, transaction_numberList[counting]) &&
			getline(inFile, selectedfoodcodeList_Trans[counting]) &&
			getline(inFile, selectedfoodnameList_Trans[counting]) &&
			getline(inFile, selectedfoodpriceList_Trans[counting]) &&
			getline(inFile, selectedfoodquantityList_Trans[counting]) &&
			getline(inFile, dateList[counting]) &&
			getline(inFile, totalpriceList[counting]))
		{
			counting++;
		}
		inFile.close();
	}

	else {
		cout << "\t\t\t\t\t\t\t\t\t\t\033[31mUnable to open file!\033[0m" << endl;
		return;
	}

	for (int x = 0; x < counting; x++) {
		outFile << selectedfoodcodeList_Trans[x] << endl
			<< selectedfoodnameList_Trans[x] << endl
			<< selectedfoodpriceList_Trans[x] << endl
			<< selectedfoodquantityList_Trans[x] << endl
			<< dateList[x] << endl
			<< totalpriceList[x] << endl;
	}

	outFile.close();

	ofstream outFile3("transaction_history.txt", ios::trunc);
	if (outFile3.is_open()) {
		//File opened successfully, so close it
		outFile3.close();
		cout << "\033[1;91;5m\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\t_________ .__                      .__            \n";
		cout << "\t\t\t\t\t\t\t\t\\_   ___ \\|  |   ____ _____ _______|__| ____    ____\n";
		cout << "\t\t\t\t\t\t\t\t/    \\  \\/|  | _/ __ \\\\__  \\\\_  __ \\  |/    \\  / ___\\\n";
		cout << "\t\t\t\t\t\t\t\t\\     \\___|  |_\\  ___/ / __ \\|  | \\/  |   |  \\/ /_/  >\n";
		cout << "\t\t\t\t\t\t\t\t \\______  /\\__/ \\___  >____  /__|  |__|___|  /\\___  / \n";
		cout << "\t\t\t\t\t\t\t\t        \\/          \\/     \\/              \\//_____/  ";
		this_thread::sleep_for(chrono::seconds(1));
		cout << " o O o";
		this_thread::sleep_for(chrono::seconds(1));
		cout << " O o O";
		this_thread::sleep_for(chrono::seconds(1));
		cout << " o O o\033[0m";
		this_thread::sleep_for(chrono::seconds(1));
		system("cls");
		cout << "\033[1;92;5m\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\t  _________                       .__          __             .___._. \n";
		cout << "\t\t\t\t\t\t\t\t\\_   ___ \\  ____   _____ ______ |  |   _____/  |_  ____   __| _/| | \n";
		cout << "\t\t\t\t\t\t\t\t/    \\  \\/ /  _ \\ /     \\\\____ \\|  | _/ __ \\   __\\/ __ \\ / __ | | | \n";
		cout << "\t\t\t\t\t\t\t\t\\     \\___(  <_> )  Y Y  \\  |_> >  |_\\  ___/|  | \\  ___// /_/ | \\|\\|\n";
		cout << "\t\t\t\t\t\t\t\t \\______  /\\____/|__|_|  /   __/|____/\\___  >__|  \\___  >____ | __\n";
		cout << "\t\t\t\t\t\t\t\t        \\/             \\/|__|             \\/          \\/      \\/ \\/\n\033[0m";
	}

	//clear transaction number file
	ofstream outFile2("transaction_number.txt");
	outFile2 << "";
	outFile2.close();
}

void restore_Transaction() {
	int latest_transaction_num;
	string selectedfoodcodeList_Trans[MAX_ITEMS];
	string selectedfoodnameList_Trans[MAX_ITEMS];
	string selectedfoodpriceList_Trans[MAX_ITEMS];
	string selectedfoodquantityList_Trans[MAX_ITEMS];
	string dateList[MAX_ITEMS];
	string totalpriceList[MAX_ITEMS];
	int counting = 0;

	ifstream infile9("transaction_number.txt");
	infile9 >> latest_transaction_num;
	if (infile9.fail()) {  // if file is empty and failed to read
		latest_transaction_num = 1;
	}
	infile9.close();

	ifstream inFile("transaction_history_backup.txt");
	ofstream outFile("transaction_history.txt", ios::app);

	if (!inFile.is_open()) {
		cout << "\t\t\t\t\t\t\t\t\t\t\033[31mUnable to open file!\033[0m" << endl;
		return;
	}

	// Write the transaction details to the file
	while (counting < MAX_ITEMS && getline(inFile, selectedfoodcodeList_Trans[counting]) &&
		getline(inFile, selectedfoodnameList_Trans[counting]) &&
		getline(inFile, selectedfoodpriceList_Trans[counting]) &&
		getline(inFile, selectedfoodquantityList_Trans[counting]) &&
		getline(inFile, dateList[counting]) &&
		getline(inFile, totalpriceList[counting])) {
		counting++;
	}

	inFile.close();

	for (int x = 0; x < counting; x++) {
		outFile
			<< latest_transaction_num++ << endl
			<< selectedfoodcodeList_Trans[x] << endl
			<< selectedfoodnameList_Trans[x] << endl
			<< selectedfoodpriceList_Trans[x] << endl
			<< selectedfoodquantityList_Trans[x] << endl
			<< dateList[x] << endl
			<< totalpriceList[x] << endl;
	}

	outFile.close();

	ofstream outFile2("transaction_history_backup.txt");
	outFile2 << "";
	outFile2.close();

	ofstream outFile5("transaction_number.txt");
	outFile5 << latest_transaction_num + counting;
	outFile5.close();



	cout << "\033[1;33;5m\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t__________                 __               .__                \n";
	cout << "\t\t\t\t\t\t\t\t\\______   \\ ____   _______/  |_  ___________|__| ____    ____  \n";
	cout << "\t\t\t\t\t\t\t\t |       _// __ \\ /  ___/\\   __\\/  _ \\_  __ \\  |/    \\  / ___\\ \n";
	cout << "\t\t\t\t\t\t\t\t |    |   \\  ___/ \\___ \\  |  | (  <_> )  | \\/  |   |  \\/ /_/  >\n";
	cout << "\t\t\t\t\t\t\t\t |____|_  /\\___  >____  > |__|  \\____/|__|  |__|___|  /\\___  / \n";
	cout << "\t\t\t\t\t\t\t\t        \\/     \\/     \\/                            \\/ ____/  ";

	this_thread::sleep_for(chrono::seconds(1));
	cout << " o O o";
	this_thread::sleep_for(chrono::seconds(1));
	cout << " O o O";
	this_thread::sleep_for(chrono::seconds(1));
	cout << " o O o\033[0m";
	this_thread::sleep_for(chrono::seconds(1));
	system("cls");
	cout << "\033[1;92;5m\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t  _________                       .__          __             .___._. \n";
	cout << "\t\t\t\t\t\t\t\t\\_   ___ \\  ____   _____ ______ |  |   _____/  |_  ____   __| _/| | \n";
	cout << "\t\t\t\t\t\t\t\t/    \\  \\/ /  _ \\ /     \\\\____ \\|  | _/ __ \\   __\\/ __ \\ / __ | | | \n";
	cout << "\t\t\t\t\t\t\t\t\\     \\___(  <_> )  Y Y  \\  |_> >  |_\\  ___/|  | \\  ___// /_/ | \\|\\|\n";
	cout << "\t\t\t\t\t\t\t\t \\______  /\\____/|__|_|  /   __/|____/\\___  >__|  \\___  >____ | __\n";
	cout << "\t\t\t\t\t\t\t\t        \\/             \\/|__|             \\/          \\/      \\/ \\/\n\033[0m";


}





