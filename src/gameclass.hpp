#pragma once

#define CLASSI
#ifdef CLASSI

class car{
public:
    int max_speed{0};
    int razgon{0};
    int kolesa{0};
    int upravl{0};
    int hp{100};
    int id{-1};
};



class zabivnoi{
public:
    int hp;
    int sila;
    int autoritet;
    std::string kli4ka;
    std::string name;
    int money;
    car mash;
    bool isband{false};
    std::vector<zabivnoi> banda;
    std::string bandname{""};
    
    zabivnoi(): hp{100}, sila{rand_generator(6,14)}, money{rand_generator(300,450)}, kli4ka{klicuhi[rand_generator(0,klicuhi.size()-1)]}, autoritet{0}, name{imena[rand_generator(0,imena.size()-1)]}{}
    
    bool fight(const zabivnoi& offnik){
        if(offnik.sila > sila){
            if(rand_generator(0,3)==0){
                return true;
            }
            return false;
        }
        if(rand_generator(0,30)==0)
            return false;
        
        return true;
    }
};
#endif
