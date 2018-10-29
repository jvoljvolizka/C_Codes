//Dijsktra Algorithm
//shortest path - navigasyon - başlangıç noktası seçip en kısa yolu bulan algoritma
#include <stdio.h>
#define SONSUZ 1000000000
#define MTS 10

void dijkstra(int Adj[MTS][MTS], int ts, int bt){
    int mesafe[MTS] = {0}, cost[MTS][MTS], ziyaret[MTS] = {0}, i, j, k, std, sti, ot[MTS] = {0};

    //komşuluk matrisinden yararlanarak maliyet(cost) matrisi oluşturur
    for(i = 0; i < ts; i++){
        for(j = 0; j < ts; j++){
            //eğer komşuluk matrisindeki değer 0 değil ise o değeri maliyet(cost) olarak alır
            if(Adj[i][j] != 0){
                cost[i][j] = Adj[i][j];
            }
            //komşuluk matrisindeki değer 0 ise (yani komşu değillerse) maliyeti(cost) sonsuz olarak alır
            else{
                cost[i][j] = SONSUZ;
            }
        }
    }

    ziyaret[bt] = 1; //başlangıç tepesini ziyaret edildi olarak işaretler
    //başlangıç tepesinden ziyaret edilmemiş tepelere olan mesafe değerini, maliyet(cost) matrisinden alır
    for(i = 0; i < ts; i++){
        if(!ziyaret[i])
            mesafe[i] = cost[bt][i];
    }
    

    //ilk tepe için yukarda çalıştı ve son tepe için çalışmasına gerek yok bu yüzden ts-2
    for(k = 0 ; k < ts-2 ; k++){
        std = SONSUZ;
        //sıradaki tepeyinin değerini(ziyaret edilmemiş en küçük değer)(std) ve indisini(sti) bulur
        for(i = 0; i < ts; i++){
            if(mesafe[i] < std && !ziyaret[i]){
                std = mesafe[i];
                sti = i;
            }
        }
        ziyaret[sti] = 1; //sıradaki tepeyi ziyaret edildi olarak işaretler
        //burdan itibaren sonraki tepe değeri(sti), şimdi tepe değeri olarak düşünülebilir

        for(i = 0; i < ts; i++){
            //şimdiki tepe değeri(std) + bu tepeden -> i tepesine olan yol, mevcut mesafe değerinden küçükse
            //ve ziyaret edilmemişse
            if((std + cost[sti][i] < mesafe[i]) && !ziyaret[i]){
                //yeni mesafeyi şimdiki tepenin değeri + sonraki tepeye olan uzaklık olarak saklar 
                mesafe[i] = std + cost[sti][i]; 
                ot[i] = sti; //şimdiki tepenin indisini(sti) önceki tepe(ot) olarak saklar
            }
        }


    }

    //sonuçları ekrana yazdırır
    printf("Baslangic Tepesi: %d\n", bt);
    for(i = 0; i < ts; i++) {
        printf("%d -> %d \nYol: %d<", i, mesafe[i], i);

        j = i;
        while(ot[j] != 0){//başlangıç tepesine ulaşana kadar çalışır
            printf("%d<", ot[j]);
            j = ot[j];
        }
        printf("%d\n", bt);
    }
}


int main(){
    int Adj[MTS][MTS];
    int tepeSayisi, baslangicTepesi, i, j;

    //tepe sayısını alır
    printf("Tepe sayisi(en fazla %d girilebilir):", MTS);
    scanf("%d", &tepeSayisi);

    //komşuluk matrisini alır
    printf("Komsuluk matrisini giriniz:\n");
    for(i = 0; i < tepeSayisi; i++){
        for(j = 0; j < tepeSayisi; j++){
            scanf("%d", &Adj[i][j]);
        }
    }

    //başlangıç tepesini alır
    printf("Baslangic Tepesini girin(ilk tepe 0 olacak sekilde):");
    scanf("%d", &baslangicTepesi);

    //alınan değerleri fonksiyona yollar
    dijkstra(Adj, tepeSayisi, baslangicTepesi);
    

    return 0;
}



