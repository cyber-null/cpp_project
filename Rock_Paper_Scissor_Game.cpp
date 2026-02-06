#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <string>
#include <cctype>
#include <string>
using namespace std;


// functions //
bool winner(string engine_answer, string user_answer);


// toLowerCase function
string toLowerCase(string str){
  for (char &c : str)
    c = tolower(c);
  return str;
}

// 
const string game[3] = {"Rock", "Paper", "Scissor"};
 

int main(){
  string user_answer;
  char answer;

  cout << "|------|-------|---------|" << endl;
  cout << "| Rock | Paper | Scissor |" << endl;
  cout << "|------|-------|---------|" << endl;

  while (true) {

    // continue or not
    cout << "Do you wanna play this game? (y or n): ";
    cin >> answer;
    if (answer != 'y')
      break;


    cout << "Rock, Paper, Scissor : ";
    cin >> user_answer; 

    // to toLowerCase string
    user_answer = toLowerCase(user_answer);

    // check for Invalid input
    if (user_answer != "rock" && user_answer != "paper" && user_answer != "scissor"){
      cout << "Invalid input!" << endl;
      continue;
    }

    // ------------------------------
    // create rand engine answer(Old)
    //srand(time(nullptr));
    //int rand_number = (rand() % 3);
    //-------------------------------

    //------------------------------------
    // creat rand engine answer(New)
    // this a 
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 2);
    
    int rand_number = distr(gen);
    //------------------------------------


    // creat game engine answer
    string engine_answer = game[rand_number];


    // check answer
    if (engine_answer == user_answer){
      cout << endl;

      cout << "| engine_answer | " << engine_answer << endl;
      cout << "| user_answer   | " << user_answer << endl;

      cout << "\n\t*---------------*";
      cout << "\n\t| this a equal! |";
      cout << "\n\t*---------------*" << "\n\n";
    }

    else
     winner(engine_answer, user_answer);
  }
  
  cout << "*-----------------------------*" << endl;
  cout << "| Okay then have good time :) |" << endl;
  cout << "*-----------------------------*" << endl;
  return 0;
}


bool winner(string engine_answer, string user_answer){
  //engine_answer = toLowerCase(engine_answer);
  //user_answer = toLowerCase(user_answer);


  if ((engine_answer == "rock" && user_answer == "scissor") ||
      (engine_answer == "scissor" && user_answer == "paper") ||
      (engine_answer == "paper" && user_answer == "rock")) {

    cout << endl;

    cout << "| engine_answer | " << engine_answer << endl;
    cout << "| user_answer   | " << user_answer << endl;

    cout << "\n\t*---------------------*";
    cout << "\n\t| Sorry, You lose! :) |";
    cout << "\n\t*---------------------*" << "\n\n";
  }

  else {
    cout << endl;

    cout << "| engine_answer | " << engine_answer << endl;
    cout << "| user_answer   | " << user_answer << endl;

    cout << "\n\t*-----------------*"; 
    cout << "\n\t| Yay!, You WIN!! |";
    cout << "\n\t*-----------------*" << "\n\n"; 
  }

  return true;
}
