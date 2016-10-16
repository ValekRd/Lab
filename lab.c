#ifndef MY_LIB_H_INCLUDED
#define MY_LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Используя метод наименьших квадратов по точкам рассчитываем наилучшее 'b' из уравнения y=a+bx (стр. 39)
float  Ideal_b(float  Y[], float  X[],float  n);

//Рассчитываем сигму погрешность коэффициента 'b' (стр. 39)
float  Sigma_Pogreshnost_b(float  Y[], float  X[],float  n);

//Рассчитываем эпсилон погрешность коэффициента 'b' в процентах (стр. 39)
float Epsilon_Pogreshnost_b (float Y[], float X[],float n);

//Используя метод наименьших квадратов по точкам рассчитываем наилучшее 'a' из уравнения y=a+bx (стр. 39)
float  Ideal_a(float  Y[], float  X[],float  n);

//Рассчитываем погрешность коэффициента 'a' (стр. 39)
float  Sigma_Pogreshnost_a(float  Y[], float  X[],float  n);

//Рассчитываем эпсилон погрешность коэффициента 'a' в процентах (стр. 39)
float Epsilon_Pogreshnost_a (float Y[], float X[],float n);

//Используя метод наименьших квадратов по точкам рассчитываем наилучшее 'k' из уравнения y=kx (стр. 39)
float  Ideal_k(float  Y[], float  X[],float  n);

//Рассчитываем погрешность коэффициента 'k' (стр. 39)
float  Sigma_Pogreshnost_k(float  Y[], float  X[],float  n);

//Рассчитываем эпсилон погрешность коэффициента 'k' в процентах (стр. 39)
float Epsilon_Pogreshnost_k (float Y[], float X[],float n);

//Рассчет наилучшего значения измеряемой величины (стр. 41)
float Srednee_znacheni_velichin (float Znach[],float n);

//Рассчитываем погрешность среднего значения измеряемой величины (стр. 41)
float Sigma_Pogreshnost_Sred_Znach (float Znach[], float n);

//Рассчитываем Эпсилон погрешность Среднего значения (стр. 41)
float Epsilon_Pogreshnost_Sred_Znach (float Znach[], float n);

#endif // MY_LIB_H_INCLUDED




#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float Ideal_b(float Y[], float X[],float n)
{
    long double Sr_YX=0, Sr_X=0, Sr_Y=0, Sr_XX=0, Sr_YY = 0, b=0 ;
    for (int i=0; i<n; i++){
        Sr_YX=Sr_YX+(Y[i]*X[i]);
    }
    Sr_YX /= n;
    
    printf ("<YX> = %Lf\n\n", Sr_YX );
    
    for (int i=0; i<n; i++){
        Sr_X=Sr_X+(X[i]);
    }
    Sr_X /= n;
    
    printf ("<X> = %Lf\n\n", Sr_X );
    
    for (int i=0; i<n; i++){
        Sr_Y=Sr_Y+(Y[i]);
    }
    Sr_Y /= n;
    
    printf ("<Y> = %Lf\n\n", Sr_Y );
    
    for (int i=0; i<n; i++){
        Sr_XX=Sr_XX+(X[i]*X[i]);
    }
    Sr_XX /= n;
    
    printf ("<XX> = %Lf\n\n", Sr_XX );
    
    for (int i=0; i<n; i++){
        Sr_YY=Sr_YY+(Y[i]*Y[i]);
    }
    Sr_YY /= n;
    
    printf ("<YY> = %Lf\n\n", Sr_YY );
    
    b=(Sr_YX-Sr_X*Sr_Y)/(Sr_XX-Sr_X*Sr_X);
    return (float)b;
}
float Sigma_Pogreshnost_b(float Y[], float X[],float n)
{
    long double b=0, Sr_YX=0, Sr_X=0, Sr_Y=0, Sr_XX=0, Sr_YY=0, Pogr_b=0;
    for (int i=0; i<n; i++){
        Sr_YX=Sr_YX+(Y[i]*X[i]);
    }
    Sr_YX /= n;
    for (int i=0; i<n; i++){
        Sr_X=Sr_X+(X[i]);
    }
    Sr_X /= n;
    for (int i=0; i<n; i++){
        Sr_Y=Sr_Y+(Y[i]);
    }
    Sr_Y /= n;
    for (int i=0; i<n; i++){
        Sr_XX=Sr_XX+(X[i]*X[i]);
    }
    Sr_XX /= n;
    for (int i=0; i<n; i++){
        Sr_YY=Sr_YY+(Y[i]*Y[i]);
    }
    Sr_YY /= n;
    
    b=(Sr_YX-Sr_X*Sr_Y)/(Sr_XX-Sr_X*Sr_X);
    Pogr_b=(1/sqrt(n))*sqrt(((Sr_YY-Sr_Y*Sr_Y)/(Sr_XX-Sr_X*Sr_X))-b*b);
    return (float)Pogr_b;
}

