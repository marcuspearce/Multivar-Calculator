//
//  main.cpp
//  Multivar Calculator
//
//  Created by Marcus Pearce on 11/4/18.
//  Copyright © 2018 MightieMuffin. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double dotProduct2(double x1, double y1, double x2, double y2);
double dotProduct3(double x1, double y1, double z1, double x2, double y2, double z2);
string crossProduct3(double x1, double y1, double z1, double x2, double y2, double z2);
double magVector2(double x, double y);
double magVector3(double x, double y, double z);
double magCrossProduct3(double x1, double y1, double z1, double x2, double y2, double z2);

// Prompt user for questions
int main()
{
    int inputFunc = -1;
    string inputQuit = "";
    double x1, y1, z1, x2, y2, z2;
    bool run = true;
    
    cout << "Welcome to Multivar Calculator" << endl << endl;
    while(run)
    {
        cout << "Please select a function (input \"1\" for 2x2 dot product)" << endl;
        cout << "(0) I don't even know what I don't know :(" << endl;
        cout << "(1) 2x2 Dot Product" << endl;
        cout << "(2) 3x3 Dot Product" << endl;
        cout << "(3) 3x3 Cross Product" << endl;
        cout << "(4) Magnitude of 2D Vector" << endl;
        cout << "(5) Magnitude of 3D Vector" << endl;
        cout << "(6) Magnitude of 3x3 Cross Product" << endl;
        
        cin >> inputFunc;
        
        string orderPrompt = "Please enter each component of the vector(s) in left to right order (seperating each with a return key)";
        string postInput = "Thanks! Lemme think a bit ... \nHere's your answer: ";
        
        // logic to calculate desired function
        switch(inputFunc)
        {
            case 0:
                cout << endl << "Sorry, I'm not programmed to solve life crises, only basic multivar functions. Good luck though! :)" << endl;
                break;
            case 1:
                cout << endl << "2x2 Dot Product" << endl << orderPrompt << endl;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << postInput << dotProduct2(x1,y1,x2,y2) << endl;
                break;
            case 2:
                cout << endl << "3x3 Dot Product" << endl << orderPrompt << endl;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                cout << postInput << dotProduct3(x1,y1,z1,x2,y2,z2) << endl;
                break;
            case 3:
                cout << endl << "3x3 Cross Product" << endl << orderPrompt << endl;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                cout << postInput << crossProduct3(x1,y1,z1,x2,y2,z2) << endl;
                break;
            case 4:
                cout << endl << "Magnitude of 2D Vector" << endl << orderPrompt << endl;
                cin >> x1 >> y1;
                cout << postInput << magVector2(x1,y1) << endl;
                break;
            case 5:
                cout << endl << "Magnitude of 3D Vector" << endl << orderPrompt << endl;
                cin >> x1 >> y1 >> z1;
                cout << postInput << magVector3(x1,y1,z1) << endl;
                break;
            case 6:
                cout << endl << "Magnitude of 3x3 Cross Product" << endl << orderPrompt << endl;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                cout << postInput << magCrossProduct3(x1,y1,z1,x2,y2,z2) << endl;
                break;
            default:
                cout << "Sorry, I don't understand that input." << endl;
        }
        
        // logic to quit calculator
        cin.ignore(10000, '\n'); // so correctly reads in following string
        while(true)
        {
            cout << endl << "Any more questions? (y/n)" << endl;
            getline(cin, inputQuit);
            if(inputQuit == "y")
            {
                cout << endl;
                break;
            }
            else if(inputQuit == "n")
            {
                run = false;
                cout << endl;
                break;
            }
            else // invalid input
                cout << endl << "Sorry, I don't understand, please input 'y' for yes and 'n' for no" << endl;
        }
    }
    
    cout << "Good luck with your homework!" << endl;
    return 0;
}


// Calculate 2x2 dot product given the numerical values in order
double dotProduct2(double x1, double y1, double x2, double y2)
{
    return x1 * x2 + y1 * y2;
}


// Calculate 3x3 dot product given the numerical values in order
double dotProduct3(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return x1 * x2 + y1 * y2 + z1 * z2;
}


// Calculate 2x2 cross product given the numerical values in order
string crossProduct2(double x1, double y1, double x2, double y2)
{
    double x = x1 * y2;
    double y = -1 * x2 * y1;
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}


// Calculate 3x3 cross product given the numerical values in order
string crossProduct3(double x1, double y1, double z1, double x2, double y2, double z2)
{
    double x = y1 * z2 - y2 * z1;
    double y = -1 * (x1 * z2 - x2 * z1);
    double z = x1 * y2 - x2 * y1;
    return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
}


// Calculate magnitude 2D vector given numerical values in order
double magVector2(double x, double y)
{
    return pow((x * x) + (y * y), 0.5); // exponent of .5 for square root
}


// Calculate magnitude 2D vector given numerical values in order
double magVector3(double x, double y, double z)
{
    return pow((x * x) + (y * y) + (z * z), 0.5);
}


// Calculate magnitude of the cross product of two 3D vectors
double magCrossProduct3(double x1, double y1, double z1, double x2, double y2, double z2)
{
    double x = y1 * z2 - y2 * z1;
    double y = -1 * (x1 * z2 - x2 * z1);
    double z = x1 * y2 - x2 * y1;
    return pow((x * x) + (y * y) + (z * z), 0.5);
}

