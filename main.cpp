#include <iostream>
#include <vector>

using namespace std;

void usage(char *argv[]){
  cout << "Uso del programa --> " << argv[0] << " [student path] [topics path] [# group]" << endl;
  exit(-1);
}

int main(int argc, char *argv[]){
  if(argc < 3){
    usage();
  }



  return 0;
}
