//Newton Raphson's Method
#define DERECE 3
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void turevAl(float f[], int derecesi, float ft[]){
    short i;
    
    //polinom türündeki fonksiyonun türevini alır.
    for(i = 1; i < derecesi+1; i++){
        ft[i-1] = f[i]*i;
    }
}

float fHesapla(float f[], int derecesi, float x){
    short i;
    float fSonuc = 0;
    //verilen f fonksiyonunda x i hesaplar
    for(i = 0; i < derecesi+1; i++){
        fSonuc += pow(x,i) * f[i];
    }
    return fSonuc;
}

void iterasyon(float f[], float ft[], int x){
    float xiOnceki = 0, xi = x, fxt, fx;
    int say = 0;

    while(xiOnceki != xi){
        printf("x%d = %f\n", say, xi);
        say++;
        xiOnceki = xi; //xi değerini Önceki olarak saklar
        fx = fHesapla(f, DERECE, xiOnceki);
        fxt = fHesapla(ft, DERECE-1, xiOnceki);
        xi = xiOnceki - (fx / fxt);
    }
    printf("Sonuc: %f", xi);
}

int main(){
    float fx[DERECE+1], fxt[DERECE], fxtt[DERECE-1];
    short i;
    float x;

    //f(x) fonksiyonun kat sayılarını alır
    for(i =  DERECE; i >= 0; i--){
        printf("x^%d:",i);
        scanf("%f",&fx[i]);
    }
    //iterasyon işlemi için başlangıç değerini alır
    printf("x baslangic noktasi:");
    scanf("%f", &x);

    turevAl(fx, DERECE, fxt); //f'(x) bul
    turevAl(fxt, DERECE-1, fxtt); //f''(x) bul

    float fxS = fHesapla(fx, DERECE, x);
    float fxtS = fHesapla(fxt, DERECE-1 ,x);
    float fxttS = fHesapla(fxtt, DERECE-2, x);
    
    if((fxS * fxttS / pow(fxtS, 2)) < 1 && (fxS*fxttS) > 0) 
        iterasyon(fx, fxt, x);
    else printf("Iterasyon islemi yapilamaz!");

    return 0;
}