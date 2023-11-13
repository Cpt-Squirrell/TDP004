// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// Note that the testcases outline here serve simply as inspiration
// you are not required to implement these tests, but you need to
// create tests for your list, so it might be a good idea to use
// these tests as a basis.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "catch.hpp"
#include "sorted_list.h"

#include <random>

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) 
{
    Sorted_List list{};

    REQUIRE( list.is_empty()  );
    REQUIRE( list.size() == 0 );
}

TEST_CASE( "Insert an item in an empty list" ) 
{
    Sorted_List list{};
    REQUIRE( list.is_empty() );
    REQUIRE( list.size() == 0 );

    list.insert(5);
	REQUIRE_FALSE( list.is_empty() );
	REQUIRE( list.size() == 1 );
	REQUIRE( list.fetch(0) == 5 );
}

SCENARIO( "Empty lists" ) 
{
    GIVEN( "An empty list" ) 
    {
		Sorted_List list{};
		REQUIRE( list.is_empty() );
		REQUIRE( list.size() == 0 );
		
		WHEN( "an item is inserted" )
		{
			list.insert(25);
		
			THEN( "the size increase and the item is first in the list" )
			{	
				REQUIRE_FALSE( list.is_empty() );
				REQUIRE( list.size() == 1 );
				REQUIRE( list.fetch(0) == 25 );
			}
		}
		
		WHEN( "an item is removed" )
		{
			list.remove(0);
		
			THEN( "the list is still empty" )
			{
				REQUIRE( list.is_empty()  );
				REQUIRE( list.size() == 0 );
			}
		}
		
		WHEN( "the list is copied to a new list" )
		{
			Sorted_List copiedList{list};

			THEN( "the new list is also empty" )
			{
				REQUIRE( copiedList.is_empty()  );
				REQUIRE( copiedList.size() == 0 );
			}
		}
		
		WHEN( "the list is copied to an existing non-empty list" )
		{
			Sorted_List existingList{};
			existingList.insert(5);
			existingList.insert(15);
			existingList.insert(55);
			existingList.insert(2);
			existingList.insert(11);
		
			THEN( "the existing list is also empty" )
			{
				existingList = list;
				REQUIRE( existingList.is_empty()  );
				REQUIRE( existingList.size() == 0 );
			}
		
		}
    }
}

SCENARIO( "Single item lists" )
{

    GIVEN( "A list with one item in it" )
    {
		Sorted_List list{};
		list.insert(5);
		REQUIRE( list.fetch(0) == 5 );

		WHEN( "a smaller item is inserted" )
		{
			list.insert(3);
			THEN( "the smaller item is inserted behind existing item" )
			{
				REQUIRE(list.fetch(0) == 3);
				REQUIRE(list.fetch(1) == 5);
			}
		}
		WHEN( "a larger item is inserted" )
		{
			list.insert(9);

			THEN( "the list has grown and the larger item is inserted last" )
			{
				REQUIRE(list.size() == 3);
				REQUIRE(list.fetch(1) == 5);
				REQUIRE(list.fetch(2) == 9 );
			}
		}
		WHEN( "an item is removed" )
		{
			list.remove(1);

			THEN( "the list size has shrunk and middle value is no longer present" )
			{
				REQUIRE(list.size() == 2);
				REQUIRE(list.fetch(0) == 3);
				REQUIRE(list.fetch(1) == 9);
			}
		}
		WHEN( "the list is copied to a new list" )
		{
			Sorted_List newList{list};
			THEN( "existing list remains untouched and new list reflects existing list" )
			{
				REQUIRE( list.size() == 2 );
				REQUIRE( newList == list );
			}
		}
		WHEN( "the list is copied to an existing non-empty list" )
		{
			Sorted_List newFilledList{};
			newFilledList.insert(15);
			newFilledList.insert(30);
			newFilledList.insert(19);
			newFilledList = list;
			THEN( "existing list remains untouched and filled list reflects existing list" )
			{
				REQUIRE( list.size() == 2 );
				REQUIRE( newFilledList == list );
			}
		}
    }
}

