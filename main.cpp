#define _USE_MATH_DEFINES // for C++
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
int s = 0;
int N;

cout << "Enter the size of array" << endl;
cin >> N;
int array[N];

    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < N; i++) {
      cin >> array[i];
    }

        for (int i = 0; i <= N; i++) {
          if (abs(array[i]) < 10)
          s = s + array[i];
        }
        cout << "Sum of the elements that have number module < 10 = " << s <<endl;

        cout << "Indexes of elements that are over than next one "<<endl;
        for (int i = 0; i < N; i++) {
          if (array[i] > array[i+1])
          cout << i << " ";
        }
        cout<<endl;

        cout << "Elements of array that multiple of 3 and multiplied by third element of this array" << endl;
        for (int i = 0; i < N; i++) {
          if (array[i] % 3 == 0)
          cout << array[i] * array[2] << " ";
        }
        cout<<endl;

}
