//
// Created by lightwave on 13.09.16.
//
#ifndef CDS_STAT_TIMESTAMPDEQUE_OUT_H
#define CDS_STAT_TIMESTAMPDEQUE_OUT_H

#include <cds_test/stress_test.h>
#include <cds/container/timestamped_deque.h>

namespace cds_test {
    static inline property_stream& operator <<( property_stream& o, cds::container::timestamped_deque::Statistic const& temp)
    {
        return o;
    }
} // namespace cds_test


#endif //CDS_STAT_TIMESTAMPDEQUE_OUT_H
