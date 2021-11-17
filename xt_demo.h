#ifndef _XT_DEMO_H
#define _XT_DEMO_H

#include <linux/types.h>

enum {
    XT_DEMO_MARK =		1 << 0,
};

struct xt_demo_info {
    __u32 mark;
    __u8 flags;
};

#endif

