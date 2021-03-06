// Copyright 2014 GSI, Inc. All rights reserved.
//
// This file contains a number of helpers to calculate execution time of a function.
//
#ifndef TIMEMEASURE_H_
#define TIMEMEASURE_H_

#include <chrono>

namespace MiscCommon
{
    template <typename TimeT = std::chrono::milliseconds>
    struct STimeMeasure
    {
        template <typename F, typename... Args>
        static typename TimeT::rep execution(F func, Args&&... args)
        {
            auto start = std::chrono::system_clock::now();

            // Now call the function with all the parameters you need.
            func(std::forward<Args>(args)...);

            auto duration = std::chrono::duration_cast<TimeT>(std::chrono::system_clock::now() - start);

            return duration.count();
        }

        //        template <typename F>
        //        static typename TimeT::rep execution(F const& func)
        //        {
        //            auto start = std::chrono::system_clock::now();
        //            func();
        //            auto duration = std::chrono::duration_cast<TimeT>(std::chrono::system_clock::now() - start);
        //            return duration.count();
        //        }
    };
} // namespace MiscCommon

#endif /*TIMEMEASURE_H_*/
