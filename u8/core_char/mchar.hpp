//
//  mchar.hpp
//  testcli
//
//  Created by Luca Melandri
//  Copyright © 2021 Luca Melandri. All rights reserved.
//

#ifndef mchar_hpp
#define mchar_hpp

#include <iostream>
#include <vector>
#include <sstream>

#include "utils.hpp"

namespace u8
{

    // --------------------------------------------------------
    // UTF-8 Multiple Char
    // --------------------------------------------------------
    /// Enclosing character class to represent an UTF-8 character
    /// composed of multiple 1 Byte char without wasting space
    class _mchar
    {

    public:
        enum class mcharw
        {
            ASCII = 1,
            MULTI1,
            MULTI2,
            MULTI3
        };
        _mchar(mcharw size): m_size(size) {}
        _mchar(const _mchar& other) = delete;
        virtual ~_mchar()
        {
            DBG_DEL("base class mchar")
        }
        virtual char& operator[](int index) = 0;
        virtual _mchar* operator++() = 0;
        virtual char* get_underlying() = 0;
        friend std::ostream& operator<<(std::ostream& os, _mchar* mch);
        int itype() { return static_cast<int>(m_size); }
        const int itype() const { return static_cast<int>(m_size); }
        mcharw type() { return m_size; }
        const mcharw type() const { return m_size; }
        
    protected:
        const mcharw m_size;
        template<mcharw N>
        union utf8 {
            char a;
            char ca[static_cast<int>(N)];
        };
    };

    // --------------------------------------------------------
    // mchar class for 1 bytes encoded UTF-8 char
    // --------------------------------------------------------
    class mchar1: public virtual _mchar
    {
    public:
        mchar1(): _mchar(mcharw::ASCII) {}
        mchar1(const std::string& init): _mchar(mcharw::ASCII)
        {
            for (int i = 0; i < init.length(); ++i)
                m_value.ca[i] = init.c_str()[i];
        }
        ~mchar1() { DBG_DEL("mchar1") }
        mchar1(const mchar1& other) = delete;
        char* get_underlying() override { return m_value.ca; }
        virtual _mchar* operator++() override;
        char& operator[](int index) override
        {
            if (index != 0)
                throw -1;
            return m_value.a;
        }
    private:
        utf8<mcharw::ASCII> m_value;
    };

    // --------------------------------------------------------
    // mchar class for 2 bytes encoded UTF-8 char
    // --------------------------------------------------------
    class mchar2: public virtual _mchar
    {
    public:
        mchar2():_mchar(mcharw::MULTI1) {}
        mchar2(const std::string& init): _mchar(mcharw::MULTI1)
        {
            for (int i = 0; i < init.length(); ++i)
                m_value.ca[i] = init.c_str()[i];
        }
        ~mchar2() { DBG_DEL("mchar2") }
        mchar2(const mchar2& other) = delete;
        char* get_underlying() override { return m_value.ca; }
        virtual _mchar* operator++() override;
        char& operator[](int index) override
        {
            if (index < 0 || index > 1)
                throw -1;
            return m_value.ca[index];
        }
    private:
        utf8<mcharw::MULTI1> m_value;
    };

    // --------------------------------------------------------
    // mchar class for 3 bytes encoded UTF-8 char
    // --------------------------------------------------------
    class mchar3: public virtual _mchar
    {
    public:
        mchar3():_mchar(mcharw::MULTI2) {}
        mchar3(const std::string& init): _mchar(mcharw::MULTI2)
        {
            for (int i = 0; i < init.length(); ++i)
                m_value.ca[i] = init.c_str()[i];
        }
        ~mchar3() { DBG_DEL("mchar3") }
        mchar3(const mchar3& other) = delete;
        char* get_underlying() override { return m_value.ca; }
        virtual _mchar* operator++() override;
        char& operator[](int index) override
        {
            if (index < 0 || index > 2)
                throw -1;
            return m_value.ca[index];
        }
    private:
        utf8<mcharw::MULTI2> m_value;
    };

    // --------------------------------------------------------
    // mchar class for 4 bytes encoded UTF-8 char
    // --------------------------------------------------------
    class mchar4: public virtual _mchar
    {
    public:
        mchar4():_mchar(mcharw::MULTI3) {}
        mchar4(const std::string& init): _mchar(mcharw::MULTI3)
        {
            for (int i = 0; i < init.length(); ++i)
                m_value.ca[i] = init.c_str()[i];
        }
        ~mchar4() { DBG_DEL("mchar4") }
        mchar4(const mchar4& other) = delete;
        char* get_underlying() override { return m_value.ca; }
        virtual _mchar* operator++() override;
        char& operator[](int index) override
        {
            if (index < 0 || index > 3)
                throw -1;
            return m_value.ca[index];
        }
    private:
        utf8<mcharw::MULTI3> m_value;
    };


    // --------------------------------------------------------
    // UTF-8 Mchar Class Wrapper (handles the _mchar pointer memory allocation)
    // --------------------------------------------------------
    /// class to manage _mchar pointer references to handle inheritance accordingly to
    /// _mchar class hierarchy and to manage memory consistency using a RAII approach
    class mchar
    {
    public:
        // managed pointer type
        using pointer = _mchar*;
        // friends
        friend std::ostream& operator<< (std::ostream& os, mchar& mch);
        // CTORs
        mchar(): m_ptr(nullptr) {}
        mchar(pointer ptr): m_ptr(ptr) {}
        // BIG 5
        mchar(const mchar& mchr);
        mchar(mchar&& mchr): m_ptr(std::move(mchr.m_ptr))
        {
            DBG("mchar::Move CTOR")
            if (m_ptr)
                delete m_ptr;
            mchr.m_ptr = nullptr;
        }
        mchar& operator = (const mchar& mchr)
        {
            DBG("mchar::Copy OPERATOR")
            mchar mchtmp(mchr);
            std::swap(m_ptr, mchtmp.m_ptr);
            return *this;
        }
        mchar& operator = (mchar&& mchr)
        {
            DBG("mchar::Move OPERATOR")
            if (m_ptr)
                delete m_ptr;
            m_ptr = std::move(mchr.m_ptr);
            mchr.m_ptr = nullptr;
            return *this;
        }
        ~mchar()
        {
            DBG_BLOCK({
                std::stringstream ss;
                if(m_ptr != nullptr)
                    ss << m_ptr;
                DBG("mchar DTOR => " << ((m_ptr) ? ss.str() : " [EMPTY] "));
            })
            delete m_ptr;
            m_ptr = nullptr;
        }
        // operators
        pointer operator++ ();
        pointer operator++ (int);
        // get underlying value
        pointer operator*()
        {
            return m_ptr;
        }
        // utilities
        void reset() { m_ptr = nullptr; }
        pointer internal() { return m_ptr; }
        const pointer internal() const { return m_ptr; }
        static pointer zero() { return nullptr; }
    private:
        // internal managed pointer
        pointer m_ptr;
    };

}

#endif /* mchar_hpp */
