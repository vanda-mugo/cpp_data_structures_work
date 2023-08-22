/*
youre given a 2d array of integers matrix, write a function that returns the transpose of the matrix.
the transpose of a matrix is a flipped version of the original matrix across its main diagonal( which runs from top left to bottom right );
it switches the row and column indices of the original matrix.

you can assume the input matrix always has at least 1 value; however its width and height are not necessarily the same 
*/

/* 
lets say given an array as above 
matrix =[ 
    [1,2] ,
 ]
note by the value 1 is at row 0 column 0, which flipped remains the same 
value 2 is at 0,1 which when flipped is 1,0
sample output :
[
    [1],
    [2]
]

given the input array above 
input matrix = [
    [1,2,3]
    [4,5,6]
    [7,8,9]
]

output matrix to be 
[
    [1,4,7]
    [4,5,6]
    [7,8,9]
]

so basically if you think about it you are taking the columns and switching them to become rows

*/
// this solution runs in the above : 0(w * h) time where by w is the width of the matrix and h is the height of the matrix

