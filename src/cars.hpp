#pragma once

#define AUECARS
#ifdef AUECARS
enum cars{
    BMW,
    MERC,
    JIGA,
    PRIORA
};


int carTuneMenu(zabivnoi off){
    int i{0};
    do{
        std::cout<<"---Тачки---\n"<<
        "1) Починить машину("<<(100-off.mash.hp)*3<<" рублей) HP:"<<off.mash.hp<<"\n"<<
        "2) Улучшить максимальную скорость(5 000 рублей) lvl:"<<off.mash.max_speed<<"\n"<<
        "3) Улучшить разгон(5 000 рублей ) lvl:"<<off.mash.razgon<<"\n"<<
        "4) Улучшить колеса(5 000 рублей) lvl:"<<off.mash.kolesa<<"\n"<<
        "5) Улучшить управление(5 000 рублей) lvl:"<<off.mash.upravl<<"\n"<<
        "6) Назад"<<std::endl;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
        }
        std::cin>>i;
    }while(!(i>0 && i<6));
    return i;
}

void carTune(zabivnoi off){
    clear();
    if(off.mash.id==-1){
        std::cout<<"Владелец выгнал тебя со словами\nТы опять из тех кто пришел воровать детали? Иди давай пока ментов не вызвал."<<std::endl;
        return;
    }
    switch(carTuneMenu(off)){
        case 1:
            if(off.money>=(100-off.mash.hp)*3){
                off.money-=(100-off.mash.hp)*3;
                off.mash.hp=100;
                std::cout<<"Вы починили машину"<<std::endl;
            }else{
                std::cout<<"У вас нехватает денег"<<std::endl;
            }
        break;
        
        case 2:
            if(off.money>=5000){
                off.money-=5000;
                off.mash.max_speed+=1;
                std::cout<<"Вы улучшили максимальную скорость"<<std::endl;
            }else{
                std::cout<<"У вас нехватает денег"<<std::endl;
            }
        break;
        
        case 3:
            if(off.money>=5000){
                off.money-=5000;
                off.mash.razgon+=1;
                std::cout<<"Вы улучшили разгон"<<std::endl;
            }else{
                std::cout<<"У вас нехватает денег"<<std::endl;
            }
        break;
        
        case 4:
            if(off.money>=5000){
                off.money-=5000;
                off.mash.kolesa+=1;
                std::cout<<"Вы улучшили колеса"<<std::endl;
            }else{
                std::cout<<"У вас нехватает денег"<<std::endl;
            }
        break;
        
        case 5:
            if(off.money>=5000){
                off.money-=5000;
                off.mash.upravl+=1;
                std::cout<<"Вы улучшили управление"<<std::endl;
            }else{
                std::cout<<"У вас нехватает денег"<<std::endl;
            }
        break;
        
    }
}

int carShopMenu(){
    int i{0};
    do{
        std::cout<<"---Тачки---\n"<<
        "При покупке новой машины тюнинг пропадает\n"<<
        "1) Беха(100 000 рублей)\n"<<
        "2) Мерс(100 000 рублей )\n"<<
        "3) Жига(20 000 рублей)\n"<<
        "4) Приора(50 000 рублей)\n"<<
        "5) Назад"<<std::endl;
        
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
        }
        std::cin>>i;
    }while(!(i>0 && i<6));
    return i;
}

void carShop(zabivnoi &off){
    clear();
            switch (carShopMenu()){
                case 1:
                    if(off.money>=100000){
                        std::cout<<"Вы купили беху"<<std::endl;
                        off.money-=100000;
                        off.mash.id = cars::BMW;
                    }else{
                        std::cout<<"Нехватает денег"<<std::endl;
                    }
                break;
                
                case 2:
                    if(off.money>=100000){
                        std::cout<<"Вы купили мерс"<<std::endl;
                        std::cout<<"Вы пополнили здоровье"<<std::endl;
                        off.money-=100000;
                        off.mash.id = cars::MERC;
                    }else{
                        std::cout<<"Нехватает денег"<<std::endl;
                    }
                break;
                
                case 3:
                    if(off.money>=20000){
                        std::cout<<"Вы купили жигу"<<std::endl;
                        std::cout<<"Вы пополнили здоровье"<<std::endl;
                        off.money-=20000;
                        off.mash.id = cars::JIGA;
                    }else{
                        std::cout<<"Нехватает денег"<<std::endl;
                    }
                break;
                
                case 4:
                    if(off.money>=50000){
                        std::cout<<"Вы купили приору"<<std::endl;
                        std::cout<<"Вы пополнили здоровье"<<std::endl;
                        off.money-=50000;
                        off.mash.id = cars::PRIORA;
                    }else{
                        std::cout<<"Нехватает денег"<<std::endl;
                    }
                break;
            }
}

int carMenu(zabivnoi &off){
    int i{0};
    do{
        std::cout<<"---Тачки---\n"<<
        "1) "<<(off.mash.id!=-1?"Поехать":"Пойти")<<" в автосалон\n"<<
        "2) Понтаваться на районе\n"<<
        "3) "<<(off.mash.id!=-1?"Поехать":"Пойти")<<" в мастерскую\n"<<
        "4) Учавстовать в гонках(3 000 рублей)\n"<<
        "5) Назад"<<std::endl;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
        }
        std::cin>>i;
    }while(!(i>0 && i<6));
    return i;
}

