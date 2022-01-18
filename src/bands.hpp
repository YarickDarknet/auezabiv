#pragma once

#define BANDS
#ifdef BANDS

int bandMenu(zabivnoi &off){
    int i{-1};
    do{
    clear();
    std::cout<<
    (off.isband==false?"1) Создать банду(500 авторитета)\n":"1) Переименовать банду\n")<<
    "2) Выгнать участника банды\n"<<
    "3) Тренировать пацанов\n"<<
    "4) Вылечить пацанов\n"<<
    "5) Навести суету\n"<<
    "6) Пощемить лохов\n"<<
    "7) Состав банды\n️"<<
    "8) Назад"<<std::endl;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767,'\n');
    }
    std::cin>>i;
    }while(!(i>0 && i<9));
    return i;
}

void printMembers(zabivnoi &off){
    for(std::size_t i{0};i!=off.banda.size();i++){
        std::cout<<i<<") "<<off.banda[i].kli4ka<<" "<<off.banda[i].name<<'\n'<<
        "--HP: "<<off.banda[i].hp<<'\n'<<
        "--Сила: "<<off.banda[i].sila<<'\n'<<
        "--Деньги: "<<off.banda[i].money<<'\n'<<std::endl;
    }
}

int kickMemberMenu(zabivnoi &off){
    
    int i{-1};
    do{
    clear();
    printMembers(off);
    std::cout<<off.banda.size()+1<<") Назад"<<std::endl;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767,'\n');
    }
    std::cin>>i;
    }while(!(i>0 && i<off.banda.size()+2));
    return i;
}

void kickMember(zabivnoi &off){
    int memid{kickMemberMenu(off)};
    if(memid>off.banda.size()){
        return;
    }
}

void bandAction(zabivnoi &off){
    switch(bandMenu(off)){
        case 1:
            if(off.isband==false){
                if(off.autoritet>=500){
                    std::cout<<"Введите название вашей банды"<<std::endl;
                    getline(std::cin,off.bandname);
                    off.isband=true;
                }else{
                    std::cout<<"С таким авторитетом ты ничего не сможешь."<<std::endl;
                }
            }else{
                std::cout<<"Введите новое название вашей банды."<<std::endl;
                getline(std::cin,off.bandname);
            }
        break;
        
        case 2:
            if(off.banda.size()==0){
                std::cout<<"Самого себя выгнать хочешь?"<<std::endl;
            }else{
                kickMember(off);
            }
        break;

        case 3:
            if(off.banda.size()==0){
                std::cout<<"Кого тренировать то будешь?"<<std::endl;
            }else{
                off.sila+=rand_generator(5,10);
                std::cout<<"💪Вы увеличили вашу силу💪"<<std::endl;
            }
        break;
    }
}

#endif

