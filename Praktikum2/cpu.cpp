#include "cpu.h"

CPU::CPU(int pc2, int reg2, int id2)
    : pc(pc2),reg(reg2),id(id2)
{

}
//Befehlssatz User
int CPU::step(int)
{

}

void CPU::unblock()
{

}

void CPU::block(int)
{

}

void CPU::print()
{

}

void CPU::quit()
{

}

//Befehlssatz CPU
void CPU::add(int i)
{
    reg+=i;
    pc++;
}

void CPU::substract(int i)
{
    reg-=i;
    pc++;
}

void CPU::define(int i)
{
    reg=i;
    pc++;
}

void CPU::block()
{

}

void CPU::exit()
{
//
    for(int i = 0;i<aktiveProzesse.size();i++){
        if(aktiveProzesse.at(i)->getPid()==id){//suche nach aktive prozess
            if(aktiveProzesse.at(i)->getPpid() >= 0){//hat das prozess ein parent
                id=aktiveProzesse.at(i)->getPpid();//setze parent id als aktiv

                for(int j = 0;j<blockierteProzesse.size();j++){//suche nach parent id in blockierte prozesse
                    if(blockierteProzesse.at(j)->getPid()==aktiveProzesse.at(i)->getPpid()){
                        pc=blockierteProzesse.at(j)->getPc();
                        reg=blockierteProzesse.at(j)->getReg();
                        break;
                    }else{
                        cout << "error beim suche von parent"<<endl;
                    }
                }
                aktiveProzesse.push_back(blockierteProzesse.at(id));//setzte Parent als aktiv
                blockierteProzesse.at(i)->~Prozess();//loesche kind

            }
            if(aktiveProzesse.at(i)->getPpid() == -1){
                cout<<"no more processes"<<endl;
                exit();//verlasse das programm
            }
        }
    }
}

void CPU::run(string filename)
{
    Prozess* p = new Prozess();
    try {
        p->befehlePair=readfile(filename);
    } catch (const char* r) {
        cout << r << endl;
    }
   if(p->getPid()==0){//erste prozess?
    aktiveProzesse.push_back(p);

    pc = p->getPc();
    reg = p->getReg();
    p->incrementLaufzeit();
   }
   else{
       aktiveProzesse.push_back(p);
       p->setPpid(id);
       pc = p->getPc();
       reg = p->getReg();
       p->incrementLaufzeit();
   }
}

vector<pair<string,string>>& CPU::readfile(const string &filename)
{
    string str1, str2 = " ";

    ifstream file;
        stringstream stream;
        string line;
        file.open(filename.c_str(), ios::in);
        //getline(file, line);
        vector<pair<string,string>> *tmpBefehle = new vector<pair<string,string>>;

        if(!file){
            throw "could not be opened";
        }
        while(getline(file, line))
        {
            stream.clear();
            stream << line;

            getline(stream, str1, ' ');
            getline(stream, str2);

            tmpBefehle->push_back(make_pair(str1,str2));
            stream.clear();
        }
        file.close();

        return *tmpBefehle;
}

Prozess *CPU::findAktiveProzess(int id)
{
    for(int i =0;i<aktiveProzesse.size();i++){
        if(id==aktiveProzesse.at(i)->getPid()){
            return aktiveProzesse.at(i);
        }else{
            return nullptr;
        }
    }
}

Prozess *CPU::findBlockierteProzess(int id)
{
    for(int i =0;i<blockierteProzesse.size();i++){
        if(id==blockierteProzesse.at(i)->getPid()){
            return blockierteProzesse.at(i);
        }else{
            return nullptr;
        }
    }
}

int CPU::getId() const
{
    return id;
}

void CPU::setId(int value)
{
    id = value;
}

int CPU::getReg() const
{
    return reg;
}

void CPU::setReg(int value)
{
    reg = value;
}

int CPU::getPc() const
{
    return pc;
}

void CPU::setPc(int value)
{
    pc = value;
}
