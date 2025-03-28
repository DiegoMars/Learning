#include <iostream>
#include <string>
#include "dvdBinaryTree.h"

using namespace std;

bool dvdBinaryTree::isDVDAvailable(string title) 
{
    bool found;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    if (found)
        found = (location->info.getNoOfCopiesInStock() > 0);
    else  
        found = false;

    return found;
}

void dvdBinaryTree::dvdCheckIn(string title)
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    if (found)
        location->info.checkIn();
    else
        cout << "The store does not carry " << title
             << endl;
}

void dvdBinaryTree::dvdCheckOut(string title)
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    if (found)
        location->info.checkOut();
    else
        cout << "The store does not carry " << title
             << endl;
}

bool dvdBinaryTree::dvdCheckTitle(string title) const
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    return found;
}

void dvdBinaryTree::dvdUpdateInStock(string title, int num)
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    if (found)
        location->info.updateInStock(num);
    else
        cout << "The store does not carry " << title
            << endl;
}

void dvdBinaryTree::dvdSetCopiesInStock(string title, 
                                            int num)
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    if (found)
        location->info.setCopiesInStock(num);
    else
        cout << "The store does not carry " << title
             << endl;
}

bool dvdBinaryTree::dvdSearch(string title)
{
    bool found = false;
    nodeType<dvdType> *location;

    searchDVDList(title, found, location);

    return found;
}

void dvdBinaryTree::searchDVDList(string title, 
                          bool& found,
                          nodeType<dvdType>* &current) const
{
    found = false;   
   
    dvdType temp;

    temp.setDVDInfo(title, "", "", "", "", "", 0);

    if (root == nullptr)  //tree is empty
        cout << "Cannot search an empty list. " << endl;
    else
    {
        current = root; //set current point to the root node 
                        //of the binary tree
        found = false;  //set found to false

        while (current != nullptr && !found) //search the tree
            if (current->info == temp)    //item is found
                found = true;
            else if (current->info > temp)
                current = current->lLink;
            else
                current = current->rLink;
    } //end else
} //end searchDVDList

void dvdBinaryTree::dvdPrintTitle() const
{
    inorderTitle(root);
}

void dvdBinaryTree::inorderTitle
                          (nodeType<dvdType> *p) const
{
    if (p != nullptr)
    { 
        inorderTitle(p->lLink);
        p->info.printTitle();
        inorderTitle(p->rLink);
    }
}

