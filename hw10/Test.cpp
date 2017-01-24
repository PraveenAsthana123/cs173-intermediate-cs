//==============================================================================
// Matt Kretchmar
// April 20, 2015
// mytest_list.cc
//
// This file does unit testing on each method of the list class.
// Uses templates
//==============================================================================

#include "list.h"

//==============================================================================
void default_constructor_test ( void )
{
    printf("======= default constructor test =============\n");
    List<int> list;
    printf("length empty: compare 0 with %d\n",list.length());
    printf("Compare [] with %s\n",list.str().c_str());
    printf("\n");
}

//==============================================================================
void copy_constructor_test ( void )
{
    printf("======= copy constructor test =============\n");
    List<int> list1;
    List<int> list2(list1);
    
    printf("list2 empty: compare size 0 with %d\n",list2.length());
    printf("Compare [] with %s\n",list2.str().c_str());
    
    list1.append(1);
    list1.append(2);
    list1.append(3);
    
    List<int> list3(list1);
    list1.pop(2);            // change list1, see if list3 changes
    list1.pop(1);
    
    printf("list3 length: compare size 3 with %d\n",list3.length());
    printf("Compare [1, 2, 3] with %s\n",list3.str().c_str());
    printf("\n");
}

//==============================================================================
void assignment_operator_test ( void )
{
    printf("======= assignment operator test =============\n");
    List<int> list1;
    List<int> list2 = list1;
    
    printf("list2 length: compare size 0 with %d\n",list2.length());
    printf("Compare [] with %s\n",list2.str().c_str());
    
    list1.append(1);
    list1.append(2);
    list1.append(3);
    
    List<int> list3;
    list2 = list1;
    printf("list2 length: compare size 3 with %d\n",list2.length());
    printf("Compare [1, 2, 3] with %s\n",list2.str().c_str());
    
    list3 = list2 = list1;
    printf("list3 length: compare size 3 with %d\n",list3.length());
    printf("Compare [1, 2, 3] with %s\n",list3.str().c_str());
    printf("\n");
}

//==============================================================================
void append_test ( void )
{
    printf("======= append test =============\n");
    List<int> list;
    list.append(1);
    printf("list length: compare size 1 with %d\n",list.length());
    printf("Compare [1] with %s\n",list.str().c_str());
    
    list.append(2);
    printf("list length: compare size 2 with %d\n",list.length());
    printf("Compare [1, 2] with %s\n",list.str().c_str());
    
    list.append(3);
    printf("list length: compare size 3 with %d\n",list.length());
    printf("Compare [1, 2, 3] with %s\n",list.str().c_str());
    printf("\n");
}

//==============================================================================

void pop_test ( void )
{
    printf("======= pop test =============\n");
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    
    printf("Starting with list = %s\n",list.str().c_str());

    printf("pop first item: compare 1 with %d\n",list.pop(0));
    printf("pop last item (default -1): compare 6 with %d\n",list.pop());
    printf("pop last item (2): compare 5 with %d\n",list.pop(3));
    printf("pop middle item (1): compare 3 with %d\n",list.pop(1));

    printf("list length: compare size 2 with %d\n",list.length());
    printf("Compare [2, 4] with %s\n",list.str().c_str());
    printf("\n");
}

//==============================================================================

void index_operator_test ( void )
{
    printf("======= index operator test =============\n");
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    
    printf("Starting with list = %s\n",list.str().c_str());
    
    printf("list[0]: compare 1 with %d\n",list[0]);
    printf("list[1]: compare 2 with %d\n",list[1]);
    printf("list[2]: compare 3 with %d\n",list[2]);
    list[1] = 5;
    printf("change list[1] to 5, compare with %d\n",list[1]);
    
    printf("list length: compare size 3 with %d\n",list.length());
    printf("Compare [1, 5, 3] with %s\n",list.str().c_str());
    printf("\n");
}

