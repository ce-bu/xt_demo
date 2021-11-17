/*
 * Shared library add-on to iptables to add DEMO matching.
 *
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <xtables.h>
#include "xt_demo.h"

enum {
    O_MARK = 0,

};

#define s struct xt_demo_info
static const struct xt_option_entry demo_opts[] = {
    {
        .name = "mark", .id = O_MARK, .type = XTTYPE_UINT32,
        .flags = XTOPT_INVERT | XTOPT_PUT, XTOPT_POINTER(s, mark),
        .max = INT_MAX
    },
    XTOPT_TABLEEND,
};
#undef s

static void demo_help(void)
{
	printf(
"DEMO options:\n"
"[!] --mark value                some marker\n"
		);
}



static void demo_parse(struct xt_option_call *cb)
{
	struct xt_demo_info *info = cb->data;

	xtables_option_parse(cb);
	switch (cb->entry->id) {
            case O_MARK:
		info->mark = cb->val.u32;
		break;
        }
}

                        
static struct xtables_match demo_match_reg = {
    
    .version       = XTABLES_VERSION,
    .name          = "demo",
    .revision      = 0,
    .family        = NFPROTO_UNSPEC,
    .size          = XT_ALIGN(sizeof(struct xt_demo_info)),
    .userspacesize = XT_ALIGN(sizeof(struct xt_demo_info)),
    .help          = demo_help,
    .x6_parse      = demo_parse,
    .x6_options    = demo_opts
    
};

void _init(void)
{
    xtables_register_match(&demo_match_reg);

}