float Epsilon_Pogreshnost_b (float Y[], float X[],float n)
{
    long double b=0, Sr_YX=0, Sr_X=0, Sr_Y=0, Sr_XX=0, Sr_YY=0, Pogr_b=0, Ep_Pog_b=0;
    for (int i=0; i<n; i++){
        Sr_YX=Sr_YX+(Y[i]*X[i]);
    }
    Sr_YX /= n;
    for (int i=0; i<n; i++){
        Sr_X=Sr_X+(X[i]);
    }
    Sr_X /= n;
    for (int i=0; i<n; i++){
        Sr_Y=Sr_Y+(Y[i]);
    }
    Sr_Y /= n;
    for (int i=0; i<n; i++){
        Sr_XX=Sr_XX+(X[i]*X[i]);
    }
    Sr_XX /= n;
    for (int i=0; i<n; i++){
        Sr_YY=Sr_YY+(Y[i]*Y[i]);
    }
    Sr_YY /= n;
    b=(Sr_YX-Sr_X*Sr_Y)/(Sr_XX-Sr_X*Sr_X);
    Pogr_b=(1/sqrt(n))*sqrt(((Sr_YY-Sr_Y*Sr_Y)/(Sr_XX-Sr_X*Sr_X))-b*b);
    Ep_Pog_b=(Pogr_b*100)/b;
    return (float)Ep_Pog_b;
}

float Ideal_a(float Y[], float X[],float n)
{
    long double b=0, a=0, Sr_YX=0, Sr_X=0, Sr_Y=0, Sr_XX=0 ;
    for (int i=0; i<n; i++){
        Sr_YX=Sr_YX+(Y[i]*X[i]);
    }
    Sr_YX /= n;
    for (int i=0; i<n; i++){
        Sr_X=Sr_X+(X[i]);
    }
    Sr_X /= n;
    for (int i=0; i<n; i++){
        Sr_Y=Sr_Y+(Y[i]);
    }
    Sr_Y /= n;
    for (int i=0; i<n; i++){
        Sr_XX=Sr_XX+(X[i]*X[i]);
    }
    Sr_XX /= n;
    b=(Sr_YX-Sr_X*Sr_Y)/(Sr_XX-Sr_X*Sr_X);
    a=Sr_Y-b*Sr_X;
    return (float)a;
}

float Sigma_Pogreshnost_a(float  Y[], float  X[],float n)
{
    long double b=0, Sr_YX=0, Sr_X=0, Sr_Y=0, Sr_XX=0, Sr_YY=0, Pogr_b=0, Pogr_a=0 ;
    for (int i=0; i<n; i++){
        Sr_YX=Sr_YX+(Y[i]*X[i]);
    }
    Sr_YX /= n;
    for (int i=0; i<n; i++){
        Sr_X=Sr_X+(X[i]);
    }
    Sr_X /= n;
    for (int i=0; i<n; i++){
        Sr_Y=Sr_Y+(Y[i]);
    }
    Sr_Y /= n;
    for (int i=0; i<n; i++){
        Sr_XX=Sr_XX+(X[i]*X[i]);
    }
    Sr_XX /= n;
    for (int i=0; i<n; i++){
        Sr_YY=Sr_YY+(Y[i]*Y[i]);
    }
    Sr_YY /= n;
    b=(Sr_YX-Sr_X*Sr_Y)/(Sr_XX-Sr_X*Sr_X);
    Pogr_b=(1/sqrt(n))*sqrt(((Sr_YY-Sr_Y*Sr_Y)/(Sr_XX-Sr_X*Sr_X))-b*b);
    Pogr_a=Pogr_b*sqrt(Sr_XX-Sr_X*Sr_X);
    return (float)Pogr_a;
}

