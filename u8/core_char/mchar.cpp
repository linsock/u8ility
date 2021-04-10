//
//  mchar.cpp
//  testcli
//
//  Created by Luca Melandri
//  Copyright © 2021 Luca Melandri. All rights reserved.
//

#include "mchar.hpp"
#include "mstr.hpp"

u8::_mchar* u8::mchar1::operator++()
{
    // decode -> inc -> encode
    uint32_t decoded = u8::mstr::decode(this);
    ++decoded;
    _mchar* ptr = u8::mstr::encode(decoded);
    return ptr;
}

u8::_mchar* u8::mchar2::operator++()
{
    // decode -> inc -> encode
    uint32_t decoded = u8::mstr::decode(this);
    ++decoded;
    _mchar* ptr = u8::mstr::encode(decoded);
    return ptr;
}

u8::_mchar* u8::mchar3::operator++()
{
    // decode -> inc -> encode
    uint32_t decoded = u8::mstr::decode(this);
    ++decoded;
    _mchar* ptr = u8::mstr::encode(decoded);
    return ptr;
}

u8::_mchar* u8::mchar4::operator++()
{
    // decode -> inc -> encode
    uint32_t decoded = u8::mstr::decode(this);
    ++decoded;
    _mchar* ptr = u8::mstr::encode(decoded);
    return ptr;
}

u8::mchar::mchar(const u8::mchar& mchr)
{
    DBG("mchar::Copy CTOR")
    _mchar* copied;
    switch(mchr.m_ptr->type())
    {
        case _mchar::mcharw::ASCII:
            copied = new mchar1();
            break;
        case _mchar::mcharw::MULTI1:
            copied = new mchar2();
            break;
        case _mchar::mcharw::MULTI2:
            copied = new mchar3();
            break;
        case _mchar::mcharw::MULTI3:
            copied = new mchar4();
            break;
    }
    char* under_cpy = copied->get_underlying();
    _mchar* internal = const_cast<_mchar*>(mchr.internal());
    for (int i = 0; i < mchr.internal()->itype(); ++i)
        under_cpy[i] = (*internal)[i]; // char by char
    m_ptr = copied;
}

std::ostream& u8::operator<< (std::ostream& os, mchar& mch)
{
    os << *mch;
    return os;
}

std::ostream& u8::operator<<(std::ostream& os, u8::_mchar* mch)
{
    char* to_print = mch->get_underlying();
    u8::_mchar::mcharw how_many = mch->m_size;
    switch(how_many)
    {
        case u8::_mchar::mcharw::ASCII:
            os << to_print[0];
            break;
        case u8::_mchar::mcharw::MULTI1:
            os << to_print[0] << to_print[1];
            break;
        case u8::_mchar::mcharw::MULTI2:
            os << to_print[0] << to_print[1] << to_print[2];
            break;
        case u8::_mchar::mcharw::MULTI3:
            os << to_print[0] << to_print[1] << to_print[2] << to_print[3];
            break;
        default:
            return os;
    }
    return os;
}

u8::_mchar* u8::mchar::operator++ ()
{
    if (m_ptr)
    {
        _mchar* next = m_ptr->operator++();
        delete m_ptr;
        m_ptr = next;
        return m_ptr;
    }
    throw "Uninitialized MCHAR object";
}

// postfix increment will return the current underlying pointer
// before creating the new character, so it will leak if you don't
// catch the pointer :)
u8::_mchar* u8::mchar::operator++ (int)
{
    if (m_ptr)
    {
        u8::_mchar* ret_pre_inc = m_ptr;
        _mchar* next = m_ptr->operator++();
        m_ptr = next;
        return ret_pre_inc;
    }
    throw "Uninitialized MCHAR object";
//    return ++(*this);
}
