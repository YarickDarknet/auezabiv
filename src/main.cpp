//Я эту игру делал по рофлу
//Я не призываю никого пиздиться и раздавать закладки
//
//http://yarickserver.ddns.net/offgame.html
//


#include <iostream>
#include <random>
#include <ctime>
#include <array>
#include <stdio.h>
#include <unistd.h>

std::array<std::string,22> klicuhi{"Жопастый","Забивной","Опасный","АУЕшный","Усатый","Уважаемый","Модный","Блатной","Четкий","Безумный","Вечно молодой","Дикий","Бессмертный","Бесстрашный","Украинский","Отсидевший","Питонист","АУЕвший","Ненасытный","Мирный","Отбитый",""};

std::array<std::string,19> imena{"Толик","Семен","Олег","Евгений","Артем","Владик","Сергей","Иваныч","Константин","Юрий","Дмитрий","Ярик","Валера","Александр","Колян","Виктор","Макс","Миша",""};

int rand_generator(int min, int max){
    return rand()%(max-min)+min;
}

void clear(){
    std::cout<<"\E[H\E[2J";    
}

#include "gameclass.hpp"
#include "cars.hpp"
//#include "bands.hpp" Позже доделать

/*int rand_generator(int min, int max){
 *    std::random_device random_device;
 *    std::mt19937 generator(random_device());
 *    std::uniform_int_distribution<> distribution(min, max);
 *    return distribution(generator);
 *    } Эта хрень по какой-то причине крашит игру.
 */

int mainMenu(zabivnoi &offnik){
    int i{-1};
    do{
    clear();
    if(offnik.hp<=20){
        std::cout<<"---КРИТИЧЕСКИЙ УРОВЕНЬ ЗДОРОВЬЯ---"<<std::endl;
        std::cout<<"---          КУПИТЕ ЕДУ        ---"<<std::endl;
    }
    std::cout<<"---"<<"HP:"<<offnik.hp<<" "<<offnik.kli4ka<<" "<<offnik.name<<"---\n"<<
    "У вас "<<offnik.money<<"₽\n"<<
    "Ваш авторитет "<<offnik.autoritet<<"\n"<<
    "Ваша сила "<<offnik.sila<<"\n"<<
    "1)  Пойти на разборки🤙\n"<<
    "2)  Пойти на турники💪\n"<<
    "3)  Пойти в качалку(100₽)💪\n"<<
    "4)  Обмануть лоха🧑‍💼\n"<<
    "5)  Пойти кладменом👉\n"<<
    "6)  Раздавать листовки🗒️\n"<<
    "7)  Бегать от ментов👮\n"<<
    "8)  🤙🤙Учавствовать на забиве(50 авторитета, 500₽, 200 силы)🤙🤙\n"<<
    "9)  Купить еду🥙\n"<<
    "10) Тачки🚗"<<std::endl;
    //"11) Банда☠️"<<std::endl;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767,'\n');
    }
    std::cin>>i;
    }while(!(i>0 && i<11));
    return i;
}

int edaMenu(){
    int i;
    do{
        std::cout<<"---Продукты---\n"<<
        "1) 🍞Хлеб(20 рублей +5 к здоровью)\n"<<
        "2) 🌯Шавуха(100 рублей +30 к здоровью)\n"<<
        "3) 🍔Бургер(50 рублей +15 к здоровью)\n"<<
        "4) 🍕Пицца(70 рублей +20 к здоровью)\n"<<
        "5) Назад"<<std::endl;
        std::cin>>i;
    }while(!(i>0 && i<6));
    return i;
}



void __pause(){
    std::cin.clear();
    std::cin.ignore(1024,'\n');
    while(std::cin.get() != '\n');
}

bool pvp(zabivnoi &vrag,zabivnoi &off){
    if(off.fight(vrag)){
        off.autoritet+=(rand_generator(0,5));
        std::cout<<"🤜Вы отпиздили "<<vrag.kli4ka<<' '<<vrag.name<<"🤛\nАвторитет+"<<std::endl;
        return true;
    } else{
        std::cout<<"⛔Вас отпиздил "<<vrag.kli4ka<<' '<<vrag.name<<"⛔\nВаш авторитет уменьшился"<<std::endl;
        off.autoritet-=(rand_generator(1,5));
        return false;
    }
}

