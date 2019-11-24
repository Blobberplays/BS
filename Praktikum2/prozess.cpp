#include "prozess.h"

Prozess::Prozess(int ppid, int laufzeit, int pc, int reg, int prio, int startzeit)
{
    static int id = 0;
    this->pid = id++;
    this->ppid = ppid;
    this->laufzeit = laufzeit;
    this->pc = pc;
    this->reg = reg;
    this->prio = prio;
    this->startzeit = startzeit;
}

int Prozess::getPid() const
{
    return pid;
}

void Prozess::setPid(int value)
{
    pid = value;
}

int Prozess::getPpid() const
{
    return ppid;
}

void Prozess::setPpid(int value)
{
    ppid = value;
}

int Prozess::getLaufzeit() const
{
    return laufzeit;
}

void Prozess::setLaufzeit(int value)
{
    laufzeit = value;
}

int Prozess::getPc() const
{
    return pc;
}

void Prozess::setPc(int value)
{
    pc = value;
}

int Prozess::getReg() const
{
    return reg;
}

void Prozess::setReg(int value)
{
    reg = value;
}

int Prozess::getPrio() const
{
    return prio;
}

void Prozess::setPrio(int value)
{
    prio = value;
}

int Prozess::getStartzeit() const
{
    return startzeit;
}

void Prozess::setStartzeit(int value)
{
    startzeit = value;
}

vector<vector<string> > Prozess::getBefehle() const
{
    return befehle;
}

void Prozess::setBefehle(const vector<vector<string> > &value)
{
    befehle = value;
}

void Prozess::incrementLaufzeit()
{
    laufzeit++;
}
