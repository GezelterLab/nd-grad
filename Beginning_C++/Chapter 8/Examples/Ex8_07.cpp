/*************************************************************\ 
|* Name: Ex8_07.cpp                                          *|
|* Author: crdrisko                                          *|
|* Date: 05/21/19-13:20:31                                   *|
|* Description: Modifying the value of a caller variable -   *|
|*  references vs. pointers                                  *|
|*                                                           *|
|*                                                           *|
|* Complile Command: g++ Ex8_07.cpp -o Ex8_07.out -std=c++17 *|
\*************************************************************/

#include <iostream>

void change_it_by_pointer(double* reference_to_it);     // Pass pointer (by value)
void change_it_by_reference(double& reference_to_it);   // Pass by reference

int main()
{
    double it {5.0};

    change_it_by_pointer(&it);                          // Now we pass the address
    std::cout << "After first function execution, it = " << it << std::endl;

    change_it_by_reference(it);                         // Now we pass a reference, not the value!
    std::cout << "After second function execution, it = " << it << std::endl;
}

void change_it_by_pointer(double* pit)
{
    *pit += 10.0;                                       // This modifies the original double
}
void change_it_by_reference(double& pit)
{
    pit += 10.0;                                        // This modifies the original double as well
}
