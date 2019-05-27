#include <iostream>
#include <fstream>

using namespace std;
int howManyFlags(int R, int G, int Z);
int flagsCalc(int minTapes);
void setValuesToZero(int* stacks);
void leftTapes(int flags, int* stacks);
int main()
{
    setlocale(LC_ALL, "Lithuanian"); //kad komentarai būtų lietuviški
    ifstream U1("U1.txt");
    ofstream U1rez("U1rez.txt");
    int flags;
    int n;  //pradinių kruvelų skaičius
    int stacks[3]; //kruvelės
    int laikinaSuma;
    string spalva;

    setValuesToZero(stacks); //deklaruoju masyvo elementus

    U1>>n;
   for(int i=0; i<n; i++){  //Pagal spalvas susumuoju juosteles
        U1>>spalva;
        if(spalva == "R"){
            U1>>laikinaSuma;
            stacks[0]+=laikinaSuma;
        }else if(spalva == "G"){
            U1>>laikinaSuma;
            stacks[1]+=laikinaSuma;
        }else{
            U1>>laikinaSuma;
            stacks[2]+=laikinaSuma;
        }
    }

    flags = howManyFlags(stacks[0], stacks[1], stacks[2]); //Skaičiuoju vėliavų kiekį
    leftTapes(flags, stacks);  //Skaičiuoju juostelių likutį

    U1rez<<flags;   //Rezultatai
    U1rez<<"G = "<<stacks[1];
    U1rez<<"Z = "<<stacks[2];
    U1rez<<"R = "<<stacks[0];

    U1.close();
    U1rez.close();
    return 0;
}
void leftTapes(int flags, int* stacks){ //'*' naudoju dėl tiesioginio kreipimosi į atminties adresą
    for(int i=0; i<3; i++){
        stacks[i] -= flags*2; //Iš visų juostelių atima kiek panaudota
    }
}
void setValuesToZero(int* stacks){
    for(int i=0; i<3; i++){
        stacks[i] = 0;
    }
}
int flagsCalc(int minTapes){ //minTapes yra mažiausias vienos spalvos juostelių skaičius, kintamąjį padalinę gaunam vėliavėles
    int flags;
    flags = minTapes/2;
    return flags;
}
int howManyFlags(int R, int G, int Z){ //Funkcija atsakinga už mažiausią juostelių kiekio suradimą bei vėliavėlių grąžinimą
    int flags;
    if(R<=G && R<=Z){
        flags = flagsCalc(R);
    }else if(G<=R && G<=Z){
        flags = flagsCalc(G);
    }else{
        flags = flagsCalc(Z);
    }
    return flags;
}




