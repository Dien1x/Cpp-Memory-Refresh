#include <iostream>
using namespace std;
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "classes.h"

/* Class for Basic type */

card::card(string in_name, string in_color, string in_rarity){
    name = in_name;
    color = in_color;
    rarity = in_rarity;
};
ostream &operator<<(ostream &left, const card &obj){
    obj.print(left);
    return left;
};

/* Class for Creature type */

creature::creature(string in_name, string in_color, string in_rarity, int in_attack, int in_defence, string in_type):
card(in_name, in_color, in_rarity){
    attack = in_attack;
    defence = in_defence;
    type = in_type;
};
ostream &creature::print(ostream &left) const{
    left<<"Card Name: "<<name<<endl;
    left<<"Color: "<<color<<endl;
    left<<"Rarity: "<<rarity<<endl;
    left<<"Attack: "<<attack<<endl;
    left<<"Defence: "<<defence<<endl;
    left<<"Type: "<<type<<endl;    
    return left;
};
ostream &operator<<(ostream &left, const creature &obj){
    obj.print(left);
    return left;
};

/* Class for Land type */

land::land(string in_name, string in_color, string in_rarity, int in_mana, string in_description, bool in_tap):
card(in_name, in_color, in_rarity){
    mana = in_mana;
    description = in_description;
    tap = in_tap;
};
ostream &operator<<(ostream &left, const land &obj){
    obj.print(left);
    return left;
};
ostream &land::print(ostream &left) const{
    left<<"Card Name: "<<name<<endl;
    left<<"Color: "<<color<<endl;
    left<<"Rarity: "<<rarity<<endl;
    left<<"Mana: "<<mana<<endl;
    left<<"Description: "<<description<<endl;
    left<<"Payable: "<<(tap?"Playable":"Non Playable")<<endl;    
    return left;
};

/* Class for Pool of Cards */

const int pool::max_cards = 300;
pool::pool(){
    current = 0;
    cardpool = new card*[max_cards];
    if(!cardpool) {cout<<"Allocation Failed"<<endl;};
};
pool::pool(const pool &obj){
    current = obj.current;
    cardpool = new card*[max_cards];
    if(!cardpool) {cout<<"Allocation Failed"<<endl;};
    for(int i=0;i<current;i++){
        cardpool[i] = obj.cardpool[i]->clone();
    };
};
pool::~pool(){
    for(int i=0;i<current;i++){
        delete cardpool[i];
    }; // Because the clone above returns new *this
    delete [] cardpool;
};
card &pool::operator[](int i){
    if(i<0 || i>=current) {
        throw out_of_range("Out of Bounds");
    };
    return *cardpool[i];
};
ostream &operator<<(ostream &left, const pool &obj){
    for(int i=0;i<obj.current;i++){
        obj.cardpool[i]->print(left)<<endl;
    };
    return left;
};
void pool::add_card(card &obj){
    cardpool[current] = obj.clone();
    current++;
};
card *pool::pick_random(){
    return cardpool[rand()%current];
};

/* Class for Hand of the player */

const int hand::max_hand = 10;
hand::hand(pool &p){
    cardhand = new card*[max_hand];
    if(!cardhand) {cout<<"Allocation Failed"<<endl;};
    current = 0;
    fill_hand(p);
};
hand::~hand(){
    delete [] cardhand;
};
void hand::pick_card(pool &p ,int i){
    cardhand[i]=&p[i];
};
void hand::fill_hand(pool &p){
    for(int i=0;i<7;i++){
        cardhand[i]=p.pick_random();
        current++;
    };
};
ostream &operator<<(ostream &left, const hand &obj){
    for(int i=0;i<=obj.current;i++){
        left<<*obj.cardhand[i]<<endl<<endl;
    };
    return left;
};