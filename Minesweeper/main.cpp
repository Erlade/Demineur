
#include "minesweeper.h"

int main(){

    while(true){
        //Crée des plateaux aléatoires en continu
        Minesweeper *app = new Minesweeper(30,16,55);
        delete app;
        cout << endl;
        sleep (5);
    }

}
