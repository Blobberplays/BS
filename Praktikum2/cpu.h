#ifndef CPU_H
#define CPU_H
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "prozess.h"
#include "stdlib.h"

using namespace std;

/*struct Prozess{
  int pid = NULL;
  int ppid = NULL;
  int laufzeit = NULL;
  int pc = NULL;
  int reg = NULL;
  int prio = NULL;
  int startzeit = NULL;
  vector<vector<string>>befehle;
};*/

class CPU
{
public:
    CPU();
    int step(int);
    void block(int);
    void unblock();
    void quit();
    void print();
    void add();
    void substract();
    void define();
    void block();
    void exit();
    void run(string);
    vector<vector<string>> readfile(const string &filename);

private:
    int id;
    int reg;
    int pc;
    vector<Prozess*>aktiveProzesse;
    vector<Prozess*>blockierteProzesse;
};

#endif // CPU_H
