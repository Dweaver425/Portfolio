#include <iostream>
#include <cmath>

using namespace std;
void TwoLegs();
void AdjHyp();
void OppAdj();


int main (){
   
    int typeTri;
cout << "What sides are given? \n "
     << "1. Opposite and Adjacent (Given SIN ratio) \n " 
     << "2. Adjacent and Hypotenuse (Given COS ratio)\n "
     << "3. Opposite and Hypotenuse (Given TAN ratio)\n "
     << "Enter the type of Triangle: ";
cin >> typeTri;

if (typeTri == 1){
    OppAdj();
    }
if (typeTri == 2){
    AdjHyp();
    }
if (typeTri == 3){
    TwoLegs();
    }

    if (typeTri > 3 || typeTri < 0){
        cout << "Skill issue\n";
    }

    cout << "Imagine having to use a calculator I programmed Zzz....\n";
   
}

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


void OppAdj(){
int sin_num, sin_den;
    cout << "Enter the Opposite over Adjcent of the sine ratio: ";
    cin >> sin_num >> sin_den;

    double cos_val = sqrt(1 - pow((double)sin_num / sin_den, 2));
    double tan_val = ((double)sin_num / sin_den) / cos_val;
    double csc_val = 1 / ((double)sin_num / sin_den);
    double sec_val = 1 / cos_val;
    double cot_val = 1 / tan_val;

    int cos_num = round(cos_val * sin_den);
    int cos_den = sin_den;
    int tan_num = round(tan_val * cos_den);
    int tan_den = cos_num;
    int csc_num = sin_den;
    int csc_den = sin_num;
    int sec_num = cos_den;
    int sec_den = cos_num;
    int cot_num = tan_den;
    int cot_den = tan_num;

    int gcd1 = gcd(cos_num, cos_den);
    int gcd2 = gcd(tan_num, tan_den);
    int gcd3 = gcd(csc_num, csc_den);
    int gcd4 = gcd(sec_num, sec_den);
    int gcd5 = gcd(cot_num, cot_den);

    cos_num /= gcd1;
    cos_den /= gcd1;
    tan_num /= gcd2;
    tan_den /= gcd2;
    csc_num /= gcd3;
    csc_den /= gcd3;
    sec_num /= gcd4;
    sec_den /= gcd4;
    cot_num /= gcd5;
    cot_den /= gcd5;

    cout << "Sine: " << sin_num << "/" << sin_den << endl;
    cout << "Cosine: " << cos_num << "/" << cos_den << endl;
    cout << "Tangent: " << tan_num << "/" << tan_den << endl;
    cout << "Cosecant: " << csc_num << "/" << csc_den << endl;
    cout << "Secant: " << sec_num << "/" << sec_den << endl;
    cout << "Cotangent: " << cot_num << "/" << cot_den << endl;
}



void AdjHyp(){
    int cos_num, cos_den;
    cout << "Enter the Adjacent over Hypotenuse of the cosine ratio: ";
    cin >> cos_num >> cos_den;

    double sin_val = sqrt(1 - pow((double)cos_num / cos_den, 2));
    double tan_val = sin_val / ((double)cos_num / cos_den);
    double csc_val = 1 / sin_val;
    double sec_val = 1 / ((double)cos_num / cos_den);
    double cot_val = 1 / tan_val;

    int sin_num = round(sin_val * cos_den);
    int sin_den = cos_den;
    int tan_num = round(tan_val * cos_den);
    int tan_den = cos_num;
    int csc_num = sin_den;
    int csc_den = sin_num;
    int sec_num = cos_den;
    int sec_den = cos_num;
    int cot_num = tan_den;
    int cot_den = tan_num;

    int gcd1 = gcd(sin_num, sin_den);
    int gcd2 = gcd(tan_num, tan_den);
    int gcd3 = gcd(csc_num, csc_den);
    int gcd4 = gcd(sec_num, sec_den);
    int gcd5 = gcd(cot_num, cot_den);

    sin_num /= gcd1;
    sin_den /= gcd1;
    tan_num /= gcd2;
    tan_den /= gcd2;
    csc_num /= gcd3;
    csc_den /= gcd3;
    sec_num /= gcd4;
    sec_den /= gcd4;
    cot_num /= gcd5;
    cot_den /= gcd5;

    cout << "Sine: " << sin_num << "/" << sin_den << endl;
    cout << "Cosine: " << cos_num << "/" << cos_den << endl;
    cout << "Tangent: " << tan_num << "/" << tan_den << endl;
    cout << "Cosecant: " << csc_num << "/" << csc_den << endl;
    cout << "Secant: " << sec_num << "/" << sec_den << endl;
    cout << "Cotangent: " << cot_num << "/" << cot_den << endl;
}





void TwoLegs() {
    int leg1, leg2;
    cout << "Enter the lengths of the two legs of the right triangle: ";
    cin >> leg1 >> leg2;

    int hypotenuse = sqrt(pow(leg1, 2) + pow(leg2, 2));

    int gcd1 = gcd(leg1, hypotenuse);
    int gcd2 = gcd(leg2, hypotenuse);
    int gcd3 = gcd(leg1, leg2);

    int sin_num = leg1 / gcd1;
    int sin_den = hypotenuse / gcd1;
    int cos_num = leg2 / gcd2;
    int cos_den = hypotenuse / gcd2;
    int tan_num = leg1 / gcd3;
    int tan_den = leg2 / gcd3;

    cout << "Sine: " << sin_num << "/" << sin_den << endl;
    cout << "Cosine: " << cos_num << "/" << cos_den << endl;
    cout << "Tangent: " << tan_num << "/" << tan_den << endl;
    cout << "Cosecant: " << sin_den << "/" << sin_num << endl;
    cout << "Secant: " << cos_den << "/" << cos_num << endl;
    cout << "Cotangent: " << tan_den << "/" << tan_num << endl;

  
}


