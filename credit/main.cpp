//
//  main.cpp
//  credit
//
//  Created by Marvin Augustin on 7/6/22.
//

#include "cardCheck.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //long c = 4003600000000014;
    //long c = 378282246310005;
    //long c = 4222222222222;
    //long c = 2223016768739313;
    //long c = 4999991111111113;
    long c = 378734493671000;
    //long c = 5555555555554444;
    //long c = 5105105105105100;
    //long c = 4999992222222229;
    //long c = 5199999999999991;
    //long c = 5299999999999990;
    
    cardCheck testObj;
    
    testObj.cardVerification(c);
    testObj.cardValidation(c);
    
    
    return 0;
}
