#include <iostream>
#include <vector>
#include "random.h"
#include <time.h>

using namespace std;

void usage(char *argv[]){
  cout << "Uso del programa --> " << argv[0] << " [student path] [topics path] [# group]" << endl;
  exit(-1);
}

void verifyInput(int students, int topics, int groups){
  if(students < groups){
    cout << "La cantidad de estudiantes es menor a la cantidad de grupos" << endl;
    exit(-1);
  }
  if(topics < groups){
    cout << "La cantidad de temas es menor a la cantidad de grupos" << endl;
    exit(-1);
  }
}

int main(int argc, char *argv[]){
  if(argc < 4){
    usage(argv);
  }
  vector<string> students = readFile(argv[1]);
  vector<string> topics = readFile(argv[2]);
  verifyInput(students.size(),topics.size(), atoi(argv[3]));
  group groups[atoi(argv[3])];
  srand(time(NULL));
  randomGroups(students, topics, groups, atoi(argv[3]));
  printAllGroups(groups,atoi(argv[3]));
  return 0;
}
