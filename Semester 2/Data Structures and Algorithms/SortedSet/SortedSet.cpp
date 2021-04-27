#include <iostream>
#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
	this->relation = r;
	this->nrElems = 0;
	this->capacity = 10;
    this->elements = new TComp[capacity];
}
// Theta(1)

bool SortedSet::add(TComp elem) {
	if(this->capacity == this->nrElems) {
        this->resize();
	}
	for(int index = 0; index < nrElems; index++) {
	    if(this->elements[index] == elem) {
	        return false;
	    }
	    else if(this->relation(elem, this->elements[index])) {
	        for(int j = nrElems; j > index; j--) {
                this->elements[j] = this->elements[j-1];
	        }
	        this->elements[index] = elem;
            nrElems++;
	        return true;
	    }
	}
	this->elements[nrElems] = elem;
	nrElems++;
	return true;
}
// Best case: Theta(1), Worst case: Theta(nrElems) => Total complexity: O(nrElems)

bool SortedSet::remove(TComp elem) {
	int pos = get_position(elem);
	if(pos == -1) {
	    return false;
	}
	for(int index = pos; index < this->nrElems-1; index++) {
	    this->elements[index] = this->elements[index+1];
	}
	nrElems--;
	return true;
}
// Best case: Theta(log2(nrElems)), Worst case: Theta(nrElems) => Total complexity: O(nrElems)

bool SortedSet::search(TComp elem) const {

	int left = 0;
	int right = nrElems-1;
	while(left <= right) {
	    int m = (left + right) / 2;
	    if(this->elements[m] == elem) {
	        return true;
	    }
	    if(this->relation(this->elements[m], elem)) {
	        left = m + 1;
	    }
	    else {
	        right = m - 1;
	    }
	}
	return false;
}
// Best case: Theta(1), Worst case: Theta(log2(nrElems)) => Total complexity: O(log2(nrElems))

int SortedSet::size() const {

	return nrElems;
}
// Theta(1)


bool SortedSet::isEmpty() const {

	return nrElems == 0;
}
// Theta(1)

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}
// Theta(1)

SortedSet::~SortedSet() {
	//TODO - Implementation!
	delete[] this->elements;
}
// Theta(1)

void SortedSet::resize() {
    auto newArr = new TComp[2 * capacity];
    for (int i = 0; i < this->size(); ++i) {
        newArr[i] = this->elements[i];
    }
    this->elements = newArr;
    capacity *= 2;
}
// Theta(nrElems)

int SortedSet::get_position(TComp elem) {
    int left = 0;
    int right = nrElems - 1;
    while(left <= right) {
        int m = (left + right) / 2;
        if(this->elements[m] == elem) {
            return m;
        }
        if(this->relation(this->elements[m], elem)) {
            left = m + 1;
        }
        else {
            right = m - 1;
        }
    }
    return -1;
}

// Best case: Theta(1), Worst case: Theta(log2(nrElems)) => Total complexity: O(log2(nrElems))
