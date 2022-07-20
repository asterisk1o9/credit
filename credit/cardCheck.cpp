//
//  cardCheck.cpp
//  credit
//
//  Created by Marvin Augustin on 7/6/22.
//

#include "cardCheck.hpp"

bool check = true;

void cardCheck::cardVerification(long &c){
    
    vector<int> card;
    
    int digit;
    const int  AA = 15;
    const int MC = 16;
    const int VISA1 = 13;
    const int VISA2 = 16;
    int index=0;
    long temp = c;
    //int cardReversed = 0;

    //Adds our card into a vector
    while(temp!=0){
        digit = temp%10;
        card.push_back(digit);
        temp = temp/10;
    }
    
    reverse(card.begin(), card.end());
    
    cout << "Card Nummber: ";
    for(auto e : card){
        cout << e;
    }
    cout << "\n";
    
    //switch case to determine which card type we have
    if(card.size() == AA){
        switch(card[index]){
            case 3:
                if(card[1] == 4 || card[1] == 7){
                    cout << "Card type: AMEX" << "\n";
                    break;
                }
            default:
                cout << "Not a valid Amex" << "\n";
                check = false;
                break;
        }

    }
    else if(card.size() == MC && card[0] == 5){
        switch(card[index]){
            case 5:
                if(card[1] == 1 || card[1] == 2 || card[1] == 3 || card[1] == 4 || card[1] == 5){
                    cout << "Card type: MASTER CARD" << "\n";
                    break;
                }
            default:
                cout << "Not a valid Mastercard" << "\n";
                check = false;
                break;
        }
    }
    else if((card.size() == VISA1 || card.size() == VISA2) && card[0] == 4){
        switch(card[index]){
            case 4:
                cout << "Card type: VISA" << "\n";
                break;
            default:
                cout << "Not a valid VISA" << "\n";
                check = false;
                break;
        }
    }
    else{
        cout << "Invalid card number" << "\n";
    }
}

void cardCheck::cardValidation(long &c){
    
    if(check == true){
    //LuhnAlgo
    int digit, digit2;
    int oddSum = 0, evenSum = 0;
    int counter = 1;
    int temp;
    //int cardReversed = 0;
    while(c!=0){
        digit = c%10;
        //cout << digit << "";
        if(counter %2 != 0){
            oddSum+= digit;
        }
        else{
            digit2 = digit*2;
            if(digit2 >= 10){
                while(digit2 !=0){
                    temp = digit2%10;
                    evenSum+= temp;
                    digit = 0;
                    digit2 = digit2/10;
                }
            }
            evenSum+= digit * 2;
        }
        counter++;
        c = c/10;
    }
    int sum = oddSum + evenSum;
        if(sum % 10 == 0){
            cout << "Valid\n";
        }
        else{
            cout << "Invalid\n";
        }
    }
}
