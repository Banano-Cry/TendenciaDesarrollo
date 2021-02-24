#include <iostream>
#include <vector>

using namespace std;

struct group{
  vector<string> students;
  vector<string> topics;
};

void printGroup(vector<string> students){
    for(string x: students){
      cout << x << endl;
    }
    cout << endl;
}

void printAllGroups(group group[], int count){
  for(int i = 0; i < count;i++){
    cout << "Grupo " << i+1 << ": " << group[i].students.size() << " Estudiantes y " << group[i].topics.size() << " Temas" << endl;
    cout <<"Estudiantes: "<<endl;
    for(string students : group[i].students)
      cout << "\t" << students << endl;
      cout << "Temas: " << endl;
    for(string topics : group[i].topics)
      cout << "\t" << topics << endl;
      cout << "\n\n" <<endl;
  }
}