//==============================================================================
void insert_test ( void )
{
    printf("======= insert test =============\n");
    List<int> list;
    list.append(1);
    list.append(2);
    printf("Starting with list = %s\n",list.str().c_str());
    
    list.insert(0,-3);
    printf("insert -3 at front: [-3, 1, 2] = %s\n",list.str().c_str());
    
    list.insert(1,-2);
    printf("insert -2 at spot 1: [-3, -2, 1, 2] = %s\n",list.str().c_str());
    
    list.insert(4,-1);
    printf("insert -1 at back: [-3, -2, 1, 2, -1] = %s\n",list.str().c_str());
    
    printf("list length: compare size 5 with %d\n",list.length());
    printf("Compare [-3, -2, 1, 2, -1] with %s\n",list.str().c_str());
    printf("\n");
}

//==============================================================================
void basic_iterator_test ( void )
{
    
    printf("======= basic iterator test =============\n");
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    printf("Starting with list = %s\nForward:\n",list.str().c_str());
    list.resetForward();
    
    for ( int i = 0; i < list.length(); i++ )
    {
        printf("\titem[%d] = %d\n",i,list.next());
    }
    
    printf("list length: compare size 3 with %d\n",list.length());
    printf("Compare [1, 2, 3] with %s\n",list.str().c_str());

    printf("Starting with list = %s\nBackward:\n",list.str().c_str());
    list.resetReverse();
    
    for ( int i = 0; i < list.length(); i++ )
    {
        printf("\titem[%d] = %d\n",i,list.prev());
    }
    
    printf("list length: compare size 3 with %d\n",list.length());
    printf("Compare [1, 2, 3] with %s\n",list.str().c_str());

    printf("\n");
}

//==============================================================================
void index_exception_test ( void )
{
    printf("======= index exception test =============\n");
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    printf("Starting with list = %s\n",list.str().c_str());
    
    try {
        printf("Trying list[-1]\n");
        list[-1] = 0;
    } catch ( IndexError &e )
    {
        printf("Generated index exception\n");
        cout << e.Reason() << endl;
    }
    
    try {
        printf("Trying list[3]\n");
        list[3] = 0;
    } catch ( IndexError &e )
    {
        printf("Generated index exception\n");
        cout << e.Reason() << endl;
    }
    
    try {
        printf("Trying pop[3]\n");
        int x = list.pop(3);
    } catch ( IndexError &e )
    {
        printf("Generated index exception\n");
        cout << e.Reason() << endl;
    }
    
    try {
        printf("Trying pop[-2]\n");
        int x = list.pop(-2);
    } catch ( IndexError &e )
    {
        printf("Generated index exception\n");
        cout << e.Reason() << endl;
    }
    
    try {
        printf("Trying insert[5]\n");
        list.insert(5,10);;
    } catch ( IndexError &e )
    {
        printf("Generated index exception\n");
        cout << e.Reason() << endl;
    }
    
    try {
        printf("Trying insert[-1]\n");
        list.insert(-1,10);;
    } catch ( IndexError &e )
    {
        printf("Generated index exception\n");
        cout << e.Reason() << endl;
    }
    printf("\n");
}
    
//==============================================================================

void iterator_exception_test ( void )
{
    printf("======= iterator exception test =============\n");
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    printf("Starting with list = %s\n",list.str().c_str());
   
    try {
        printf("trying to reset forward and then print 4 items\n");
        list.resetForward();
        for ( int i = 0; i < list.length()+1; i++ )
            printf("\t = %d\n",list.next());
    } catch ( StopIteration &e ) {
        printf("Generated iterator exception\n");
        cout << e.Reason() << endl;
    }
    
    try {
        printf("trying to reset reverse and then print 4 items\n");
        list.resetReverse();
        for ( int i = 0; i < list.length()+1; i++ )
            printf("\t = %d\n",list.prev());
    } catch ( StopIteration &e ) {
        printf("Generated iterator exception\n");
        cout << e.Reason() << endl;
    }
    
    printf("\n");
}

