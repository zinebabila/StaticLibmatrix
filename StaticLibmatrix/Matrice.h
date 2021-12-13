#pragma once
#include <iostream>
using namespace std;
namespace algebre {
	template <class t>
	class Matrice
	{
	private:
		//l'etat de l'objet
		int col;
		int ligne;
		t** Matrix;
	public:
		//comportement de l'objet
		Matrice(int c = 0, int l = 0);
		Matrice(const Matrice&) = delete;
		void remplissage(t val);
		Matrice& operator=(const Matrice) = delete;
		Matrice& operator+(const Matrice& c) const;
		Matrice& operator-(const Matrice& c) const;
		Matrice& operator*(const Matrice& c) const;
		void print()const;
		~Matrice();

	};

	template<class t>
	algebre::Matrice<t>::Matrice(int c, int l)
	{
		this->col = c;
		this->ligne = l;
		this->Matrix = new t* [this->ligne];
		for (int i = 0; i < this->ligne; i++) {
			this->Matrix[i] = new t[this->col];
			/*for (int j = 0; j < this->col; j++) {
				this->Matrix[i][j] = 0;
			}*/
		}
	}

	template<class t>
	 void algebre::Matrice<t>::remplissage(t val)
	{
		for (int i = 0; i < this->ligne; i++) {
			for (int j = 0; j < this->col; j++) {
				this->Matrix[i][j] = val;

			}

		}
	}
	template<class t>
	Matrice<t>& algebre::Matrice<t>::operator+(const Matrice& c) const
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

	template<class t>
	Matrice<t>& algebre::Matrice<t>::operator-(const Matrice& c) const
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

	template<class t>
	Matrice<t>& algebre::Matrice<t>::operator*(const Matrice& c) const
	{
		Matrice* matri = new Matrice(c.col, this->ligne);
		int sum;
		if (this->col == c.ligne && this->ligne == c.col) {

			for (int i = 0; i < this->ligne; i++) {

				for (int j = 0; j < this->col; j++) {
					sum = 0;
					for (int k = 0; k < this->col; k++) {
						sum += this->Matrix[i][k] * c.Matrix[k][j];

					}
					matri->Matrix[i][j] = sum;

				}


			}
		}
		return *matri;

	}

	template<class t>
	void algebre::Matrice<t>::print() const
	{

		for (int i = 0; i < this->ligne; i++) {
			for (int j = 0; j < this->col; j++) {
				cout << this->Matrix[i][j] << "\t";

			}
			cout << endl;
		}
	}

	template<class t>
	algebre::Matrice<t>::~Matrice()
	{
		if (this->Matrix != nullptr) {
			for (int i = 0; i < this->ligne; i++) {
				if (this->Matrix[i] != nullptr) {

					delete[] this->Matrix[i];
					this->Matrix[i] = nullptr;
				}
			}
			delete[] this->Matrix;
			this->Matrix = nullptr;
		}
	}

}
