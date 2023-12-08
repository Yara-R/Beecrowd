#include <stdio.h>
 
int main() {
 
    int number, hours;
    double amount,salary;
    
    scanf("%d", &number);
    scanf("%d", & hours);
    scanf("%lf", &amount);
    
    salary = hours * amount;
    
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2lf\n", salary);
 
    return 0;
}
