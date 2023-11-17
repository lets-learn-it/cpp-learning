#include<iostream>
#include<fstream>
using namespace std;

int main() {
  const string filename = "./resources/population.txt";
  ifstream inputStream;
  inputStream.open(filename);

  if(!inputStream.is_open()){
    return 1;
  }

  string line;

  while(getline(inputStream,line,':')) {
    int population;
    inputStream >> population;

    if(!inputStream){
      break;
    }

    cout << line << " : " << population << endl;
  }

  return 0;
}