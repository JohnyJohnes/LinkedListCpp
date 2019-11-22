# Assignment 1 - Lists

## Task

In this assignment you will program a doubly-linked list (with sentinel node) data structures. This class must be programmed as class templates and follow the C++ STL convention of accessing and manipulating elements. Most of the boilerplate code is already written and resides in [src/include/list.h](src/include/list.h).


## Instructions

After you have accepted the classroom invitation and a private repository has been created for you, do the following:

1. Create a new CLion project by checking out the assignment from your freshly created classroom repository.

1. After creating the project, in CLion in the terminal window execute the following two git commands:

    ~~~bash
    git submodule init
    git submodule update
    ~~~
    
    This will pull googletest repository as a submodule and add it to your project. 

1. Try to run the `tests_singly` target - most likely all the tests will pass. This target tests the singly-linked list implementation in [src/include/forward_list.h](src/include/forward_list.h).

1. Now try to run 'tests_doubly' target - you will observe that all but 3 tests fail. What's worse the test itself will crash. Your goal is to fix the implementation in [src/include/list.h](src/include/list.h), so that as many tests as possible pass.

1. You get one point for each fixed test to a maximum of 20 points. There are 26 tests in total, but the three already pass, so you have 23 chances to get a point.

1. There is already an implementation of the singly-linked list. Use it. Many functions of the doubly-linked list look very similar to their singly-linked siblings. 

1. The places where you should write or change some code are conveniently marked with `todo` tags, there are also short descriptions in those places.

1. You will notice that in many functions there are lines like: `(void)other;    //remove this one!`. You can safely remove those after you fixed a function. Those weird casts to void silence a compiler warning about an unused parameter.

1. If you have questions, need help, etc:
    
    * (optional) create a new branch.
    
    * commit and push the changes
    
    * create an issue and assign me to it.

1. If you are ready commit your changes and push them to Github, **your commit message must start with a word:** ***GRADE***

That's all!
