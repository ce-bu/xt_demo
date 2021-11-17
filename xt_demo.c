#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter/x_tables.h>
#include "xt_demo.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Cezar B");
MODULE_DESCRIPTION("xt_demo module.");
MODULE_VERSION("0.01");


static int demo_mt_check(const struct xt_mtchk_param *par)
{
    printk("%s\n", __PRETTY_FUNCTION__);
    return 0;
}

static bool demo_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
    const struct xt_demo_info *info = par->matchinfo;
    printk("%s mark=%u\n", __PRETTY_FUNCTION__, info->mark);
    return 0;
}

static struct xt_match demo_mt_reg __read_mostly = {
	.name       = "demo",
	.revision   = 0,
	.family     = NFPROTO_UNSPEC,
	.match      = demo_mt,
	.checkentry = demo_mt_check,
	.matchsize  = XT_ALIGN(sizeof(struct xt_demo_info)),
	.me         = THIS_MODULE,
};

static int __init demo_init(void) {    
    printk(KERN_INFO "+xt_demo\n");
    return xt_register_match(&demo_mt_reg);
}
static void __exit demo_exit(void) {
    printk(KERN_INFO "-xt_demo\n");
    xt_unregister_match(&demo_mt_reg);
}

module_init(demo_init);
module_exit(demo_exit);
