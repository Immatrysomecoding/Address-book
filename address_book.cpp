#include <iostream>
#include <string>
#include "record.h"
#include "llist.h"
#include "address_book.h"

void run_program() {
    llist records(get_file_name()); /* Lets user create their own .txt file */
    std::string input_name = "";
    std::string input_address = "";
    std::string input_phone = "";
    std::string dummy = "";
    int input_year = 0;
    int menu_selection = 0;

    display_commands();
    do { // do while menu_selection != 7
        menu_selection = get_menu_selection();
        switch (menu_selection) {
            case 1: // case 1 - add record
                std::cout << "--------------------\n";
                std::cout << "Add a new Record\n";
                input_name = get_name();
                input_address = get_address();
                input_year = get_birth_year();
                input_phone = get_phone_number();
                records.add_record(input_name, input_address, input_year, input_phone);
                break; // end case 1
            case 2: // case 2 - print specific record by name
                std::cout << "--------------------\n";
                std::cout << "Print Record(s) with the same name\n";
                input_name = get_name();
                records.print_record(input_name);
                break; // end case 2
            case 3: // case 3 - modify specific record by name
                std::cout << "--------------------\n";
                std::cout << "Modify Record(s) with the same name\n";
                input_name = get_name();
                input_address = get_address();
                std::getline(std::cin, dummy);
                //std::cin.getline(dummy, 4);
                input_phone = get_phone_number();
                records.modify_record(input_name, input_address, input_phone);
                break; // end case 3
            case 4: // case 4 - print all records
                std::cout << "--------------------\n";
                std::cout << "Printing Records...\n";
                records.print_all_records();
                break; // end case 4
            case 5: // case 5 - delete specific record by name
                std::cout << "--------------------\n";
                std::cout << "Delete Record(s) with the same name\n";
                input_name = get_name();
                records.delete_record(input_name);
                break; // end case 5
            case 6: // case 6 - recursively reverse order of linked list
                std::cout << "--------------------\n";
                std::cout << "Reversing the order of all the Records...\n";
                records.reverse_llist();
                break; // end case 6
        }
        if (menu_selection != 7) {
            display_commands();
        } // end if menu_selection != 7
    } while (menu_selection != 7); // end while
    return; // run_program return
}

void debug_function(int function_call, std::string name, std::string address, std::string phone_number, int year) {
    std::cout << "********************\n";
    if (function_call == 1) {
        std::cout << "llist::addRecord( " << name << ", " << address << ", " << year << ", " << phone_number << " );\n";
    } else if (function_call == 2) {
        std::cout << "llist::printRecord( " << name << " )n";
    } else if(function_call == 3) {
        std::cout << "llist::modifyRecord( " << name << ", " << address << ", " << phone_number << " );\n";
    } else if (function_call == 4) {
        std::cout << "llist::printAll( );\n";
    } else if (function_call == 5) {
        std::cout << "llist::deleteRecord( " << name << " )n";
    } else if (function_call == 6) {
        std::cout << "llist::reverse( );\n";
    } // end if function_call checks
    std::cout << "********************\n";
    return;
}

void display_commands() {
    std::cout << "Usage:\n";
    std::cout << "\t1: Add a new record into the database.\n";
    std::cout << "\t2: Print information about a record using the name as the key. \n";
    std::cout << "\t3: Modify a record in the database using the name as the key. \n";
    std::cout << "\t4: Print all information in the database.\n";
    std::cout << "\t5: Delete an existing record from the database.\n";
	std::cout << "\t6: Reverse the order of all existing records from the database.\n";
    std::cout << "\t7: Quit the program.\n";
    std::cout << "What would you like to do?\n";
    return; // display_commands return
}

int get_menu_selection() {
    // get_menu_selection
    int selection = 0;

    std::cin >> selection;
    while (std::cin.fail() || selection < 1 || selection > 7) { // while input is not valid
        if (std::cin.fail()) {
            std::cout << "Your input was not an integer. Please enter an integer: ";
        } else if ( selection < 1 || selection > 7) {
            std::cout << "Not a valid choice.\n";
            display_commands();
        }
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> selection;
    }
    std::cin.clear();
    return selection;
}

std::string get_name() {

    std::string name = "";

    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cout << "Please enter the person's NAME: ";
    std::getline(std::cin, name);

    return name;

std::string get_address() {

    std::string address = "";

    std::cout << "Please enter the person's ADDRESS (Enter '$' when you're finished):\n";
    std::getline(std::cin, address, '$');

    return address;
}

int get_birth_year() {

    int birth_year = 0;

    std::cout << "Please enter the person's BIRTH YEAR: ";
    std::cin >> birth_year;
    while (std::cin.fail()) { // while input is invalid
        std::cout << "Not an integer, please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> birth_year;

    std::cin.clear();
    std::cin.ignore(256, '\n');
    return birth_year; // get_birth_year return
}

std::string get_phone_number() {

    std::string phone_number = "";

    std::cout << "Please enter the contact's TELEPHONE NUMBER: ";
    std::getline(std::cin, phone_number);

    return phone_number; // get_phone_number return
}

std::string get_file_name() {

    std::string file_name = "";
    int count;

    std::cout << "Please enter your file name: ";
    std::getline(std::cin, file_name);
    file_name += ".txt";
    return file_name; // get_file_name and return
}