int doaction(int action,zabivnoi &off){
    clear();
    zabivnoi vrag;
    vrag.sila = rand_generator(off.sila-off.autoritet,off.sila/2+3);
    switch(action){
        case 1:
            if(off.sila>3){
                pvp(vrag,off)?off.hp-=rand_generator(1,4):off.hp-=rand_generator(5,14);
                off.sila-=rand_generator(1,5);
            }else{
                std::cout<<"Ты очень слаб. Ты можешь погибнуть. Иди подкачайся."<<std::endl;
            }
        break;
        
        case 2:
            std::cout<<"💪Вы пошли на турники💪"<<std::endl;
            if(rand_generator(0,5)==0){
                std::cout<<"На вас напали по пути к турникам"<<std::endl;
                pvp(vrag,off);
            } else{
                off.sila+=rand_generator(5,10);
                std::cout<<"💪Вы увеличили вашу силу💪"<<std::endl;
            }
        break;
        
        case 3:
            if(off.money>=100){
                off.money-=100;
                std::cout<<"💪Вы увеличили вашу силу💪"<<std::endl;
                off.sila+=rand_generator(10,90);
            } else{
                std::cout<<"У вас нехватает денег!"<<std::endl;
            }
        break;
        
        case 4:
            if(rand_generator(0,10)==0){
                if(rand_generator(0,4)==0){
                    std::cout<<"Лох вызвал полицию. Вы пытаетесь убежать."<<std::endl;
                    if(rand_generator(0,2)==0){
                        if(off.mash.id!=-1){
                            if(rand_generator(0,4)==0){
                                std::cout<<"Вас поймали. Мусора решили поиздеваться над вами и тяжело ранили вас.\nВы лежите в больнице.\nМедики устали следить за вашим состоянием здоровья.\nВас отключили от приборов."<<std::endl;
                                return 1;
                            }
                        }else{
                            return (escapeCar()?1:0);
                        }
                    }else{
                        std::cout<<"Вы сбежали"<<std::endl;
                    }
                }
                std::cout<<"❌Вы не смогли ограбить лоха❌"<<std::endl;
                if(rand_generator(0,3)==0){
                    std::cout<<"Этот лох оказался далеко не лохом\nОн попробовал напасть на вас."<<std::endl;
                    pvp(vrag,off);
                }
            }else{
                off.money+=rand_generator(50,200);
                std::cout<<"🤑Вы ограбили лоха🤑"<<std::endl;
            }
        break;
        
        case 5:
            if(rand_generator(0,10)==0){
                std::cout<<"❌У вас украли закладки❌"<<std::endl;
                if(off.money<300){
                    std::cout<<"У вас не хватило денег чтобы заплатить заплатить, к вам приехали братки и отпиздили вас."<<std::endl;
                    return 1;
                }
                off.money-=300;
                std::cout<<"💵Вам пришлось заплатить за потерю💵"<<std::endl;
            }else{
                off.money+=rand_generator(200,900);
                std::cout<<"🤑Вы успешно расставили закладки🤑"<<std::endl;
            }
        break;
        
        case 6:
            if(off.sila>0){
            if(rand_generator(0,25)==0){
                std::cout<<"На вас напали!"<<std::endl;
                pvp(vrag,off);
            }else{
                off.money+=rand_generator(200,400);
                off.sila-=rand_generator(3,15);
                std::cout<<"🤑Вы раздали листовки🤑"<<std::endl;
                std::cout<<"Вы Устали"<<std::endl;
                std::cout<<"👎Сила уменшилась👎"<<std::endl;
            }
            }else{
                std::cout<<"Ты слишком слаб."<<std::endl;
            }
        break;
        
        case 7:
            if(rand_generator(0,8)==0){
                std::cout<<"Тебя поймали менты, вас отпиздили и посадили в тюрьму\nЧерез 2 месяца тебя отпиздили заключенные."<<std::endl;
                return 1;
            }else{
                std::cout<<"Вы убежали от ментов, вас стали уважать сильнее.☝️"<<std::endl;
                off.autoritet+=rand_generator(20,80);
            }
        break;
        
        case 8:
            //(50 авторитета, 500₽, 200 силы)
            if(off.autoritet>=50 && off.money>=500 && off.sila>=200){
                off.autoritet-=50;
                off.money-=500;
                off.sila-=200;
                if(rand_generator(0,30)==0){
                    std::cout<<"👎Вас отпиздили на забиве.👎"<<std::endl;
                    off.hp-=30;
                    return 0;
                }
                off.autoritet+=70;
                off.sila+=190;
                std::cout<<"😵Была очень четкая рубка.😵\nТы немного устал.\nТебя зауважали."<<std::endl;
            }else{
                std::cout<<"Ты еще очень слаб волк.🐺"<<std::endl;
            }
        break;
        
        case 9:
            switch (edaMenu()){
                case 1:
                    if(off.money>=20){
                        std::cout<<"Вы купили хлеб"<<std::endl;
                        off.money-=20;
                        off.hp+=5;
                    }else{
                        std::cout<<"Нехватает денег"<<std::endl;
                    }
                break;
                
                case 2:
                    if(off.money>=100){
                        std::cout<<"Вы купили шавуху"<<std::endl;
                        off.money-=100;
                        off.hp+=30;
                    }else{
                        std::cout<<"Нехватает денег"<<std::endl;
                    }
                break;
                
                case 3:
                    if(off.money>=50){
                        std::cout<<"Вы купили бургер"<<std::endl;
                        off.money-=50;
                        off.hp+=15;
                    }else{
                        std::cout<<"Нехватает денег"<<std::endl;
                    }
                break;

                case 4:
                    if(off.money>=70){
                        std::cout<<"Вы купили пиццу"<<std::endl;
                        off.money-=70;
                        off.hp+=20;
                    }else{
                        std::cout<<"Нехватает денег"<<std::endl;
                    }
                break;
                
            }
        std::cout<<"Вы пополнили здоровье"<<std::endl;
        break;
        
        case 10:
            carAction(off);
        break;
        
        //case 11:
            //bandAction(off);
        //break;
    }
    __pause();
    if(off.hp>100) off.hp=100;
    return 0;
}
        
int main(int argc, char **argv) {
    srand(std::time(nullptr));
    zabivnoi offwhite;
    clear();
    std::cout<<"Введите имя вашего оффника"<<std::endl;
    std::getline(std::cin,offwhite.name);
    int i = doaction(mainMenu(offwhite),offwhite);
    while(offwhite.hp>0 && i==0)
        i = doaction(mainMenu(offwhite),offwhite);
    
    std::cout<<"❌Вы умерли❌'"<<std::endl;
}
