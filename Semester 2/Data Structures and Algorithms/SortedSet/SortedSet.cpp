#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
	//TODO - Implementation!
	this->relation = r;
	this->nrElems = 0;
	this->capacity = 1;
}


bool SortedSet::add(TComp elem) {
	//TODO - Implementation!
	if(this->capacity == this->nrElems) {
        this->resize();
	}
	for(int index = 0; index < nrElems; index++) {
	    if(this->elements[index] == elem) {
	        return false;
	    }
	    else if(!this->relation(elem, this->elements[index])) {
	        for(int j = index+1; j <= this->nrElems; j++) {
                this->elements[j] = this->elements[j-1];
	        }
	        this->elements[index] = elem;
	    }
	}
	nrElems++;
	return true;
}


bool SortedSet::remove(TComp elem) {
	//TODO - Implementation!
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


bool SortedSet::search(TComp elem) const {
	//TODO - Implementation!
	int left = 0;
	int right = nrElems - 1;
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


int SortedSet::size() const {
	//TODO - Implementation!
	return nrElems;
}



bool SortedSet::isEmpty() const {
	//TODO - Implementation!
	return nrElems == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	//TODO - Implementation!
	delete[] this->elements;
}

void SortedSet::resize() {
    auto newArr = new TComp[2 * capacity];
    for (int i = 0; i < this->size(); ++i) {
        newArr[i] = this->elements[i];
    }
    this->elements = newArr;
    capacity *= 2;
}

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


