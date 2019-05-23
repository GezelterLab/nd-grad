/*************************************************************\ 
|* Name: Ex3_02.cpp                                          *|
|* Author: crdrisko                                          *|
|* Description: Operations with enumerations                 *|
|*                                                           *|
|*                                                           *|
|* Complile Command: g++ Ex3_02.cpp -o Ex3_02.out -std=c++17 *|
\*************************************************************/

#include <iostream>
#include <iomanip>

int main()
{
    enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
    Day yesterday{Day::Monday}, today{Day::Tuesday}, tomorrow{Day::Wednesday};
    const Day poets_day{Day::Friday};

    enum class Punctuation : char { Comma = ',', Exclamation = '!', Question = '?' };
    Punctuation ch{ Punctuation::Comma};

    std::cout << "yesterday's value is " << static_cast<int>(yesterday)
              << static_cast<char>(ch) << " but poets_day's is " << static_cast<int>(poets_day)
              << static_cast<char>(Punctuation::Exclamation) << std::endl;
            
    today = Day::Thursday;                          // Assign new ...
    ch = Punctuation::Question;                     // ... enumarator values
    tomorrow = poets_day;                           // Copy enumerator values

    std::cout << "Is today's value(" << static_cast<int>(today)
              << ") the same as poets_day(" << static_cast<int>(poets_day)
              << ")" << static_cast<char>(ch) << std::endl;

    // ch = tomorrow;                               // Uncomment ...
    // tomorrow = Friday;                           // ... any of these ...
    // today = 6;                                   // ... for an error.

}