float Epsilon_Pogreshnost_a (float Y[], float X[],float n)
{
    long double b=0, Sr_YX=0, Sr_X=0, Sr_Y=0, Sr_XX=0, Sr_YY=0, Pogr_b=0, Pogr_a=0, a=0, Ep_Pog_a=0 ;
    for (int i=0; i<n; i++){
        Sr_YX=Sr_YX+(Y[i]*X[i]);
    }
    Sr_YX /= n;
    for (int i=0; i<n; i++){
        Sr_X=Sr_X+(X[i]);
    }
    Sr_X /= n;
    for (int i=0; i<n; i++){
        Sr_Y=Sr_Y+(Y[i]);
    }
    Sr_Y /= n;
    for (int i=0; i<n; i++){
        Sr_XX=Sr_XX+(X[i]*X[i]);
    }
    Sr_XX /= n;
    for (int i=0; i<n; i++){
        Sr_YY=Sr_YY+(Y[i]*Y[i]);
    }
    Sr_YY /= n;
    b=(Sr_YX-Sr_X*Sr_Y)/(Sr_XX-Sr_X*Sr_X);
    Pogr_b=(1/sqrt(n))*sqrt(((Sr_YY-Sr_Y*Sr_Y)/(Sr_XX-Sr_X*Sr_X))-b*b);
    Pogr_a=Pogr_b*sqrt(Sr_XX-Sr_X*Sr_X);
    a=Sr_Y-b*Sr_X;
    Ep_Pog_a=(Pogr_a*100)/a;
    return (float)Ep_Pog_a;
}

float  Ideal_k(float  Y[], float  X[],float n)
{
    long double k=0, Sr_YX=0, Sr_XX=0 ;
    for (int i=0; i<n; i++){
        Sr_YX=Sr_YX+(Y[i]*X[i]);
    }
    Sr_YX /= n;
    for (int i=0; i<n; i++){
        Sr_XX=Sr_XX+(X[i]*X[i]);
    }
    Sr_XX /= n;
    k=Sr_YX/Sr_XX;
    return (float)k;
}

float  Sigma_Pogreshnost_k(float  Y[], float  X[],float n)
{
    long double  Sr_YX=0, Sr_XX=0, Sr_YY=0, Pogr_k=0, k=0 ;
    for (int i=0; i<n; i++){
        Sr_YX=Sr_YX+(Y[i]*X[i]);
    }
    Sr_YX /= n;
    for (int i=0; i<n; i++){
        Sr_XX=Sr_XX+(X[i]*X[i]);
    }
    Sr_XX /= n;
    for (int i=0; i<n; i++){
        Sr_YY=Sr_YY+(Y[i]*Y[i]);
    }
    Sr_YY /= n;
    k=Sr_YX/Sr_XX;
    Pogr_k=(1/sqrt(n))*sqrt((Sr_YY/Sr_XX)-k*k);
    return (float)Pogr_k;
}

float Epsilon_Pogreshnost_k (float Y[], float X[],float n)
{
    long double  Sr_YX=0, Sr_XX=0, Sr_YY=0, Pogr_k=0, k=0, Ep_Pog_k=0 ;
    for (int i=0; i<n; i++){
        Sr_YX=Sr_YX+(Y[i]*X[i]);
    }
    Sr_YX /= n;
    for (int i=0; i<n; i++){
        Sr_XX=Sr_XX+(X[i]*X[i]);
    }
    Sr_XX /= n;
    for (int i=0; i<n; i++){
        Sr_YY=Sr_YY+(Y[i]*Y[i]);
    }
    Sr_YY /= n;
    k=Sr_YX/Sr_XX;
    Pogr_k=(1/sqrt(n))*sqrt((Sr_YY/Sr_XX)-k*k);
    Ep_Pog_k=(Pogr_k*100)/k;
    return (float)Ep_Pog_k;
}

float Srednee_znacheni_velichin (float Znach[],float n)
{
    long double X_Sr=0;
    for (int i=0; i<n; i++)
    {
        X_Sr = X_Sr + Znach[i];
    }
    X_Sr /= n;
    return (float)X_Sr;
}

