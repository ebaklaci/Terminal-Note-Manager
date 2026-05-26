#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char metin[100];
}not;

void notekle(int *n,not k[]);
void listele(int n,not k[]);
void sil(int *n,not k[]);
void dosyayayaz(int n,not k[]);
void dosyayadanoku();


int main()
{
int secim=-1;
int n=0;
not k[100];

while(secim!=0){
printf("\n------MENU TABLOSU-------\n");
printf("0-programdan cik\n");
printf("1-ekleme\n");
printf("2-listeleme\n");
printf("3-silme\n");
printf("4-dosyaya yazma\n");
printf("5-dosyadan okumak\n");
printf("lutfen 0-5 arasindan sayi seciniz: ");
scanf("%d",&secim);
getchar();

switch(secim){

case 0: printf("\nprogramdan cikis yapiliyor...\n");
break;

case 1: notekle(&n,k);
break;

case 2: listele(n,k);
break;

case 3: sil(&n,k);
break;

case 4: dosyayayaz(n,k);
break;

case 5: dosyayadanoku();
break;

default : printf("\nlutfen 0-5 arasindan bir sayi seciniz!!!\n");
break;
}
}



    return 0;
}

void notekle(int *n,not k[]){
int i;
printf("lutfen notunuzu giriniz: ");
fgets(k[*n].metin,sizeof(k[*n].metin),stdin);
k[*n].metin[strcspn(k[*n].metin,"\n")]=0;
(*n)++;
}

void listele(int n,not k[]){
int i;
printf("\n-----LISTE------\n");
for(i=0;i<n;i++){
printf("%d.not:%s\n",i+1,k[i].metin);
}
}

void sil(int *n,not k[]){
char silinecek[100];
printf("lutfen silinecek metni giriniz: ");
fgets(silinecek,sizeof(silinecek),stdin);
silinecek[strcspn(silinecek,"\n")]=0;

int i,bulundu=0,j;
for(i=0;i<*n;i++){
if(strcmp(k[i].metin,silinecek)==0){
printf("silinecek metin bulundu");
bulundu=1;

for(j=i;j<(*n)-1;j++){
k[j]=k[j+1];
}
(*n)--;
break;
}
}
 if(bulundu==0){
printf("%s bulunamadi",silinecek);
}
}



void dosyayayaz(int n,not k[]){
int i;
FILE *dosya;
dosya=fopen("proje01.txt","w");
if(dosya==NULL){
printf("dosya acilamadi");
return;
}

for(i=0;i<n;i++){
fprintf(dosya,"%s\n",k[i].metin);
}
fclose(dosya);
printf("\ndosyaya yazma basariyla gerceklestirildi");
}

void dosyayadanoku(){
char metin[100];
FILE *dosya;
dosya=fopen("proje01.txt","r");
if(dosya==NULL){
printf("dosya acilamadi");
return;
}
printf("\n------DOSYADAKI NOTLAR------\n");
while(fgets(metin,sizeof(metin),dosya)!=NULL){
printf("%s",metin);
}
fclose(dosya);
printf("\ndosyadan okuma basariyla gerceklestirildi");
}
