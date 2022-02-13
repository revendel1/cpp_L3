#ifndef HW_L3_DOMAIN_LAYER_H
#define HW_L3_DOMAIN_LAYER_H

#include "hw/l4_InfrastructureLayer.h"

const size_t MAX_NAME_LENGTH     = 50;
const size_t MIN_VALUE           = 0;
const size_t MAX_COST            = 50000;
const size_t MAX_SIZE            = 4294967296;
const size_t MAX_MARK            = 5;

class Store : public ICollectable {
    std::string   _name_of_app;
    std::string   _category;
    float    _cost;
    uint32_t _sizeapp;
    uint32_t _number_of_install;
    float    _mark;

protected:
    bool invariant() const;

public:
    Store() = delete;
    Store(const Store & s) = delete;

    Store & operator = (const Store & s) = delete;

    Store(const std::string & name_of_app, const std::string & category, float cost, uint32_t sizeapp, uint32_t number_of_install, float mark);

    const std::string & getNameOfApp() const;
    const std::string & getCategory() const;
    float               getCost() const;
    uint32_t            getSizeApp() const;
    uint32_t            getNumberOfInstall() const;
    float               getMark() const;

    virtual bool   write(std::ostream& os) override;
};


class ItemCollector: public ACollector
{
public:
    virtual std::shared_ptr<ICollectable> read(std::istream& is) override;
};

#endif // HW_L3_DOMAIN_LAYER_H
