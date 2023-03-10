//Berk Sunduri 180201145

// Hocam kodumda veriler1 ve veriler 2 dosyasini okuttum ona gore islemler yaptim
//Binary olayini cozemedim her denedigimde noktalar 0.0000 olarak gosteriliyordu hic bir sekilde tam verilere ulasamadim
//(kendi olusturdugum binary dosyasinda bile ayni hatayi aliyordum)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
struct
{
    float x,y,z;
    int r,g,b;
} nokta[10000];
struct
{
    float x2,y2,z2;

} nokta2[84578];




int main()
{

    FILE *veriler1;
    FILE *veriler2;
    FILE *output;

    veriler1=fopen("veriler1.nkt","r");
    veriler2=fopen("veriler2.nkt","r");
    output=fopen("output.nkt","w+");

    char line[10000];

    char line2[84578];

    if(veriler1==NULL)
    {
        printf("Dosya hatali");
        exit(1);
    }
    if(veriler2==NULL)
    {
        printf("Dosya hatali");
        exit(1);
    }
    if(output==NULL)
    {
        printf("Dosya hatali");
        exit(1);
    }





    for(int k=6; k<10005; k++) //veriler1in kontrol mekanizmasi
    {
        nokta[k].x=0.010;
        nokta[k].y=0.010;
        nokta[k].z=0.010;
        nokta[k].r=300;
        nokta[k].g=300;
        nokta[k].b=300;
    }
    for(int k=6; k<84584; k++) //veriler2 kontrol mekanizmasi
    {
        nokta2[k].x2=0.010;
        nokta2[k].y2=0.010;
        nokta2[k].z2=0.010;

    }


    int i = 0;
    int j=0;
    int index2=0;
    int index=0;
    while (fgets(line, sizeof(line), veriler1))//Verilerin x,y,z r,g,b ye atanmasi
    {
        i++;
        if(i > 4 )
        {
            fscanf(veriler1,"%f %f %f %d %d %d",&nokta[index].x,&nokta[index].y,&nokta[index].z,&nokta[index].r,&nokta[index].g,&nokta[index].b);//Noktalarin dosya1den okunup struct a kaydedilmesi
            //printf("%f %f %f %d %d %d\n",nokta[index].x,nokta[index].y,nokta[index].z,nokta[index].r,nokta[index].g,nokta[index].b);//Noktalari Yazdirma
            index++;
        }
    }
    while (fgets(line2, sizeof(line2), veriler2))//Veriler2nin x2,y2,z2  ye atanmasi
    {
        j++;
        if(j > 4 )
        {
            fscanf(veriler2,"%f %f %f",&nokta2[index2].x2,&nokta2[index2].y2,&nokta2[index2].z2);//Noktalarin dosya1den okunup struct a kaydedilmesi
            //printf("%f %f %f \n",nokta2[index2].x2,nokta2[index2].y2,nokta2[index2].z2);//Noktalari Yazdirma
            index2++;
        }

    }


    float dist=0;
    float mini=FLT_MAX;
    float dist1=0;
    float mini1=FLT_MAX;
    int vericont;
printf("# Noktalar dosya format\n");
    printf("VERSION 1\n");
    printf("ALANLAR X Y Z\n");
    printf("ALANLAR X Y Z R G B\n");
    printf("NOKTALAR %d\n",index);
    printf("NOKTALAR %d\n",index2);
    fputs("# Noktalar dosya format\n",output);
    fputs("VERSION 1\n",output);
    fputs("ALANLAR X Y Z\n",output);
    fputs("ALANLAR X Y Z R G B\n",output);
    fprintf(output,"NOKTALAR %d\n",index);
    fprintf(output,"NOKTALAR %d\n",index2);
    int operasyon;
LOOP:
    printf("\n\nBir Islem seciniz:\n");
    printf("1) Dosyalarda ki verilerin tam olup olmadigini kontrol etmek.\n");
    printf("2) Birbirine en yakin noktalarin bilgileri ve ortalama uzakliklari \n");
    printf("3) Tum noktalari icine alacak bir kupun kenar nokta bilgileri\n");
    printf("4) Bir kurenin icinde kalan noktalarin bilgileri ve nokta numaralari\n");
    printf("5) Cikis yap\n");
    printf("Bir islem seciniz:");
    scanf("%d",&operasyon);
    fflush(stdin);

        if(operasyon==1)
        {
            printf("Hangi veriler dosyasini kontrol etmek istersiniz?\n");
        printf("1) Veriler 1 dosyasi\n");
        printf("2) Veriler 2 dosyasi\n");

        printf("Bir dosya seciniz:");
        scanf("%d",&vericont);
        if(vericont==1)//veriler 1 in tam olup olmadigini kontrol etmek
        {
            for(int c=0; c<index; c++) //Verilerin tam olup olmadigini kontrol etmek
            {
                if(nokta[c].x==0.010 || nokta[c].y==0.010 || nokta[c].z==0.010 || nokta[c].r==300 || nokta[c].g==300 || nokta[c].b ==300)
                {
                    printf("Veriler 1 dosyasinda ki %d sirasinda ki deger tam degildir.\n",c);
                    fprintf(output,"Veriler 1 dosyasinda ki %d sirasinda ki deger tam degildir.\n",c);
                    break;
                }
                else
                    printf("Veriler 1 dosyasinda ki degerler tamdir\n");
                    fprintf(output,"Veriler 1 dosyasinda ki degerler tamdir\n");
                break;

            }

        }
        if(vericont==2)//veriler 2nin tam olup olmadigini kontrol etmek
        {
            for(int c=0; c<index2; c++) //Veriler2nin tam olup olmadigini kontrol etmek
            {
                if(nokta2[c].x2==0.010 || nokta2[c].y2==0.010 || nokta2[c].z2==0.010)
                {
                    printf("Veriler 2 dosyasinda ki %d sirasinda ki deger tam degildir.\n",c);
                    fprintf(output,"Veriler 2 dosyasinda ki %d sirasinda ki deger tam degildir.\n",c);
                    break;
                }
                else
                    printf("Veriler 2 dosyasinda ki degerler tamdir.\n");
                    fprintf(output,"Veriler 2 dosyasinda ki degerler tamdir.\n");
                break;
            }
        }


        }




        if(operasyon==2)//en yakin veri kontrolu
        {
            fflush(stdin);
       float aver=0;
        int n=0;
        float ort;
        int vericont2;
        printf("Islem yapmak istediginiz dosyayi secin:\n");
        printf("1)Veriler 1\n");
        printf("2)Veriler 2\n");
        scanf("%d",&vericont2);
        if(vericont2==1)
        {printf("Isleminiz yapiliyor lutfen bekleyin...\n");
              for(int u=0; u<index; u++) //distance control of veriler 1
            {

                for(int o=u+1; o<index-1; o++)
                {

                    dist = sqrt( pow((nokta[o].x- nokta[u].x),2) +pow((nokta[o].y - nokta[u].y),2)+pow((nokta[o].z-nokta[u].z),2));
                               n++;
                                aver=aver+dist;
                    if(dist<mini)
                    {
                        mini=dist;
                    }

                }

            }
            ort=aver/n;

            printf("En yakin uzaklik %f ve ortalama uzaklik: %f ",mini,ort);
            fprintf(output,"En yakin uzaklik %f ve ortalama uzaklik: %f",mini,ort);
        }
        if(vericont2==2)
        {
            printf("Isleminiz yapiliyor lutfen bekleyin...\n");
              float aver1=0;
            float ort1=0;
            int n1;

            for(int p=0; p<index2; p++) //distance control of veriler2
            {
                for(int a=p+1; a<index2-1; a++)
                {
                    dist1 = sqrt( pow((nokta2[p].x2 - nokta2[a].x2),2) +pow((nokta2[p].y2 - nokta2[a].y2),2)+pow((nokta2[p].z2-nokta2[a].z2),2));
                                n1++;
                    if(dist1<mini1)
                    {
                        mini1=dist1;
                    }
                    aver1=aver1+dist1;
                }
            }
            ort1=aver1/n1;
            printf("En yakin uzaklik %f ve ortalama uzaklik: %f ",mini1,ort1);
             fprintf(output,"En yakin uzaklik %f ve ortalama uzaklik: %f ",mini1,ort1);

        }

        }

        if(operasyon==3)//Kup bilgileri

        {
            printf("Verilen verilerde ki Kup Kenarlarinin Bilgileri:\n");
             int locationX=0,locationRX,locationRY,locationRZ;
            int locationY=0,locationGX,locationGY,locationGZ;
            int locationZ=0,locationBX,locationBY,locationBZ;
            float maximumX=nokta[0].x;
            float maximumY=nokta[0].y;
            float maximumZ=nokta[0].z;
            printf("\nVeriler1 dosyasi icin:\n");
            fprintf(output,"\nVeriler1 dosyasi icin:\n");
            for(int c=1;c<index;c++)
            {
                if(nokta[c].x>maximumX)
                {
                    maximumX=nokta[c].x;
                    locationRX=nokta[c].r;
                    locationGX=nokta[c].g;
                    locationBX=nokta[c].b;
                    locationX=c;
                }
            }
            printf("Nokta degeri(X:%f, Bulundugu sira:%d, Renk Verileri: %d %d %d\n",maximumX,locationX+6,locationRX,locationGX,locationBX);
             fprintf(output,"Nokta degeri(X:%f, Bulundugu sira:%d, Renk Verileri: %d %d %d\n",maximumX,locationX+6,locationRX,locationGX,locationBX);
            for(int c=1;c<index;c++)
            {
                if(nokta[c].y>maximumY)
                {
                    maximumY=nokta[c].y;
                    locationRY=nokta[c].r;
                    locationGY=nokta[c].g;
                    locationBY=nokta[c].b;
                    locationY=c;
                }
            }
            printf("Nokta degeri(Y):%f, Bulundugu sira:%d, Renk Verileri: %d %d %d\n",maximumY,locationY+6,locationRY,locationGY,locationBY);
            fprintf(output,"Nokta degeri(Y):%f, Bulundugu sira:%d, Renk Verileri: %d %d %d\n",maximumY,locationY+6,locationRY,locationGY,locationBY);
            for(int c=1;c<index;c++)
            {
                if(nokta[c].z>maximumZ)
                {
                    maximumZ=nokta[c].z;
                    locationRZ=nokta[c].r;
                    locationGZ=nokta[c].g;
                    locationBZ=nokta[c].b;
                    locationZ=c;
                }
            }
            printf("Nokta degeri(Z):%f, Bulundugu sira:%d, Renk Verileri: %d %d %d\n",maximumZ,locationZ+6,locationRZ,locationGZ,locationBZ);
            fprintf(output,"Nokta degeri(Z):%f, Bulundugu sira:%d, Renk Verileri: %d %d %d\n",maximumZ,locationZ+6,locationRZ,locationGZ,locationBZ);
            float maximumX2=nokta2[0].x2;
            float maximumY2=nokta2[0].y2;
            float maximumZ2=nokta2[0].z2;
            int locationX2=0;
            int locationY2=0;
            int locationZ2=0;
            printf("\nVeriler2 dosyasi icin:\n");
            fprintf(output,"\nVeriler2 dosyasi icin:\n");
            for(int c=1;c<index2;c++)
            {
                if(nokta2[c].x2>maximumX2)
                {
                    maximumX2=nokta2[c].x2;
                    locationX2=c;
                }
            }
            printf("Nokta degeri(X):%f, Bulundugu sira:%d\n",maximumX2,locationX2+6);
            fprintf(output,"Nokta degeri(X):%f, Bulundugu sira:%d\n",maximumX2,locationX2+6);
            for(int c=1;c<index2;c++)
            {
                if(nokta2[c].y2>maximumY2)
                {
                    maximumY2=nokta2[c].y2;
                    locationY2=c;
                }
            }
            printf("Nokta degeri(Y):%f, Bulundugu sira:%d\n",maximumY2,locationY2+6);
            fprintf(output,"Nokta degeri(Y):%f, Bulundugu sira:%d\n",maximumY2,locationY2+6);
            for(int c=1;c<index2;c++)
            {
                if(nokta2[c].z2>maximumZ2)
                {
                    maximumZ2=nokta2[c].z2;
                    locationZ2=c;
                }
            }
            printf("Nokta degeri(Z):%f, Bulundugu sira:%d\n",maximumZ2,locationZ2+6);
            fprintf(output,"Nokta degeri(Z):%f, Bulundugu sira:%d\n",maximumZ2,locationZ2+6);

        }
        if(operasyon==4)
        {
            int vericont3;
            printf("Hangi dosyada islem yapmak istersiniz:\n");
            printf("1)Veriler1\n");
            printf("2)Veriler2\n");
            scanf("%d",&vericont3);
            if(vericont3==1)
            {
                float cx,cy,cz;
            int r;
            float x1,y1,z1;
            float kure=0;
            int insideValue=0;
            printf("Merkezin 3 boyutlu koordinatini giriniz:(X Y Z)\n");
            fprintf(output,"\nMerkezin 3 boyutlu koordinatini giriniz:(X Y Z)\n");
            scanf("%f %f %f",&cx,&cy,&cz);
            fprintf(output,"%f %f %f\n",cx,cy,cz);
            printf("Yaricapi giriniz(intvalue):\n");
            fprintf(output,"\nYaricapi giriniz(intvalue):\n");
            scanf("%d",&r);
            fprintf(output,"%d\n",r);
            for(int z=0;z<index;z++)
            {
                x1=pow((nokta[z].x-cx),2);
                y1=pow((nokta[z].y-cy),2);
                z1=pow((nokta[z].z-cz),2);
            kure=sqrt(x1+y1+z1);
            if(kure<r)
            {
                printf("X:%f Y:%f Z:%f\n",nokta[z].x,nokta[z].y,nokta[z].z);
                fprintf(output,"X:%f Y:%f Z:%f\n",nokta[z].x,nokta[z].y,nokta[z].z);
                insideValue++;
            }
            }
            printf("Veriler1 Dosyasi icin\n");
            printf("\nKurenin icinde %d tane deger vardir\n",insideValue);
            fprintf(output,"Veriler1 Dosyasi icin\n");
            printf(output,"\nKurenin icinde %d tane deger vardir\n",insideValue);
            }
            if(vericont3==2)
            {
                float cx1,cy1,cz1;
            int r1;
            float x12,y12,z12;
            float kure1=0;
            int insideValue2=0;
            printf("Merkezin 3 boyutlu koordinatini giriniz:(X Y Z)\n");
            fprintf(output,"\nMerkezin 3 boyutlu koordinatini giriniz:(X Y Z)\n");
            scanf("%f %f %f",&cx1,&cy1,&cz1);
            fprintf(output,"%f %f %f\n",cx1,cy1,cz1);
            printf("Yaricapi giriniz(intvalue):\n");
            fprintf(output,"\nYaricapi giriniz(intvalue):\n");
            scanf("%d",&r1);
            fprintf(output,"%d\n",r1);
            for(int z=0;z<index2;z++)
            {
                x12=pow((nokta2[z].x2-cx1),2);
                y12=pow((nokta2[z].y2-cy1),2);
                z12=pow((nokta2[z].z2-cz1),2);
            kure1=sqrt(x12+y12+z12);
            if(kure1<r1)
            {
                printf("X:%f Y:%f Z:%f\n",nokta2[z].x2,nokta2[z].y2,nokta2[z].z2);
                fprintf(output,"X:%f Y:%f Z:%f\n",nokta2[z].x2,nokta2[z].y2,nokta2[z].z2);
                insideValue2++;
            }
            }
            printf("Veriler2 Dosyasi icin:\n");
            printf("\nKurenin icinde %d tane deger vardir\n",insideValue2);
            fprintf(output,"Veriler2 Dosyasi icin:\n");
            fprintf(output,"\nKurenin icinde %d tane deger vardir\n",insideValue2);
            }

            }


        if(operasyon==5)
        {
            exit(1);
        }
        if(operasyon<1||operasyon>5)
        {
            printf("Hatali giris, Tekrar seciniz.\n");
        }







    goto LOOP;




    fclose(veriler1);
    fclose(veriler2);
    fclose(output);
    return 0;
}
