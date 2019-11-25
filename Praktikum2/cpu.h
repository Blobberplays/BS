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
    CPU(int pc = 0, int reg = 0, int id = 0);
    void step(int);
    void block(int);
    void unblock();
    void quit();
    void print();

    void add(int i);
    void substract(int i);
    void define(int i);
    void block();
    void exit();
    void run(string);
    vector<pair<string,string>>& readfile(const string &filename);
    Prozess* findAktiveProzess(int id);
    Prozess* findBlockierteProzess(int id);
    bool deleteFromAktiveProzesse(int id);
    bool deleteFromBlockierteProzesse(int id);

    int getId() const;
    void setId(int value);

    int getReg() const;
    void setReg(int value);

    int getPc() const;
    void setPc(int value);


//private:
    int id;
    int reg;
    int pc;
    vector<Prozess*>aktiveProzesse;
    vector<Prozess*>blockierteProzesse;
};

#endif // CPU_H
