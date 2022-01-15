// Patrick Jirele 
// Practice with arrays and functions

#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 20;

void loadArray(int[], int&);
void displayArray(int[], int);
int sumArray(int[], int);
int findMax(int[], int);
int linearSearch(int[], int, int);
void findLargestTwo(int x[], int, int&, int&);
void displayReverse(int[], int);
bool isAllEven(int[], int);
bool inAscendingOrder(int[], int);
int countInstances(int[], int, int);

int main()
{
    int x[MAX], size = 0, target = 13;
    loadArray(x, size);


    cout << "Expected:" << endl;
    cout << "displays a random set of integers" << endl;
    cout << "Actual: " << endl;
    displayArray(x, size);


    cout << "Sum is: " << sumArray(x, size) << endl << endl;
    cout << "Max is: " << findMax(x, size) << endl << endl;
    cout << "Found " << target << " at: " << linearSearch(x, size, target) << endl << endl;

    int largest = findMax(x, size);
    int secondLargest = 0;
    findLargestTwo(x, size, largest, secondLargest);
    displayReverse(x, size);

    cout << "Expected: " << endl;
    cout << "return true if array is all even, return false if array is not all even" << endl;
    cout << "Actual: " << endl;

    cout << boolalpha;
    cout << isAllEven(x, size) << endl;


    cout << endl;
    cout << endl;


    cout << "Expected: " << endl;
    cout << "return true if array is in ascending order, return false if array is not in ascending order" << endl;
    cout << "Actual: " << endl;

    cout << boolalpha;
    cout << inAscendingOrder(x, size) << endl;


    cout << endl;
    cout << endl;



    cout << "Expected: " << endl;
    cout << "returns the number of times the target was found in the array" << endl;
    cout << "Actual: " << endl;
    cout << countInstances(x, size, target) << endl;



}

void loadArray(int data[], int& n) {
    int minVal, maxVal;
    cout << "How many? ";
    cin >> n;
    cout << "Min and max random? ";
    cin >> minVal >> maxVal;
    //srand(time(NULL));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % (maxVal - minVal + 1) + minVal;
    } //for
} //loadArray

void displayArray(int d[], int n) {
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl << endl;
}

int sumArray(int d[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += d[i];
    }
    return sum;
}

int findMax(int d[], int n) {
    int maxV = d[0];
    for (int i = 0; i < n; i++)
        if (d[i] > maxV) {
            maxV = d[i];
        }
    return maxV;
}

int linearSearch(int d[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (d[i] == target)
            return i;
    }
    return -1;
}

void findLargestTwo(int x[], int n, int& largest, int& secondLargest)
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] > largest)
        {
            largest = x[i];
        }
    } // end for

    for (int i = 0; i < n; i++)
    {
        if (x[i] != largest)
        {
            if (x[i] > secondLargest)
            {
                secondLargest = x[i];
            }
        }
    } // end for
    cout << "Expected:" << endl;
    cout << "The two largest values " << endl;
    cout << "Actual: " << endl;
    cout << "The largest value is: " << largest << " and the second largest value is: " << secondLargest << endl << endl;
} // end find largest two

void displayReverse(int x[], int n)
{
    cout << "Expected: " << endl;
    cout << "The array is reverse order" << endl;
    cout << "Actual: " << endl;
    for (int i = n; i > 0; i--)
    {
        x[i] = x[i - 1];
        cout << x[i] << " ";
    }

    cout << endl;
    cout << endl;
} // end display reverse

bool isAllEven(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] % 2 == 0)
        {
            continue;
        }
        else
            return false;
    }

    return true;

} // end is all even

bool inAscendingOrder(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] < x[i - 1])
        {
            return false;
        }
    } // end for
    return true;
} // end is ascending order

int countInstances(int x[], int n, int target)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == target)
        {
            counter++;
        }
    } // end for
    return counter;
} // end count Instances