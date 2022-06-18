#include <iostream>
#include <vector>

using namespace std;

void func(vector< vector<int> > &myMatrix) { //pass by reference to not copy entire matrix 

}

void myPrintFunc(vector< vector<int> > &myMatrix) { 
    for (int m = 0; m < 3; m++){
        cout << "Row " << m << ": " << endl;
        for (int i = 0; i < 5; i++) {
            int printout = myMatrix[m][i];
            cout << printout << ", ";
        }
        cout << endl;
    }
}


int main() {
    vector< vector<int> > myMatrix;
    vector<int> myRow;
    for (int m = 0; m < 3; m++){
        myRow.clear();
        for (int i = 0; i < 5; i++) {
            myRow.push_back(0);
        }
        myMatrix.push_back(myRow);
    }
    int sizeM = myMatrix.size(); //this gives the number of rows 
    int sizeM1 = myMatrix[0].size(); // this gives the number columns



    myMatrix[2][4]=23; //test this one 
    cout << "Before function: " <<  endl;
    myPrintFunc(myMatrix);

    func(myMatrix);
    cout << "After Function: " <<  endl;
    myPrintFunc(myMatrix);   


    /*
    int temp1;
    temp1 = myMatrix[0][1];
    cout << "myMatrix[0][1] after going into fucntion: " << temp1 << endl;
    */
}