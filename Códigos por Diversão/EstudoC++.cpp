#include <iostream>
#include <iomanip>
#include <stdlib.h>

class Complex{
	
	private:
		int real;
		int img;
	public:
		Complex(int real,int img){
			
			setReal(real);
			setImg(img);
		}
		
		int getReal(){ return this->real;}
		
		int getImg(){ return this->img;}
		
		void setReal(int real){this->real = real;}
		
		void setImg(int img){this->img = img;}
		
		Complex operator + (Complex c)
		{	
			return Complex(this->getReal() + c.getReal(),this->getImg() + c.getImg());
		}
		
		Complex operator = (Complex c)
		{
			c = Complex(this->getReal(),this->getImg());
			return c;
		}
		
		//friend Complex operator* (int a);
		
		~Complex(){
			delete &real;
			delete &img;
		}
	
};

/*Complex :: operator* (int a){
	return a*c;
}*/

int main()
{
	
	char nome[7];
	std::cin.getline(nome,4).std::cin.peek().getline(nome,3);
	std::cout << nome;
		
}


