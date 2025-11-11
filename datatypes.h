#ifndef DATATYPES_H
#define DATATYPES_H

#include <cstdint>

#define BUFFER_SIZE 100

#pragma pack(push, 1)
struct ADC_pack_struct {
    uint16_t number;
    uint16_t chan_num;
    uint64_t TS;
    uint64_t sync_TS;
    uint32_t dTS;
    int32_t adc_l[BUFFER_SIZE];
};
#pragma pack(pop)

#endif // DATATYPES_H