float Sigma_Pogreshnost_Sred_Znach (float Znach[], float n)
{
    long double X_Sr = 0, Sig_Sr = 0, Kv_Razn_Sr = 0;
    for (int i=0; i<n; i++)
    {
        X_Sr = X_Sr + Znach[i];
    }
    X_Sr /= n;
    
    for (int i = 0; i<n; i++)
    {
        Kv_Razn_Sr = Kv_Razn_Sr + (Znach[i] - X_Sr)*(Znach[i] - X_Sr);
    }
    Sig_Sr = sqrt((1/(n*(n-1)))*Kv_Razn_Sr);
    return (float)Sig_Sr;
}

float Epsilon_Pogreshnost_Sred_Znach (float Znach[], float n)
{
    long double X_Sr = 0, Sig = 0, Kv_Razn_Sr = 0, Eps = 0;
    for (int i=0; i<n; i++)
    {
        X_Sr = X_Sr + Znach[i];
    }
    X_Sr /= n;
    
    for (int i = 0; i<n; i++)
    {
        Kv_Razn_Sr = Kv_Razn_Sr + (Znach[i] - X_Sr)*(Znach[i] - X_Sr);
    }
    Sig = sqrt((1/(n*(n-1)))*Kv_Razn_Sr);
    Eps = (Sig *100)/X_Sr;
    return (float)Eps;
}



int main ()
{
    printf ("\n");
    printf("Hello\n\n");
    int End = 0;
    do
    {
        printf ("What do you want?\n\n");
        printf ("1 - Working with Graph   ");
        printf ("2 - Working with <X>   ");
        printf ("3 - Exit\n\n");
        
        double tmp=0;
        scanf ("%lf", &tmp);
        if (tmp==1)
        {
            printf("\n");
            float n = 0;                                 //—читываем кол-во измерений
            printf("vvedite kol-vo izmereniy\n");
            scanf ("%f", &n);
            printf("\n");
            
            float Y[50];                                 //—читываем параметры Y
            printf("vvedite parametry Y\n");
            for (int i=0; i<n; i++){
                scanf  ("%f", &Y[i]);
            }
            
            printf("\n");
            float X[50];                                 //—читываем параметры X
            printf("vvedite parametry X\n");
            for (int i=0; i<n; i++){
                scanf ("%f", &X[i]);
            }
            printf ("\n");
            
            printf ("Ideal b = %f\n\n", Ideal_b( Y,  X, n));
            printf ("Ideal a = %f\n\n", Ideal_a( Y,  X, n));
            printf ("Ideal k = %f\n\n", Ideal_k( Y,  X, n));
            printf ("Sigma Pogreshnost b = %f\n\n", Sigma_Pogreshnost_b( Y,  X, n));
            printf ("Sigma Pogreshnost a = %f\n\n", Sigma_Pogreshnost_a( Y,  X, n));
            printf ("Sigma Pogreshnost k = %f\n\n", Sigma_Pogreshnost_k( Y,  X, n));
            printf ("Epsilon Pogreshnost b = %f \n\n", Epsilon_Pogreshnost_b( Y,  X, n));
            printf ("Epsilon Pogreshnost a = %f \n\n", Epsilon_Pogreshnost_a( Y,  X, n));
            printf ("Epsilon Pogreshnost k = %f \n\n", Epsilon_Pogreshnost_k( Y,  X, n));
        }
        if (tmp==2)
        {
            printf("\n");
            float n = 0;                                     //—читываем кол-во измерений
            printf("vvedite kol-vo izmereniy\n");
            scanf ("%f", &n);
            printf("\n");
            float Znach[50];                                 //—читываем значени€
            printf("vvedite ih znacheniya\n");
            for (int i=0; i<n; i++)
            {
                scanf  ("%f", &Znach[i]);
            }
            printf ("\n");
            printf ("Srednee znachenie = %f\n\n", Srednee_znacheni_velichin ( Znach, n ));
            printf ("Sigma Pogreshnost Srednego znachiniya = %f\n\n", Sigma_Pogreshnost_Sred_Znach( Znach, n ));
            printf ("Epsilon Pogreshnost Srednego znachiniya = %f\n\n", Epsilon_Pogreshnost_Sred_Znach( Znach, n ));
        }
        if (tmp == 3)
        {
            break;
        }
        printf ("1 - Exit\t\t");
        printf ("2 - Back\t\t");
        scanf ("%d", &End);
        if (End == 1)
        {
            break;
        }
    }
    while (End == 2);
    
    return 0;
}
