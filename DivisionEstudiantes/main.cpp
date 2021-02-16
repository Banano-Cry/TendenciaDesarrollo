#include <iostream>
#include <vector>
#include "file.h"
#include "group.h"
#include <time.h>

using namespace std;

void usage(char *argv[]){
  cout << "Uso del programa --> " << argv[0] << " [student path] [topics path] [# group]" << endl;
  exit(-1);
}

vector<int> groupRest(int count){
  vector<int> groupNumber;
  for(int i = 0; i < count; i ++){
    groupNumber.push_back(i);
  }
  return groupNumber;
}

void randomGroups(vector<string> students, vector<string> topics, group groups[], int count){
  int numStudents = fileSize(students);
  srand(time(NULL));
  for(int i = 0; i < numStudents - numStudents%count; i++){
    int random = rand();
    int select = i%count;
    groups[select].students.push_back(students[random%fileSize(students)]);
    students.erase(students.begin()+random%fileSize(students));
  }
  cout << "paso" << endl;
  if(fileSize(students) > 0){
    int numStudentsRest = count;
    vector<int> num = groupRest(numStudentsRest);
    for(int i = 0; i < fileSize(students); i ++){
      int random = rand();
      int select = random%numStudentsRest;
      groups[num[select]].students.push_back(students[i]);
      num.erase(num.begin()+select);
      numStudentsRest--;
    }
  }

  //Seleccion temas
  int numTopics = fileSize(topics);
  for(int i = 0; i < numTopics - numTopics%count; i++){
    int random = rand();
    int select = i%count;
    groups[select].topics.push_back(topics[random%fileSize(topics)]);
    topics.erase(topics.begin()+random%fileSize(topics));
  }
  if(fileSize(topics) > 0){
    vector<int> num = groupRest(count);
    int numTopicsRest = count;
    for(int i = 0; i < fileSize(topics); i ++){
      int random = rand();
      int select = random%numTopicsRest;
      groups[num[select]].topics.push_back(topics[i]);
      num.erase(num.begin()+select);
      numTopicsRest--;
    }
  }

  //Imprimir todo
  printAllGroups(groups, count);
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
  randomGroups(students, topics, groups, atoi(argv[3]));
  return 0;
}
