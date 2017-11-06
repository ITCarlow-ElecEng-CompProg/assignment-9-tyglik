/** Lab 09 - Sphere Calculator
 *
 * Martina Nunvarova
 * 6/11/2017
 */

///includes
#include <iostream>
#include <stdio.h>

///define PI
#define PI 3.141592654

///namespace
using namespace std;

///Input:
///     prompt - the text to be displayed
///     zeroOptions - 0=no option, only positive value; 1=Zero and positive; 2=Any real number
double getDoubleValue(string prompt, int zeroOptions)
{
    double output;
    char outOK;

    do {
        outOK=1;
        cout << prompt;
        fflush(stdout);
        fflush(stdin);
        cin>>output;
        if (output<0) {
            if (zeroOptions<2)
                outOK=0;
        } else if (output==0) {
            if (zeroOptions<1)
                outOK=0;
        }
        if (!outOK)
            cout << "Illegal input. ";
    } while (!outOK);
    return output;
}

/// using a function to calculate, using pointers to pass parametres in and out
void fx(double *r, double *v, double *s)
{
    *v=(4*PI**r**r**r/3.0);
    *s=(4*PI* *r * *r);
}

///Main Function
int main()
{
    double r,s,v;                                                           ///Declare variables

    cout << "Sphere calculator" << endl<<endl<<endl;                        ///Tell user, it's sphere calculator
    r=getDoubleValue("Please enter a radius of the sphere: ",1);            ///Force them to enter positive double or 0

    fx(&r,&v,&s);                                                           ///Call a function as per assignment, with pointer parametres

    cout <<endl<<endl<< "~The sphere claculated~" << endl << endl << "Radius: " << r<<endl<<"Surface: "<<s<<endl<<"Volume: "<<v<<endl<<endl; ///notify user

    getDoubleValue("Enter anything to quit",2);                             ///wait for something to be entered

    return 0;                                                               ///exit to OS no errors
}
