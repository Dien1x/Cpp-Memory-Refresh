#include <iostream>
using namespace std;
#include "classes.h"

int main(){
    
    srand(time(NULL));
    
    pool myCardPool;
    
    creature c1("Akroan Crusader", "Red", "Common", 1, 1, "Humman Soldier");
    creature c2("Rune-Scarred Deamon", "Black", "Rare", 6, 6, "Deamon");
    land c3("Plains", "White", "Uncommon", 1, "Basic Land - Plains", false);
    land c4("Swamp", "Black", "Uncommon", 1, "Basic Land - Swamp", false);
    land c5("Forest", "Green", "Uncommon", 1, "Basic Land - Forest", false);
    creature c6("Aegis Angel", "White", "Rare", 5, 5, "Angel");
    creature c7("Harbringer of Life", "Black", "Common", 2, 3, "Summon Spirit");
    creature c8("Ghalta, Primal Hunger", "Green", "Rare", 12,12, "Elder Dinosaur");
    creature c9("Skarrgan Hellkite", "Red", "Rare", 4, 4, "Deamon");
    creature c10("Spawn of Mayhem", "Black", "Rare", 4, 4, "Deamon");
    
    myCardPool.add_card(c1);
    myCardPool.add_card(c2);
    myCardPool.add_card(c3);
    myCardPool.add_card(c4);
    myCardPool.add_card(c5);
    myCardPool.add_card(c6);
    myCardPool.add_card(c7);
    myCardPool.add_card(c8);
    myCardPool.add_card(c9);
    myCardPool.add_card(c10);
    

    
    hand newHand(myCardPool);
    
    cout<<newHand;
    
    return 0;
};
