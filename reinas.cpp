#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;
void mostrarTabla();
void llenarTabla();
void funcionIndeonidad();
int tabla[8][8];

int main(){
    llenarTabla();
    mostrarTabla();
    funcionIndeonidad();

    return 0;
}


void funcionIndeonidad(){
    int total = 28;
    int countF=0, contadorF=0;
    for (int i = 0; i < 8;i++){
        countF =0;
        for (int j = 0; j < 8;j++){ 
            if(tabla[i][j]==1){countF++;};
        }
        contadorF += (countF-1 > 0) ? (countF - 1) : 0;
    }

    int countD = 0, countI = 0, contadorD=0;
    for (int i = 0; i < 8;i++){
        for (int j = 0; j < 8;j++){
            if(tabla[i][j]==1){
                countD = 0;countI = 0;
                for (int id = i + 1; id < 8;id++){
                    for (int jd = 0; jd < 8;jd++){
                        if(abs(j-jd) == abs(i-id) && tabla[id][jd]==1){
                            if(jd<j && countI<1){countI++;}
                            if(j<jd && countD<1){countD++;}
                        }
                    }
                }
                contadorD = contadorD + countD + countI;
            }
        }
    }
    cout <<endl<< "Cantidad inicial:  " << total<< endl;
    cout <<"Ataques diagonales: "<<contadorD<< endl;
    cout <<"Ataques en fila:    "<<contadorF<< endl;
    cout << "Cantidad final:    "<< total - contadorD - contadorF;

} 

void llenarTabla(){
    srand(time(0));
    for (int j = 0; j < 8;j++){
        for (int i = 0; i < 8;i++){
            tabla[i][j] = 0;
            if(i==7){tabla[rand() % 8][j]=1;}
        }
    }
}

void mostrarTabla(){
    cout << "           8 Reinas" << endl;
    cout << "---------------------------------"<<endl;
    for (int i = 0; i < 8;i++){
        cout << "| ";
        for (int j = 0; j < 8;j++){
            cout << tabla[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "---------------------------------";
}