    //Eric Deokie
    //Array Manipulation Extra Credit Assignment

    #include<iostream>

    using namespace std;

    bool isFull(int& numElements, const int CAP);
    int  getIndex(int a[], int& numElements, int index);
    void output (int a[], int& numElements, const int CAP);
    void append(int a[], int num, int& numElements, const int CAP);
    void insertAt(int a[],int& numElements,int value, int position,const int CAP);
    void removeElement(int a[], int& numElements, int num);
    void removeFirst(int a[],int& numElements);
    void removeLast(int a[], int& numElements);
    bool containElement(int a[], int& numElements,int num);

    //Function prototype declarations
    //CAP was set as a constant integer because it can never be changed by the program.
    //This prevents the program from exceeding boundary limits.
    //NumElements is set up to use call by reference because the values must be kept current and updated at all times during program execution.


    int main ()

    {

    const int CAPACITY=10;
    int numbers[CAPACITY];
    int numElements =0;

    //Variable and array declarations.
    //The array size is specified using the CAPACITY variable. This ensures that the array cannot hold more than 10 values and that it cannot be o
    //NumElements is used to keep track of the elements within the array.

    cout <<"Populate Array\n";

    append(numbers, 10, numElements,CAPACITY);
    append(numbers, 20, numElements,CAPACITY);
    append(numbers, 30, numElements,CAPACITY);
    append(numbers, 40, numElements,CAPACITY);
    append(numbers, 50, numElements,CAPACITY);
    output(numbers, numElements, CAPACITY);

    //Making function calls to append the numbers to the array.
    //The array, the desired value, number of elements and the capacity of the array are being passed to the append function.
    //Once the append function is successfully called on and executed, the number of elements with their values in the array are updated.
    //Calling the output function after the values have been appended will display the most updated elements in the array.
    //This occurs because numElements is being called by reference in the program.


    cout <<endl;
    cout <<endl;

    cout <<"Remove first element: 10\n";

    removeFirst(numbers, numElements);
    output(numbers, numElements,CAPACITY);

    //Making a call to the removeFirst function and redisplaying the array after it has been modified by the removeFirst function.

    cout <<endl;
    cout <<endl;

    cout <<"Remove last element: 50\n";

    removeLast(numbers,numElements);
    output(numbers,numElements,CAPACITY);

    //Making a call to the removeLast function and redisplaying the array after it has been modified by the removeLast function.

    cout <<endl;
    cout <<endl;

    cout <<"Insert 100 at index[2]:\n";

    insertAt(numbers, numElements,100, 2 , CAPACITY);
    output(numbers, numElements,CAPACITY);

    //The value that needs to be added to the array along with it's specified position is passed to the insertAt function.
    //If the index value specified is out of bounds, an error message is displayed on the screen and the output function simply
    //redisplays the array without any modifications.

    cout <<endl;
    cout <<endl;

    cout <<"Remove 30:\n";

    removeElement(numbers,numElements,30);
    output(numbers,numElements,CAPACITY);

    //Making a function call to remove the element 30, from the array.

    cout <<endl;
    cout <<endl;

    cout <<"Append 60:\n";

    append(numbers, 60, numElements,CAPACITY);
    output(numbers, numElements,CAPACITY);

    //Append function is called on to add the value 60, to the end of the array. The output function redisplays the array after it has been modified by the append function.

    cout <<endl;
    cout <<endl;

    cout <<"Insert 70 at index [0]:\n";

    insertAt(numbers, numElements,70, 0 , CAPACITY);
    output(numbers, numElements,CAPACITY);

    //The specified value of the element and it's corresponding index value is passed to the insertAt function.
    //Output function redisplays the array based on modification.

    cout <<endl;
    cout <<endl;

    cout <<"Insert 80 at index [10]:\n";
    insertAt(numbers, numElements, 80, 10 , CAPACITY);
    output(numbers, numElements,CAPACITY);

    //The desired element value and index values are passed to the insertAt function.
    //The index value however, is out of bounds. The numbers array has a maximum index of 9, which corresponds to the 10th element in the array.
    //An error message will be generated to the user and the output function will simply display the array without any modification.

    cout <<endl;
    cout <<endl;

    cout <<"Append 80:\n";
    append(numbers, 80, numElements,CAPACITY);
    output(numbers, numElements,CAPACITY);

    //Making a call to the append function and the output function to add 80 to the end of the array and then redisplay the updated array.


    cout <<endl;

    return 0;

    //End of program.

    }
    void append(int a[], int num, int& numElements, const int CAP) {

        isFull(numElements, CAP);

        if(numElements < CAP) {
            a[numElements] = num;
            numElements++;
        }

    }
    //The isFull function is called on before any values are appended to the array. This validates that the array is not full and allows elements to be appended.
    //If the number of elements is less than the size of the array, the number is added to the array.
    //Else, an error message is displayed by the isFull helper function and the program does not enter the if statement in the append function.
    //This is done by declaring that the numbers array(a) of size numElements is equal to the value that we are trying to add.
    //Once this is done, numElements is incremented to reflect the total amount of elements in the array.
    //This is executed everytime the append function is called, and the numElements parameter is always kept current.

    bool isFull(int& numElements, const int CAP){

        if (numElements == CAP)
        {
            cout <<"Array is fully populated. New values cannot be added.\n";
            return true;
        }
        else {
            return false;
        }
    }
    //This function checks to make sure that the number of elements in the array does not exceed the capacity of the array.
    //If the number of elements is equal to the capacity of the array, an error message is displayed.

    void output (int a[], int& numElements, const int CAP) {

        int counter=0;

        cout << "Array: ";


        for(int i=0; i<numElements; i++) {
            cout << a[i] << " ";
            counter++;
        }
        cout <<"Size: " <<counter;

    }
    //The counter variable is used to count the number of elements within the array and is the value used for displaying the current size of the array.
    //It is incremented after each successful iteration of the for loop.
    //The for loop is used to populate and display the array, where the variable i is being used as a control variable for numElements.

    int getIndex(int a[],int& numElements, int index){

        containElement(a,numElements,index);
    if(containElement(a,numElements,index)){


        for (int i = 0;i < numElements; i++){
            if (a[i] == index)
                return i;
        }
        return -1;
    }
    }
    //This function makes use of the helper function containsElement.
    //If any element exists in the array, the value of the index is returned.
    //all values within the array are checked with each iteration of the for loop to see if it matches with the index value.
    //If the element doesn't exist, -1 is returned.

    void removeFirst(int a[],int& numElements) {

     for(int i=0; i<numElements; i++) {
            a[i] = a[i+1];
        }
        numElements--;

    }
    //This function allows for the first element of the array to be removed. It first works by shifting the indexes of numElements to the right and then decrementing the size of the array.
    //Essentially, it is getting removing the first index, by decrementing the array size.

    void removeLast(int a[], int& numElements) {

        numElements--;

    }
    //This function simply decrements the size of the array and in doing so causes the last value to not be displayed.

    void insertAt(int a[],int& numElements, int value, int position,int CAP) {

    isFull(numElements,CAP);


    if (position > CAP-1) {

        cout <<"Index number exceeds capacity of array. New number cannot be added.\n\n";
    }


    else if(numElements < CAP){
            numElements++;
            for(int i=numElements-1; i> position; i--) {
                a[i] = a[i-1];
            }
            a[position] = value;

    }

    //Before values are inserted into the array, the isFull helper function checks to make sure that there is available space in the array for new values.
    //The function is executed once it is determined that the array is not full, else, an error message is generated.
    //The number of elements in the array is incremented before the for loop, so as to ensure that garbage values are not generated.
    //It is also ensuring that the numElements is kept updated with the execution of the program, since it is a call by reference parameter.
    //The for loop is then used to assign the desired value to a specific index within the array.
    //The value is placed in the index slot before the existing value that we are trying to insert the new element.

    }
    void removeElement(int a[], int& numElements, int num) {

    int index = getIndex(a, numElements, num);

        for(int i=index; i<numElements; i++) {
            a[i] = a[i+1];
        }
        numElements--;

    }
    //This function is used to remove a specific element from the array.
    //It makes use of the getIndex helper function to obtain the index of the value that has to be removed.
    //The index value is then assigned to the index variable.
    //The for loop is then used to remove the element at the specified index, by basically leaving an empty space in the memory that holds the value of the element.
    //The number of elements is decremented to reflect the removal of the element at the specified index.

    bool containElement(int a[], int& numElements,int num){

        for (int i = 0;i < numElements;i++){
            if (a[i] == num)
                cout <<"Number already exists.";
                return true;
        }

        return false;
    }
    //This helper function checks through all values in the array to see if the value that is trying to be removed exists in the array.
