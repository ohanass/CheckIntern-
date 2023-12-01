#include "empresa.hpp"

Empresa::Empresa(std::string nome, std::map<std::string,std::pair<std::string, std::string>> contas){
    this->_nome=nome;
    this->_contas.insert(contas.begin(),contas.end());
}

void Empresa::adicionar_contas(std::map<std::string,std::pair<std::string, std::string>> contas){
    _contas.insert(contas.begin(),contas.end());
}

void Empresa::remover_conta(std::string email){
    if(_contas.find(email)!=_contas.end()){
        _contas.erase(email);
    }
    else{
        std::cout<<"EMAIL NÃO CADASTRADO"<<std::endl;
    }
}

void Empresa::alterar_senha(std::string email, std::string senha){
    if(_contas.find(email)!=_contas.end()){
        _contas.at(email).second=senha;
    }
    else{
        std::cout<<"EMAIL NÃO CADASTRADO"<<std::endl;
    }
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
        std::cout<<"CODIGO: "<<i+1<<std::endl;
        _vagas[i]->mostrar_vaga();
        if(i!=_vagas.size()-1)
            std::cout<<"***************************"<<std::endl<<std::endl;
    }
    std::cout<<"###########################"<<std::endl<<std::endl;
}

void Empresa::adicionar_curriculo(unsigned long int cod_vaga, Estagiario* estagiario){
    _curriculos_recebidos.insert(std::pair<unsigned long int,Estagiario*>(cod_vaga-1,estagiario));
}

void Empresa::remover_curriculo(unsigned long int cod_vaga, std::string nome){
    for (std::multimap<unsigned long int,Estagiario*>::iterator it=_curriculos_recebidos.begin(); it!=_curriculos_recebidos.end(); ++it){
        if(it->second->get_nome()==nome&&it->first==cod_vaga-1){
            _curriculos_recebidos.erase(it);
            break;
        }
    }
}

void Empresa::remover_curriculo(std::string nome){
    for (std::multimap<unsigned long int,Estagiario*>::iterator it=_curriculos_recebidos.begin(); it!=_curriculos_recebidos.end(); ++it){
        if(it->second->get_nome()==nome){
            _curriculos_recebidos.erase(it);
            it=_curriculos_recebidos.begin();
        }
    }
}

void Empresa::mostrar_curriculos(void){
    std::cout<<"###########################"<<std::endl;
    std::cout<<"CURRICULOS"<<std::endl;
    unsigned long int i=0;
    
    for (std::multimap<unsigned long int,Estagiario*>::iterator it=_curriculos_recebidos.begin(); it!=_curriculos_recebidos.end(); ++it){
        std::cout<<"---------------------------"<<std::endl;
        std::cout<<"CODIGO VAGA: "<<it->first+1<<std::endl;
        it->second->mostrar_curriculo();
        if(i!=_curriculos_recebidos.size()-1)
            std::cout<<"***************************"<<std::endl<<std::endl;
        i++;
    }
    std::cout<<"###########################"<<std::endl<<std::endl;
}

bool Empresa::encontrar_email(std::string email){
    if(_contas.find(email)!=_contas.end()){
        return true;
    }
    else{
        return false;
    }
}

std::vector<Vaga*> Empresa::get_vagas(){
    return this->_vagas;
}

std::string Empresa::get_nome(void){
    return this->_nome;
}

std::string Empresa::get_senha(std::string email){
    return this->_contas.at(email).second;
}

std::string Empresa::get_nome_conta(std::string email){
    return this->_contas.at(email).first;
}