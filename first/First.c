#include<stdio.h>
#include<stdlib.h>

int sum_of_divisors(int n){
    int sum = 1; 

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            sum += i; 
        }
    }
    return sum; 
}

int is_prime(int n){
    if(n < 2){
        return 0; 
    }

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return 0; 
        }
    }
    return 1; 
}

int exponent(int x){
    int result = 1; 
    for(int i = 0; i < x; i++){
        result *= 2; 
    }
    return result; 
}

int find_mersenne_prime(int num){
    if(num == sum_of_divisors(num)){
        int p = 2; 
        while(1){
            int mersenne = exponent(p) - 1; 
            int perfect = exponent(p - 1) * mersenne; 

            if (perfect = num){
                if(is_prime(mersenne)){
                    return mersenne; 
                }
                else{
                    return -1; 
                }
            }
            if(perfect > 1){
                break; 
            }
            p++; 
        }
    }
    return -1;  // 
}


int main(){ 
  int num; 
  printf("Enter a number: ");
  if(scanf("%d", &num) != 1){
        printf("Invlaid Input, Enter a valid number. \n");
        return 1; 
  }

  int result = find_mersenne_prime(num); 
  printf("%d\n", result);

    return 0; 
  }