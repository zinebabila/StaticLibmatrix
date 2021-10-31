#pragma once
namespace algebre {
	class Matrice
	{
	private:
		int col;
		int ligne;
		int** Matrix;
	public:
			Matrice(int c=0, int l=0);
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


