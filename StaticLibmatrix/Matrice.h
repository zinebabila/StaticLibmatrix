#pragma once
namespace algebre {
	class Matrice
	{
	private:
		//l'etat de l'objet
		int col;
		int ligne;
		int** Matrix;
	public:
		//comportement de l'objet
			Matrice(unsigned int c=0, unsigned int l=0);
			Matrice(const Matrice&) = delete;
			void remplissage(int val);
			Matrice& operator=(const Matrice) = delete;
			
			Matrice& operator+(const Matrice& c) const;
			Matrice & operator-(const Matrice& c) const;
			Matrice & operator*(const Matrice& c) const;
			void print()const;
			~Matrice();

	};
}


