#include "Warehouse.h"

using namespace std;

void Warehouse::deallocate()
{
    // step 1: loop through the vector and delete each Box pointer it contains.
    for (Box *boxPtr : *_pBoxen)
    {
        delete boxPtr;
    }

    // step 2: After the contents are deleted, delete the vector itself.
    delete _pBoxen;
}

void Warehouse::deepCopy(const Warehouse &other)
{
    // step 1: allocate a new vector for the new Warehouse object on the free store
    _pBoxen = new vector<Box *>;

    // step 2: copy the _warehouseLetter
    _warehouseLetter = other._warehouseLetter;

    // step 3: iterate through the other warehosue's boxes, create a new copy of each box, and add the new box to the new vector
    for (size_t i = 0; i < other.getNumberOfBoxes(); i++)
    {
        double boxSize = other.getBox(i)->getBoxSize();
        _pBoxen->push_back(new Box(boxSize));
    }
}

Warehouse::Warehouse()
{
    _pBoxen = new vector<Box *>;
    _warehouseLetter = '?';
}

Warehouse::~Warehouse()
{
    this->deallocate();
}

Warehouse::Warehouse(const Warehouse &other)
{
    this->deepCopy(other);
}

Warehouse &Warehouse::operator=(const Warehouse &other)
{
    // step 1: chcek for self assignment
    if (this == &other)
    {
        return *this;
    }

    // step 2: deallocate old data `this` owns
    this->deallocate();

    // step 3: deep copy
    this->deepCopy(other);

    // step 4: return the reference to allow chained assignemnt
    return *this;
}

void Warehouse::storeInBox(const int SIZE)
{
    _pBoxen->push_back(new Box(SIZE));
}

Box *Warehouse::getBox(const size_t BOX_POS) const
{
    return _pBoxen->at(BOX_POS);
}

size_t Warehouse::getNumberOfBoxes() const
{
    return _pBoxen->size();
}

char Warehouse::getWarehouseLetter() const
{
    return _warehouseLetter;
}

void Warehouse::setWarehouseLetter(const char warehouseLetter)
{
    _warehouseLetter = warehouseLetter;
}

std::ostream &operator<<(ostream &os, const Warehouse &WH)
{
    os << "Warehouse " << WH.getWarehouseLetter() << " has " << WH.getNumberOfBoxes() << " boxes (";
    for (size_t i = 0; i < WH.getNumberOfBoxes(); i++)
    {
        os << WH.getBox(i)->getBoxSize();
        if (i < WH.getNumberOfBoxes() - 1)
        {
            os << ", ";
        }
    }
    os << ")";
    return os;
}
