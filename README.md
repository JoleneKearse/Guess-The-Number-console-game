# Number Guessing Game
## Made in C++

This is a learning app for me.  I completed 2 Beginner's C++ courses, then had **ChatGPT** generate a list of practice apps for me to build.  I prompted it with the concepts I had learned, what I wanted more practice with, and sample projects already completed.

This is the third in the list. I got to expand my skills above and beyond.

###Demo
Coming Soon!

##How to Play
- Install a C++ Compiler
On Linux, or WSL2, *like me*, enter the following in your terminal:
```
sudo apt-get update
sudo apt-get install gcc
sudo apt-get install g++
```
- Get all the necessary C++ libraries with:
```
sudo apt-get install build-essential
```
- You can verify all went well with:
```
g++ --version
```
- Fork this repo
- Compile it in your terminal with:
```
g++ main.cpp -o main
```
- Run with:
```
./main
```

###MVP
Here is the AI-generated challenge:
> Guessing Game: Develop a number guessing game where the program generates a random number, and the user tries to guess it. Provide feedback to the user, indicating if their guess is too high or too low, until they guess the correct number.

###MVP Path
- [x]  Get user input
```c++
int guess;
cout << "Guess a decimal number from 1 - 10 : " << endl;
cin >> guess;
```
- [x]  Generate a random number
```c++
int minNum = 1;
int maxNum = 10;
srand(time(nullptr));
int target = minNum + (rand() % maxNum);
```
- [x]  Provide input to user 
```c++
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
```

###Extras
1.  I wanted to validate the numbers entered weren't too high or low.
```c++
if (guess < minNum || guess > maxNum)
{
  cout << "Invalid! Please enter a number between " 
  << minNum << " and " << maxNum << "." << endl;
}
```
2. I also wanted to prevent non-numeric characters, and pulled this out as a separate function, when I noticed I would need it somewhere else.
```c++
bool validateInput(int &number) //  take reference to input to modify if necessary
{
  if (cin.fail())
  {
    cout << "Invalid input! Please enter a number." << endl;
    cin.clear(); // clear the fail state
    cin.ignore(100, '\n'); // ignore any remaining chars in input buffer
    return false;
  }
  return true;
}
```
This was so much fun, because it introduced me to functions of `cin`, including:
- `.fail()`, which checks if the input stream has raised an error,
- `.clear()` to remove all elements, and
- `.ignore()` ignores characters in the input buffer
3. I had to research the **while loop** and was happy to find it's pretty much the same as other languages!
```c++
bool stillGuessing = true;

while (stillGuessing)
{
  // elicit guess
  if (guess < minNum || guess > maxNum)
  {
    cout << "Invalid! Please enter a number between " 
    << minNum << " and " << maxNum << "." << endl;
    continue;
  }

  stillGuessing = checkGuess(guess, target);
  return 0;
}
```
4. Have user enter lowest possible number and highest. I also needed a while loop here, in case they had invalid input.

