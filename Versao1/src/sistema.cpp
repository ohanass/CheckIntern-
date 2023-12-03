#include "sistema.hpp"

void teste_compatibilidade(Vaga curriculo, std::vector<Vaga*> vagas){
    int compatibilidade;
    std::map<double, Vaga*> ordenador;
    for(long unsigned int i=0; i<vagas.size(); ++i){
        
        compatibilidade=0;
        for(long unsigned int j=0; j<curriculo.get_beneficios().size(); ++j){

            for(long unsigned int k=0; k<vagas.at(i)->get_beneficios().size(); ++k){
                if(vagas.at(i)->get_beneficios().at(k).find(curriculo.get_beneficios().at(j))!=std::string::npos){
                    compatibilidade++;
                    break;
                }
            }
        }
        for(long unsigned int j=0; j<curriculo.get_requisitos().size(); ++j){
            for(long unsigned int k=0; k<vagas.at(i)->get_requisitos().size(); ++k){
                if(vagas.at(i)->get_requisitos().at(k).find(curriculo.get_requisitos().at(j))!=std::string::npos){
                    compatibilidade++;
                    break;
                }
            }  
        }
        ordenador.insert(std::make_pair(100.0-(((double)compatibilidade/(double)(curriculo.get_beneficios().size()+curriculo.get_requisitos().size()))*100),vagas.at(i)));
    }
    for(std::map<double, Vaga*>::iterator it=ordenador.begin();it!=ordenador.end();++it){
        if((100.0-it->first)>=50.0){
            std::cout<<"---------------------------"<<std::endl;
            it->second->mostrar_vaga();
            std::cout<<"---------------------------"<<std::endl;
            std::cout<<"COMPATIBILIDADE: "<<std::fixed<<std::setprecision(2)<<(100.0-it->first)<<"%"<<std::endl;
        }
    }
    std::cout<<"---------------------------"<<std::endl<<std::endl;
}

void Sistema::cadastrar_empresa(std::string cnpj, Empresa* nova_empresa){
    if(_lista_empresas.find(cnpj)==_lista_empresas.end()){
        _lista_empresas.insert(std::make_pair(cnpj, nova_empresa));
    }
    else{
        std::cout<<"EMPRESA JÁ CADASTRADA"<<std::endl;
    }
}

void Sistema::adicionar_conta_empresa(std::string cnpj, std::map<std::string,std::pair<std::string, std::string>> contas){
    if(_lista_empresas.find(cnpj)!=_lista_empresas.end()){
        _lista_empresas.at(cnpj)->adicionar_contas(contas);
    }
    else{
        std::cout<<"EMPRESA NÃO ENCONTRADA"<<std::endl;
    }
}

void Sistema::adicionar_vaga(std::string cnpj, Vaga* vagas){
    _lista_empresas.at(cnpj)->adicionar_vaga(vagas);
}

void Sistema::cadastrar_estagiario(std::string email, std::string nome, std::string senha){
    if(_lista_estagiarios.find(email)==_lista_estagiarios.end()){
        _lista_estagiarios.insert(std::pair<std::string,Estagiario*>(email, new Estagiario(nome, senha)));
    }
    else{
        std::cout<<"ESTAGIARIO JÁ CADASTRAO"<<std::endl;
    }
}

bool Sistema::entrar_conta_estagiario(std::string email, std::string senha){
    if(_lista_estagiarios.find(email)!=_lista_estagiarios.end()){
        if(_lista_estagiarios.at(email)->get_senha()==senha){
            std::cout<<"SEJA BEM VINDO "<<_lista_estagiarios.at(email)->get_nome()<<std::endl;
            return true;
        }
    }
    std::cout<<"SENHA OU USUARIO INCORRETOS"<<std::endl;
    return false;
}

bool Sistema::entrar_conta_empresa(std::string cnpj, std::string email, std::string senha){
    if(_lista_empresas.find(cnpj)!=_lista_empresas.end()){
        if(_lista_empresas.at(cnpj)->encontrar_email(email)){
            if(_lista_empresas.at(cnpj)->get_senha(email)==senha){
                std::cout<<"SEJA BEM VINDO "<<_lista_empresas.at(cnpj)->get_nome_conta(email)<<std::endl;
                return true;
            }
        }
        std::cout<<"SENHA OU USUARIO INCORRETOS"<<std::endl;
        return false;
    }
    std::cout<<"CNPJ NÃO CADASTRADO"<<std::endl;
    return false;
}

void Sistema::atualizar_curriculo(std::string email, Vaga* curriculo){
    _lista_estagiarios.at(email)->atualizar_curriculo(curriculo);
}

void Sistema::mostrar_vagas_compativeis(std::string email){
    for(std::map<std::string, Empresa*>::iterator it=_lista_empresas.begin();it!=_lista_empresas.end();++it){
        std::cout<<it->second->get_nome()<<std::endl;
        std::cout<<"CNPJ: "<<it->first<<std::endl;
        teste_compatibilidade(_lista_estagiarios.at(email)->get_curriculo(), it->second->get_vagas());
    }
}

void Sistema::mostrar_todas_vagas(void){
    for(std::map<std::string, Empresa*>::iterator it=_lista_empresas.begin();it!=_lista_empresas.end();++it){
        std::cout<<"---------------------------"<<std::endl;
        std::cout<<it->second->get_nome()<<std::endl;
        std::cout<<"CNPJ: "<<it->first<<std::endl;
        it->second->mostrar_vagas();
    }
}