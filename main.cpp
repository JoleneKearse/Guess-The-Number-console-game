#include <iostream>
#include <cstdlib>
using namespace std;

bool checkGuess(int guess, int target)
{
  if (guess == target)
  {
    cout << "Right on!" << endl;
    return false;
  }
  else if (guess > target)
  {
    cout << "Too high!" << endl;
  }
  else
  {
    cout << "Too low!" << endl;
  }

  return true;
}

// check if input successful and if cin entered fail state
bool validateInput(int &number) //  take reference to input to modify if necessary
{
  if (cin.fail())
  {
    cout << "Invalid input! Please enter a number." << endl;
    cin.clear();           // clear the fail state
    cin.ignore(100, '\n'); // ignore any remaining chars in input buffer
    return false;
  }
  return true;
}

int main()
{
  cout << "Welcome to the Number Guessing Game!" << endl;
  int guess;
  int minNum;
  int maxNum;

  while (true)
  {
    cout << "Choose the lowest possible number:" << endl;
    cin >> minNum;
    if (validateInput(minNum))
    {
      break;
    }
  }

  while (true)
  {
    cout << "Choose the highest: " << endl;
    cin >> maxNum;
    if (validateInput(maxNum))
    {
      break;
    }
  }

  srand(time(nullptr));
  int target = minNum + (rand() % maxNum);

  bool stillGuessing = true;

  while (stillGuessing)
  {
    cout << "Guess a decimal number from " << minNum << " to " << maxNum << " : " << endl;
    cin >> guess;

    if (!validateInput(guess))
    {
      continue;
    }

    if (guess < minNum || guess > maxNum)
    {
      cout << "Invalid! Please enter a number between " << minNum << " and " << maxNum << "." << endl;
      continue;
    }

    stillGuessing = checkGuess(guess, target);
  }

  return 0;
}
