#include "empresa.hpp"

void Empresa::alterar_nome(std::string nome){
    this->_nome=nome;
}

void Empresa::alterar_numeroContato(std::string numeroContato){
    this->_numeroContato=numeroContato;
}

void Empresa::alterar_email(std::string email){
    this->_email=email;
}

void Empresa::adicionar_vaga(Vaga* vagas){
    _vagas.push_back(vagas);
}

void Empresa::remover_vaga(unsigned long int cod_vaga){
    _vagas.erase(_vagas.begin()+cod_vaga-1);
}

void Empresa::mostrar_vagas(void){
    std::cout<<"###########################"<<std::endl;
    std::cout<<"VAGAS"<<std::endl;   
    for(unsigned long int i=0;i<_vagas.size();i++){
        std::cout<<"---------------------------"<<std::endl;
        std::cout<<"CODIGO: #"<<i+1<<std::endl;
        _vagas[i]->mostrar_vaga_resumido();
        if(i!=_vagas.size()-1)
            std::cout<<"***************************"<<std::endl<<std::endl;
    }
    std::cout<<"###########################"<<std::endl<<std::endl;
}

std::vector<Vaga*> Empresa::get_vagas(){
    return this->_vagas;
}

std::string Empresa::get_nome(void){
    return this->_nome;
}

std::string Empresa::get_CNPJ(void){
    return this->_CNPJ;
}
