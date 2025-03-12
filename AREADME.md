# Largest Number in Array 
 
## Student Information - **Name**: Boru Golicha - **Student ID**: RMNS-2889/23 - **Course**: DSA
 
## Algorithm 
1. Input:

--Prompt the user to enter the size of the array (n).

--If the size of the array is less than 3, display a message indicating that there are not enough elements to determine the second and third largest elements and terminate the program.

--Prompt the user to enter the elements of the array.

2. Initialization:

--Initialize three variables (firstLargest, secondLargest, thirdLargest) to the smallest possible integer value (INT_MIN).

3. Iteration:

--Iterate through each element in the array:

----If the current element is greater than firstLargest:

------Update thirdLargest to secondLargest.

------Update secondLargest to firstLargest.

------Update firstLargest to the current element.

---Else if the current element is greater than secondLargest:

------Update thirdLargest to secondLargest.

------Update secondLargest to the current element.

---Else if the current element is greater than thirdLargest:

------Update thirdLargest to the current element.

4. Output:

--If secondLargest and thirdLargest are not INT_MIN:

----Prompt the user to choose which element to print (1 - Largest, 2 - Second Largest, 3 - Third Largest).

----Display the chosen element based on the user's input.

----If the user's choice is invalid, display an error message and prompt the user to choose again or terminate the program based on the user's decision.

5. Repeat:

--Ask the user if they want to try again:

----If the user chooses "Yes", repeat steps 1-4.

----If the user chooses "No", display a goodbye message and terminate the program.

----If the user inputs an invalid choice, display an error message and terminate the program. 
 
## How to Run the Code 
1. Clone the repository to your local machine. 
2. Open the terminal and navigate to the repository directory. 
3. Compile the C++ code using: 
   ```bash 
   g++ main.cpp -o main 
 
Run the compiled program: 
./main 
Output 
The program will output: 
The largest number in the array is: 50 
 
Contributing 
Feel free to contribute to this project by forking the 
repository and submitting a pull request. 
License 
This project is licensed under the MIT License. 