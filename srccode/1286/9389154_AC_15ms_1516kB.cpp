#include <stdio.h>  
int ans;  
void Eu(int n){  
    for(int i = 2; i * i <= n;++i){  
        if(!(n%i)){  
            ans *= i - 1;  
            n /= i;  
            while(!(n%i)){  
                ans *= i;n/=i;   
            }   
        }  
    }  
    if(n > 1){  
        ans *= n -1;  
    }  
    return ;  
}  
int main(){  
    int n,test_case;  
    scanf("%d",&test_case);  
    while(test_case--){  
        scanf("%d",&n);  
        ans = 1;  
        Eu(n);  
        printf("%d\n",ans);  
    }  
    return 0;  
}  