//
//  main.cpp
//  testcli
//
//  Created by Luca Melandri
//  Copyright © 2021 Luca Melandri. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <array>

#include "mstr.hpp"

int main(int argc, const char * argv[])
{
    // initialize local chrono environment
    CHRONO_INIT
    // test build time for the construction of an u8::mstr from utf-8 encoded string
    CHRONO({
        u8::mstr chinese_test(u8"狗将以传统刻字打开");
    }, 1)
    
    // construct an u8::mstr from utf-8 encoded string and print it
    u8::mstr chinese_test(u8"狗将以传统刻字打开");
    std::cout << chinese_test << std::endl;
    
    // build u8::mchar to handle an utf-8 single byte character and print it
    u8::mchar tchar(new u8::mchar1("a"));
    std::cout << tchar << "\n";
    
    // catch second character in chinese_test u8::mstr
    auto tutto(chinese_test[1]);
    std::cout << tutto << "\n";
    
    // get an u8::mchar from the u8::mstr and print using its internal value
    std::cout << *chinese_test[1] << "\n";
    std::cout << *chinese_test[2] << "\n";
    
    // build vector of u8::mchar from an initializer list
    std::vector<u8::mchar> mchar_vect({ new u8::mchar3(u8"狗"),
                                        new u8::mchar3(u8"打"),
                                        new u8::mchar3(u8"传")
                                      });
    CHRONO({
        // build u8::mstr from u8::mchar std::vector<u8::mchar>
        u8::mstr str_from_vect(mchar_vect);
        
        // build u8::mstr from u8::mchar initializer list
        u8::mstr str_from_init_list({ new u8::mchar3(u8"狗"),
                                      new u8::mchar3(u8"打"),
                                      new u8::mchar3(u8"传")
                                    });
        // build u8::mchar from the right fit utf-8 character
        u8::mchar emoji_right_size(new u8::mchar4(u8"😀"));
        // easier to get the same char from an u8::mstr using indexing
        u8::mstr emoji(u8"😀");
        u8::mchar tmpinc = emoji[0];
    }, 2)
    
    // build u8::mstr from u8::mchar std::vector<u8::mchar>
    u8::mstr str_from_vect(mchar_vect);
    
    // build u8::mstr from u8::mchar initializer list
    u8::mstr str_from_init_list({ new u8::mchar3(u8"狗"),
                                  new u8::mchar3(u8"打"),
                                  new u8::mchar3(u8"传")
                                });
    // build u8::mchar from the right fit utf-8 character
    u8::mchar emoji_right_size(new u8::mchar4(u8"😀"));
    // easier to get the same char from an u8::mstr using indexing
    u8::mstr emoji(u8"😀");
    u8::mchar tmpinc = emoji[0];
    
    CHRONO({
            for (int i = 0; i < 10; ++i)
                std::cout << ++tmpinc << std::endl;
    }, 3)
    
    // u8::mchar temporary wrapper to not leak the post-increment
    u8::mchar wr;
    for (int i = 0; i < 10; ++i)
        std::cout << (wr = tmpinc++) << std::endl;
    
    // direct use of u8::mstr static method encode to get
    // corresponding utf-8 encoded u8::mchar::pointer, wrapped in
    // u8::mchar instance for memory management
    u8::mchar enc = u8::mstr::encode(2047);
    std::cout << ++enc << std::endl;
    
    enc = u8::mstr::encode(8943);
    std::cout << enc << std::endl;
    
    // instance of uppercase a wrapped in u8::mchar
    u8::mchar character_a(new u8::mchar1("A"));
    
    // push character_a into a vector of mchar
    std::vector<u8::mchar> pvc;
    pvc.push_back(character_a);
    // MUST catch postfix increment pointer (which would otherwise leak)
    pvc.push_back((wr = character_a++));
    // catch (for fun) pointer of character_a
    pvc.push_back((wr = ++character_a));
    
    // reset the wrapper to not double free the memory
    // of the last catched pointer at the exit from main
    wr.reset();
    
    // get a copy of std::vector containing u8:mchar
    std::vector<u8::mchar> tmp = chinese_test.get_mchar_vector();
    
    // copy first char of traditional chinese string used for test
    u8::mchar ch = chinese_test[1];
    
    // std::array of u8::mchar::pointer, to hold the value (pointer) of the corresponding mchars
    std::array<u8::mchar::pointer, 3> arr;
    arr[0] = *ch;
    arr[1] = *chinese_test[3];
    arr[2] = *chinese_test[1];
   
    // vector of u8::mchar
    std::vector<u8::mchar> vec;
    
    {
        // block scope to force RAII destruction
        u8::mchar a(new u8::mchar1("W"));
        u8::mchar b(new u8::mchar1("Q"));
        vec.push_back(a);
        vec.push_back(b);
    }
    std::cout << "-------- THE END --------" << std::endl;
    return 0;
}
