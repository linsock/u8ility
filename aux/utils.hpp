//
//  utils.hpp
//  testcli
//
//  Created by Luca Melandri
//  Copyright © 2021 Luca Melandri. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#undef DEBUG

#if defined(DEBUG)
    #define DBG_FOR(name, n) \
        for (int i = 0; i < n; ++i) { \
            DBG(name)\
        }
    #define DBG_DEL(name) std::cout << "[DEBUG] DEL " << name << std::endl;
    #define DBG_BLOCK(instruction_block) \
                      instruction_block
    #define DBG(name) std::cout << "[DEBUG] " << name << std::endl;
#else
    #define DBG_FOR(name, n)
    #define DBG_DEL(name)
    #define DBG_BLOCK(instruction_block)
    #define DBG(name)
#endif


#define CHRONO_INIT \
    using hrc = std::chrono::high_resolution_clock;\
    using std::chrono::microseconds;\
    decltype(hrc::now()) main_chrono_start_time;\
    decltype(hrc::now()) main_chrono_end_time; \

#define CHRONO(instruction_block, id) \
    main_chrono_start_time = hrc::now();\
    instruction_block \
    main_chrono_end_time = hrc::now(); \
    std::cout << "[CHRONO] Time taken by block #" << id << ": " \
        << std::chrono::duration_cast<microseconds>(\
            main_chrono_end_time - main_chrono_start_time\
        ).count() << "μs " << std::endl;

#endif /* utils_hpp */
