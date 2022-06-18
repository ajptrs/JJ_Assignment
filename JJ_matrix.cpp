#include <iostream>
#include <vector>

using namespace std;

void myPrintFunc(vector< vector<int> > &myMatrix) { 
    for (int m = 0; m < myMatrix.size(); m++){
        //cout << "Row " << m << ": " << endl;
        for (int i = 0; i < myMatrix[0].size(); i++) {
            int printout = myMatrix[m][i];
            cout << printout << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void func(vector< vector<int> > &myMatrix) { // Pass by reference to not copy entire matrix 
    int numRow = myMatrix.size(); // Number of rows 
    int numCol = myMatrix[0].size(); // Number columns
    //cout << "Num rows: " << numRow <<", Num Cols: " << numCol << endl;
    vector<int> onesRow;
    vector<int> onesCol;

    // These for loops will detect all the ones in the matrix
    for (int m = 0; m < numRow; m++) { //rows
        for (int i = 0; i < numCol; i++) { //columns
            if (myMatrix[m][i] == 1) {
                onesRow.push_back(i);
                onesCol.push_back(m);
                //cout << "row: " << m << ", column: " << i << endl;
            }
        }
    }

    // Change necessary rows/columns to 1s
    for (int numConvert = 0; numConvert < onesRow.size(); numConvert++) { // number of rows/columns that need to change
        for (int m = 0; m < numRow; m++) { // column indeces of each row 
            int temp2 = onesRow[numConvert];
            //cout << m << ", " << temp2 << endl;
            myMatrix[m][onesRow[numConvert]] = 1;
        }
    }
    for (int numConvert = 0; numConvert < onesCol.size(); numConvert++) { // number of rows/columns that need to change
        for (int i = 0; i < numCol; i++) { //columns
            int temp1 = onesCol[numConvert];
            //cout << temp1 << ", " << i << endl;
            myMatrix[onesCol[numConvert]][i] = 1;
        }
    }

}

void func2 (vector< vector<int> > &myMatrix) {
    int numRow = myMatrix.size(); // Number of rows 
    int numCol = myMatrix[0].size(); // Number columns

    vector<int> onesRow(numCol, 1); // Row of ones
    vector<int> onesCol(numRow, 1); // Column of ones

    vector<int> oneRowIdx;
    vector<int> oneColIdx;

    for (int m = 0; m < numRow; m++) { //rows
        for (int i = 0; i < numCol; i++) { //columns
            if (myMatrix[m][i] == 1) {
                oneRowIdx.push_back(i);
                oneColIdx.push_back(m);
                cout << "row: " << m << ", column: " << i << endl;
            }
        }
    }

    for (int i = 0; i < oneRowIdx.size(); i ++) {
        int temp3 = oneRowIdx[i];
        cout << "oneRowIdx[i]: " << temp3 << endl;
        myMatrix[oneRowIdx[i]].swap(onesRow);
        myPrintFunc(myMatrix);

    }
}



int main() {
    vector< vector<int> > myMatrix;
    vector<int> myRow(4,0); 

    for (int i = 0; i < myRow.size(); i++){
        myMatrix.push_back(myRow);
    }

    myMatrix[0][0]=1; //test this one
    myMatrix[1][3]=1; 
    cout << "Before function: " <<  endl;
    myPrintFunc(myMatrix);

    //func(myMatrix);
    func2(myMatrix);
    cout << "After Function: " <<  endl;
    myPrintFunc(myMatrix);   
}