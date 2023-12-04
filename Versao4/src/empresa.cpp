#include "empresa.hpp"

unsigned long int Empresa::_cod_vaga=1;

void Empresa::alterar_nome(std::string nome){
    this->_nome=nome;
}

void Empresa::alterar_numeroContato(std::string numeroContato){
    this->_numeroContato=numeroContato;
}

void Empresa::alterar_email(std::string email){
    this->_email=email;
}

void Empresa::adicionar_vaga(Vaga* vaga){
    this->_vagas.insert(std::make_pair(this->_cod_vaga, vaga));
    _cod_vaga++;
}

void Empresa::remover_vaga(unsigned long int cod_vaga){
    if(this->_vagas.find(cod_vaga)!=this->_vagas.end()){
        if(this->_vagas.at(cod_vaga)->get_ativa()){
            this->_vagas.at(cod_vaga)->inativar_vaga();
            return;
        }
    }
    std::cout<<"VAGA INEXISTENTE"<<std::endl;
}

void Empresa::mostrar_vagas(void){
    std::cout<<"###########################"<<std::endl;
    std::cout<<"VAGAS"<<std::endl;  
    unsigned long int i=0; 
    for(std::map<unsigned long int, Vaga*>::iterator it=this->_vagas.begin();it!=this->_vagas.end();++it){
            
            std::cout<<"---------------------------"<<std::endl;
            std::cout<<"CODIGO: #"<<it->first<<std::endl;
            it->second->mostrar_vaga_resumido();
            if(i!=_vagas.size()-1){
                i++;
                std::cout<<"***************************"<<std::endl<<std::endl;
            }
    }
    std::cout<<"###########################"<<std::endl<<std::endl;
}

bool Empresa::verifica_existenciaVaga(unsigned long int cod_vaga){
    if(this->_vagas.find(cod_vaga)!=this->_vagas.end()){
        return (this->_vagas.at(cod_vaga)->get_ativa());
    }
    return false;
}

void Empresa::receber_curriculo(unsigned long int cod_vaga, Aluno* curriculo){
    this->_curriculos.insert(std::make_pair(cod_vaga, curriculo));
}

void Empresa::mostrar_curriculos(void){
    std::cout<<"###########################"<<std::endl;
    std::cout<<"CURRICULOS"<<std::endl; 
    unsigned long int i=0;  
    for(std::multimap<unsigned long int, Aluno*>::iterator it=this->_curriculos.begin();it!=this->_curriculos.end();++it){
        std::cout<<"---------------------------"<<std::endl;
        std::cout<<"CODIGO: #"<<it->first<<std::endl;
        it->second->mostrar_curriculo();
        if(i!=_curriculos.size()-1){
            i++;
            std::cout<<"***************************"<<std::endl<<std::endl;
        }
    }
    std::cout<<"###########################"<<std::endl<<std::endl;
}

Vaga* Empresa::get_vaga(unsigned long int cod_vaga){
    return this->_vagas.at(cod_vaga);
}

std::map<unsigned long int, Vaga*> Empresa::get_vagas(void){
    return this->_vagas;
}


std::string Empresa::get_nome(void){
    return this->_nome;
}

std::string Empresa::get_CNPJ(void){
    return this->_CNPJ;
}
