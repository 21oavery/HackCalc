#include <linux/init.h>
#include <linux/module.h>

static struct usb_driver ti_driver {
    .name = "nspire_calc";
}

static int __init nspire_calc_init() {
    int r = usb_register(&ti_driver);
    if (r < 0) {
        err("usb_register failed for "__FILE__" driver\nerror code %d", r);
    }
    return r;
}

static void __exit nspire_calc_exit() {
    usb_deregister(&ti_driver);
