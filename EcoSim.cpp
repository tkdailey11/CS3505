#include <iostream>

using namespace std;

double numFoxes = 0;
double numRabbits = 0;

//Parameters for testing the update Population method.
double g = 0.2;
double K = 1000;
double p = 0.002;
double m = 0.2;
double c = 0.6;

void updatePopulations(double g, double p, double c, double m, double K, double &numRabbits, double &numFoxes);
void incrementCounter(int*);
void plotCharacter(int, char);
void chart(double, double, double);

int main(){
  cout << "Please enter a value for the initial Fox population: " << endl;
  cin >> numFoxes;
  cout << "Please enter a value for the initial Rabbit population: " << endl;
  cin >> numRabbits;

  int numSimulations = 0;

  while(numSimulations < 500 && numFoxes > 0 && numRabbits > 0){
    chart(numRabbits, numFoxes, 0.1);
    updatePopulations(g, K, p, m, c, numRabbits, numFoxes);
    int* ptr = &numSimulations;
    incrementCounter(ptr);
    //cout << "Rabbits: " << numRabbits << " Foxes: " << numFoxes << endl;
  }
}

void updatePopulations(double g, double K, double p, double m, double c, double &R, double &F){
  R = numRabbits;
  F = numFoxes;
  numRabbits = R + (g*R*(1-(R/K))-(p*R*F));
  numFoxes = F + (c*p*R*F - m*F);
}

/*
  Takes in the number of Rabbits, the number of Foxes, and a scalar factor, and then creates
  a line where an r is placed rabbits*scalar spaces from the left, and an F is placed foxes*scalar
  spaces from the left. In the event that thos two numbers are equal, a single * character will be
  placed in the line.
*/
void chart(double rabbits, double Foxes, double scale){
  string line = "";
  int foxSpaces = Foxes*scale;
  int rabbitSpaces = rabbits*scale;
  
  if(foxSpaces == rabbitSpaces){
    plotCharacter(foxSpaces, '*');
    cout << endl;
  }
  else if(foxSpaces < rabbitSpaces){
    plotCharacter(foxSpaces, 'F');
    rabbitSpaces = rabbitSpaces - foxSpaces;
    plotCharacter(rabbitSpaces, 'r');
    cout << endl;
  }
  else{
    plotCharacter(rabbitSpaces, 'r');
    foxSpaces = foxSpaces - rabbitSpaces;
    plotCharacter(foxSpaces, 'F');
    cout << endl;
  }
}

void incrementCounter(int* ptr){
  *ptr = *ptr + 1;
}

void plotCharacter(int spaces, char c){
  string line = "";
  while(spaces > 1){
    line = line + " ";
    spaces--;
  }
  line = line + c;
  cout << line;
}
    

  
