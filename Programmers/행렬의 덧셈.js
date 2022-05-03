function solution(arr1, arr2) {  
    return arr1.map((A,i) => A.map((b,j) => b + arr2[i][j]));
}
