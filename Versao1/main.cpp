#include "vaga.hpp"
#include "estagiario.hpp"
#include "empresa.hpp"
#include "sistema.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <map>

void separar_Str(std::vector<std::string>* be){
    std::string aux;
    char input;
    do {
        input = getchar(); // Lê um caractere do console
        if ((input == ','&&!(aux.empty()))||(input == '\n'&&!(aux.empty()))) {
            be->push_back(aux);
            aux.clear();
        } else if (input != '\n'&&!(input==' '&&aux.empty())&&input != ',') {
            aux+=input;
        }
    } while (input != '\n');
}

int main(){
    std::vector<std::string> ar={"vt","gympass","banheiro","va","vc"};
    std::vector<std::string> be={"vt","astolfo","banheiro","ricardo","vc"};
    std::vector<std::string> re={"dinheiro","gya","banheiro","fa","fe"};;
    std::map<std::string,std::pair<std::string, std::string>> conta;
    for(unsigned long int i=0;i<ar.size();i++)
        conta.insert(std::make_pair(ar[i],std::make_pair(be[i],re[i])));
    for(std::map<std::string,std::pair<std::string, std::string>>::iterator it=conta.begin();it!=conta.end();++it)
        std::cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<std::endl;
    Sistema asas;
    asas.cadastrar_empresa("1921484841", new Empresa("alacrim", conta ));
    asas.cadastrar_empresa("1921481211", new Empresa("outra", conta ));
    std::string email;
    std::string nome;
    std::string senha;
    std::cin>>email>>nome>>senha;
    asas.cadastrar_estagiario(email, nome, senha);
    asas.adicionar_vaga("1921484841", new Vaga(1212121, be, re));
    asas.adicionar_vaga("1921481211", new Vaga(1212121, be, ar));
    asas.adicionar_vaga("1921484841", new Vaga(1212121, ar, be));
    asas.atualizar_curriculo(email, new Vaga(1212121, be, re));
    asas.mostrar_vagas_compativeis(email);
}