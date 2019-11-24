#include "cpu.h"

CPU::CPU()
{

}

int CPU::step(int)
{

}

void CPU::block(int)
{

}

void CPU::unblock()
{

}

void CPU::quit()
{

}

void CPU::print()
{

}

void CPU::add()
{

}

void CPU::substract()
{

}

void CPU::define()
{

}

void CPU::block()
{

}

void CPU::exit()
{

}

void CPU::run(string filename)
{
    Prozess* p = new Prozess();
    try {
        p->setBefehle(readfile(filename));
    } catch (const char* r) {
        cout << r << endl;
    }

    aktiveProzesse.push_back(p);
    pc = p->getPc();
    reg = p->getReg();
    p->incrementLaufzeit();
}

vector<vector<string>> CPU::readfile(const string &filename)
{
    string str1, str2 = " ";

    ifstream file;
        stringstream stream;
        string line;
        file.open(filename.c_str(), ios::in);
        getline(file, line);
        vector<vector<string>>tmpBefehle;

        if(!file){
            throw "could not be opened";
        }
        while(getline(file, line))
        {

            getline(file, line);
            stream.clear();
            stream << line;

            getline(stream, str1, ' ');
            getline(stream, str2);


            for(int i = 0; i <tmpBefehle.size(); i++){
                for(int j = 0; j<tmpBefehle.size(); j++){
                    tmpBefehle[i].push_back(str1);
                    tmpBefehle[i].push_back(str2);
                }
            }

            stream.clear();
        }
        file.close();

        return tmpBefehle;

}