//void

bool carBAction(zabivnoi &off){
    if(rand_generator(0,10)==0){
            std::cout<<"Кому-то не понравилась твоя машина, он решил украсить её и поломал её"<<std::endl;
            off.mash.hp-=rand_generator(1,4);
            return false;
    }
    if(rand_generator(0,20)==0){
            std::cout<<"Ты попал в аварию ты поломал свою машину"<<std::endl;
            off.mash.hp-=rand_generator(5,20);
            return false;
    }
    return true;
}

void sopRace(zabivnoi &off){
        if(rand_generator(0,3)==0){
            std::cout<<"Он обогнал тебя. ";
            if(rand_generator(0,2)==0){
                std::cout<<"Во время гонки ты поцарапал свою машину"<<std::endl;
                off.mash.hp-=rand_generator(5,10);
            }else{
                std::cout<<"Братки увидели как ты продул сопернику. Ты видел как они смеялись над тобой.\nТвой авторитет понижен"<<std::endl;
                off.autoritet-=rand_generator(10,20);
            }
        } else{
            std::cout<<"Ты победил, браткам понравилась гонка.\nАвторитет повышен"<<std::endl;
            off.autoritet+=rand_generator(5,40);
        }
}

void carAction(zabivnoi &off){
    clear();
    switch(carMenu(off)){
        case 1:
            carShop(off);
        break;
        
        case 2:
            if(off.mash.id==-1){
                std::cout<<"Купи сначало машину"<<std::endl;
                return;
            }
            if(carBAction(off)){
                if(rand_generator(0,6)==0){
                    switch(off.mash.id){
                        case cars::BMW:
                            std::cout<<"Пацан на мерсе решил узнать чья тачка быстрее. Вы начали гонку"<<std::endl;
                            sopRace(off);
                        break;
                        
                        case cars::JIGA:
                            std::cout<<"Пацан на приоре решил узнать чья тачка быстрее. Вы начали гонку"<<std::endl;
                            sopRace(off);
                        break;
                        
                        case cars::MERC:
                            std::cout<<"Пацан на бехе решил узнать чья тачка быстрее. Вы начали гонку"<<std::endl;
                            sopRace(off);
                        break;
                        
                        case cars::PRIORA:
                            rand_generator(0,2)==0?std::cout<<"Пацан на мерсе решил узнать чья тачка быстрее. Вы начали гонку"<<std::endl:std::cout<<"Пацан на бехе решил узнать чья тачка быстрее. Вы начали гонку"<<std::endl;
                            sopRace(off);
                        break;
                    }
                }else{
                std::cout<<"Браткам понравилась твоя тачка, ты вырос в их глазах"<<std::endl;
                off.autoritet+=rand_generator(5,6+off.mash.kolesa+off.mash.upravl+off.mash.razgon+off.mash.max_speed-(100-off.mash.hp));
                }
            }
        break;
        
        case 3:
            if(carBAction(off)){
                carTune(off);
            }
        break;
        
        case 4:
            if(off.mash.id==-1){
                std::cout<<"Купи сначало машину"<<std::endl;
                return;
            }
            if(carBAction(off)){
                if(rand_generator(0,(off.mash.kolesa+off.mash.upravl+off.mash.razgon+off.mash.max_speed-(100-off.mash.hp))/2)==0){
                    std::cout<<"Тебе не повезло, тебя обогнали и поцарапали машину."<<std::endl;
                    off.mash.hp-=rand_generator(3,15);
                }else{
                    off.autoritet+=rand_generator(5,90);
                    std::cout<<"Браткам понравилось как ты гоняешь."<<std::endl;
                }
            }
        break;
    }
    if(off.mash.hp<=0){
            std::cout<<"Твоя машина сломалась, её пришлось сдать на металлалом"<<std::endl;
            off.mash.id=-1;
    }
}

bool escapeCar(){
    std::cout<<"Вы сели в свою припаркованную рядом машину и пытаетесь уехать от ментов."<<std::endl;
    if(rand_generator(0,6)==0){
        
        switch(rand_generator(0,3)){
            case 0:
            std::cout<<"Ты начал выезжать, но на твоем пути встала припаркованная рядом машина."<<std::endl;
            break;
                                    
            case 1:
            std::cout<<"Ты пытаешься завести движок, но он не заводится."<<std::endl;
            break;
                                    
            case 2:
            std::cout<<"Тебе не повезло. Рядом стояла мусорская машина. Ты не смог выехать."<<std::endl;
            break;
            }
            
        std::cout<<"Мусора поймали тебя. Но перед тем как отвезти в отделение полиции они хорошенько отбили тебя.\nПрибыв в отделении на тебя напали твои враги.\nМусора пришли слишком поздно."<<std::endl;
        return true;
        
    }else{
        std::cout<<"Вас чуть не поймали, но вы уехали от мусоров."<<std::endl;
    }
    return false;
}
#endif