//==============================================================================

void nasty_iterator_test ( void )
{
    printf("======= nasty iterator test =============\n");
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    printf("\n");
    printf("Starting with list = %s\n",list.str().c_str());

    printf("Test 1: reset forward, step once, delete middle (current), step twice more\n");
    try {
        printf("trying to reset forward and then print 3 items\n");
        list.resetForward();
        printf("\t (1) = %d\n",list.next());        // step forward once
        list.pop(1);                            // remove 2nd item (current forward)
        printf("\t (3) = %d\n",list.next());        // step forward once
        printf("\t (x) = %d\n",list.next());        // step forward again -- should be error
    } catch ( StopIteration &e ) {
        printf("Generated iterator exception\n");
        cout << e.Reason() << endl;
    }

    list.insert(1,2);
    printf("\n");
    printf("Starting with list = %s\n",list.str().c_str());
    printf("Test 2: reset reverse, step once, delete middle (current), step twice more\n");
    try {
        printf("trying to reset reverse and then print 3 items\n");
        list.resetReverse();
        printf("\t (3) = %d\n",list.prev());        // step rev once
        list.pop(1);                                // remove 2nd item (current forward)
        printf("\t (1) = %d\n",list.prev());        // step rev once
        printf("\t (x) = %d\n",list.prev());        // step rev again -- should be error
    } catch ( StopIteration &e ) {
        printf("Generated iterator exception\n");
        cout << e.Reason() << endl;
    }
    list.insert(1,2);

    printf("\n");
    printf("Starting with list = %s\n",list.str().c_str());
    
    printf("Test 3: reset forward, step, delete,  step twice more\n");
    try {
        printf("trying to reset forward and then print 3 items\n");
        list.resetForward();
        printf("\t (1) = %d\n",list.next());        // step forward once
        printf("\t (2) = %d\n",list.next());        // step forward once
        list.pop(-1);                                 // remove last item (current)
        printf("\t (x) = %d\n",list.next());        // step forward again -- should be error
    } catch ( StopIteration &e ) {
        printf("Generated iterator exception\n");
        cout << e.Reason() << endl;
    }
    list.insert(2,3);
    
    printf("\n");
    printf("Starting with list = %s\n",list.str().c_str());
    
    printf("Test 4: copy constructor\n");
    try {
        printf("trying to reset forward and then move once\n");
        list.resetForward();
        printf("\tlist1: (1) = %d\n",list.next());        // step forward once
        printf("now creating second list with copy constructor\n");
        List<int> list2(list);
        printf("\tlist2: (2) = %d\n",list2.next());        // step forward once
        printf("\tlist1: (2) = %d\n",list.next());         // step forward once
        printf("\tlist2: (3) = %d\n",list2.next());        // step forward again
        printf("\tlist2: (x) = %d\n",list2.next());        // step forward again -- should be error
    } catch ( StopIteration &e ) {
        printf("Generated iterator exception\n");
        cout << e.Reason() << endl;
    }
    
    
    printf("\n");
}
    
//==============================================================================
void index_test ( void )
{
    printf("======= index test =============\n");
    List<int> list;
    list.append(1);
    list.append(2);
    list.append(1);
    
    printf("\n");
    printf("Starting with list = %s\n",list.str().c_str());
    printf("index of %d = %d\n",0,list.index(0));
    printf("index of %d = %d\n",1,list.index(1));
    printf("index of %d = %d\n",2,list.index(2));
}

//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================

int main ( void )
{
    default_constructor_test();
    append_test();
    index_test();
    assignment_operator_test();
    index_operator_test();
    basic_iterator_test();
    iterator_exception_test();
    copy_constructor_test();
    pop_test();
    insert_test();
    index_exception_test();
    nasty_iterator_test();
    
    return 0;
}
