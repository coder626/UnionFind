#include <iostream>
#include <unordered_map>
#include <iterator>
#include <cstring>
#include <fstream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <queue>
#include <array>
#include <vector>
#include <queue>
#include <cassert>
#include <stack>
#include <algorithm>
using namespace std;



int arr[1000000];



int find(int set){
  //cout << arr[set];
  if(arr[set] == -1){
    return set;
  }
   //return find(arr[set]);
  arr[set] = find(arr[set]);
  return arr[set];
}

void unionFunction(int set1, int set2){

  set1 = find(set1);
  set2 = find(set2);

  if(set1 == set2){
    return;
  }
  
  if(arr[set1] < arr[set2]){
    arr[set2] = -1;
    arr[set1] = set2;
    return;
  }
  arr[set1] = -1;
  arr[set2] = set1;
  
  //find(set1);
  //find(set2);
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /*
  //tester code, comment out on Kattis
  ifstream cin("input.txt");
  ifstream textFile;
  textFile.open("input.txt");
  if(textFile.fail()){
    cout << "File Open Failed";
    return 0;
  }
*/




  int a;
  int b;
  cin >> a >> b;

 // cout << a << " " << b << endl;
  std::fill_n(arr, a, -1);

  /*
  for(int i = 0; i < a; i++){
    arr[i] = -1;
  }
*/
  

  char operation;
  int set1;
  int set2;
  for(int i = 0; i < b; i++){
    //cout << i;
    cin >> operation >> set1 >> set2;
    if(operation == '='){
      unionFunction(set1, set2);
    }
    else{
      //cout << find(set1) << " " << find(set2) << endl;
      if(find(set1) == find(set2)){
        cout << "yes";
      }
      else{
        cout << "no";
      }
      cout << "\n";
    }
  }


  /*
  for(int i = 0; i < a; i++){
    cout << i << " ";
  }
  cout << endl;
  for(int i = 0; i < a; i++){
    cout << arr[i] << " ";
  }
  */
  

  
  
}