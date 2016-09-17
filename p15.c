#include <stdio.h>

#define N 11

long double p15(int m,int n){
        int i;
        long double sum=0;
        if (m==0 || n==0)
                return 0;
        if (m==1 || n==1)
                return 1;
        if (m==2)
                return n;
        if (n==2)
                return m;
        for (i=m;i>=0;i--)
                sum+=p15(i,n-1);
        return sum;
}

int main(){

        int i,j;

        long double sum=0;
/*
        for(i=1;i<N-1;i++){
                for(j=2;j<N;j++){
                        sum+= 2*p15(N,i)*p15(2*N-1-i,N);
                }
        }
        for(i=1;i<N-1;i++){
                for(j=2;j<N;j++){
                        sum+= p15(i,N)*(p15(N-i,j))*p15(N-j,N);
                }
        }

        sum+=p15(N,N)*p15(N,N);

        printf("%llf\n",sum);*/
        printf("%llf\n",p15(2*N-1,2*N-1));

        return 0;

}
