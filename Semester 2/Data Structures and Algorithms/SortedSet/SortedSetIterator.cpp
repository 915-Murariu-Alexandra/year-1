#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	//TODO - Implementation!
	this->current = 0;
}
// Theta(1)

void SortedSetIterator::first() {
	//TODO - Implementation!
	this->current = 0;
}
//Theta(1)

void SortedSetIterator::next() {
	//TODO - Implementation!
	if(this->current == this->multime.nrElems) {
	    throw exception();
	}
	else {
	    this->current++;
	}
} //Theta(1)


TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation!
    if(this->current == this->multime.nrElems) {
        throw exception();
    }
	return this->multime.elements[this->current];
} //Theta(1)

bool SortedSetIterator::valid() const {
	//TODO - Implementation!
	if(this->current < this->multime.nrElems) {
	    return true;
	}
	return false;
} //Theta(1)

