//
//  main.cpp
//  AbsoluteCpp_ch15_1
//
//

//Demonstrates the performance of the virtual function bill.
#include <iostream>
#include "sale.h" //Not really needed, but safe due to ifndef.
#include "discountsale.h"
#include <vector>
using std::cout;
using std::endl;
using std::ios;
using std::vector;
using namespace SavitchSale;



int main( )
{
    
    
    Sale simple(10.00); // One item at $10.00.
    DiscountSale discount(11.00, 10); // One item at $11.00
                                      // with a 10% discount.


    cout << "---- test 1 ----" << endl;
    Sale & saleRef = discount;
    cout << saleRef.bill() << endl;    // Sale: 11

    
    cout << "---- test 2 ----" << endl;
    Sale * salePtr;
    salePtr = &discount;
    cout << salePtr->bill() << endl;    // Sale: 11
    
    
    cout << "---- test 3 ----" << endl;
    Sale * salePtr2 = new Sale;
    salePtr2 = &discount;
    cout << salePtr2->bill() << endl;    // Sale: 11

    
    cout << "---- test 4 ----" << endl;
    Sale simple2(10.00);
    simple2 = discount; // operator =
    cout << simple2.bill() << endl;    // Sale: 11

    
    cout << "---- test 5 ----" << endl;
    Sale * salesArrayPtr = new Sale[2];
    salesArrayPtr[0] = simple; // operator =
    salesArrayPtr[1] = discount; // operator =
    cout << salesArrayPtr[0].bill() << endl;    // Sale: 10
    cout << salesArrayPtr[1].bill() << endl;    // Sale: 11

    
    cout << "---- test 6 ----" << endl;
    Sale salesArray[2];
    salesArray[0] = simple; // operator =
    salesArray[1] = discount; // operator =
    cout << salesArray[0].bill() << endl;    // Sale: 10
    cout << salesArray[1].bill() << endl;    // Sale: 11
    
    
    cout << "---- test 7 ----" << endl;
    vector<Sale> salesVec;
    salesVec.push_back(simple); // push_back (copy constructor)
    salesVec.push_back(discount);
    cout << salesVec[0].bill() << endl;    // Sale: 10
    cout << salesVec[1].bill() << endl;    // Sale: 11
    
    
    cout << "---- test 8 ----" << endl;
    vector<Sale*> salePtrVec;
    salePtrVec.push_back(&simple); // push_back (address)
    salePtrVec.push_back(&discount);
    cout << salePtrVec[0]->bill() << endl;    // Sale: 10
    cout << salePtrVec[1]->bill() << endl;    // Sale: 11
    

    /*
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if (discount < simple)
    {
        cout << "Discounted item is cheaper.\n";
        cout << "Savings is $" << simple.savings(discount) << endl;
    }
    else
        cout << "Discounted item is not cheaper.\n";
    */
    
    return 0;
}
