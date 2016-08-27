//CS3505 Assignment 1, 8/26/16
//@author Tyler Dailey, u0765892
#include <iostream>

using namespace std;

//Define the four helper methods, that will be called from within the main method.
void updatePopulations(double g, double K, double p, double m, double c, double &numRabbits, double &numFoxes);
void incrementCounter(int*);
void plotCharacter(int, char);
void chart(double, double, double);

//This method prompts the user for initial values for the populations of the foxes and rabbits,
//and then it calls the chart, updatePopulations, and incrementCounter helper methods within a loop
//which runs up to 500 times.
int main(){

  //Initialize the variables that will be used in this method.
  double numFoxes = 0;
  double numRabbits = 0;
  double rabbitGrowth = 0.2;
  double predationRate = 0.002;
  double foxPreyConversion = 0.6;
  double foxMortalityRate = 0.2;
  double carryCapacity = 1000.0;

  cout << "Please enter values for the initial Fox and Rabbit Populations: " << endl;

  int numSimulations = 0;

  //If the input stream parses as two ints, then compute and plot the populations,
  //otherwise inform the user of their invalid entires, and terminate the program.
  if(cin >> numFoxes && cin >> numRabbits){
    while(numSimulations < 500 && numFoxes > 0 && numRabbits > 0){
      chart(numRabbits, numFoxes, 0.1);
      updatePopulations(rabbitGrowth, carryCapacity, predationRate, foxMortalityRate, foxPreyConversion, numRabbits, numFoxes);
      int* ptr = &numSimulations;
      incrementCounter(ptr);
    }
    return 0;
  }
  else{
    cout << "Invalid entries..." << endl;
    return 1;
  }
}

//Takes in all of the environmental factors pertinent to the approximation of the fox and rabbit populations,
//then computes the new populations for both, and then updates the populations.
void updatePopulations(double g, double K, double p, double m, double c, double &rabbits, double &Foxes){
  double R = rabbits;
  double F = Foxes;
  rabbits = R + (g*R*(1-(R/K))-(p*R*F));
  Foxes = F + (c*p*R*F - m*F);
}

//Takes in the number of Rabbits, the number of Foxes, and a scalar factor, and then creates
//a line where an r is placed rabbits*scalar spaces from the left, and an F is placed foxes*scalar
//spaces from the left. In the event that thos two numbers are equal, a single * character will be
//placed in the line.
void chart(double rabbits, double Foxes, double scale){
  string line = "";
  int foxSpaces = Foxes*scale;
  int rabbitSpaces = rabbits*scale;
  
  //Check to see whether the two populations are equal, in which case a '*' is placed
  // the appropriate number of spaces from the left.
  if(foxSpaces == rabbitSpaces){
    plotCharacter(foxSpaces, '*');
    cout << endl;
  }
  //If there are fewer Foxes than rabbits place an 'F' the appropriate spaces from the left,
  //then figure out how many remaining spaces are appropriate for a rabbit and place an 'r'.
  else if(foxSpaces < rabbitSpaces){
    plotCharacter(foxSpaces, 'F');
    rabbitSpaces = rabbitSpaces - foxSpaces;
    plotCharacter(rabbitSpaces, 'r');
    cout << endl;
  }
  //If there are fewer rabbits than Foxes place an 'r' the appropriate spaces from the left,
  //then figure out how many remaining spaces are appropriate for a Fox and place an 'F'.
  else{
    plotCharacter(rabbitSpaces, 'r');
    foxSpaces = foxSpaces - rabbitSpaces;
    plotCharacter(foxSpaces, 'F');
    cout << endl;
  }
}

//Helper method called in the main method to increment the counter.
//Used in order to practice using pointers in c++.
void incrementCounter(int* ptr){
  *ptr = *ptr + 1;
}

//Takes in an int n, and a char c, creates a line of (n-1) spaces follwed by c.
//It then sends this line to cout, without and end of line character. 
void plotCharacter(int spaces, char c){
  string line = "";
  while(spaces > 1){
    line = line + " ";
    spaces--;
  }
  line = line + c;
  cout << line;
}
    

  
