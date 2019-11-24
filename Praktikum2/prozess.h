#ifndef PROZESS_H
#define PROZESS_H
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Prozess
{
public:
    Prozess(int ppid = 0, int laufzeit = 0, int pc = 0, int reg = 0, int prio = 0, int startzeit = 0);

    int getPid() const;
    void setPid(int value);

    int getPpid() const;
    void setPpid(int value);

    int getLaufzeit() const;
    void setLaufzeit(int value);

    int getPc() const;
    void setPc(int value);

    int getReg() const;
    void setReg(int value);

    int getPrio() const;
    void setPrio(int value);

    int getStartzeit() const;
    void setStartzeit(int value);

    vector<vector<string> > getBefehle() const;
    void setBefehle(const vector<vector<string> > &value);

    void incrementLaufzeit();

private:
    int pid = NULL;
    int ppid = NULL;
    int laufzeit = NULL;
    int pc = NULL;
    int reg = NULL;
    int prio = NULL;
    int startzeit = NULL;
    vector<vector<string>>befehle;
};

#endif // PROZESS_H
