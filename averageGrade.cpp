#include <iostream>

using namespace std;

//Create prototypes for functions
void bubbleSort(int [], int);
double averageScore(int [], int);

int main()
{
    //Create variables and pointer
    int *iptr = nullptr;
    int numOfGrades;
    double average;

    //Get user input on number of grades to be averaged
    cout << "This is a program that finds the averages of test scores" << endl;
    cout << "Enter the number of test scores" << endl;
    cin >> numOfGrades;

    //Input validation for days
    while (numOfGrades <= 0)
        {
            cout << "That is not a valid number. Please enter again: ";
            cin >> numOfGrades;
        }

    //Dynamically allocate memory for array
    iptr = new int[numOfGrades];

    //Input scores for each test
    cout << "Enter the test scores" << endl;
    for(int i = 0; i < numOfGrades; i++)
    {
        cout << "Test Score " << (i + 1) << ": " << endl;
        cin >> *(iptr + i);
        while ((*(iptr + i)) <= 0)
        {
            cout << "That is not a valid test score. Please enter again: ";
            cin >> *(iptr + i);
        }
    }

    //Sort grades in ascending order
    bubbleSort(iptr, numOfGrades);

    //Find average of grades
    average = averageScore(iptr, numOfGrades);

    //Output test scores and average
    cout << "Your test scores were: ";
    for(int i = 0; i < numOfGrades; i++)
    {
        cout << *(iptr + i) << " ";
    }

    cout << endl << "Your average score was: " << average;

    return 0;
}

void bubbleSort(int array[], int size)
{
    int minElement;
    int index;

    for(minElement = size - 1; minElement > 0; minElement--)
    {
        for(index = 0; index < minElement; index++)
        {
            if(array[index] > array[index + 1])
            {
                int temp = array[index];
                array[index] = array[index + 1];
                array[index + 1] = temp;
            }
        }
    }
}

double averageScore(int array[], int size)
{
     int total = 0;
     double average;
     for(int i = 0; i < size; i++)
     {
        total += *(array + i);
     }
     average = total / size;
     return average;
}