SCENARIO( "Multi-item lists" )
{

    GIVEN( "A list with five items in it" )
    {
		Sorted_List list{};
		list.insert(10);
		list.insert(20);
		list.insert(30);
		list.insert(40);
		list.insert(50);

		// create the given scenario and all THEN statements
		// and all REQUIRE statements
		
		WHEN( "an item smaller than all other is inserted" )
		{
			list.insert(5);
			THEN( "new item is placed before all existing items" )
			{
				REQUIRE(list.fetch(0) == 5);
				REQUIRE(list.fetch(1) == 10);
			}
		}
		WHEN( "an item larger than all other is inserted" )
		{
			list.insert(55);
			THEN("new item is placed after all existing items")
			{
				REQUIRE(list.fetch(5) == 50);
				REQUIRE(list.fetch(6) == 55);
			}
		}
		WHEN( "an item smaller than all but one item is inserted" )
		{
			list.insert(9);
			THEN("the inserted item is placed second to first")
			{
				REQUIRE(list.fetch(0) == 5);
				REQUIRE(list.fetch(1) == 9);
				REQUIRE(list.fetch(2) == 10);
			}
		}
		WHEN( "an item larger than all but one item is inserted" )
		{
			list.insert(52);
			THEN("new item is inserted second to last")
			{
				REQUIRE(list.fetch(6) == 50);
				REQUIRE(list.fetch(7) == 52);
				REQUIRE(list.fetch(8) == 55);
			}
		}
		WHEN( "an item is removed" )
		{
			int sizeBefore = list.size();
			int itemBefore = list.fetch(2);
			list.remove(2);
			THEN("item at index is removed and size is changed accordingly")
			{
				REQUIRE(list.fetch(2) != itemBefore);
				REQUIRE(list.fetch(1) == 9);
				REQUIRE(list.fetch(2) == 20);
				REQUIRE(list.fetch(3) == 30);
				REQUIRE(list.size() == sizeBefore - 1);
			}
		}
		WHEN( "all items are removed" )
		{
			list.clear();
			THEN("the list has zero size and trying to access it throws")
			{
				REQUIRE(list.size() == 0);
				REQUIRE_THROWS(list.fetch(0));
			}
		}
		WHEN( "the list is copied to a new list" )
		{
			Sorted_List newList{};
			list.insert(10);
			list.insert(20);
			list.insert(30);
			newList = list;
			THEN("new list contains items from old list")
			{
				REQUIRE(newList.fetch(0) == list.fetch(0));
				REQUIRE(newList.fetch(1) == list.fetch(1));
				REQUIRE(newList.fetch(2) == list.fetch(2));
			}
		}
		WHEN( "the list is copied to an existing non-empty list" )
		{
			Sorted_List newList{};
			newList.insert(55);
			newList.insert(66);
			newList.insert(77);
			newList = list;
			THEN("new list contains items from old list and has no trace of its old items")
			{
				REQUIRE(newList.fetch(0) == list.fetch(0));
				REQUIRE(newList.fetch(1) == list.fetch(1));
				REQUIRE(newList.fetch(2) == list.fetch(2));
				REQUIRE_THROWS(newList.fetch(3));
			}
		}
    }
}

SCENARIO( "Lists can be copied" )
{

    GIVEN( "A list with five items in it, and a new copy of that list" )
    {
		Sorted_List list{};
		list.insert(10);
		list.insert(20);
		list.insert(30);
		list.insert(40);
		list.insert(50);
		Sorted_List copyList = list;

		WHEN( "the original list is changed" )
		{
			list.remove(2);
			THEN( "the copy remain unmodified" )
			{
				REQUIRE(copyList.fetch(0) == 10);
				REQUIRE(copyList.fetch(1) == 20);
				REQUIRE(copyList.fetch(2) == 30);
				REQUIRE(copyList.fetch(3) == 40);
				REQUIRE(copyList.fetch(4) == 50);
			}
		}

		WHEN( "the copied list is changed" )
		{
			copyList.remove(3);
			THEN( "the original remain unmodified" )
			{
				REQUIRE(list.fetch(0) == 10);
				REQUIRE(list.fetch(1) == 20);
				REQUIRE(list.fetch(2) == 40);
				REQUIRE(list.fetch(3) == 50);
			}
		}
    }
}

SCENARIO( "Lists can be heavily used" )
{

    GIVEN( "A list with 1000 random items in it" )
    {
		// create the given list with 1000 random items
		std::random_device rd;
		std::uniform_int_distribution<int> uniform(1,1000);
		Sorted_List list{};
		
		for (int i{0}; i < 1000; ++i)
		{
			int random { uniform(rd) }; // generate a random number
			list.insert(random);
		}
		
		THEN("the order of the items are sorted correctly")
		{
			REQUIRE(list.validateOrder());
		}
		
		WHEN( "the list have 1000 random numbers inserted" )
		{
			for (int i{0}; i < 1000; ++i)
			{
				int random { uniform(rd) }; // generate a random number
				list.insert(random);
			}
			list.validateOrder();
		}

		WHEN( "the list have 2000 random numbers removed" )
		{
			for (int i{0}; i < 2000; ++i)
			{
				list.remove(0);
			}
			THEN("the list becomes an empty list")
			{
				REQUIRE(list.is_empty());
				REQUIRE(list.size() == 0);
			}
		}
    }
}

Sorted_List trigger_move(Sorted_List list)
{
	list.insert(55);
    return list;
}

SCENARIO( "Lists can be passed to functions" )
{

    GIVEN( "A list with 5 items in it" )
    {
		Sorted_List list{};
		list.insert(5);
		list.insert(10);
		list.insert(15);
		list.insert(20);
		list.insert(25);
		
		WHEN( "the list is passed to trigger_move()" )
		{
			Sorted_List returnList{ trigger_move(list) };
		
			THEN( "the given list remain and the result have the change" )
			{
				REQUIRE(list.fetch(0) == 5);
				REQUIRE(list.fetch(4) == 25);
				REQUIRE(list.size() == 5);
				
				REQUIRE(returnList.fetch(5) == 55);
				REQUIRE(list.size() == 6);
			}
		}
    }
}

// In addition you must of course verify that the list is printed
// correct and that no memory leaks occur during use. You can solve
// the printing part on your own. Here's how to run the (test) program
// when you check for memory leaks:

// You must of course verify that no memory leaks occur during use.
// To do so, an external program must be used to track what memory
// is allocated and free'd, you can run such a program like so:
//
// $ valgrind --tool=memcheck a.out

// Finally you need to check that you can do all operations that make
// sense also on a immutable list (eg all operations but insert):  
void use_const_list(Sorted_List const& list)
{
	list.is_empty();
	list.size();
	list.fetch(0); // Warning: Will throw because list is empty!
	list.print();
	list.validateOrder();
}
