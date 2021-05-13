#include "minesweeper.h"

Minesweeper::Minesweeper(int columns_get, int rows_get, int bomb_count_get):
    rows{rows_get}, columns{columns_get}, max_size{rows*columns}, bomb_count{bomb_count_get}
{
    //Initialise les variables puis exécute les fonctions dans l'ordre
    create_table(); // création d'un plateau;
    add_bombs(); // ajout des bombes;
    add_numbers(); // ajout des nombres;
    show_table(); // affiche le plateau;
}

Minesweeper::~Minesweeper()
{

}

void Minesweeper::create_table(){
    table.resize(rows,vector<int>(columns, 0)); //ajuste la taille en fonction des valeurs de "row" et "column"
}

void Minesweeper::add_bombs(){

    // Imaginons que rows=20 columns=10
    // donc max_size=rows*columns
    // max_size=200 dans ce cas
    // création d'un vecteur d'integers qui s'appelle 'bombs' [1,2,3,4,5....,199,200]
    for(int i{1}; i<=max_size; ++i){
        bombs.push_back(i);
    }

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    // Parce qu'on veut des bombes aléatoires, on a besoin de mélanger
    // vecteur de mélange de bombes [1,2,3,4,5....,199,200]
    // ex output [20,32,50,120,153,.....1,12]
    shuffle(bombs.begin(), bombs.end(), default_random_engine(seed));

    // par exemple l'utilisateur demande de générer 3 bombes
    // bomb_count=3
    // l'output de bombs donne : [20,32,50]
    // maintenant nous avons 3 bombes aux carrés 20, 32 et 50
    bombs.reserve(bomb_count);
    bombs.resize(bomb_count);

}

int Minesweeper::find_column(int a){
    //calcule le nombre de colonnes grace au nombre de carrés donné
    int column_of_it{0};
    if(a%columns==0){
        column_of_it = columns;
    }else{
        column_of_it = a % columns;
    }
    return column_of_it;
}

int Minesweeper::find_row(int a, int column){
    //calculate the row by the given square number and the column
    //we have to find_column in order to find_row
    int row_of_it { ((a-column)/columns)+1 };
    return row_of_it;
}

void Minesweeper::add_numbers(){
    // add numbers
    int column_of_the_bomb_real{};
    int row_of_the_bomb_real{};
    int column_of_the_bomb{}; //for array starting at 0
    int row_of_the_bomb{}; //for array starting at 0

    for(auto bomb: bombs){
        //for each of the bombs
        column_of_the_bomb_real = find_column(bomb); //find the column of the bomb
        row_of_the_bomb_real = find_row(bomb, column_of_the_bomb_real); //find the row of the bomb
        column_of_the_bomb = column_of_the_bomb_real-1; //for array starting at 0
        row_of_the_bomb = row_of_the_bomb_real-1; //for array starting at 0

        // add the numbers around each bomb
        // if statements are checking for the edges of the table
        // the areas around one bomb look like this:
        //   1 2 3
        //   4 * 5
        //   6 7 8

        //for area "1"
        if(row_of_the_bomb != 0 && column_of_the_bomb != 0) //check for edge
            table[row_of_the_bomb-1][column_of_the_bomb-1] += 1;

        //for area "2"
        if(row_of_the_bomb != 0) //check for edge
            table[row_of_the_bomb-1][column_of_the_bomb] += 1;

        //for area "3"
        if(row_of_the_bomb != 0 && column_of_the_bomb != columns-1) //check for edge
            table[row_of_the_bomb-1][column_of_the_bomb+1] += 1;

        //for area "4"
        if(column_of_the_bomb != 0) //check for edge
            table[row_of_the_bomb][column_of_the_bomb-1] += 1;

        //for area "5"
        if(column_of_the_bomb != columns-1) //check for edge
            table[row_of_the_bomb][column_of_the_bomb+1] += 1;

        //for area "6"
        if(row_of_the_bomb != rows-1 && column_of_the_bomb != 0) //check for edge
            table[row_of_the_bomb+1][column_of_the_bomb-1] += 1;

        //for area "7"
        if(row_of_the_bomb != rows-1) //check for edge
            table[row_of_the_bomb+1][column_of_the_bomb] += 1;

        //for area "8"
        if(row_of_the_bomb != rows-1 && column_of_the_bomb != columns-1) //check for edge
            table[row_of_the_bomb+1][column_of_the_bomb+1] += 1;

    }


}

void Minesweeper::show_table(){
    //print the 2D vector table

    int square_of_the_bomb{0};

    for (int r = 1; r <= rows; r++) {
        for (int c = 1; c <= columns; c++){
            square_of_the_bomb = ((r-1)*columns)+c; // find the square of the bomb formula (by given row and column)
            if( find(bombs.begin(), bombs.end(), square_of_the_bomb) != bombs.end() ){
                //si le carré est une bombre, affiche *
                cout << "*" << " ";
            }else if(table[r-1][c-1] == 0){
                //si le carré est vide, affiche un espace vide
                cout << "  ";
            }else{
                //si le carré est un nombre, affiche le nombre
                cout << table[r-1][c-1] << " ";
            }

        }
        cout << endl;
    }

    //affiche la localisation des bombes
    cout << endl << "[ ";
    for(auto a:bombs)
        cout << a << ", ";
    cout << "]" << endl;

}
