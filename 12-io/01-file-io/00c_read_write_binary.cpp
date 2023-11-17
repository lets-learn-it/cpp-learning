#include<iostream>
#include<fstream>
using namespace std;

#pragma pack(push,1)  // turns off padding / pack  of struct
// without pragma sizeof(Person) = 64 and with 62
struct Person {
  char name[50];
  int age;
  double weight;
};

#pragma pack(pop)

int main() {
  const char * filename = "test.bin";

  Person someone = {"Parikshit",220,72};

  ofstream outputFile;

  outputFile.open(filename,ios::binary);

  if(outputFile.is_open()){
    outputFile.write((char *)&someone,sizeof(Person));
    // outputFile.write(reinterpret_cast<char *>(&someone),sizeof(Person));
    outputFile.close();
  } else{
    cout<< "Could not create file" << filename;
  }

  // reading from file
  Person someoneElse = {};

  ifstream inputFile;

  inputFile.open(filename,ios::binary);

  if(inputFile.is_open()){
    inputFile.read((char *)&someoneElse,sizeof(Person));
    inputFile.close();
  } else{
    cout<< "Could not create file" << filename;
  }

  cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.weight << endl;

  return 0;
}