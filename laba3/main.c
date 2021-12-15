#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double func(double x){
return x*x-2;
}

int main()
{
    double x1,x2, epsilon, x;
    unsigned int maxN,N=0, regim, vybir, menu;
    time_t start, stop;
    printf("oberit metod(1 - hord, 2 - polovynogog dilenya) ");
    scanf("%u",&menu);
    printf("vy bazaete rezym vidlagodzenya (0- No, 1-Yes) ");
    scanf("%u",&regim);
    printf("vedit pochatkove znachenia x1  ");
    scanf("%lf",&x1);
    printf("vedit pochatkove znachenia x2  ");
    scanf("%lf",&x2);
    printf("vedit pohubky epsilon  ");
    scanf("%lf",&epsilon);
    printf("vedit max iteraciy  ");
    scanf("%u",&maxN);
    start=time(NULL);
    if(menu==1)
    if(func(x1)*func(x2)<0)
    {
       do{
               x=(func(x2)*x1-func(x1)*x2)/(func(x2)-func(x1));
               if(func(x1)*func(x)<0)
                x2=x;
               if(func(x)*func(x2)<0)
                x1=x;
                N++;
                if(regim==1){
                    printf("%u iteracia nabl.korin =%.5f \n ", N, x);
                }
                if(N>maxN){
                    printf("perevysheno maxymalnu klk iteraciy. sho vybyraesh : \n");
                    printf("1 - prodovzyem z takouz klk \n");
                    printf("2 - prodovzyem poshuk \n");
                    printf("3 - zupynka programy  \n");
                    scanf("%u",&vybir);
                switch(vybir){
                case 1: maxN*=2; break;
                case 2: maxN=999999999; break;
                case 3: printf("promizny resultat");
                   printf("korin =%.5f \n ", x);
                   printf("F(x) =%.5f \n ", func(x));
                   printf("klk iteraciy =%u \n ", N);
                   return 0;
                default: printf("Error vybir");
                }
                }
       }while(fabs(func(x))>=epsilon);
       printf("korin =%.5f \n ", x);
       printf("F(x) =%.5f \n ", func(x));
       printf("klk iteraciy =%u \n ", N);
    }
    else printf("Error");
   //*********************************************************************************
    if(menu==2)
    if(func(x1)*func(x2)<0)
    {
        while(fabs(x1-x2)>=epsilon){
               x=(x1+x2)/2;
               if(func(x1)*func(x)<0)
                x2=x;
               if(func(x)*func(x2)<0)
                x1=x;
                N++;
                if(regim==1){
                    printf("%u iteracia nabl.korin =%.5f \n ", N, x);
                }
                if(N>maxN){
                    printf("perevysheno maxymalnu klk iteraciy. sho vybyraesh : \n");
                    printf("1 - prodovzyem z takouz klk \n");
                    printf("2 - prodovzyem poshuk \n");
                    printf("3 - zupynka programy  \n");
                    scanf("%u",&vybir);
                switch(vybir){
                case 1: maxN*=2; break;
                case 2: maxN=999999999; break;
                case 3: printf("promizny resultat");
                   printf("korin =%.5f \n ", x);
                   printf("F(x) =%.5f \n ", func(x));
                   printf("klk iteraciy =%u \n ", N);
                   return 0;
                default: printf("Error vybir");
                }
                }


       }
       printf("korin =%.5f \n ", x);
       printf("F(x) =%.5f \n ", func(x));
       printf("klk iteraciy =%u \n ", N);
    }
    else printf("Error");


    stop=time(NULL);
    printf("Loop required %f seconds", (stop - start));

    return 0;
}
