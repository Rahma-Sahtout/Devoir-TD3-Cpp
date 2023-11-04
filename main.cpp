//exercice 1
#include<iostream>
#include <cmath>
#include <complex>
using namespace std;

class Complex{
private:
   double reel;
    double imag;
public:
    Complex(double re,double im ): reel(re) , imag(im){}
    Complex addition(Complex autre){
        return Complex(reel + autre.reel , imag + autre.imag);
    }
    Complex soustraction(Complex autre){
        return Complex(reel-autre.reel , imag-autre.reel);
    }
    Complex multiplication(Complex autre){
        double nmbreel=(reel*autre.reel) + (imag*autre.imag);
        double nmbimag= (reel*autre.imag) + (imag*autre.reel);
        return Complex(nmbreel,nmbimag);
    }
    Complex division(Complex autre ){
        double denom= pow(autre.reel, 2)+ pow(autre.imag, 2);
        double nmbreel=(reel*autre.reel + imag*autre.imag)/denom;
        double nmbimag= (reel*autre.imag + imag*autre.reel)/denom;
        return Complex(nmbreel,nmbimag);
    }
    void display (){
        cout<<reel<<"+"<<imag<<"i"<<endl;
    }
};
int main (){
    double reel1,reel2,imag1,imag2;
    cout<< "entrez la partie reel du premier nombre complex ";
    cin>>reel1;
    cout<< "entrez la partie imaginaire du premier nombre complex ";
    cin>>imag1;
    cout<< "entrez la partie reel du deuxieme nombre complex ";
    cin>>reel2;
    cout<< "entrez la partie imaginaire du deuxieme nombre complex ";
    cin>>imag2;
    Complex results(0,0);
    Complex nombrecomplex1(reel1,imag1);
    Complex nombrecomplex2(reel2,imag2);
   char choix;
    cout<<"entre loperation que vous souhaitez";
    cin>>choix;
    switch (choix) {
        case'1':
            results= nombrecomplex1.addition(nombrecomplex2);break;
        case'2':
            results= nombrecomplex1.soustraction(nombrecomplex2);break;
        case'3':
            results= nombrecomplex1.multiplication(nombrecomplex2);break;
        case'4':
            results= nombrecomplex1.division(nombrecomplex2);break;

        default:
            cout<<"choix invalide"<<endl;
            return 1;
    }
    cout<<"\nresults"<<endl;

   results.display();
    return 0;
}
