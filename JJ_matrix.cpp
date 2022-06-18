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
    int numRows = myMatrix.size(); // Number of rows 
    int numCols = myMatrix[0].size(); // Number columns

    vector<int> oneRowIdx; //Record the indeces of ones
    vector<int> oneColIdx;

    for (int m = 0; m < numRows; m++) { //rows
        for (int i = 0; i < numCols; i++) { //columns
            if (myMatrix[m][i] == 1) {
                oneRowIdx.push_back(m);
                oneColIdx.push_back(i);
                cout << "row: " << m << ", column: " << i << endl;
            }
        }
    }

    //Replaces rows with all 1s
    for (int i = 0; i < oneRowIdx.size(); i ++) { 
        int temp3 = oneRowIdx[i];
        myMatrix[oneRowIdx[i]].assign(numCols,1);
        //cout << "After replacing all the rows: " << endl;
        //myPrintFunc(myMatrix); 
    }

    // Replaces columns with all 1s
    for (int numConvert = 0; numConvert < oneColIdx.size(); numConvert++) { // number of rows/columns that need to change
        for (int i = 0; i < numRows; i++) {
            int temp1 = oneColIdx[numConvert];
            //cout << temp1 << ", " << i << endl;
            myMatrix[i][oneColIdx[numConvert]] = 1;
        }
    }
    //cout << "After replacing all the columns: " << endl;
      //  myPrintFunc(myMatrix); 
}

int main() {
    vector< vector<int> > myMatrix;
    vector<int> myRow(6,0); //Row of 4 zeros

    for (int i = 0; i < 3; i++){
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