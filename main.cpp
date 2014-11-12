#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main()
{
    int y = 0, m = 0, n = 100; //used for storing attempts and hints
    int a, x;
    srand(time(NULL));
    x = rand() % 100 + 1;

    while (a != x) //loop for user input
    {
        cout << "Guess a number: ";
        cin >> a;
        
        while (cin.fail()) //loop for an invalid input (so people only use int numbers)
        {
            cout << "Invalid Entry\nOnly enter full number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> a;
        }
        y++; //adds 1 to attempts

        if (a < x) //changes the hint numbers for help
        {
            m = (m < a)? a : m;
        } else
        {
            n = (n > a)? a : n;
        }
        cout << "That's not a correct number. Hint: [" << m << "," << n << "]" << endl;
    }
    //If the number is guessed, this gets outputed
    cout << "Number " << a << " is correct. Number of attempts: " << y << endl;

    cout << "Click 'Enter' to exit" << endl;
    fflush(stdin);
    cin.get();
    return 0;
}
