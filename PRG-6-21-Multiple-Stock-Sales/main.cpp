//
//  main.cpp
//  PRG-6-20-Stock-Profit
//
//  Created by Keith Smith on 9/21/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Use the function you wrote in Programming Challenge 20 (Stock Profit) in a
//  program that calculates the total profit or loss from the sale of multiple stocks. The
//  program should ask the user for the number of stock sales and the necessary data for
//  each stock sale. It should accumulate the profit or loss for each stock sale, then display
//  the total.

#include <iostream>

using namespace std;

int getTotalNumberOfSales();
void inputData(int &, float &, float &, float &, float &);
float calculateGain(int, float, float, float, float, float);

int main()
{
    int intNumberOfShares;
    int intTotalNumberOfSales;
    
    float fltSalePricePerShare;
    float fltSaleCommissionPaid;
    float fltPurchasePricePerShare;
    float fltPurchaseCommissionPaid;
    float fltTotalGain;
    float fltTotalGainSales;
    
    fltTotalGain = 0.0f; // Initialize at 0 to pass to calculateGain()
    fltTotalGainSales = 0.0f; // Initialize accumulator
    
    intTotalNumberOfSales = getTotalNumberOfSales();
    
    for(int i = 0 ; i < intTotalNumberOfSales ; i++)
    {
        inputData(intNumberOfShares, fltSalePricePerShare, fltSaleCommissionPaid, fltPurchasePricePerShare, fltPurchaseCommissionPaid);
        
        fltTotalGain = calculateGain(intNumberOfShares, fltSalePricePerShare, fltSaleCommissionPaid, fltPurchasePricePerShare, fltPurchaseCommissionPaid, fltTotalGain);
        
        fltTotalGainSales += fltTotalGain;
        
        cout << "The total gain/loss of the sale of this stock is: $" << fltTotalGain << endl;
    }
    
    cout << "The total gain/loss was $" << fltTotalGainSales << endl;
    
    return 0;
}

int getTotalNumberOfSales()
{
    int intSalesNumber;
    
    cout << "Enter the total number of sales to calculate:\n";
    cin >> intSalesNumber;
    
    while(!cin || intSalesNumber <= 0 || intSalesNumber > 10)
    {
        cout << "Please enter a number between 1 and 10:\n";
        cin.clear();
        cin.ignore();
        cin >> intSalesNumber;
    }
    
    return intSalesNumber;
}

void inputData(int &refShares, float &refSalePrice, float &refSaleCommission, float &refPurchasePrice, float &refPurchaseCommission)
{
    cout << "Please enter the total number of shares:\n";
    cin >> refShares;
    
    while(!cin || refShares < 0 || refShares > 1000000)
    {
        cout << "Please enter a number between 1 and 1,000,000:\n";
        cin.clear();
        cin.ignore();
        cin >> refShares;
    }
    
    cout << "Please enter the sale price per share:\n";
    cin >> refSalePrice;
    
    while(!cin || refSalePrice < 0.0f || refSalePrice > 10000.0f)
    {
        cout << "Please enter a number between $1.00 and $10,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> refSalePrice;
    }
    
    cout << "Please enter the sales commission:\n";
    cin >> refSaleCommission;
    
    while(!cin || refSaleCommission < 0.0f || refSaleCommission > 100000.0f)
    {
        cout << "Please enter a number between $1.00 and $100,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> refSaleCommission;
    }
    
    cout << "Please enter the purchase price per share:\n";
    cin >> refPurchasePrice;
    
    while(!cin || refPurchasePrice < 0.0f || refPurchasePrice > 10000.0f)
    {
        cout << "Please enter a number between $1.00 and $10,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> refPurchasePrice;
    }
    
    cout << "Please enter purchase commission:\n";
    cin >> refPurchaseCommission;
    
    while(!cin || refPurchaseCommission < 0.0f || refPurchaseCommission > 100000.0f)
    {
        cout << "Please enter a number between $1.00 and $100,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> refPurchaseCommission;
    }
}

float calculateGain(int intNumberOfShares, float fltSalesPricePerShare, float fltSaleCommissionPaid, float fltPurchasePricePerShare, float fltPurchaseCommissionPaid, float fltTotalGain)
{
    fltTotalGain = ((intNumberOfShares * fltSalesPricePerShare) - fltSaleCommissionPaid) - ((intNumberOfShares * fltPurchasePricePerShare) - fltPurchaseCommissionPaid);
    
    return fltTotalGain;
}


