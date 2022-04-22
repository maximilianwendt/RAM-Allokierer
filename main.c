//Maximilian Wendt programmierte:
#include <stdio.h>
#include <stdlib.h>


int main(){

    unsigned int j = 0; //Damit das Programm weiß wo es aufgehört hat das Array v mit 1sen vollzuschreiben(So muss nicht immer wieder von vorne angefangen werden, was die performance EXTREM verbessert)
    unsigned long MB = 1024*1024; //1MB= 1024kb * 1024b
    long gewuenschteGroesse = 0;

    unsigned long *v = (unsigned long*) malloc(0* MB); //Erstmal wollen wir vom Betriebssystem nur ein leeres Array damit wir es später vergroessern (reallokieren) koennen

    printf("Lieber Nutzer, wieviel RAM-Speicher in MB soll reserviert werden?\n");
    scanf("%ld", &gewuenschteGroesse);
    
    if(gewuenschteGroesse<=0){
        printf("Es macht keinen Sinn %ld MB Speicher zu reservieren. Das Programm wird beendet.\n", gewuenschteGroesse);
        return 0;
    } 

    scanf("Wird das Programm vorzeitig beendet, ist es nicht moeglich den gewuenschten Speicher zu reservieren. \n");

    for(int i=1;i <= gewuenschteGroesse; i++){
        
        v = (unsigned long*) realloc(v, i* MB); //Pro Durchlauf wird immer ein MB mehr Speicher reserviert

        for(j;j<=(i* MB)/sizeof(long);j++){ //Der angeforderte Speicher muss KOMPLETT mit Daten beschrieben werden, sonst kann deutlich mehr Speicher rerviert werden als eigentlich verfügbar ist
            //Wir fangen also an das Array mit Einsen zu beschreiben, wo wir in der etzten Iteration aufgehört haben(siehe erster Kommentar), bis der angeforderte Speicher komplett mit longs befüllt ist 
            v[j]=1; 
        }

        printf("%d Mb reserviert\n", i);
          
    }

    printf("Es ist moeglich %ld MB bzw. %lf GB Speicher in deinem RAM zu reservieren\n", gewuenschteGroesse, gewuenschteGroesse/1024.0);
    free(v);
    

    return 1;


}