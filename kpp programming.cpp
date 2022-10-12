// NAMA       : Ahmad Aqbil Na'im
// NRP        : 5024221035
// Jurusan    : Teknik Komputer

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

double A = SUDUT*3.14159/180;

float mencari_V0(int xmax)
{
    float v = sqrt((xmax*GRAVITASI)/(sin(2*A)));
    
    return v;
}

int mencari_x_max(int v)
{
    int max = (pow(v,2)*sin(2*A)) / GRAVITASI;
    
    return max;
}

int speed_dgn_loss(int v)
{
    if(v>=1 && v<=10){
        v -= 1;
    }
    else if(v>=11 && v<=20){
        v -= 3;
    }
    else if(v>=21 && v<=30){
        v -= 5;
    }
    return v;
}

float speed_no_loss(float v)
{
    if(v>=1 && v<=10){
        v += 1;
    }
    else if(v>=11 && v<=20){
        v += 3;
    }
    else if(v>=21 && v<=30){
        v += 5;
    }
    return v;
}

int main() {
    /* tulis kode utama kalian disini */
    
    int v;
    
    /* input adalah kecepatan tangensial maksimum roller */
    
    std::cin >> v;
    
    int v0 = speed_dgn_loss(v);
    int xmax = mencari_x_max(v0);
    float vtan = speed_no_loss( mencari_V0(xmax) );

    std::cout << xmax << " " << vtan << std::endl;
    
    return 0;
}