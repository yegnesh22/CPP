++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			Simple Pooler Class

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Description:
This source contains the implementation of a Pooler class which can do the following:
1. Create a pool with fixed number of objects of one specific class/data type.
2. ObjAlloc - function to return an address to a valid slot in the pool/nullptr if a
   valid slot does not exist.
3. ObjDealloc - function that takes an address in the pool as an argument and releases
   it from use. Returns a boolean status true if the address was in the allocated list
   within this pool, false if the address does not exists or address is nullptr.
4. Destroy the pool of addresses acquired while creation.

Usage:
1. Creating a pool:
    Pooler<Type> PoolerVar() <-- for single element pool
    Pooler<Type> PoolerVar(n) <-- for pool with n elements. n should be <= 1000.
2. Get a slot from the pool:
    Type* Var = PoolerVar->ObjAlloc() <-- Allocates an object's address to Var.
    If Var is nullptr, allocation failed.
3. Release a slot from the pool:
    bool s = PoolerVar->ObjDealloc(Var) <-- Releases the slot back to the pool.
    If s == true, then Dealloc was successful and the address is added back to
    the pool. If s == false, the Dealloc was unsuccessful. Reason for failure
    could be, a. Var is nullptr, b. Var is not an address in this PoolerVar.
    If successful, Var is set to nullptr;

Limitation:
1. ObjAlloc call allocates only 1 object at a time. Does not take the number of slots
   as an argument.	
2. Pooler cannot support objects of classes without default constructors.
    E.g: Refer the ExampleClasses.h file for the class definition
    class NoDefaultConstructor. This class has the constructor taking an integer
    parameter and it does not have a constructor with no parameters. Since the
    pooler has to support multiple types of objects and datatypes, it requires 
    default constructor with no arguments to be defined for classes/types it can
    take as templates.

Sources:
    include
        |------------ ExampleClasses.h (Sample Classes for testing the pool implementation)

        |------------ Pool.h (Implementation of Pool functions) <---------------------------------------

        |------------ Tests (dir of header files with unit test function declarations for all data types)
        |------------ |------------- Base1Tests.h (test function declaration for Base2)
        |------------ |------------- Base2Tests.h (test function declaration for Base2)
        |------------ |------------- ByteTypeTests.h (test function declaration for ByteType)
        |------------ |------------- DerivedTests.h (test function declaration for Derived)
        |------------ |------------- FixedStringTypeTests.h (test function declaration for FixedStringType)
        |------------ |------------- PointerTypeTests.h (test function declaration for PointerType)
        |------------ |------------- StructPointTypeTests.h (test function declaration for StructPointType)
        |------------ |------------- Tests.h (main header file containing all unit test function pointers)
    src
        |------------ Tests (dir of source files with unit test function definitions for all data types)
        |------------ |------------- Base1Tests.cpp (test function definition for Base2)
        |------------ |------------- Base2Tests.cpp (test function definition for Base2)
        |------------ |------------- ByteTypeTests.cpp (test function definition for ByteType)
        |------------ |------------- DerivedTests.cpp (test function definition for Derived)
        |------------ |------------- FixedStringTypeTests.cpp (test function definition for FixedStringType)
        |------------ |------------- PointerTypeTests.cpp (test function definition for PointerType)
        |------------ |------------- StructPointTypeTests.cpp (test function definition for StructPointType)
        |------------ |------------- Tests.cpp (main source file that calls all the test functions)
       

Compiling:
    Run 'make' from the directory. This will create object files under build directory and the main
    an executable 'PoolerTest'.

Running the tests:
    Run the 'PoolerTest' executable created under the build directory.

Tested on: Linux
		
