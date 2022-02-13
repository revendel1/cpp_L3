#include "hw/l3_DomainLayer.h"

using namespace std;


bool Store::invariant() const {
        return _cost >= MIN_VALUE && _cost <= MAX_COST
            && _sizeapp >= MIN_VALUE && _sizeapp <= MAX_SIZE
            && _number_of_install >= MIN_VALUE
            && _mark >= MIN_VALUE && _mark <= MAX_MARK 
            && !_name_of_app.empty() && _name_of_app.size() <= MAX_NAME_LENGTH
            && !_category.empty() && _category.size() <= MAX_NAME_LENGTH;
}

Store::Store(const std::string & name_of_app, const std::string & category, float cost, uint32_t sizeapp, uint32_t number_of_install, float mark)
        : _name_of_app(name_of_app), _category(category), _cost(cost), _sizeapp(sizeapp), _number_of_install(number_of_install), _mark(mark)
    {
        assert(invariant());
    }

const string & Store::getNameOfApp() const { return _name_of_app;}
const string & Store::getCategory() const { return _category;}
float Store::getCost() const { return _cost; }
uint32_t Store::getSizeApp() const { return _sizeapp; }
uint32_t Store::getNumberOfInstall() const { return _number_of_install; }
float Store::getMark() const { return _mark; }

bool   Store::write(ostream& os) {
    writeString(os, _name_of_app);
    writeString(os, _category);
    writeNumber(os, _cost);
    writeNumber(os, _sizeapp);
    writeNumber(os, _number_of_install);
    writeNumber(os, _mark);

    return os.good();
}

shared_ptr<ICollectable> ItemCollector::read(istream& is) {
    std::string   name_of_app = readString(is, MAX_NAME_LENGTH);
    std::string   category = readString(is, MAX_NAME_LENGTH);
    float    cost = readNumber<uint32_t>(is);
    uint32_t sizeapp = readNumber<uint32_t>(is);
    uint32_t number_of_install = readNumber<uint32_t>(is);
    float mark = readNumber<float>(is);

    return make_shared<Store>(name_of_app, category, cost, sizeapp, number_of_install, mark);
}
