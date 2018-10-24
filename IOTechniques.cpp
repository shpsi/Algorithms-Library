// reading an entire binary file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  int size;
  char * memblock;

  ifstream file ("example.txt", ios::in|ios::binary|ios::ate);
  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [size+1];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();
    memblock[size]='\0';
    cout << "the entire file content is in memory\n"<<memblock<<endl;

    delete[] memblock;
  }
  else cout << "Unable to open file";
  return 0;
}
/*// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  return 0;
}*/
/*
// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile ("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}*/
/*// obtaining file size
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  int begin,end;
  ifstream myfile ("example.txt", ios::binary);
  begin = myfile.tellg();
  myfile.seekg (0, ios::end);
  end = myfile.tellg();
  myfile.close();
  cout << "size is: " << (end-begin) << " bytes.\n";
  return 0;
}*/
