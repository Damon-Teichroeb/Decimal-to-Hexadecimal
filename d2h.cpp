#include <iostream>
using namespace std;

#define ASCII_A    55 // ASCII code for the capital letter A.
#define ASCII_ZERO 48 // ASCII code for the number zero.
#define MAX_HEX    16 // Maximum number of hexadecimal digits.

// Asks the user if they want to convert another number.
bool again();

int main()
{
    unsigned long long decimal[MAX_HEX];
    short index = 0;

    do
    {
        // Gets the user's decimal number.
        cout << "\n\nPlease enter your number: ";
        cin  >> decimal[0];
        
        // Converts the decimal number into a hexadecimal number.
        while (decimal[index] > 0 && index < MAX_HEX)
        {
            if (index < MAX_HEX - 1) decimal[index+1] = decimal[index] / 16;
            decimal[index] = decimal[index] % 16;
            if (decimal[index] > 9) decimal[index] += ASCII_A;
            else                    decimal[index] += ASCII_ZERO;
            index++;
        }
        
        // Checks to see if the first and last index are reached.
        if      (index == 0)       decimal[index] = ASCII_ZERO;
        else if (index == MAX_HEX) index--;

        // Prints the hexadecimal number.
        cout << "\nYour hexadecimal number is: ";
        for (; index > 0; index--) cout << (char)decimal[index];
        cout << (char)decimal[index];
    }
    while (again()); // Asks if the user wants to convert another number.

    // Says good-bye and terminates the program.
    cout << "\n\nThanks for using my program!"
         <<   "\nHave a nice day! ;-)"
         << "\n\n\n";
    return 0;
}

// Asks the user if they want to convert another number.
bool again()
{
    char answer;

    cout << "\n\n\n";
    do
    {
        cout << "Would you like to convert another number? (y/n): ";
        cin  >> answer;
        answer = tolower(answer);
    }
    while (answer != 'y' && answer != 'n');
    return answer == 'y';
}