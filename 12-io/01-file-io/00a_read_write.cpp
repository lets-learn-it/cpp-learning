#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream infile;
  ofstream outfile;

  const char *read_from = "./resources/text.txt";
  const char *write_to = "./resources/copied_text.txt";

  infile.open(read_from);
  outfile.open(write_to);

  string str;

  if (infile.is_open() && outfile.is_open()) {
    while(getline(infile, str)) {
      cout << str << endl;
      outfile << str << endl;
    }
    outfile.close();
    infile.close();
  } else {
    cerr << "files not opened." << endl;
  }
}