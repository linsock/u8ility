//
//  mstr.hpp
//  testcli
//
//  Created by Luca Melandri
//  Copyright © 2021 Luca Melandri. All rights reserved.
//

#ifndef mstr_hpp
#define mstr_hpp


#include <iostream>
#include <vector>
#include <sstream>

#include "mchar.hpp"
#include "utils.hpp"

namespace u8
{
    
    // --------------------------------------------------------
    // UTF-8 String Class (composed of multiple chars a.k.a. mchar)
    // --------------------------------------------------------
    /// Enclosing string class to represent an UTF-8 string composed
    /// of 1-N multiple characters (mchar) entries
    class mstr
   {
   public:
       // friends
       friend std::ostream& operator<< (std::ostream& os, mstr& str);
       // statics
       static uint32_t decode(const mchar mch); // decode an instance of mchar
       static uint32_t decode(_mchar* mch); // decode an instance of mchar
       static u8::_mchar* encode(uint32_t ch); // encode a UNICODE identifier into a mchar instance
       // CTORs
       mstr(std::initializer_list<mchar>&& chs)
       {
           DBG("Initializer list ctor")
           std::stringstream ss;
           for (int i = 0; i < chs.size(); ++i)
           {
               _mchar* ch = const_cast<_mchar*>((*(chs.begin()+i)).internal());
               ss << ch;
           }
           m_str = ss.str();
           parse(false);
           m_it = std::begin(m_char_slice);
       }
       mstr(std::vector<mchar>& chs)
       {
           std::stringstream ss;
           for (auto mch : chs)
               ss << *mch;
           m_str = ss.str();
           parse(false);
           m_it = std::begin(m_char_slice);
       }
       mstr(std::string& str): m_str(str)
       {
           parse(false);
           m_it = std::begin(m_char_slice);
       }
       mstr(std::string&& str): m_str(str)
       {
           parse(false);
           m_it = std::begin(m_char_slice);
       }
       // BIG 5
       mstr(mstr& mine)
       {
           m_str = std::string(mine.m_str);
           m_char_slice = std::vector<std::pair<int, int>>(mine.m_char_slice);
       }
       mstr(mstr&& mine)
       {
           m_str = std::move(mine.m_str);
           m_char_slice = std::move(mine.m_char_slice);
       }
       mstr& operator = (mstr& mine)
       {
           mstr tmp(mine);
           std::swap(m_char_slice, mine.m_char_slice);
           std::swap(m_str, mine.m_str);
           return *this;
       }
       mstr& operator = (mstr&& mine)
       {
           m_str = std::move(mine.m_str);
           m_char_slice = std::move(mine.m_char_slice);
           return *this;
       }
       ~mstr() = default;
       // indexed accessor to chars (on demand)
       mchar operator[](int index)
       {
           if (index < m_char_slice.size())
           {
               m_it = std::begin(m_char_slice) + index;
               return build_next();
           }
           throw -1;
       }
       // extract a vector of mchar from the underlying string
       std::vector<mchar> get_mchar_vector();
       // public iterator to mstr slice representation
       using CharIterator = std::vector<std::pair<int, int>>::iterator;
   private:
       _mchar* build_next();
       void parse(bool prnt=true);
       static _mchar* build_mchar(uint32_t ch, _mchar::mcharw size);
       // hidden members
       std::string m_str;
       std::vector<std::pair<int, int>> m_char_slice;
       CharIterator m_it;
   }; // end of mstr
}

#endif /* mstr_hpp */
