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
    Prozess(int ppid = -1, int laufzeit = 0, int pc = 0, int reg = 0, int prio = 0, int startzeit = 0);
    ~Prozess();
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

    vector<pair<string,string>> befehlePair;
private:
    int pid = 0;
    int ppid = 0;
    int laufzeit = 0;
    int pc = 0;
    int reg = 0;
    int prio = 0;
    int startzeit = 0;
    vector<vector<string>>befehle;

};

#endif // PROZESS_H
