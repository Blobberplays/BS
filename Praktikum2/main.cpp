#include <iostream>
#include "cpu.h"
#include "prozess.h"

using namespace std;

int main()
{
    CPU c;
    Prozess* runningProcess = nullptr;
    c.run("init.txt");

    while(1){

        runningProcess = c.findAktiveProzess(c.getId());
        if(runningProcess==nullptr){
            cout<<"no more aktiv processes";
            return 0;
        }
        while(1){

            if(runningProcess->befehlePair.at(c.getPc()).first=="D"){
                c.define(stoi(runningProcess->befehlePair.at(c.getPc()).second));
                break;
            }else if(runningProcess->befehlePair.at(c.getPc()).first=="A"){
                c.add(stoi(runningProcess->befehlePair.at(c.getPc()).second));
                break;
            }else if(runningProcess->befehlePair.at(c.getPc()).first=="S"){
                c.substract(stoi(runningProcess->befehlePair.at(c.getPc()).second));
                break;
            }else if(runningProcess->befehlePair.at(c.getPc()).first=="B"){

            }else if(runningProcess->befehlePair.at(c.getPc()).first=="X"){

            }else if(runningProcess->befehlePair.at(c.getPc()).first=="R"){
                c.run(runningProcess->befehlePair.at(c.getPc()).second);
                break;
            }else{
                cout<<"command not found"<<endl;
                break;
            }
        }
    }
    return 0;
}
