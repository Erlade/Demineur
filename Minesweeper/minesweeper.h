#ifndef MINESWEEPER_H
#define MINESWEEPER_H


#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <unistd.h>

using namespace std;

class Minesweeper
{
private:
    int rows; //lignes, données par l'utilisateur
    int columns; //colonnes, données par l'utilisateur
    int max_size; //lignes*colonnes
    int bomb_count; //total des bombes, donné par l'utilisateur
    vector<vector<int>> table; //plateau principal du jeu
    vector<int> bombs; //le vecteur qui contient la localisation des bombes

    int find_column(int); //trouve les colonnes du plateau
    int find_row(int,int); //trouve les lignes du plateau avec le nombre de colonnes connu

    void create_table(); //1. Création du plateau
    void add_bombs(); //2. Création de bombes aléatoires
    void add_numbers();//3. Ajout des nombres autour des bombes

    void show_table(); //4. Affiche le plateau dans le Command Prompt

public:
    Minesweeper(int columns_get=9, int rows_get=9, int bomb_count_get=10);
    ~Minesweeper();

};


#endif // MINESWEEPER_H
