#include <iostream>
#include <cstdlib>
#include <time.h>
#include <limits>

using namespace std;

int main()
{
    int y = 0, m = 0, n = 100;
    int a, x;
    srand(time(NULL));
    x = rand() % 100 + 1;

    //loop that tests if the guess is correct
    while (a != x)
    {
        cout << "Guess a number: ";
        cin >> a;
        //loop for an invalid input (so people only use int numbers)
        while (cin.fail())
        {
            cout << "Invalid Entry\nOnly enter full number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> a;
        }
        y++; //counter for attempts
        //Saves data for hint
        if (a < x)
        {
            m = (m < a)? a : m;
        } else
        {
            n = (n > a)? a : n;
        }
        cout << "That's not a correct number. Hint: [" << m << "," << n << "]" << endl;
    }
    //If the number is guessed, this gets outputed
    cout << "Number " << a << "is correct. Number of attempts: " << y << endl;

    system("pause");
    return 0;
}
