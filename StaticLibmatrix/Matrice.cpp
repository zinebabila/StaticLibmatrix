#include "pch.h"
#include "Matrice.h"
#include <iostream>
using namespace std;
using namespace algebre;
algebre::Matrice::Matrice(int c, int l)
{
    this->col = c;
    this->ligne = l;
    this->Matrix = new int* [this->ligne]; 
    for (int i = 0; i < this->ligne; i++) {
       this->Matrix[i] = new int[this->col];
       for (int j = 0; j < this->col; j++) {
           this->Matrix[i][j] = 0;
       }
    }
   
}

void algebre::Matrice::remplissage(int val)
{
    for (int i = 0; i < this->ligne; i++) {
        for (int j = 0; j < this->col; j++) {
            this->Matrix[i][j] = val;

        }
       
    }
}

Matrice & algebre::Matrice::operator+(const Matrice& c) const
{
    Matrice* matri = new Matrice(this->col, this->ligne);
    if (this->col == c.col && this->ligne == c.ligne) {
       
        for (int i = 0; i < this->ligne; i++) {
            for (int j = 0; j < this->col; j++) {
                matri->Matrix[i][j] = this->Matrix[i][j] + c.Matrix[i][j];
            }
        }
    }
    return *matri;
    
}

Matrice & algebre::Matrice::operator-(const Matrice& c) const
{
    Matrice* matri = new Matrice(this->col, this->ligne);
    if (this->col == c.col && this->ligne == c.ligne) {
        for (int i = 0; i < this->ligne; i++) {
            for (int j = 0; j < this->col; j++) {
                matri->Matrix[i][j] = this->Matrix[i][j] - c.Matrix[i][j];

            }

        }
    }
    return *matri;
}

Matrice& algebre::Matrice::operator*(const Matrice& c) const
{
    Matrice* matri = new Matrice(c.col, this->ligne);
    
    if (this->col == c.ligne && this->ligne == c.col) {
      
        for (int i = 0; i < this->ligne; i++) {
            for (int j = 0; j < this->col; j++) {
                for(int k=0;k<c.col;k++)
                matri->Matrix[i][j] = this->Matrix[i][k] * c.Matrix[k][j];

            }

        }
       
   }
    return *matri;
    
}

void algebre::Matrice::print() const
{
    for (int i = 0; i < this->ligne; i++) {
        for (int j = 0; j < this->col; j++) {
            cout << this->Matrix[i][j] << "\t";
            
        }
        cout << endl;
    }
}

algebre::Matrice::~Matrice()
{
    if (this->Matrix != nullptr) {
        for (int i = 0; i < this->ligne; i++) {
            if (this->Matrix[i] != nullptr) {

                delete this->Matrix[i];
                this->Matrix[i] = nullptr;
            }
        }
        delete this->Matrix;
        this->Matrix = nullptr;
    }
    
}
