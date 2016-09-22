#include "Factory.h"
#include "AVL.h"
//You may add #include statements here

/*
You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
getAVL()

Creates and returns an object whose class extends AVLInterface.
This should be an object of a class you have created.

Example: If you made a class called "AVL", you might say, "return new AVL();".
*/
AVLInterface * Factory::getAVL()
{
	return new AVL();//Modify this line
}
