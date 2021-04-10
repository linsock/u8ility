//
//  mstr.cpp
//  testcli
//
//  Created by Luca Melandri
//  Copyright © 2021 Luca Melandri. All rights reserved.
//

#include "mstr.hpp"

#include <vector>

std::vector<u8::mchar> u8::mstr::get_mchar_vector()
{
    m_it = std::begin(m_char_slice);
    std::vector<mchar> chars(m_char_slice.size());
    
    _mchar* tmp;
    int i = 0;
    do
    {
        tmp = build_next();
        if (tmp != mchar::zero()) {
            chars[i] = tmp;
            ++i;
        }

    } while (tmp != mchar::zero());
    return chars;
}

u8::_mchar* u8::mstr::build_next()
{
    if (m_it != std::end(m_char_slice))
    {
        auto curr = *m_it;
        u8::_mchar* ch;
        u8::_mchar::mcharw sz = static_cast<u8::_mchar::mcharw>(curr.second-curr.first+1);
        switch(sz)
        {
            case u8::_mchar::mcharw::ASCII:
                ch = new u8::mchar1();
                break;
            case u8::_mchar::mcharw::MULTI1:
                ch = new mchar2();
                break;
            case u8::_mchar::mcharw::MULTI2:
                ch = new mchar3();
                break;
            case u8::_mchar::mcharw::MULTI3:
                ch = new mchar4();
                break;
            default:
                //return nullptr; // Me ne pentiro' sicuramente
                break;
        }
        for (int s = curr.first, i = 0; s <= curr.second; ++s, ++i)
            (*ch)[i] = m_str[s];
        ++m_it;
        return ch;
    }
    return nullptr;
}


uint32_t u8::mstr::decode(mchar mch) // funziona, otteniamo la corrispondente forma decimale
{
    return decode(mch.internal());
} // decode an instance of mchar

uint32_t u8::mstr::decode(_mchar* ch) // funziona, otteniamo la corrispondente forma decimale
{
    switch (ch->type()) {
        case u8::_mchar::mcharw::ASCII:
            return static_cast<uint32_t>(ch->get_underlying()[0]);
        case u8::_mchar::mcharw::MULTI1:
        {
            char* under = ch->get_underlying();
            uint16_t primo = under[0] & 0x1F; // 63 aka 00111111
            primo = primo << 6;
            primo = primo | (under[1] & 0x3F);
            return primo; // upcasting
        }
        case u8::_mchar::mcharw::MULTI2:
        {
            char* under = ch->get_underlying();
            uint32_t primo = under[0] & 0x0F; // 15 aka 00001111
            primo = primo << 6;
            primo = primo | (under[1] & 0x3F);
            primo = primo << 6;
            primo = primo | (under[2] & 0x3F);
            return primo; // upcasting
        }
        case u8::_mchar::mcharw::MULTI3:
        {
            // caso 4
            char* under = ch->get_underlying();
            uint32_t primo = under[0] & 0x07; // 7 aka 00000111
            primo = primo << 6;
            primo = primo | (under[1] & 0x3F);
            primo = primo << 6;
            primo = primo | (under[2] & 0x3F);
            primo = primo << 6;
            primo = primo | (under[3] & 0x3F);
            return primo;
        }
        default:
            break;
    }
    return -99l;
} // decode an instance of mchar


u8::_mchar* u8::mstr::build_mchar(uint32_t ch, _mchar::mcharw size)
{
    _mchar* out;
    _mchar::mcharw mcsize = static_cast<_mchar::mcharw>(size);
    switch (mcsize) {
        case u8::_mchar::mcharw::ASCII:
        {
            out = new mchar1();
            (*out)[0] = ch & 255;
            break;
        }
        case u8::_mchar::mcharw::MULTI1:
        {
            out = new mchar2();
            (*out)[1] = 0x80 | (ch & 0x3F);
            (*out)[0] = 0xC0 | ( (ch >> 6) & 0x1F);
            break;
        }
        case u8::_mchar::mcharw::MULTI2:
        {
            out = new mchar3();
            (*out)[2] = 0x80 | (ch & 0x3F);
            (*out)[1] = 0x80 | static_cast<char>((ch >> 6) & 0x3F);
            (*out)[0] = 0xE0 | static_cast<char>((ch >> 12) & 0x0F);
            
            break;
        }
        case u8::_mchar::mcharw::MULTI3:
        {
            out = new mchar4();
            (*out)[3] = 0x80 | (ch & 0x3F);
            (*out)[2] = 0x80 | ((ch >> 6) & 0x3F);
            (*out)[1] = 0x80 | ((ch >> 12) & 0x3F);
            (*out)[0] = 0xF0 | ( (ch >> 18) & 0x07);
            break;
        }
        default:
            out = nullptr;
            break;
    }
    return out;
}

// encode a UNICODE identifier into a mchar instance
u8::_mchar* u8::mstr::encode(uint32_t ch)
{
    auto b4 = static_cast<int>((ch >= 0x010000)&&(ch <= 0x10FFFF));
    auto b3 = static_cast<int>((ch >= 0x0800)&&(ch <= 0xFFFF));
    auto b2 = static_cast<int>((ch >= 0x0080)&&(ch <= 0x07FF));
    u8::_mchar::mcharw size = static_cast<u8::_mchar::mcharw>(b4 * 4 + b3 * 3 + b2 * 2);
    
    if(ch < 0x0080)
        size = u8::_mchar::mcharw::ASCII;
    _mchar* out = build_mchar(ch, size);
    return out;
}


void u8::mstr::parse(bool prnt)
{
    for(int s = 0; s < m_str.length();)
    {
        char sstr = m_str[s];
        
        int t1 = static_cast<int>((sstr & 0xF0) == 0xF0);
        int t2 = static_cast<int>((sstr & 0xE0) == 0xE0);
        int t3 = static_cast<int>((sstr & 0xC0) == 0xC0);
        int t4 = static_cast<int>(sstr <= 0x7F);
        int inner = t1 + t2 + t3 + t4;
        m_char_slice.push_back(std::make_pair(s, s+inner-1));
        DBG_BLOCK({
            DBG("Head of " + std::to_string(inner) + " byte encode of utf8 representation")
            DBG_FOR("inner byte of utf8 representation", inner)
        })
        s+=inner;
    }
}
    
std::ostream& u8::operator<< (std::ostream& os, u8::mstr& str)
{
    os << str.m_str;
    return os;
}
