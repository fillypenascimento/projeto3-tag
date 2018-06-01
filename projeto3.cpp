#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <fstream>
#include <queue>
#include <map>

using namespace std;
class Graph{
    map<list<int>, list<string>> professores;
    map<string, list<int>> escolas_contratantes;

    public:
    void inicializaMaps(){
        string line, number, escola;
        list<int> professor, info_escola;
        list<string> escolas;
        ifstream file("entrada.txt");
        int i, j, prof_number, habilitacao, vagas, aux;
        char char_aux;

        while (getline(file, line)){
            line.push_back('\n');
            if(line.size() <= 36 && line.size() > 14){
                i=2;
                j=0;
                while(line[i] != ','){
                    number[j] = line[i];
                    j++;
                    i++;
                }
                prof_number = stoi(number);
                professor.push_back(prof_number);
                i+=2;
                number = line[i];
                habilitacao = stoi(number);
                professor.push_back(habilitacao);

                cout << prof_number << " " << habilitacao << "\n";

                i+=5;
                j=0;
                aux = i;

                do{
                    // cout << line[i] << "\n";
                    if(line[i] != ',' && line[i] != ')'){
                        // cout << "entrei nessa merda\n";
                        // escola[j] += line[i];
                        i++;
                        j++;
                        // cout << i << '\n';
                    }
                    else{
                        escola = line.substr(aux, j);
                        // cout << escola << "\n";
                        escolas.push_back(escola);
                        escola.clear();
                        i+=2;
                        j=0;
                        aux = i;
                    }
                    if(i>line.size()-1){
                        i = line.size()-1;
                    }
                }while(line[i] != '\n');

                for (auto v : escolas){
                    cout << v << " ";
                }

                professores[professor] = escolas;

                cout << "\n";
                professor.clear();
                escolas.clear();
            }
            else if(line.size() < 15){
                i=1;
                j=0;
                // cout << line[i] << "\n";
                while(line[i] != '\n'){
                    if(line[i] != ')'){
                        j++;
                    }
                    else{
                        escola = line.substr(1, j);
                        // cout << escola << "\n";
                        i+=3;
                        number = line.substr(i, 1);
                        habilitacao = stoi(number);
                        // cout << habilitacao << "\n";
                        info_escola.push_back(habilitacao);

                        i+=4;
                        number = line.substr(i, 1);
                        vagas = stoi(number);
                        // cout << vagas << "\n";
                        info_escola.push_back(vagas);

                        escolas_contratantes[escola] = info_escola;
                        i++;
                    }
                    i++;
                }
            }
        }

        cout << professores.size() << "\n";
        cout << escolas_contratantes.size() << "\n";
    }
};

int main(){
    Graph gbipart;
    gbipart.inicializaMaps();
}