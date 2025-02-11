# Employee Management System with Sorting

This project is an implementation of an **Employee Management System** in C++. It allows users to store employee details and sort them based on their IDs using various sorting algorithms. Below is a detailed description of the project.

---

## Project Description

The **Employee Management System** is a C++ program that:

- Stores employee details such as **ID**, **name**, **age**, and **salary**.
- Provides sorting functionalities using the following algorithms:
  - **Selection Sort**
  - **Bubble Sort**
  - **Insertion Sort**
- Allows the user to choose their preferred sorting algorithm to sort employees based on their IDs.

---

## Features

1. **Employee Class**:
   - Represents an employee with attributes:
     - `emp_id`: Employee ID (unique identifier).
     - `name`: Employee name.
     - `age`: Employee age.
     - `salary`: Employee salary.

2. **EmployeeManager Class**:
   - Manages a list of employees.
   - Implements the following sorting algorithms:
     - **Selection Sort**: Selects the smallest element and places it in its correct position iteratively.
     - **Bubble Sort**: Repeatedly swaps adjacent elements if they are in the wrong order.
     - **Insertion Sort**: Inserts each element into its proper position within a sorted portion of the array.

3. **User-Friendly Interface**:
   - Allows the user to input employee details.
   - Displays the list of employees before and after sorting.
   - Provides an option to choose the sorting algorithm.

---

## Program Flow

1. The user enters the number of employees and their details (ID, name, age, and salary).
2. Employees are stored in a `vector`.
3. The user selects a sorting algorithm from the following options:
   - **Selection Sort**
   - **Bubble Sort**
   - **Insertion Sort**
4. The program sorts the employees based on their IDs using the selected algorithm.
5. The sorted list of employees is displayed.


