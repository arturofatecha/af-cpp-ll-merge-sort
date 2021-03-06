/**
 * @file main.cpp
 * University of Illinois CS 400, MOOC 2, Week 1: Linked Lists
 *
 * @author Eric Huber
**/

#include <iostream>
#include <string>

#include "LinkedList.h"
#include "LinkedListExercises.h"

// -----------------------------------------------------------------------
// Function prototypes: When global functions are defined later in the
// compilation unit than they are called, then at least these function
// prototype header lines must be written before the call.

// Some informal unit tests. Defined at the bottom of main.cpp
void informalTests();
// Helper function used by informalTests. Defined at the bottom of main.cpp
void errorReaction(std::string msg);

// -----------------------------------------------------------------------

// main program: You can do whatever you want to test your code here.
// See also the test suite that you can build with "make test".
int main() {
  informalTests();
  return 0;
}

// ------------------------------------------------------------------------

// Choose what to do if an informal test has a big problem.
void errorReaction(std::string msg) {
  // If you want to throw an exception and stop the program immediately:
  // throw std::runtime_error(msg);
  // If you want to display a warning and keep going:
  std::cout << std::endl << "WARNING: " << msg << std::endl << std::endl;;
}

// These tests aren't very exhaustive of the student exercise code.
// They are more of a sanity check on the LinkedList class itself.
void informalTests() {

  std::cout << "Running a few informal tests. Feel free to study these or edit them." << std::endl;
  std::cout << "The unit tests in the tests/ subdirectory are much more exhaustive!" << std::endl;
  std::cout << "You can run those by doing: make clean && make test && ./test" << std::endl;
  std::cout << "Remember that when you're ready to submit, you should do: make zip" << std::endl;
  std::cout << "That will package the zip file properly for submission." << std::endl;

  {
    std::cout << std::endl << "Testing insertOrdered:" << std::endl;

    LinkedList<int> expected;
    expected.pushBack(-1);
    expected.pushBack(4);
    expected.pushBack(5);
    expected.pushBack(6);
    expected.pushBack(7);
    expected.pushBack(8);
    expected.pushBack(9);
    expected.pushBack(10);

    LinkedList<int> l;
    l.pushBack(5);
    l.pushBack(6);
    l.pushBack(8);
    l.pushBack(9);
    std::cout << "List: " << l << std::endl;
    l.insertOrdered(7);
    l.insertOrdered(4);
    l.insertOrdered(-1);
    l.insertOrdered(10);
    std::cout << "Inserting items now." << std::endl;
    std::cout << "List: " << l << std::endl;
    std::cout << "Expected: " << expected << std::endl;
    if (l != expected) errorReaction("wrong result");

    std::cout << "Testing copy constructor:" << std::endl;
    LinkedList<int> l2(l);
    std::cout << "Copy: " << l2 << std::endl;
    std::cout << "Expected: " << expected << std::endl;
    if (l2 != expected) errorReaction("wrong result");

    std::cout << "Checking equivalency:" << std::boolalpha << (l == l2) << std::endl;

  }

  {
    std::cout << std::endl << "Testing merge():" << std::endl;
    LinkedList<int> l;
    l.pushBack(1);
    l.pushBack(3);
    l.pushBack(5);
    LinkedList<int> r;
    r.pushBack(-1);
    r.pushBack(2);
    r.pushBack(10);
    r.pushBack(20);

    LinkedList<int> expected;
    expected.pushBack(-1);
    expected.pushBack(1);
    expected.pushBack(2);
    expected.pushBack(3);
    expected.pushBack(5);
    expected.pushBack(10);
    expected.pushBack(20);

    std::cout << "Left List: " << l << "  ";
    std::cout << "Right List: " << r << std::endl;
    auto merged = l.merge(r);
    std::cout << "Merged: " << merged << std::endl;
    std::cout << "Expected: " << expected << std::endl;
    if (merged != expected) errorReaction("Bug in merge");
  }

  std::cout << "\n\nInformal tests finished without crashing, but the output may have been incorrect."
    << "\nPlease scroll to the top of the output to read the diagnostics." << std::endl;

}
